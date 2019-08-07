#ifndef ENEMYWAY_H
#define ENEMYWAY_H

#include <QPoint>
#include <QPainter>

class EnemyWay
{
public:
    void setEnemyWay(const QString &fileName = QString(":/Round1/config/TowerBasePosition1.txt"));
    QPointF* getStartPos();
    QPointF* getNextPos();

private:
    QList<QPointF>::Iterator      it;
    QList<QPointF>                way;
};
#endif // ENEMYWAY_H
