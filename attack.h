#ifndef ATTACK_H
#define ATTACK_H
#include <QPoint>
#include <QGraphicsItem>
class Enemy;

class Attack: public QGraphicsItem
{
public:
    Attack(QPointF _pos, Enemy *_targetEnemy,
           const QPixmap &img = QPixmap(":/utiliy/image/bullet.png"), QGraphicsItem *parent = nullptr);

protected:
    virtual QRectF boundingRect()const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

protected slots:
    virtual void hitTarget();

protected:
    QPointF       pos;
    Enemy         *enemy;
    const QPixmap img;
};

class OrdinaryBullet : public Attack
{
public:
    OrdinaryBullet(QPointF _pos, Enemy *_targetEnemy,
                   const int _HPDamage = 100,
                   const QPixmap &_img = QPixmap(":/utiliy/image/bullet.png"), QGraphicsItem *parent = nullptr);

protected slots:
    virtual void advance(int phase);
    virtual void hitTarget();

protected:
    const int     HPDamage;
};

#endif // ATTACK_H
