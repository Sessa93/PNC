#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>
#include <QLabel>

#include "arc.h"
#include "pitem.h"
#include "graphwidget.h"
#include "place.h"

#include "math.h"


PItem::PItem(GraphWidget *graphWidget, bool pt, char* lbl) : graph(graphWidget), PTYPE(pt)
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);
    name = new QGraphicsTextItem(lbl);
    name->setFont(QFont("Verdana",7));
    name->setFlag(ItemIsMovable);
    name->hide();
    graph->scene()->addItem(name);
}

void PItem::addArc(Arc *arc)
{
    arcList << arc;
    arc->adjust();
}

QList<Arc *> PItem::arcs() const
{
    return arcList;
}

bool PItem::advance()
{
    if (newPos == pos())
        return false;

    setPos(newPos);
    return true;
}

void PItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(graph->connectionMode && graph->dragging)
    {
        if(PItem *dest = dynamic_cast<PItem*>(this->graph->scene()->itemAt(event->scenePos(), this->graph->transform())))
            graph->scene()->addItem(new Arc(this,dest));
    }
    graph->dragging = false;
    graph->tmpLine->hide();
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

void PItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //switch(event->button())
    {
        if(event->button() == Qt::LeftButton)
        {
            PItem *plc;
            foreach (QGraphicsItem *item, this->graph->scene()->items())
            {
                if((plc = qgraphicsitem_cast<PItem *>(item)))
                {
                    plc->selected = false;
                    plc->update();
                }
            }
            this->selected = true;
            graph->selectedItem = this;
            graph->dragging = true;
         }
    }
    update();
    QGraphicsItem::mousePressEvent(event);
}

void PItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(!graph->connectionMode)
    {
        int x = floor(event->scenePos().x() / 10) * 10;
        int y = floor(event->scenePos().y() / 10) * 10;
        this->setPos(x, y);
    }
}

QVariant PItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        foreach (Arc *arc, arcList)
            arc->adjust();
            if(!name->isVisible())
            {
                name->setPos(this->scenePos().x()+8,this->scenePos().y()-20);
                name->show();
            }
            else
                name->setPos(this->scenePos().x() + (name->scenePos().x() - px), this->scenePos().y() + (name->scenePos().y() - py));
            px = this->scenePos().x();
            py = this->scenePos().y();
        break;
    case ItemRotationHasChanged:
        foreach (Arc *arc, arcList)
            arc->adjust();
        break;
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}

