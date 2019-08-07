#include "mapblock.h"
#include <QDebug>
MapBlock::MapBlock(QPointF _pos, const QPixmap &_img, QGraphicsItem *parent)
    : QGraphicsItem(parent),
      pos(_pos),
      img(_img)
{

}

QRectF MapBlock::boundingRect() const
{
    return QRectF(0,0,0,0);
}
void MapBlock::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    qDebug() << "MapBlock::paint" << pos<< endl;
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->save();
    painter->drawPixmap(pos,img);
    painter->restore();
}
