#ifndef PLACE_H
#define PLACE_H

#include <QGraphicsItem>
#include <QList>
#include <pitem.h>

class PItem;
class GraphWidget;
class QGraphicsSceneMouseEvent; 

class Place : public PItem
{
	public:
        Place(GraphWidget *graphWidget, char *lbl, int tks);
		bool advance();
		QRectF boundingRect() const;
		QPainterPath shape() const;
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        void setToken(int tk);
    private:
        int token;
};

#endif
