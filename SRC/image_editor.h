#ifndef IMAGEEDITOR_H
#define IMAGEEDITOR_H

#include <QWidget>
#include <QtWidgets>
#include <QRubberBand>
#include <QHash>

class ImageEditor : public QGraphicsScene
{
    Q_OBJECT

public:
    ImageEditor();

    void setImage(QString fileName);
    void updateCursorType(QString newCursorType);
    void updateClassLabel(QString newClassLabel);

    void createActions();
    void clearItems();

    QString getCursorType();

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

    QString cursorType;
    QString classLabel;
    QString currFileName;

    QPoint origin;
    QPoint lastPoint;

    QPointF originF;
    QPointF lastPointF;

    QString clipbordText;

    QPointF clipbordPoint;
    QPointF clipbordClickPoint;

    qreal clipbordHeight;
    qreal clipbordWidth;

    QAction *copyAction;
    QAction *pasteAction;
    QAction *deleteAction;

    QRubberBand *rubberBand;

    QHash<QString, QList<QRectF>>  applicationRectState;
    QHash<QString, QList<QPair<QString, QPointF>>>  applicationTextState;

    void drawRectangle(QRectF newRectangle);
    void drawText(QString newText, QPointF newPoint);

    void saveImageState();
    void openImage(QString fileName);

    bool savedStateExists(QString fileName);

signals:
    void cursorTypeChanged();
};

#endif // IMAGEEDITOR_H
