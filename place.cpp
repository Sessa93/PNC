#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>
#include <QLabel>
#include <stdlib.h>

#include "arc.h"
#include "place.h"
#include "graphwidget.h" 

Place::Place(GraphWidget *graphWidget, char *lbl, int tks) : PItem(graphWidget,false,lbl)
{
    token = tks;
}

QRectF Place::boundingRect() const
{
    qreal adjust = 2;
    return QRectF( -10 - adjust, -10 - adjust, 23 + adjust, 23 + adjust);
}

QPainterPath Place::shape() const
{
    QPainterPath path;
    path.addEllipse(-10, -10, 20, 20);
    return path;
}

void Place::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    painter->setBrush(Qt::white);
    if(!this->selected) painter->setPen(QPen(Qt::black, 0));
    else painter->setPen(QPen(Qt::red, 2));
    painter->drawEllipse(-10, -10, 20, 20);
    painter->setPen(Qt::NoPen);
    //TOKENS DRAWING
    painter->setBrush(Qt::black);
    painter->setPen(QPen(Qt::white));
    QString T;
    T.setNum(token);
    switch(token)
    {
        case 1:
            painter->drawEllipse(-3,-3,6,6);
            break;
        case 2:
            painter->drawEllipse(-7,-3,6,6);
            painter->drawEllipse(1,-3,6,6);
            break;
        case 3:
            painter->drawEllipse(-7, 0, 6, 6);
            painter->drawEllipse(1, 0, 6, 6);
            painter->drawEllipse(-3,-6,6,6);
            break;
        default:
            if(token != 0)
            {
                painter->drawEllipse(-8,-8,16,16);
                painter->setFont(QFont("Verdana",7));
                if(token >= 10)
                {
                    painter->drawText(-6,3,T);
                    break;
                }
                painter->drawText(-3.1,3,T);
            }
    }
}

void Place::setToken(int tk)
{
    token = tk;
}
