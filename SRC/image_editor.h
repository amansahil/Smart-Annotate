#ifndef IMAGEEDITOR_H
#define IMAGEEDITOR_H

#include <custom_resizer.h>

#include <QHash>
#include <QRubberBand>
#include <QtWidgets>
#include <QWidget>

class ImageEditor : public QGraphicsScene
{
    Q_OBJECT

public:
    ImageEditor();

    void setImage(const QString fileName);
    void updateCursorType(const QString newCursorType);
    void updateClassLabel(const QString newClassLabel);

    void createActions();
    void clearItems();
    void saveImageState();

    QHash<QString, QList<QRectF>> getApplicationRectState() const;

    QString getCursorType() const;

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

    QList<CustomResizer *> resizerItems;

    QHash<QString, QList<QRectF>> applicationRectState;
    QHash<QString, QList<QPair<QString, QPointF>>> applicationTextState;

    void drawRectangle(const QRectF newRectangle);
    void drawText(const QString newText, const QPointF newPoint);

    void openImage(const QString fileName);

    bool savedStateExists(const QString fileName);

signals:
    void cursorTypeChanged();
};

#endif // IMAGEEDITOR_H
