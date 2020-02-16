#ifndef IMAGEEDITOR_H
#define IMAGEEDITOR_H

#include <QHash>
#include <QRubberBand>
#include <QtWidgets>
#include <QWidget>

#include <custom_resizer.h>

//! Custom image editor component for annotating images and labelling image
class ImageEditor : public QGraphicsScene
{
    Q_OBJECT

public:
    ImageEditor();

    //! Cursor type enum for identifying the current state of the cursor
    enum CursorType
    {
        Draw,  /*!< Cursor for drawing shapes */
        Text,  /*!< Cursor for adding text */
        Select /*!< Cursor for moving, resizing, copying, pasting and deleting shapes and text */
    };

    //! Annotation shape enum for identifying the current state of the shape being drawn
    enum AnnotationShapeType
    {
        Rectangle, /*!< For drawing rectangles */
        FreeHand,  /*!< For drawing free hand */
        Points     /*!< For drawing with points */
    };

    /*!
     *  Sets image being viewed on the editor

        @param fileName Absolute path to an image
    */
    void setImage(const QString fileName);

    /*!
     *  Loads saved state annotations onto image if any exists
     */
    void loadAnnotations();

    /*!
     *  Saves information of the text and shapes on the image into relevant hash tables
    */
    void saveImageState();

    /*!
     *  Updates `cursorType`
     *  @param newCursorType
    */
    void updateCursorType(const CursorType newCursorType);

    /*!
     *  Updates `annotationShape`
     *  @param newCursorType
    */
    void updateAnnotationShapeType(const AnnotationShapeType newAnnotationShape);

    /*!
     *  Updates the text used when adding text on the image
     *  @param newClassLabel
    */
    void updateClassLabel(const QString newClassLabel);

    /*!
     *  Updates `applicationRectState`
     *  @param fileName
     *  @param rectItems
     */
    void updateApplicationRectState(const QString fileName, const QList<QRectF> rectItems);

    /*!
     *  Updates `applicationPolygonState`
     *  @param fileName
     *  @param polygonItems
     */
    void updateApplicationPolygonState(const QString fileName, const QList<QPolygonF> polygonItems);

    /*!
     *  Updates `applicationTextState`
     *  @param fileName
     *  @param textItems
     */
    void updateApplicationTextState(const QString fileName, const QList<QPair<QString, QPointF>> textItems);

    /*!
     *  Clears all items on the scene except the image
     */
    void clearItems();

    /*!
     *  Returns `cursorType`
     */
    CursorType getCursorType() const;

    /*!
     *  Returns `annotationShape`
     */
    AnnotationShapeType getAnnotationShapeType() const;

    /*!
     *  Returns `applicationRectState`
     */
    QHash<QString, QList<QRectF>> getApplicationRectState() const;

    /*!
     *  Returns `applicationPolygonState`
     */
    QHash<QString, QList<QPolygonF>> getApplicationPolygonState() const;

    /*!
     *  Returns `applicationTextState`
     */
    QHash<QString, QList<QPair<QString, QPointF>>> getApplicationTextState() const;

    /*!
     *  Force reloads curent image to load any annotations from the annotation file
     */
    void forceReload();

public slots:

    /*!
     *  Deletes selected Qgraphics item
     */
    void deleteSelectedItem();

    /*!
     *  Stores information of selected item in relevant containers
     */
    void copySelectedItem();

    /*!
     *  Creates QGraphicsItem based on information from relevant containers
     */
    void pasteSelectedItem();

    /*!
     *  Creates QGraphicsItem based on information from relevant containers and
     *  additonaly the mouse position
     */
    void pasteSelectedItemInPlace();

    /*!
     *  Creates a polygon of `clickPoints`
     */
    void connectClickElipses();

    /*!
     *  Delete all `clickElipses`
     */
    void deleteClickElipses();

protected:
    /*!
     *  @link https://doc.qt.io/qt-5/qgraphicsitem.html#mousePressEvent
    */
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    /*!
     *  @link https://doc.qt.io/qt-5/qgraphicsitem.html#mouseMoveEvent
    */
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    /*!
     *  @link https://doc.qt.io/qt-5/qgraphicsitem.html#mouseReleaseEvent
    */
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    /*!
     *  @link https://doc.qt.io/qt-5/qgraphicsitem.html#contextMenuEvent
    */
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

    /*!
     *  @link https://doc.qt.io/qt-5/qgraphicsitem.html#keyPressEvent
    */
    void keyPressEvent(QKeyEvent *event) override;

private:
    //! Clipbord content enum for for identifying the current content held by the clipbord
    enum ClipbordContent
    {
        Label, /*!< Clipbord contains a text item */
        Rect,  /*!< Clipbord contains a rectangle */
        Poly   /*!< Clipbord contains a polygon */
    };

    //! Boolean for whether or not an image is set for better performance with comparisson operators
    bool imageSet;

    //! Boolean for drawing state
    bool drawing;

    //! Boolean for  for whether clipobord containers are empty or not for better performance with comparisson operators
    bool clipbord;

    //! Container for the cursor state
    CursorType cursorType;

    //! Container for the state of shape being drawn
    AnnotationShapeType annotationShape;

    //! Container for the class state (Text that would be added)
    QString classLabel;

    //! Container for the file name
    QString currFileName;

    //! Point where mouse was pressed, used QRubberBand
    QPoint origin;

    //! Point where mouse was released, used QRubberBand
    QPoint lastPoint;

    //! Point where the mouse was pressed, used by shape being drawn
    QPointF originF;

    //! Point where the mouse was released, used by shape being drawn
    QPointF lastPointF;

    //! Container for the text copied by user
    QString clipbordText;

    //! Container for the position of item copied by user
    QPointF clipbordPoint;

    //! Container for position of the mouse when the context menu was created
    QPointF clipbordClickPoint;

    //! Container for height of the QGraphicsRectItem which was copied
    qreal clipbordHeight;

    //! Container for width of the QGraphicsRectItem which was copied
    qreal clipbordWidth;

    //! Container for the polygon of the QGraphicsPolygonItem which was copied
    QPolygonF clipbordPolygon;

    //! Container for the position of the QGraphicsPolygonItem which was copied
    QPointF clipbordPolygonItemPoint;

    //! Container to identify the type of item that has been copied
    ClipbordContent clipbordContent;

    QAction *copyAction;
    QAction *pasteAction;
    QAction *deleteAction;

    //! @link https://doc.qt.io/qt-5/qrubberband.html
    QRubberBand *rubberBand;

    //! Container to store points marked by the user to create a polygon
    QList<QPointF> clickPoints;

    //! Container to store line markers used when creating a polygon
    QList<QGraphicsLineItem *> clickLines;

    //! Container to store eplipse markers used when creating a polygon
    QList<QGraphicsEllipseItem *> clickEplipses;

    //! A container for the information on the polygons drawn on the image and the relevant image file path
    QHash<QString, QList<QPolygonF>> applicationPolygonState;

    //! A container for the information on the recatangles drawn on the image and the relevant image file path
    QHash<QString, QList<QRectF>> applicationRectState;

    //! A container for the information on the text boxes added on the image and the relevant image file path
    QHash<QString, QList<QPair<QString, QPointF>>> applicationTextState;

    /*!
     *  Creates copy, paste and delete actions which is attached to the context menu
     *  created when user right clicks on the image editor
    */
    void createActions();

    /*!
     *  Adds image on scene
     *  \param fileName
     */
    void openImage(const QString fileName);

    /*!
     *  Adds QGraphicsPolygonItem on scene
     *  \param QPolygonF @link https://doc.qt.io/qt-5/qpolygonf.html
     */
    void drawPolygon(const QPolygonF newPolygon);

    /*!
     *  Adds QGraphicsRectItem on scene
     *  \param newRectangle @link https://doc.qt.io/qt-5/qrectf.html
     */
    void drawRectangle(const QRectF newRectangle);

    /*!
     *  Adds text on scene
     *  \param newText
     *  \param newPoint
     */
    void drawText(const QString newText, const QPointF newPoint);

    /*!
     *  Checks if image has any existing annotation and labels
     *  \param fileName Absolute path to image
     */
    bool savedStateExists(const QString fileName);

signals:

    /*!
     *  Sends a signal to the labeller class when cursor type changes
     */
    void cursorTypeChanged();

    /*!
     *  Sends a signal to the labeller class when annotation shape changes
     */
    void annotationShapeChanged();

    /*!
     *  Sends a signal to the labeller class when a rectangle is being drawn
     */
    void drawingRectangle();

    /*!
     *  Sends a signal to the labeller class when a rectangle is finished being drawn
     */
    void finishedDrawingRectangle();
};

#endif // IMAGEEDITOR_H
