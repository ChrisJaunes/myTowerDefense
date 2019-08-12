#include "attack.h"
#include "enemy.h"
#include <QDebug>
#include <QVector2D>

Attack::Attack(QPointF _pos, Enemy *_targetEnemy,
               const QPixmap &_img, QGraphicsItem *parent)
    : QGraphicsItem(parent)
    , pos(_pos)
    , enemy(_targetEnemy)
    , img(_img)
{
    enemy->addAttackSource(this);
}

QRectF Attack::boundingRect()const
{
    return QRectF();
}

void Attack::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    qDebug() << "Attack::paint" <<endl;
    painter->save();

    painter->drawPixmap(pos, img);

    painter->restore();
}

void Attack::hitTarget()
{
    enemy->removeAttackSource(this);
}


OrdinaryBullet::OrdinaryBullet(QPointF _pos, Enemy *_targetEnemy,
                               const int _HPDamage,
                               const QPixmap &_img, QGraphicsItem *parent)
    : Attack (_pos, _targetEnemy, _img, parent)
    , HPDamage(_HPDamage)
{

}

void OrdinaryBullet::advance(int phase)
{
    qDebug() << "OrdinaryBullet::advance" << phase<<endl;
    if(phase == 1) {
        QPointF targetPoint = enemy->getpos();
        // 向量标准化
        qreal movementSpeed = 10;
        QVector2D normalized(targetPoint - pos);
        normalized.normalize();
        pos = pos + normalized.toPoint() * movementSpeed;
        if(pos == enemy->getpos()) hitTarget();
        qDebug() << pos<< endl;
    }
}
void OrdinaryBullet::hitTarget()
{
    Attack::hitTarget();
    enemy->changeHP(HPDamage);
}
