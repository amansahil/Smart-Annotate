#ifndef SHAPE_H
#define SHAPE_H

#include <QtWidgets>

class Shape: public QGraphicsRectItem
{
public:
    Shape();

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
};

#endif // SHAPE_H
