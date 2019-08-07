#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QPoint>
#include <QSize>
#include <QPixmap>
#include <QGraphicsItem>

#include "enemyway.h"

class Enemy : public QGraphicsItem
{
public:
    Enemy(EnemyWay _enemyWay, int _maxHP = 100, int _moveSpeed = 1,
          const QPixmap &_img = QPixmap(":/utiliy/image/enemy.png"), QGraphicsItem *parent = nullptr);

    //void draw(QPainter *painter) const;
    //void move();
    //void getDamage(int damage);
    //void getRemoved();
    //void getAttacked(Tower *attacker);
    //void gotLostSight(Tower *attacker);
    //QPoint getpos() const;

protected:
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

protected slots:
    void advance(int phase);

protected:
    int             maxHp;
    int	            currentHp;
    qreal           moveSpeed;
    QPointF         pos;
    EnemyWay        enemyWay;

    const QPixmap   img;
};
#endif // ENEMY_H
