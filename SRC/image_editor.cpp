#include "image_editor.h"

#include <QDebug>

ImageEditor::ImageEditor() : imageSet(false), clipbord(false), cursorType("none"), classLabel(""), currFileName(""), clipbordText(""), rubberBand(new QRubberBand(QRubberBand::Rectangle, nullptr))
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

QString ImageEditor::getCursorType() { return cursorType; };

void ImageEditor::setImage(QString fileName)
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

        updateCursorType("draw");
    }
    catch (QException e)
    {
        QMessageBox::warning(nullptr, tr("Error"),
                             tr("Could not open image"));
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
    }
}

void ImageEditor::openImage(QString fileName)
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
        QList<QPair<QString, QPointF>> textItems;

        for (int i = 0; i < ImageEditor::items().count(); i++)
        {
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
        }

        applicationRectState[currFileName] = rectItems;
        applicationTextState[currFileName] = textItems;
    }
}

bool ImageEditor::savedStateExists(QString fileName)
{
    QHash<QString, QList<QRectF>>::const_iterator valueIt = applicationRectState.find(fileName);

    if (valueIt == applicationRectState.end())
    {
        return false;
    }
    return true;
}

void ImageEditor::updateCursorType(QString newCursorType)
{
    if (imageSet && cursorType != newCursorType)
    {
        cursorType = newCursorType;
        emit cursorTypeChanged();
    }
}

void ImageEditor::updateClassLabel(QString newClassLabel)
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

        if (cursorType == "draw")
        {
            rubberBand->setGeometry(QRect(origin, QSize()));
            rubberBand->show();
        }
        else if (cursorType == "addText" && classLabel != "")
        {
            drawText(classLabel, originF);
        }

        if (cursorType == "none")
            QGraphicsScene::mousePressEvent(event);

        ImageEditor::update();
    }
}

void ImageEditor::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (imageSet)
    {
        if (cursorType == "draw")
        {
            drawing = true;

            lastPoint = event->screenPos();
            lastPointF = event->scenePos();

            rubberBand->setGeometry(QRect(origin, lastPoint).normalized());
        }

        if (cursorType == "none")
            QGraphicsScene::mouseMoveEvent(event);

        ImageEditor::update();
    }
}

void ImageEditor::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (imageSet)
    {
        if (cursorType == "draw" && origin != lastPoint && drawing)
        {
            rubberBand->hide();

            drawRectangle(QRectF(originF, lastPointF));

            drawing = false;
        }

        if (cursorType == "none")
            QGraphicsScene::mouseReleaseEvent(event);

        ImageEditor::update();
    }
}

void ImageEditor::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    if (cursorType == "none" && imageSet)
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
    if (event->type() == QKeyEvent::KeyPress && cursorType == "none")
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
        delete ImageEditor::selectedItems().at(0);
    }
}

void ImageEditor::copySelectedItem()
{
    if (ImageEditor::selectedItems().size() > 0)
    {
        QGraphicsItem *selectedItem = ImageEditor::selectedItems().at(0);

        QGraphicsTextItem *textItem = qgraphicsitem_cast<QGraphicsTextItem *>(selectedItem);

        clipbord = true;

        if (textItem == nullptr)
        {
            const QRectF selectedReactangle = selectedItem->sceneBoundingRect();

            clipbordText = "";
            clipbordPoint = selectedReactangle.topLeft();
            clipbordHeight = selectedReactangle.height();
            clipbordWidth = selectedReactangle.width();
        }
        else
        {
            clipbordText = textItem->toPlainText();
            clipbordPoint = selectedItem->scenePos();
        }
    }
}

void ImageEditor::pasteSelectedItem()
{
    if (imageSet && clipbord)
    {
        const qreal x = clipbordPoint.x() + 4.0;
        const qreal y = clipbordPoint.y() - 8.0;

        if (clipbordText == "")
        {
            drawRectangle(QRectF(QPointF(x, y), QSizeF(clipbordWidth, clipbordHeight)));
        }
        else
        {
            drawText(clipbordText, QPointF(x, y));
        }

        updateCursorType("none");
    }
}

void ImageEditor::pasteSelectedItemInPlace()
{
    if (imageSet && clipbord)
    {
        const qreal x = clipbordClickPoint.x() + 4.0;
        const qreal y = clipbordClickPoint.y() - 8.0;

        if (clipbordText == "")
        {
            drawRectangle(QRectF(QPointF(x, y), QSizeF(clipbordWidth, clipbordHeight)));
        }
        else
        {
            drawText(clipbordText, QPointF(x, y));
        }
    }
}

void ImageEditor::drawRectangle(QRectF newRectangle)
{
    QPen pen;
    pen.setBrush(Qt::blue);
    pen.setWidth(2);

    QGraphicsRectItem *rectangle = ImageEditor::addRect(newRectangle, pen);
    rectangle->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

    CustomResizer *rectSizeGripItem = new CustomResizer(rectangle);
    resizerItems.append(rectSizeGripItem);
}

void ImageEditor::drawText(QString newText, QPointF newPoint)
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
            applicationRectState.remove(currFileName);
            applicationTextState.remove(currFileName);
        }
    }
}
