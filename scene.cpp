#include <QtGui>
#include <QGraphicsSceneMouseEvent>
#include "scene.h"


GraphicsScene::GraphicsScene(QObject *parent) : QGraphicsScene(parent)
{

}

void GraphicsScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    int gridInterval = 10; //interval to draw grid lines at
    painter->setWorldMatrixEnabled(true);

    qreal left = int(rect.left()) - (int(rect.left()) % gridInterval );
    qreal top = int(rect.top()) - (int(rect.top()) % gridInterval );

    QVarLengthArray<QLineF, 100> linesX;
    for (qreal x = left; x < rect.right(); x += gridInterval )
        linesX.append(QLineF(x, rect.top(), x, rect.bottom()));

    QVarLengthArray<QLineF, 100> linesY;
    for (qreal y = top; y < rect.bottom(); y += gridInterval )
            linesY.append(QLineF(rect.left(), y, rect.right(), y));

    painter->setPen(QPen(Qt::lightGray, .3));
    painter->drawLines(linesX.data(), linesX.size());
    painter->drawLines(linesY.data(), linesY.size());
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(graph->connectionMode && graph->dragging)
    {
        int x = ceil(event->scenePos().x() / 10) * 10;
        int y = ceil(event->scenePos().y() / 10) * 10;

        this->graph->tmpLine->show();
        this->graph->tmpLine->setLine(this->graph->selectedItem->pos().x()-1, this->graph->selectedItem->pos().y(),x,y-1);

    }
    update();
    QGraphicsScene::mouseMoveEvent(event);
}
