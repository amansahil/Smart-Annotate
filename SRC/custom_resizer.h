#ifndef CUSTOMRESIZER_H
#define CUSTOMRESIZER_H

#include <QBrush>
#include <QGraphicsItem>
#include <QGraphicsRectItem>

//! Class for the resizer box
class CustomResizer : public QGraphicsItem
{
private:

    //! Class for the resizer item
    class HandleItem : public QGraphicsRectItem
    {
    public:

        //! Custom type value used by QGraphicsRectItem to indentify the item type
        enum
        {
            Type = UserType + 1
        };

    protected:

        //! @link https://doc.qt.io/qt-5/qgraphicsitem.html#itemChange
        virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    private:

        //! Container for pointer to the parent resizer class
        CustomResizer *parent;

        /*!
         *  Returns QPointF based on position flag
         *  \param newPos
         */
        QPointF restrictPosition(const QPointF &newPos);

        //! int to represent position of resizer reative to related containers
        int positionFlags;

    public:
        HandleItem(int positionFlags, CustomResizer *parent);

        //! Returns `positionFlags`
        int getPositionFlags() const;

        //! Returns custom type value
        int type() const override;
    };

public:

    //! Used by QGraphicsRectItem to indentify the item type
    enum
    {
        Type = UserType
    };

    CustomResizer(QGraphicsItem *parent = 0);
    virtual ~CustomResizer();

    /*!
     * Returns `rect`
     */
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    /*!
     * Sets top left resizer item
     */
    void setTopLeft(const QPointF &pos);

    /*!
     * Sets top right resizer item
     */
    void setTopRight(const QPointF &pos);

    /*!
     * Sets bottom right resizer item
     */
    void setBottomRight(const QPointF &pos);

    /*!
     * Sets bottom left resizer item
     */
    void setBottomLeft(const QPointF &pos);

    /*!
     * Sets top resizer item
     */
    void setTop(qreal y);

    /*!
     * Sets right resizer item
     */
    void setRight(qreal x);

    /*!
     * Sets bottom resizer item
     */
    void setBottom(qreal y);

    /*!
     * Sets left resizer item
     */
    void setLeft(qreal x);

    //! Returns custom type value
    int type() const override;

private:

    //! Enum to represent position of resizer item
    enum Position
    {
        Top = 0x1,
        Bottom = 0x2,
        Left = 0x4,
        TopLeft = Top | Left,
        BottomLeft = Bottom | Left,
        Right = 0x8,
        TopRight = Top | Right,
        BottomRight = Bottom | Right
    };

    /*!
     *  Upadtes postions of necessary resizer items and updates size of QGraphicsItem
     */
    void doResize();

    /*!
     *  Upadtes postions of individual resizer items
     */
    void updateHandleItemPositions();

    //! List of individual resizer items
    QList<HandleItem *> handleItems;

    //! Bounding rectangle
    QRectF rect;
};

#endif // CUSTOMRESIZER_H
