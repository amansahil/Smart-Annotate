#include "customresizer.h"

#include <QBrush>

CustomResizer::HandleItem::HandleItem(int positionFlags, CustomResizer *parent)
    : QGraphicsRectItem(-4, -4, 8, 8, parent),
      positionFlags_(positionFlags),
      parent_(parent)
{
    setBrush(QBrush(Qt::lightGray));
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
}

int CustomResizer::HandleItem::positionFlags() const { return positionFlags_; }

QVariant CustomResizer::HandleItem::itemChange(GraphicsItemChange change,
                                               const QVariant &value)
{
    QVariant retVal = value;

    if (change == ItemPositionChange)
    {
        retVal = restrictPosition(value.toPointF());
    }
    else if (change == ItemPositionHasChanged)
    {
        QPointF pos = value.toPointF();

        switch (positionFlags_)
        {
        case TopLeft:
            parent_->setTopLeft(pos);
            break;
        case Top:
            parent_->setTop(pos.y());
            break;
        case TopRight:
            parent_->setTopRight(pos);
            break;
        case Right:
            parent_->setRight(pos.x());
            break;
        case BottomRight:
            parent_->setBottomRight(pos);
            break;
        case Bottom:
            parent_->setBottom(pos.y());
            break;
        case BottomLeft:
            parent_->setBottomLeft(pos);
            break;
        case Left:
            parent_->setLeft(pos.x());
            break;
        }
    }

    return retVal;
}

QPointF CustomResizer::HandleItem::restrictPosition(const QPointF &newPos)
{
    QPointF retVal = pos();

    if (positionFlags_ & Top || positionFlags_ & Bottom)
        retVal.setY(newPos.y());

    if (positionFlags_ & Left || positionFlags_ & Right)
        retVal.setX(newPos.x());

    if (positionFlags_ & Top && retVal.y() > parent_->rect_.bottom())
        retVal.setY(parent_->rect_.bottom());
    else if (positionFlags_ & Bottom && retVal.y() < parent_->rect_.top())
        retVal.setY(parent_->rect_.top());

    if (positionFlags_ & Left && retVal.x() > parent_->rect_.right())
        retVal.setX(parent_->rect_.right());
    else if (positionFlags_ & Right && retVal.x() < parent_->rect_.left())
        retVal.setX(parent_->rect_.left());

    return retVal;
}

CustomResizer::CustomResizer(QGraphicsItem *parent) : QGraphicsItem(parent)
{
    if (parentItem())
        rect_ = parentItem()->boundingRect();

    handleItems_.append(new HandleItem(TopLeft, this));
    handleItems_.append(new HandleItem(Top, this));
    handleItems_.append(new HandleItem(TopRight, this));
    handleItems_.append(new HandleItem(Right, this));
    handleItems_.append(new HandleItem(BottomRight, this));
    handleItems_.append(new HandleItem(Bottom, this));
    handleItems_.append(new HandleItem(BottomLeft, this));
    handleItems_.append(new HandleItem(Left, this));
    updateHandleItemPositions();
}

CustomResizer::~CustomResizer() {}

QRectF CustomResizer::boundingRect() const
{
    return rect_;
}

void CustomResizer::paint(QPainter *painter,
                          const QStyleOptionGraphicsItem *option,
                          QWidget *widget)
{
}

#define IMPL_SET_FN(TYPE, POS)           \
    void CustomResizer::set##POS(TYPE v) \
    {                                    \
        rect_.set##POS(v);               \
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
    QGraphicsRectItem *rectItem =
        dynamic_cast<QGraphicsRectItem *>(parentItem());

    if (rectItem)
    {
        rectItem->setRect(rect_);
    }

    updateHandleItemPositions();
}

void CustomResizer::updateHandleItemPositions()
{
    foreach (HandleItem *item, handleItems_)
    {
        item->setFlag(ItemSendsGeometryChanges, false);

        switch (item->positionFlags())
        {
        case TopLeft:
            item->setPos(rect_.topLeft());
            break;
        case Top:
            item->setPos(rect_.left() + rect_.width() / 2 - 1,
                         rect_.top());
            break;
        case TopRight:
            item->setPos(rect_.topRight());
            break;
        case Right:
            item->setPos(rect_.right(),
                         rect_.top() + rect_.height() / 2 - 1);
            break;
        case BottomRight:
            item->setPos(rect_.bottomRight());
            break;
        case Bottom:
            item->setPos(rect_.left() + rect_.width() / 2 - 1,
                         rect_.bottom());
            break;
        case BottomLeft:
            item->setPos(rect_.bottomLeft());
            break;
        case Left:
            item->setPos(rect_.left(),
                         rect_.top() + rect_.height() / 2 - 1);
            break;
        }

        item->setFlag(ItemSendsGeometryChanges, true);
    }
}
