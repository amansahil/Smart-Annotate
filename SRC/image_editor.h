#ifndef IMAGEEDITOR_H
#define IMAGEEDITOR_H

#include <custom_resizer.h>

#include <QHash>
#include <QRubberBand>
#include <QtWidgets>
#include <QWidget>

//! Custom image editor component for annotating images and labelling images

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
        Select /*!< Cursor for moving, copying, pasting and deleting shapes and text */
    };

    //! Annotation Shape enum for identifying the current state of shape being drawn
    enum AnnotationShapeType {
        Rectangle, /*!< For drawing rectangles */
        FreeHand, /*!< For drawing free hand */
        Points /*!< For drawing with points */
    };

    /*!
     *  Sets image being viewed on the editor

        @param fileName Absolute path to an image
    */
    void setImage(const QString fileName);

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
     *  Creates copy, paste and delete actions which is attached to the context menu
     *  created on right click on the image editor
    */
    void createActions();

    /*!
     *  Clears all items on the scene except the image
    */
    void clearItems();

    /*!
     *  Saves postions of the text and shape into relevant Hash Tables
    */
    void saveImageState();

    /*!
     *  Returns `applicationRectState`
    */
    QHash<QString, QList<QRectF>> getApplicationRectState() const;

    /*!
     *  Returns `cursorType`
    */
    CursorType getCursorType() const;

    /*!
     *  Returns `annotationShape`
    */
    AnnotationShapeType getAnnotationShapeType() const;

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
<<<<<<< HEAD

    //! Clipbord content enum for for identifying the current content held by the clipbord
    enum ClipbordContent
    {
        Label, /*!< Clipbord contains a text item */
        Rect, /*!< Clipbord contains a rectangle */
        Poly /*!< Clipbord contains a polygon */
    };

    //! Boolean for whether or not an image is set for better performance with comparisson operators
=======
    //! Boolean for whether or not  an image is set for better performance with comparisson operators
>>>>>>> 94ebe9b39cfaa255086c8a1b96c90d5c08101199
    bool imageSet;

    //! Boolean for drawing state
    bool drawing;

    //! Boolean for  for whether clipobord containers are empty or not for better performance with comparisson operators
    bool clipbord;

    //! Container for cursor state
    CursorType cursorType;

    //! Container for state of shape being drawn
    AnnotationShapeType annotationShape;

    //! Container for class state (Text that would be added)
    QString classLabel;

    //! Container for file name
    QString currFileName;

    //! Point where mouse pressed used QRubberBand
    QPoint origin;

    //! Point where mouse released used QRubberBand
    QPoint lastPoint;

    //! Point where mouse pressed used by rectangle being drawn
    QPointF originF;

    //! Point where mouse released used by rectangle being drawn
    QPointF lastPointF;

    //! Container for text copied by user
    QString clipbordText;

    //! Container for position of item copied by user
    QPointF clipbordPoint;

    //! Container for position of mouse when context menu was created
    QPointF clipbordClickPoint;

    //! Container for height of QGraphicsRectItem which was copied
    qreal clipbordHeight;

    //! Container for width of QGraphicsRectItem which was copied
    qreal clipbordWidth;

    //! Container for polygon of QGraphicsPolygonItem which was copied
    QPolygonF clipbordPolygon;

    //! Container for QGraphicsPolygonItem which was copied
    QPointF clipbordPolygonItemPoint;

    //! Container to identify what item has been copied
    ClipbordContent clipbordContent;

    QAction *copyAction;
    QAction *pasteAction;
    QAction *deleteAction;

    QRubberBand *rubberBand;

    //! Container to store points marked by user to create a polygon
    QList<QPointF> clickPoints;

    //! Container to store line markers used when creating a polygon
    QList<QGraphicsLineItem*> clickLines;

    //! Container to store eplipse markers used when creating a polygon
    QList<QGraphicsEllipseItem*> clickEplipses;

    //! A list of resize components associated with each shape
    QList<CustomResizer *> resizerItems;

    //! A container for information on polygons drawn on the image and information of the relevant image file
    QHash<QString, QList<QPolygonF>> applicationPolygonState;

    //! A container for information on recatangles drawn on the image and information of the relevant image file
    QHash<QString, QList<QRectF>> applicationRectState;

    //! A container for information on texts added on the image and information of the relevant image file
    QHash<QString, QList<QPair<QString, QPointF>>> applicationTextState;

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
     *  \param newText Text to be added
     *  \param newPoint Position of text to be added
     */
    void drawText(const QString newText, const QPointF newPoint);

    /*!
     *  Adds image on scene
     *  \param fileName
     */
    void openImage(const QString fileName);

    /*!
     *  Checks if image has any existing annotation and labels
     *  \param fileName Absolute path to image
     */
    bool savedStateExists(const QString fileName);

signals:

    /*!
     *  Sends a signal to labeller class when cursor type changes
     */
    void cursorTypeChanged();

    /*!
     *  Sends a signal to labeller class when annotation shape changes
     */
    void annotationShapeChanged();
};

#endif // IMAGEEDITOR_H
