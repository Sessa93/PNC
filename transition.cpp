#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>

#include "arc.h"
#include "transition.h"
#include "graphwidget.h"

Transition::Transition(GraphWidget *graphWidget, char *lbl) : PItem(graphWidget,true,lbl)
{
    rot = 0;
}

QRectF Transition::boundingRect() const
{
    qreal adjust = 3;
    return QRectF(-3,-10.5,6.3,21.3);
}

QPainterPath Transition::shape() const
{
    QPainterPath path;
    path.addRect(-3,-10.5,6.3,21.3);
    return path;
}

void Transition::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    painter->fillRect(-2.5,-10,5,20,Qt::black);
    if(!this->selected) painter->setPen(QPen(Qt::black, 0));
    else painter->setPen(QPen(Qt::red, 1));
    painter->drawRect(-2.5, -10, 5, 20);
}

void Transition::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    rot += 90;
    if (rot == 180) rot = 0;
    this->setRotation(rot);
    this->update();
}
