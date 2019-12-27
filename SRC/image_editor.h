#ifndef IMAGEEDITOR_H
#define IMAGEEDITOR_H

#include <QWidget>
#include <QtWidgets>
#include <QRubberBand>

class ImageEditor : public QGraphicsScene
{
    Q_OBJECT

public:
    ImageEditor();

    void setImage(QString fileName);
    void setImageToFalse();

    void updateCursorType(QString newCursorType);
    void updateClassLabel(QString newClassLabel);
    void createActions();

public slots:
    void deleteSelectedItem();
    void copySelectedItem();
    void pasteSelectedItem();
    void pasteSelectedItemInPlace();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    bool imageSet;
    bool drawing;
    bool clipbord;

    QPen pen;

    QString cursorType;
    QString classLabel;

    QPoint origin;
    QPoint lastPoint;

    QPointF originF;
    QPointF lastPointF;

    QPointF clipbordPoint;
    QPointF clipbordClickPoint;
    qreal clipbordHeight;
    qreal clipbordWidth;

    QAction *copyAction;
    QAction *pasteAction;
    QAction *deleteAction;

    QRubberBand *rubberBand;
};

#endif // IMAGEEDITOR_H
