 #include <QPainter>

 #include "arc.h"
 #include "pitem.h"

 #include <math.h>

 static const double Pi = 3.14159265358979323846264338327950288419717;
 static double TwoPi = 2.0 * Pi;

 Arc::Arc(PItem *sourceNode, PItem *destNode): arrowSize(7)
 {
     setAcceptedMouseButtons(0);
     source = sourceNode;
     dest = destNode;
     source->addArc(this);
     dest->addArc(this);
     adjust();
 }

 PItem *Arc::sourceNode() const
 {
     return source;
 }

 PItem *Arc::destNode() const
 {
     return dest;
 }

 void Arc::adjust()
 {
     if (!source || !dest)
         return;

     QLineF line(mapFromItem(source, 0, 0), mapFromItem(dest, 0, 0));
     qreal length = line.length();

     prepareGeometryChange();

     if (length > qreal(20.))
     {
         qreal factorS = 10;
         qreal factorD = 10;
         if(source->PTYPE) factorS = 2.5;
         if(dest->PTYPE) factorD = 2.5;
         QPointF edgeOffsetS((line.dx() * factorS) / length, (line.dy() * 10) / length);
         QPointF edgeOffsetD((line.dx() * factorD) / length, (line.dy() * 10) / length);
         if(source->rotation()) edgeOffsetS = QPointF((line.dx() * 10) / length, (line.dy() * factorS) / length);
         if(dest->rotation()) edgeOffsetD = QPointF((line.dx() * 10) / length, (line.dy() * factorD) / length);
         sourcePoint = line.p1() + edgeOffsetS;
         destPoint = line.p2() - edgeOffsetD;
     } else {
         sourcePoint = destPoint = line.p1();
     }
 }

 QRectF Arc::boundingRect() const
 {
     if (!source || !dest)
         return QRectF();

     qreal penWidth = 1;
     qreal extra = (penWidth + arrowSize) / 2.0;

     return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(),
                                       destPoint.y() - sourcePoint.y()))
         .normalized()
         .adjusted(-extra, -extra, extra, extra);
 }

 void Arc::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
 {
     if (!source || !dest)
         return;

     QLineF line(sourcePoint, destPoint);
     if (qFuzzyCompare(line.length(), qreal(0.)))
         return;

     // Draw the line itself
     painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
     painter->drawLine(line);

     // Draw the arrows
     double angle = ::acos(line.dx() / line.length());
     if (line.dy() >= 0)
         angle = TwoPi - angle;

     QPointF destArrowP1 = destPoint + QPointF(sin(angle - Pi / 3) * arrowSize,
                                               cos(angle - Pi / 3) * arrowSize);
     QPointF destArrowP2 = destPoint + QPointF(sin(angle - Pi + Pi / 3) * arrowSize,
                                               cos(angle - Pi + Pi / 3) * arrowSize);

     painter->setBrush(Qt::black);
     painter->drawPolygon(QPolygonF() << line.p2() << destArrowP1 << destArrowP2);
 } 
