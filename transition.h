#ifndef TRANSITION_H
#define TRANSITION_H

#include <QGraphicsItem>
#include <QList>
#include <pitem.h>

class PItem;
class GraphWidget;
class QGraphicsSceneMouseEvent;

class Transition : public PItem
{
    public:
        Transition(GraphWidget *graphWidget, char *lbl);
        bool advance();
        QRectF boundingRect() const;
        QPainterPath shape() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    protected:
        void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    private:
        int rot;
};

#endif
