#include "image_editor.h"

ImageEditor::ImageEditor() : imageSet(false), cursorType("none"), classLabel(""), rubberBand(new QRubberBand(QRubberBand::Rectangle, nullptr)), clipbord(false)
{
    pen.setBrush(Qt::blue);
    pen.setWidth(2);

    createActions();
}

void ImageEditor::setImageToFalse() { imageSet = false; };

void ImageEditor::createActions()
{
    deleteAction = new QAction(tr("Delete"), this);
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(deleteSelectedItem()));

    copyAction = new QAction(tr("Copy"), this);
    connect(copyAction, SIGNAL(triggered()), this, SLOT(copySelectedItem()));

    pasteAction = new QAction(tr("Paste"), this);
    connect(pasteAction, SIGNAL(triggered()), this, SLOT(pasteSelectedItemInPlace()));
}

void ImageEditor::setImage(QString fileName)
{
    try
    {
        QImage image(fileName);

        QImage small = image.scaled(781, 651, Qt::KeepAspectRatio);

        QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(small));

        ImageEditor::clear();
        ImageEditor::update();

        ImageEditor::addItem(item);

        imageSet = true;
        cursorType = "draw";
    }
    catch (QException &e)
    {
        QMessageBox::about(nullptr, tr("Error"),
                           tr("Could not open image"));
    }
}

void ImageEditor::updateCursorType(QString newCursorType)
{
    if (imageSet && cursorType != newCursorType)
    {
        cursorType = newCursorType;
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
            QFont font;
            font.setPixelSize(20);

            QGraphicsTextItem *text = ImageEditor::addText(classLabel, font);
            text->setPos(originF);
            text->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
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

            QGraphicsRectItem *rectangle = ImageEditor::addRect(QRectF(originF, lastPointF), pen);

            rectangle->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

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
        QRectF selectedReactangle = ImageEditor::selectedItems().at(0)->sceneBoundingRect();
        clipbord = true;
        clipbordPoint = selectedReactangle.topLeft();
        clipbordHeight = selectedReactangle.height();
        clipbordWidth = selectedReactangle.width();
    }
}

void ImageEditor::pasteSelectedItem()
{
    if (clipbord)
    {
        qreal x = clipbordPoint.x() + 4.0;
        qreal y = clipbordPoint.y() - 8.0;

        QGraphicsRectItem *rectangle = ImageEditor::addRect(QRectF(QPointF(x, y), QSizeF(clipbordWidth, clipbordHeight)), pen);

        rectangle->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

        cursorType = "none";
    }
}

void ImageEditor::pasteSelectedItemInPlace()
{
    if (clipbord)
    {
        qreal x = clipbordClickPoint.x() + 4.0;
        qreal y = clipbordClickPoint.y() - 8.0;

        QGraphicsRectItem *rectangle = ImageEditor::addRect(QRectF(QPointF(x, y), QSizeF(clipbordWidth, clipbordHeight)), pen);

        rectangle->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
    }
}
