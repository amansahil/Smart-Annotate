#include "custom_resizer.h"

CustomResizer::HandleItem::HandleItem(int positionFlags, CustomResizer *parent) : QGraphicsRectItem(-4, -4, 8, 8, parent), positionFlags(positionFlags), parent(parent)
{
    setBrush(QBrush(Qt::lightGray));
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
}

int CustomResizer::HandleItem::type() const { return Type; }

int CustomResizer::HandleItem::getPositionFlags() const { return positionFlags; }

QVariant CustomResizer::HandleItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
    QVariant retVal = value;

    if (change == ItemPositionChange)
    {
        retVal = restrictPosition(value.toPointF());
    }
    else if (change == ItemPositionHasChanged)
    {
        QPointF pos = value.toPointF();

        switch (positionFlags)
        {
        case TopLeft:
            parent->setTopLeft(pos);
            break;
        case Top:
            parent->setTop(pos.y());
            break;
        case TopRight:
            parent->setTopRight(pos);
            break;
        case Right:
            parent->setRight(pos.x());
            break;
        case BottomRight:
            parent->setBottomRight(pos);
            break;
        case Bottom:
            parent->setBottom(pos.y());
            break;
        case BottomLeft:
            parent->setBottomLeft(pos);
            break;
        case Left:
            parent->setLeft(pos.x());
            break;
        }
    }

    return retVal;
}

QPointF CustomResizer::HandleItem::restrictPosition(const QPointF &newPos)
{
    QPointF retVal = pos();

    if (positionFlags & Top || positionFlags & Bottom)
        retVal.setY(newPos.y());

    if (positionFlags & Left || positionFlags & Right)
        retVal.setX(newPos.x());

    if (positionFlags & Top && retVal.y() > parent->rect.bottom())
        retVal.setY(parent->rect.bottom());
    else if (positionFlags & Bottom && retVal.y() < parent->rect.top())
        retVal.setY(parent->rect.top());

    if (positionFlags & Left && retVal.x() > parent->rect.right())
        retVal.setX(parent->rect.right());
    else if (positionFlags & Right && retVal.x() < parent->rect.left())
        retVal.setX(parent->rect.left());

    return retVal;
}

CustomResizer::CustomResizer(QGraphicsItem *parent) : QGraphicsItem(parent)
{
    if (parentItem())
        rect = parentItem()->boundingRect();

    handleItems.append(new HandleItem(TopLeft, this));
    handleItems.append(new HandleItem(Top, this));
    handleItems.append(new HandleItem(TopRight, this));
    handleItems.append(new HandleItem(Right, this));
    handleItems.append(new HandleItem(BottomRight, this));
    handleItems.append(new HandleItem(Bottom, this));
    handleItems.append(new HandleItem(BottomLeft, this));
    handleItems.append(new HandleItem(Left, this));
    updateHandleItemPositions();
}

CustomResizer::~CustomResizer() {}

int CustomResizer::type() const { return Type; }

QRectF CustomResizer::boundingRect() const { return rect; }

void CustomResizer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}

#define IMPL_SET_FN(TYPE, POS)           \
    void CustomResizer::set##POS(TYPE v) \
    {                                    \
        rect.set##POS(v);                \
        doResize();                      \
    }

IMPL_SET_FN(qreal, Top)
IMPL_SET_FN(qreal, Right)
IMPL_SET_FN(qreal, Bottom)
IMPL_SET_FN(qreal, Left)
IMPL_SET_FN(const QPointF &, TopLeft)
IMPL_SET_FN(const QPointF &, TopRight)
IMPL_SET_FN(const QPointF &, BottomRight)
IMPL_SET_FN(const QPointF &, BottomLeft)

void CustomResizer::doResize()
{
    QGraphicsRectItem *rectItem = dynamic_cast<QGraphicsRectItem *>(parentItem());

    if (rectItem)
    {
        rectItem->setRect(rect);
    }

    updateHandleItemPositions();
}

void CustomResizer::updateHandleItemPositions()
{
    foreach (HandleItem *item, handleItems)
    {
        item->setFlag(ItemSendsGeometryChanges, false);

        switch (item->getPositionFlags())
        {
        case TopLeft:
            item->setPos(rect.topLeft());
            break;
        case Top:
            item->setPos(rect.left() + rect.width() / 2 - 1,
                         rect.top());
            break;
        case TopRight:
            item->setPos(rect.topRight());
            break;
        case Right:
            item->setPos(rect.right(),
                         rect.top() + rect.height() / 2 - 1);
            break;
        case BottomRight:
            item->setPos(rect.bottomRight());
            break;
        case Bottom:
            item->setPos(rect.left() + rect.width() / 2 - 1,
                         rect.bottom());
            break;
        case BottomLeft:
            item->setPos(rect.bottomLeft());
            break;
        case Left:
            item->setPos(rect.left(),
                         rect.top() + rect.height() / 2 - 1);
            break;
        }

        item->setFlag(ItemSendsGeometryChanges, true);
    }
}
