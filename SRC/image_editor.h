#ifndef IMAGEEDITOR_H
#define IMAGEEDITOR_H

#include <QWidget>
#include <QtWidgets>
#include <QRubberBand>
#include <vector>
#include <QObject>
#include<QGraphicsObject>

#include <sstream> //for std::stringstream
#include <string>  //for std::string


class ImageEditor : public QGraphicsScene
{
    Q_OBJECT

public:
    ImageEditor();

    void setImage(QString fileName);
    void updateCursorType(QString newCursorType);
    void updateClassLabel(QString newClassLabel);

    void setImageToFalse();
    void createActions();

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

    void drawRectangle(QRectF newRectangle);
    void drawText(QString newText, QPointF newPoint);

signals:
    void cursorTypeChanged();
};

#endif // IMAGEEDITOR_H
