#ifndef CUSTOMRESIZER_H
#define CUSTOMRESIZER_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <map>
#include <string>
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
        HandleItem(int positionFlags, CustomResizer *parent);
        int positionFlags() const;

    protected:
        virtual QVariant itemChange(GraphicsItemChange change,
                                    const QVariant &value);

    private:
        QPointF restrictPosition(const QPointF &newPos);

        int positionFlags_;
        CustomResizer *parent_;
    };

public:
    CustomResizer(QGraphicsItem *parent = 0);
    virtual ~CustomResizer();
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget = 0);
    void setTopLeft(const QPointF &pos);
    void setTop(qreal y);
    void setTopRight(const QPointF &pos);
    void setRight(qreal x);
    void setBottomRight(const QPointF &pos);
    void setBottom(qreal y);
    void setBottomLeft(const QPointF &pos);
    void setLeft(qreal x);

private:
    void doResize();
    void updateHandleItemPositions();

    QList<HandleItem *> handleItems_;
    QRectF rect_;
};

#endif // CUSTOMRESIZER_H
