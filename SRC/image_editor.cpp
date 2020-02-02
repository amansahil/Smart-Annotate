#include "image_editor.h"

ImageEditor::ImageEditor() : imageSet(false), drawing(false), clipbord(false), cursorType(CursorType::Select), annotationShape(Rectangle), classLabel(""), currFileName(""), clipbordText(""), rubberBand(new QRubberBand(QRubberBand::Rectangle, nullptr))
{
    createActions();
}

void ImageEditor::createActions()
{
    deleteAction = new QAction(tr("Delete"), this);
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(deleteSelectedItem()));

    copyAction = new QAction(tr("Copy"), this);
    connect(copyAction, SIGNAL(triggered()), this, SLOT(copySelectedItem()));

    pasteAction = new QAction(tr("Paste"), this);
    connect(pasteAction, SIGNAL(triggered()), this, SLOT(pasteSelectedItemInPlace()));
}

ImageEditor::CursorType ImageEditor::getCursorType() const { return cursorType; }

ImageEditor::AnnotationShapeType ImageEditor::getAnnotationShapeType() const { return annotationShape; }

void ImageEditor::setImage(const QString fileName)
{
    // Save previous image details
    saveImageState();

    // Open new selected image
    try
    {
        ImageEditor::clear();

        openImage(fileName);

        currFileName = fileName;
        imageSet = true;

        updateCursorType(CursorType::Draw);
    }
    catch (QException e)
    {
        QMessageBox::warning(nullptr, "Error", "Could not open image");
    }

    // Load any annotation and lables on image if it exists
    if (savedStateExists(fileName))
    {
        for (int i = 0; i < applicationRectState.value(fileName).count(); i++)
        {
            drawRectangle(applicationRectState.value(fileName).at(i));
        }

        for (int i = 0; i < applicationTextState.value(fileName).count(); i++)
        {
            drawText(applicationTextState.value(fileName).at(i).first, applicationTextState.value(fileName).at(i).second);
        }

        for (int i = 0; i < applicationPolygonState.value(fileName).count(); i++)
        {
            drawPolygon(applicationPolygonState.value(fileName).at(i));
        }

    }
}

void ImageEditor::openImage(const QString fileName)
{
    const QImage image(fileName);
    const QImage small = image.scaled(781, 651, Qt::KeepAspectRatio);

    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(small));

    ImageEditor::addItem(item);
    ImageEditor::update();
}

void ImageEditor::saveImageState()
{
    if (imageSet && currFileName != "")
    {
        QList<QRectF> rectItems;
        QList<QPolygonF> polygonItems;
        QList<QPair<QString, QPointF>> textItems;

        for (int i = 0; i < ImageEditor::items().count(); i++)
        {
            QGraphicsPolygonItem *polygonItem = qgraphicsitem_cast<QGraphicsPolygonItem *>(ImageEditor::items().at(i));
            QGraphicsRectItem *rectItem = qgraphicsitem_cast<QGraphicsRectItem *>(ImageEditor::items().at(i));
            QGraphicsTextItem *textItem = qgraphicsitem_cast<QGraphicsTextItem *>(ImageEditor::items().at(i));

            if (rectItem != nullptr)
            {
                const QRectF newRectItem = rectItem->sceneBoundingRect();
                rectItems.append(newRectItem);
            }
            else if (textItem != nullptr)
            {
                QPair<QString, QPointF> newTextItem;
                newTextItem.first = textItem->toPlainText();
                newTextItem.second = textItem->pos();

                textItems.append(newTextItem);
            }
            else if(polygonItem != nullptr)
            {
                polygonItems.append(polygonItem->polygon().translated(polygonItem->scenePos()));
            }
        }

        applicationPolygonState[currFileName] = polygonItems;
        applicationRectState[currFileName] = rectItems;
        applicationTextState[currFileName] = textItems;
    }
}

bool ImageEditor::savedStateExists(const QString fileName)
{
    QHash<QString, QList<QRectF>>::const_iterator valueIt = applicationRectState.find(fileName);

    if (valueIt == applicationRectState.end())
    {
        return false;
    }
    return true;
}

QHash<QString, QList<QRectF>> ImageEditor::getApplicationRectState() const { return applicationRectState; }

void ImageEditor::updateCursorType(const ImageEditor::CursorType newCursorType)
{
    if (imageSet && cursorType != newCursorType)
    {
        cursorType = newCursorType;
        emit cursorTypeChanged();
    }
}

void ImageEditor::updateAnnotationShapeType(const AnnotationShapeType newAnnotationShape)
{
    if (annotationShape != newAnnotationShape)
    {
        annotationShape = newAnnotationShape;
        emit annotationShapeChanged();
    }

    cursorType = CursorType::Draw;
    emit cursorTypeChanged();
}

void ImageEditor::updateClassLabel(const QString newClassLabel)
{
    if (classLabel != newClassLabel)
    {
        classLabel = newClassLabel;
    }
}

void ImageEditor::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (imageSet)
    {
        origin = event->screenPos();
        originF = event->scenePos();

        if (cursorType == CursorType::Draw && event->button() == Qt::LeftButton)
        {
            if(annotationShape == AnnotationShapeType::Rectangle) {
                rubberBand->setGeometry(QRect(origin, QSize()));
                rubberBand->show();
            }
            else if(annotationShape == AnnotationShapeType::FreeHand)
            {
                clickPoints.append(originF);
            }
            else
            {
                QGraphicsEllipseItem* ellipseItem =new QGraphicsEllipseItem(QRectF(originF.x(), originF.y(), 10, 10));
                ellipseItem->setBrush(Qt::blue);
                ellipseItem->setPen(Qt::NoPen);
                ellipseItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
                ImageEditor::addItem(ellipseItem);

                clickEplipses.append(ellipseItem);
            }
        }
        else if (cursorType == CursorType::Text && classLabel != "")
        {
            drawText(classLabel, originF);
        }

        if (cursorType == CursorType::Select)
            QGraphicsScene::mousePressEvent(event);

        ImageEditor::update();
    }
}

void ImageEditor::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (imageSet)
    {
        if (cursorType == CursorType::Draw && (event->buttons() & Qt::LeftButton))
        {
            drawing = true;

            if(annotationShape == ImageEditor::AnnotationShapeType::Rectangle)
            {
                lastPoint = event->screenPos();
                lastPointF = event->scenePos();

                rubberBand->setGeometry(QRect(origin, lastPoint).normalized());
            }
            else if (annotationShape == ImageEditor::AnnotationShapeType::FreeHand)
            {
                clickPoints.append(event->scenePos());

                QPen pen;
                pen.setBrush(Qt::blue);
                pen.setWidth(1);

                QLineF lineF(clickPoints[clickPoints.size() - 2], clickPoints[clickPoints.size() - 1]);
                QGraphicsLineItem* item = this->addLine(lineF, pen);

                clickLines.append(item);
            }
        }

        if (cursorType == CursorType::Select)
            QGraphicsScene::mouseMoveEvent(event);

        ImageEditor::update();
    }
}

void ImageEditor::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (imageSet)
    {
        if (cursorType == CursorType::Draw && event->button() == Qt::LeftButton)
        {
            if(annotationShape == ImageEditor::AnnotationShapeType::Rectangle) {
                rubberBand->hide();

                drawRectangle(QRectF(originF, lastPointF));
            }
            else if (annotationShape == ImageEditor::AnnotationShapeType::FreeHand)
            {
                QPolygonF polygon;

                for(int i =0; i < clickPoints.size(); i++)
                {
                    if(clickPoints.size() - 1 == i)
                    {
                        polygon << clickPoints[i] << clickPoints[0];
                    }
                    else
                    {
                        polygon << clickPoints[i] << clickPoints[i+1];
                    }
                }

                drawPolygon(polygon);

                qDeleteAll(clickLines.begin(), clickLines.end());
                clickLines.clear();
                clickPoints.clear();
            }

            drawing = false;
        }

        if (cursorType == CursorType::Select)
            QGraphicsScene::mouseReleaseEvent(event);

        ImageEditor::update();
    }
}

void ImageEditor::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    if (cursorType == CursorType::Select && imageSet)
    {
        QMenu menu;

        menu.addAction(copyAction);
        menu.addAction(pasteAction);
        menu.addAction(deleteAction);

        clipbordClickPoint = event->scenePos();
        menu.exec(event->screenPos());
    }
}

void ImageEditor::keyPressEvent(QKeyEvent *event)
{
    if (event->type() == QKeyEvent::KeyPress && cursorType == CursorType::Select)
    {
        if (event->matches(QKeySequence::Copy))
        {
            copySelectedItem();
        }
        else if (event->matches(QKeySequence::Paste))
        {
            pasteSelectedItem();
        }
        else if (event->matches(QKeySequence::Delete))
        {
            deleteSelectedItem();
        }
    }
}

void ImageEditor::deleteSelectedItem()
{
    if (ImageEditor::selectedItems().size() > 0)
    {
        QGraphicsItem *selectedItem = ImageEditor::selectedItems().at(0);

        QGraphicsEllipseItem *elipseItem = qgraphicsitem_cast<QGraphicsEllipseItem *>(selectedItem);

        delete selectedItem;

        if(elipseItem)
        {
            clickEplipses.removeOne(elipseItem);
        }
    }
}

void ImageEditor::copySelectedItem()
{
    if (ImageEditor::selectedItems().size() > 0)
    {
        QGraphicsItem *selectedItem = ImageEditor::selectedItems().at(0);

        QGraphicsTextItem *textItem = qgraphicsitem_cast<QGraphicsTextItem *>(selectedItem);

        QGraphicsRectItem *rectItem = qgraphicsitem_cast<QGraphicsRectItem *>(selectedItem);

        QGraphicsPolygonItem *polygonItem = qgraphicsitem_cast<QGraphicsPolygonItem *>(selectedItem);

        clipbord = true;

        if (rectItem)
        {
            const QRectF selectedReactangle = selectedItem->sceneBoundingRect();

            clipbordContent = ClipbordContent::Rect;
            clipbordPoint = selectedReactangle.topLeft();
            clipbordHeight = selectedReactangle.height();
            clipbordWidth = selectedReactangle.width();
        }
        else if(textItem)
        {
            clipbordContent = ClipbordContent::Label;
            clipbordText = textItem->toPlainText();
            clipbordPoint = selectedItem->scenePos();
        }
        else
        {
            clipbordContent = ClipbordContent::Poly;
            clipbordPoint = selectedItem->scenePos();
            clipbordPolygon = polygonItem->polygon();
        }
    }
}

void ImageEditor::pasteSelectedItem()
{
    if (imageSet && clipbord)
    {
        const qreal x = clipbordPoint.x() + 4.0;
        const qreal y = clipbordPoint.y() - 8.0;

        if (clipbordContent == ClipbordContent::Rect)
        {
            drawRectangle(QRectF(QPointF(x, y), QSizeF(clipbordWidth, clipbordHeight)));
        }
        else if(clipbordContent == ClipbordContent::Label)
        {
            drawText(clipbordText, QPointF(x, y));
        }
        else
        {
            // Workaround to change position of polygon
            QPolygonF polygon = clipbordPolygon.translated(QPointF(x, y));
            drawPolygon(polygon);
        }

        updateCursorType(CursorType::Select);
    }
}

void ImageEditor::pasteSelectedItemInPlace()
{
    if (imageSet && clipbord)
    {
        const qreal x = clipbordClickPoint.x() + 4.0;
        const qreal y = clipbordClickPoint.y() - 8.0;

        if (clipbordContent == ClipbordContent::Rect)
        {
            drawRectangle(QRectF(QPointF(x, y), QSizeF(clipbordWidth, clipbordHeight)));
        }
        else if(clipbordContent == ClipbordContent::Label)
        {
            drawText(clipbordText, QPointF(x, y));
        }
        else
        {
            // Workaround to change position of polygon
            QPolygonF polygon = clipbordPolygon.translated(QPointF(x, y));
            drawPolygon(polygon, QPointF(x, y));
        }
    }
}

void ImageEditor::connectClickElipses()
{

    if(clickEplipses.size() <= 2)
    {
        QMessageBox::warning(nullptr, "Error", "You need to mark at least three points");
        return;
    }

    QPolygonF polygon;

    for(int i =0; i < clickEplipses.size(); i++)
    {
        if(clickEplipses.size() - 1 == i)
        {
            polygon << clickEplipses[i]->rect().topLeft() << clickEplipses[0]->rect().topLeft();;
        }
        else
        {
            polygon << clickEplipses[i]->rect().topLeft() << clickEplipses[i+1]->rect().topLeft();
        }
    }

    drawPolygon(polygon);
    deleteClickElipses();
}

void ImageEditor::deleteClickElipses()
{
    qDeleteAll(clickEplipses.begin(), clickEplipses.end());
    clickEplipses.clear();
}

void ImageEditor::drawPolygon(const QPolygonF newPolygon)
{
    QPen pen;
    pen.setBrush(Qt::blue);
    pen.setWidth(2);

    QGraphicsPolygonItem *polygon = ImageEditor::addPolygon(newPolygon, pen);
    polygon->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
}

void ImageEditor::drawPolygon(const QPolygonF newPolygon, const QPointF position)
{
    QPen pen;
    pen.setBrush(Qt::blue);
    pen.setWidth(2);

    QGraphicsPolygonItem *polygon = ImageEditor::addPolygon(newPolygon, pen);
    polygon->setPos(position);
    polygon->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
}

void ImageEditor::drawRectangle(const QRectF newRectangle)
{
    QPen pen;
    pen.setBrush(Qt::blue);
    pen.setWidth(2);

    QGraphicsRectItem *rectangle = ImageEditor::addRect(newRectangle, pen);
    rectangle->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

    CustomResizer *rectSizeGripItem = new CustomResizer(rectangle);
    resizerItems.append(rectSizeGripItem);
}

void ImageEditor::drawText(const QString newText, const QPointF newPoint)
{
    QFont font;
    font.setPixelSize(20);

    QGraphicsTextItem *text = ImageEditor::addText(newText, font);
    text->setPos(newPoint);
    text->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
}

void ImageEditor::clearItems()
{
    if (imageSet)
    {
        ImageEditor::clear();

        openImage(currFileName);

        if (savedStateExists(currFileName))
        {
            applicationPolygonState.remove(currFileName);
            applicationRectState.remove(currFileName);
            applicationTextState.remove(currFileName);
        }
    }
}
