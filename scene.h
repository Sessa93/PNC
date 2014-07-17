#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include "graphwidget.h"

class QGraphicsSceneMouseEvent;

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT

    public:
        GraphicsScene( QObject *parent = 0);
        GraphWidget *graph;
    protected:
        void mouseMoveEvent (QGraphicsSceneMouseEvent *mouseEvent);
        void drawBackground(QPainter *painter, const QRectF &rect);
};

#endif
