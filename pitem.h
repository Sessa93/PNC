#ifndef PITEM_H
#define PITEM_H

#include <QGraphicsItem>
#include <QList>

class Arc;
class GraphWidget;
class QGraphicsSceneMouseEvent;

class PItem : public QGraphicsItem
{
    public:
        PItem(GraphWidget *graphWidget, bool pt, char *lbl);
        QList<Arc *> arcs() const;

        enum { PType = UserType + 1 };
        int type() const { return PType; }

        QList<Arc *> arcList;
        QPointF newPos;
        GraphWidget *graph;
        bool advance();
        bool selected;
        void addArc(Arc *arc);
        bool PTYPE;
        QGraphicsTextItem *name;

    protected:
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
        QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    private:
        int px;
        int py;
};

#endif

