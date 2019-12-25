#include "image_editor.h"
#include<QDebug>

ImageEditor::ImageEditor() : imageSet(false), cursorType("none")
{
}

void ImageEditor::setImage(QString fileName) {
    QImage image(fileName);

    QImage small = image.scaled(781, 651, Qt::KeepAspectRatio);

    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(small));


    ImageEditor::clear();
    ImageEditor::update();

    ImageEditor::addItem(item);

    imageSet = true;
    cursorType = "draw";
}

void ImageEditor::updateCursorType(QString newCursorType) {
    try {
        if(imageSet && cursorType != newCursorType) {
            cursorType = newCursorType;
        }
    } catch (QException e) {
    }
}

void ImageEditor::updateClassLabel(QString newClassLabel) {
    if(classLabel != newClassLabel) {
        classLabel = newClassLabel;
    }
}

void ImageEditor::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    origin = event->screenPos();
    originF = event->scenePos();

    if(cursorType == "draw") {
        rubberBand = new QRubberBand(QRubberBand::Rectangle, nullptr);
        rubberBand->setGeometry(QRect(origin, QSize()));
        rubberBand->show();

        ImageEditor::update();
    } else if(cursorType == "addText") {
        QFont font;
        font.setPixelSize(20);

        QGraphicsTextItem *text = ImageEditor::addText(classLabel, font);
        text->setPos(originF);
        text->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
        ImageEditor::update();
    }
}

void ImageEditor::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if(cursorType == "draw") {
        drawing = true;

        lastPoint = event->screenPos();
        lastPointF= event->scenePos();

        rubberBand->setGeometry(QRect(origin, lastPoint).normalized());

        ImageEditor::update();
    }
}

void ImageEditor::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if(cursorType == "draw" && origin != lastPoint && drawing) {
        rubberBand->hide();

        QGraphicsRectItem *rectangle = ImageEditor::addRect(QRectF(originF, lastPointF));

        rectangle->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

        drawing = false;

        ImageEditor::update();
    }
}
