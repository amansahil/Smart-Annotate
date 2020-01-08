#ifndef CUSTOMRESIZER_H
#define CUSTOMRESIZER_H

#include <QBrush>
#include <QGraphicsItem>
#include <QGraphicsRectItem>

class CustomResizer : public QGraphicsItem
{
private:
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

    class HandleItem : public QGraphicsRectItem
    {
    public:
        enum
        {
            Type = UserType + 1
        };

    protected:
        virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    private:
        CustomResizer *parent;

        QPointF restrictPosition(const QPointF &newPos);

        int positionFlags;

    public:
        HandleItem(int positionFlags, CustomResizer *parent);

        int getPositionFlags() const;
        int type() const override;
    };

public:
    enum
    {
        Type = UserType
    };

    CustomResizer(QGraphicsItem *parent = 0);
    virtual ~CustomResizer();

    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    void setTopLeft(const QPointF &pos);
    void setTopRight(const QPointF &pos);
    void setBottomRight(const QPointF &pos);
    void setBottomLeft(const QPointF &pos);

    void setTop(qreal y);
    void setRight(qreal x);
    void setBottom(qreal y);
    void setLeft(qreal x);

    int type() const override;

private:
    void doResize();
    void updateHandleItemPositions();

    QList<HandleItem *> handleItems;
    QRectF rect;
};

#endif // CUSTOMRESIZER_H
