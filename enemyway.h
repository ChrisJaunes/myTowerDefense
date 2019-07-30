#ifndef ENEMYWAY_H
#define ENEMYWAY_H

#include <QPoint>
#include <QPainter>

class EnemyWay
{
public:
    EnemyWay(QPoint pos);

    void draw(QPainter *painter) const;

    void setNextWay(EnemyWay *nextPoint);
    EnemyWay* getNextWay() const;
    const QPoint getPos() const;

private:
    const QPoint		pos;
    EnemyWay *			nextWay;
};
#endif // ENEMYWAY_H
