#include "image_editor.h"

#define SCENE_WIDTH 781
#define SCENE_HEIGHT 651

ImageEditor::ImageEditor() : imageSet(false),
                             drawing(false),
                             clipbord(false),
                             cursorType(CursorType::Select),
                             annotationShape(Rectangle),
                             classLabel(""),
                             currFileName(""),
                             clipbordText(""),
                             rubberBand(new QRubberBand(QRubberBand::Rectangle, nullptr))
{
    createActions();
}

void ImageEditor::setImage(const QString fileName)
{
    // Save previous image details
    saveImageState();

    // Delete any smart annotation points from previous image
    deleteClickElipses();

    ImageEditor::clear();

    // Open new selected image
    try
    {
        openImage(fileName);
    }
    catch (QException &e)
    {
        QMessageBox::warning(nullptr, "Error", "Could not open image");
    }

    currFileName = fileName;
    imageSet = true;

    updateCursorType(CursorType::Draw);

    // Load any annotations and lables on image if it exists
    loadAnnotations();
}

void ImageEditor::loadAnnotations()
{
    if (savedStateExists(currFileName))
    {
        for (const QRectF &currRect: applicationRectState.value(currFileName))
        {
            drawRectangle(currRect);
        }

        for (const QPair<QString, QPointF> &currText: applicationTextState.value(currFileName))
        {
            drawText(currText.first, currText.second);
        }

        for (const QPolygonF &currPolygon: applicationPolygonState.value(currFileName))
        {
            drawPolygon(currPolygon);
        }
    }
}

void ImageEditor::saveImageState()
{
    if (imageSet)
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
            else if (polygonItem != nullptr)
            {
                // Ensures polygon is in the updated positon if moved or copied
                const QPolygonF newPolygonItem = polygonItem->polygon().translated(polygonItem->scenePos());
                polygonItems.append(newPolygonItem);
            }
        }

        applicationPolygonState[currFileName] = polygonItems;
        applicationRectState[currFileName] = rectItems;
        applicationTextState[currFileName] = textItems;
    }
}

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

    updateCursorType(CursorType::Draw);
}

void ImageEditor::updateClassLabel(const QString newClassLabel) { classLabel = newClassLabel; }

void ImageEditor::updateApplicationRectState(const QString fileName, const QList<QRectF> rectItems) { applicationRectState[fileName] = rectItems; }

void ImageEditor::updateApplicationPolygonState(const QString fileName, const QList<QPolygonF> polygonItems) { applicationPolygonState[fileName] = polygonItems; }

void ImageEditor::updateApplicationTextState(const QString fileName, const QList<QPair<QString, QPointF>> textItems) { applicationTextState[fileName] = textItems; }

void ImageEditor::clearItems()
{
    if (imageSet)
    {
        // Delete any smart annotation points from image
        deleteClickElipses();

        ImageEditor::clear();

        // ImageEditor::clear method clears the image too so the image needs to be openned again
        try
        {
            openImage(currFileName);
        }
        catch (QException &e)
        {
            QMessageBox::warning(nullptr, "Error", "There was a problem reloading the image");
        }

        if (savedStateExists(currFileName))
        {
            applicationPolygonState.remove(currFileName);
            applicationRectState.remove(currFileName);
            applicationTextState.remove(currFileName);
        }
    }
}

ImageEditor::CursorType ImageEditor::getCursorType() const { return cursorType; }

ImageEditor::AnnotationShapeType ImageEditor::getAnnotationShapeType() const { return annotationShape; }

QHash<QString, QList<QRectF>> ImageEditor::getApplicationRectState() const { return applicationRectState; }

QHash<QString, QList<QPolygonF>> ImageEditor::getApplicationPolygonState() const { return applicationPolygonState; }

QHash<QString, QList<QPair<QString, QPointF>>> ImageEditor::getApplicationTextState() const { return applicationTextState; }

void ImageEditor::forceReload() { loadAnnotations(); }

void ImageEditor::deleteSelectedItem()
{
    if (ImageEditor::selectedItems().size() > 0)
    {
        QGraphicsItem *selectedItem = ImageEditor::selectedItems().at(0);

        QGraphicsEllipseItem *elipseItem = qgraphicsitem_cast<QGraphicsEllipseItem *>(selectedItem);

        if (elipseItem)
        {
            clickEplipses.removeOne(elipseItem);
        }

        delete selectedItem;
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
        else if (textItem)
        {
            clipbordContent = ClipbordContent::Label;
            clipbordText = textItem->toPlainText();
            clipbordPoint = selectedItem->scenePos();
        }
        else if (polygonItem)
        {
            clipbordContent = ClipbordContent::Poly;
            clipbordPoint = selectedItem->scenePos();
            clipbordPolygon = polygonItem->polygon();
            clipbordPolygonItemPoint = polygonItem->sceneBoundingRect().topLeft();
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
        else if (clipbordContent == ClipbordContent::Label)
        {
            drawText(clipbordText, QPointF(x, y));
        }
        else if (clipbordContent == ClipbordContent::Poly)
        {
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
        else if (clipbordContent == ClipbordContent::Label)
        {
            drawText(clipbordText, QPointF(x, y));
        }
        else if (clipbordContent == ClipbordContent::Poly)
        {
            // Workaround to change screen pos to scene pos of polygon
            QPolygonF polygon = clipbordPolygon.translated(clipbordClickPoint - clipbordPolygonItemPoint);
            drawPolygon(polygon);
        }
    }
}

void ImageEditor::connectClickElipses()
{

    if (clickEplipses.size() <= 2)
    {
        QMessageBox::warning(nullptr, "Error", "You need to mark at least three points");
        return;
    }

    QPolygonF polygon;

    for (int i = 0; i < clickEplipses.size(); i++)
    {
        if (clickEplipses.size() - 1 == i)
        {
            polygon << clickEplipses[i]->rect().topLeft() << clickEplipses[0]->rect().topLeft();
        }
        else
        {
            polygon << clickEplipses[i]->rect().topLeft() << clickEplipses[i + 1]->rect().topLeft();
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

void ImageEditor::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (imageSet && event->button() == Qt::LeftButton)
    {
        origin = event->screenPos();
        originF = event->scenePos();

        if (cursorType == CursorType::Draw)
        {
            if (annotationShape == AnnotationShapeType::Points)
            {
                QGraphicsEllipseItem *ellipseItem = new QGraphicsEllipseItem(QRectF(originF.x() - 5, originF.y() - 5, 10, 10));
                ellipseItem->setBrush(Qt::blue);
                ellipseItem->setPen(Qt::NoPen);
                ellipseItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

                ImageEditor::addItem(ellipseItem);

                clickEplipses.append(ellipseItem);
            }
            else if (annotationShape == AnnotationShapeType::FreeHand)
            {
                clickPoints.append(originF);
            }
            else
            {
                // Creates a boundry indicater
                rubberBand->setGeometry(QRect(origin, QSize()));
                rubberBand->show();
            }
        }
        else if (cursorType == CursorType::Text && classLabel != "")
        {
            drawText(classLabel, originF);
        }
        else
        {
            QGraphicsScene::mousePressEvent(event);
        }

        ImageEditor::update();
    }
}

void ImageEditor::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (imageSet && (event->buttons() & Qt::LeftButton))
    {
        if (cursorType == CursorType::Draw)
        {
            drawing = true;

            if (annotationShape == ImageEditor::AnnotationShapeType::Rectangle)
            {
                emit drawingRectangle();

                lastPoint = event->screenPos();
                lastPointF = event->scenePos();

                // Dynamically adjusts border indicater
                rubberBand->setGeometry(QRect(origin, lastPoint).normalized());
            }
            else if (annotationShape == ImageEditor::AnnotationShapeType::FreeHand)
            {
                clickPoints.append(event->scenePos());

                QPen pen;
                pen.setBrush(Qt::blue);
                pen.setWidth(1);

                QLineF lineF(clickPoints[clickPoints.size() - 2], clickPoints[clickPoints.size() - 1]);
                QGraphicsLineItem *item = this->addLine(lineF, pen);

                clickLines.append(item);
            }
        }
        else if (cursorType == CursorType::Select)
        {
            QGraphicsScene::mouseMoveEvent(event);
        }

        ImageEditor::update();
    }
}

void ImageEditor::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (imageSet && event->button() == Qt::LeftButton)
    {
        if (cursorType == CursorType::Draw && drawing)
        {
            if (annotationShape == ImageEditor::AnnotationShapeType::Rectangle)
            {
                emit finishedDrawingRectangle();

                rubberBand->hide();

                drawRectangle(QRectF(originF, lastPointF).normalized());
            }
            else if (annotationShape == ImageEditor::AnnotationShapeType::FreeHand)
            {
                QPolygonF polygon;

                // Connects all points and connects last point to the first one
                for (int i = 0; i < clickPoints.size(); i++)
                {
                    if (clickPoints.size() - 1 == i)
                    {
                        polygon << clickPoints[i] << clickPoints[0];
                    }
                    else
                    {
                        polygon << clickPoints[i] << clickPoints[i + 1];
                    }
                }

                drawPolygon(polygon);

                // Clears line indicators and point list
                qDeleteAll(clickLines.begin(), clickLines.end());
                clickLines.clear();
                clickPoints.clear();
            }

            drawing = false;
        }
        else if (cursorType == CursorType::Select)
        {
            QGraphicsScene::mouseReleaseEvent(event);
        }

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

void ImageEditor::createActions()
{
    deleteAction = new QAction(tr("Delete"), this);
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(deleteSelectedItem()));

    copyAction = new QAction(tr("Copy"), this);
    connect(copyAction, SIGNAL(triggered()), this, SLOT(copySelectedItem()));

    pasteAction = new QAction(tr("Paste"), this);
    connect(pasteAction, SIGNAL(triggered()), this, SLOT(pasteSelectedItemInPlace()));
}

void ImageEditor::openImage(const QString fileName)
{
    const QImage image(fileName);
    const QImage smallImage = image.scaled(SCENE_WIDTH, SCENE_HEIGHT, Qt::KeepAspectRatio);

    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(smallImage));

    ImageEditor::addItem(item);
    ImageEditor::update();

    // Center Image
    ImageEditor::setSceneRect(0, 0, smallImage.width(), smallImage.height());
}

bool ImageEditor::savedStateExists(const QString fileName)
{
    QHash<QString, QList<QRectF>>::const_iterator valueIt = applicationRectState.find(fileName);

    if (valueIt == applicationRectState.end())
        return false;

    return true;
}

void ImageEditor::drawPolygon(const QPolygonF newPolygon)
{
    QPen pen;
    pen.setBrush(Qt::blue);
    pen.setWidth(2);

    QGraphicsPolygonItem *polygon = ImageEditor::addPolygon(newPolygon, pen);
    polygon->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
}

void ImageEditor::drawRectangle(const QRectF newRectangle)
{
    QPen pen;
    pen.setBrush(Qt::blue);
    pen.setWidth(2);

    QGraphicsRectItem *rectangle = ImageEditor::addRect(newRectangle, pen);
    rectangle->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

    new CustomResizer(rectangle);
}

void ImageEditor::drawText(const QString newText, const QPointF newPoint)
{
    QFont font;
    font.setPixelSize(20);

    QGraphicsTextItem *text = ImageEditor::addText(newText, font);
    text->setPos(newPoint);
    text->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
}
