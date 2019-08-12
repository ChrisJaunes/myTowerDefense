#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QPoint>
#include <QList>
#include <QSize>
#include <QPixmap>
#include <QGraphicsItem>
#include <QGraphicsScene>

#include "enemyway.h"
class Attack;
class GameScene;
class Enemy : public QGraphicsItem
{
public:
    Enemy(GameScene *_gameSence, EnemyWay _enemyWay,
          int _maxHP = 100, int _moveSpeed = 1,
          const QPixmap &_img = QPixmap(":/utiliy/image/enemy.png"), QGraphicsItem *parent = nullptr);

    void addAttackSource(Attack *attack);
    void removeAttackSource(Attack *attack);

    QPointF getpos() const;
    void changeHP(int x);
    void goDead();

protected:
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

protected slots:
    void advance(int phase);

protected:
    GameScene       *gameSence;
    EnemyWay        enemyWay;
    QList<Attack*>  attackSourceList;

    int             maxHp;
    int	            currentHp;
    qreal           moveSpeed;
    QPointF         pos;

    const QPixmap   img;
};
#endif // ENEMY_H
