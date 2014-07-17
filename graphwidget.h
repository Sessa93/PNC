#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>
#include "pitem.h"
#include "place.h"
#include "transition.h"

class GraphWidget : public QGraphicsView
{
    Q_OBJECT

    public:
        GraphWidget(QWidget *parent = 0);
        void itemMoved();
        PItem *selectedItem;
        bool connectionMode;
        bool dragging;
        QGraphicsLineItem *tmpLine;
        QString name;
        void setConnection();
        void addPlace();
        void addTransition();
        QList<Place*> placeList;
        QList<Transition*> tranList;
    public slots:
        void shuffle();
        void zoomIn();
        void zoomOut();
    protected:
        void keyPressEvent(QKeyEvent *event);
        void wheelEvent(QWheelEvent *event);
        void scaleView(qreal scaleFactor);      

};

#endif
 
