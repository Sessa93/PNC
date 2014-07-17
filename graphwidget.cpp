 #include "graphwidget.h"
 #include "arc.h"
 #include "place.h"
 #include "transition.h"
 #include "scene.h"

 #include <QtGui>
 #include <math.h>

 GraphWidget::GraphWidget(QWidget *parent) : QGraphicsView(parent)
 {
     GraphicsScene *scene = new GraphicsScene(this);
     scene->setItemIndexMethod(QGraphicsScene::NoIndex);
     scene->setSceneRect(-200, -200, 400, 400);
     scene->graph = this;
     dragging = false;
     setScene(scene);
     setCacheMode(CacheBackground);
     setViewportUpdateMode(BoundingRectViewportUpdate);
     setRenderHint(QPainter::Antialiasing);
     setTransformationAnchor(AnchorUnderMouse);

     connectionMode = true;

     scale(qreal(1.5), qreal(1.5));
     setMinimumSize(400, 400);

     /*setWindowTitle(tr("PETRI"));

     Place *node1 = new Place(this,"P1",2);
     Place *node2 = new Place(this,"P2",1);
     Place *node3 = new Place(this,"P3",3);
     Place *node4 = new Place(this,"P4",1);
     Place *node5 = new Place(this,"P5",3);
     Place *node6 = new Place(this,"P6",1);
     Place *node7 = new Place(this,"P7",6);
     Place *node8 = new Place(this,"P8",2);
     Place *node9 = new Place(this,"P9",3);
     Place *node10 = new Place(this,"P10",10);

     node5->selected = true;
     this->selectedItem = node5;

     Transition *tr1 = new Transition(this,"T1");

     scene->addItem(tr1);
     scene->addItem(node1);
     scene->addItem(node2);
     scene->addItem(node3);
     scene->addItem(node4);
     scene->addItem(node5);
     scene->addItem(node6);
     scene->addItem(node7);
     scene->addItem(node8);
     scene->addItem(node9);
     scene->addItem(node10);

     scene->addItem(new Arc(tr1, node1));

     scene->addItem(new Arc(tr1, node2));
     scene->addItem(new Arc(node2, node3));
     scene->addItem(new Arc(node2, node5));
     scene->addItem(new Arc(node3, node6));
     scene->addItem(new Arc(node4, node1));
     scene->addItem(new Arc(node4, node5));
     scene->addItem(new Arc(node5, node6));
     scene->addItem(new Arc(node5, node8));
     scene->addItem(new Arc(node6, node9));
     scene->addItem(new Arc(node7, node4));
     scene->addItem(new Arc(node8, node7));
     scene->addItem(new Arc(node9, node8));

     node1->setPos(-95, -100);
     node2->setPos(5, -100);
     node3->setPos(105, -100);
     node4->setPos(-95, 0);
     node5->setPos(5, 0);
     node6->setPos(105, 0);
     node7->setPos(-95, 100);
     node8->setPos(5, 100);
     node9->setPos(105, 100);
     node10->setPos(155,120);
     tr1->setPos(-70,-150);
     //scene->addItem(new Arc(node9,node10));*/

     tmpLine = scene->addLine(0,0,0,0, QPen( "grey" ));
     tmpLine->hide();
 }

 void GraphWidget::keyPressEvent(QKeyEvent *event)
 {

 }


 void GraphWidget::wheelEvent(QWheelEvent *event)
 {
     scaleView(pow((double)2, -event->delta() / 240.0));
 }

 void GraphWidget::scaleView(qreal scaleFactor)
 {
     qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
     if (factor < 0.07 || factor > 100)
         return;

     scale(scaleFactor, scaleFactor);
 }

 void GraphWidget::shuffle()
 {
     foreach (QGraphicsItem *item, scene()->items()) {
         if (qgraphicsitem_cast<Place *>(item))
             item->setPos(-150 + qrand() % 300, -150 + qrand() % 300);
     }
 }

 void GraphWidget::zoomIn()
 {
     scaleView(qreal(1.2));
 }

 void GraphWidget::zoomOut()
 {
     scaleView(1 / qreal(1.2));
 }

 void GraphWidget::addPlace()
 {
     QString lbl,tmp;
     lbl = "P";
     tmp.setNum(placeList.length()+1);
     lbl.append(tmp);
     //Place *newPlace = new Place(this,lbl,0);

 }

