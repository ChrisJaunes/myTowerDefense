#include "enemyway.h"
#include <QPainter>
#include <QColor>

EnemyWay::EnemyWay(QPoint _pos)
    : pos(_pos),
      nextWay(nullptr)
{
}

void EnemyWay::draw(QPainter *painter) const
{
    painter->save();
    painter->setPen(Qt::green);
    painter->drawEllipse(pos, 6, 6);
    painter->drawEllipse(pos, 2, 2);

    if (nextWay)
        painter->drawLine(pos, nextWay->pos);
    painter->restore();
}

void EnemyWay::setNextWay(EnemyWay *_nextWay)
{
    nextWay = _nextWay;
}

EnemyWay* EnemyWay::getNextWay() const
{
    return nextWay;
}

const QPoint EnemyWay::getPos() const
{
    return pos;
}


