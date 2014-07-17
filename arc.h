#ifndef ARC_H
#define ARC_H

#include <QGraphicsItem>

class PItem;

class Arc : public QGraphicsItem
{
    public:
        Arc(PItem *sourceNode, PItem *destNode);
        PItem *sourceNode() const;
        PItem *destNode() const;
        void adjust();
        enum { Type = UserType + 2 };
        int type() const { return Type; }
    protected:
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    private:
     PItem *source, *dest;
     QPointF sourcePoint;
     QPointF destPoint;
     qreal arrowSize;
};

#endif
 
