#ifndef IMAGEEDITOR_H
#define IMAGEEDITOR_H

#include <QWidget>
#include <QtWidgets>
#include <QRubberBand>

class ImageEditor: public QGraphicsScene
{
    Q_OBJECT

public:
    ImageEditor();

    void setImage(QString fileName);
    void updateCursorType(QString newCursorType);
    void updateClassLabel(QString newClassLabel);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*event) override;

private:
    bool imageSet;
    bool drawing;

    QString cursorType;
    QString classLabel;

    QPoint origin;
    QPoint lastPoint;

    QPointF originF;
    QPointF lastPointF;

    QRubberBand *rubberBand;
};

#endif // IMAGEEDITOR_H
