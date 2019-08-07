#include "enemy.h"
#include "enemyway.h"
#include <QPainter>
#include <QColor>
#include <QDebug>
#include <QMatrix>
#include <QVector2D>
#include <QtMath>

//static const int Health_Bar_Width = 20;

//const QSize Enemy::ms_fixedSize(52, 52);

Enemy::Enemy(EnemyWay _enemyWay, int _maxHP, int _moveSpeed, const QPixmap &_img, QGraphicsItem *parent)
    : QGraphicsItem(parent)
    , maxHp(_maxHP)
    , moveSpeed(_moveSpeed)
    , enemyWay(_enemyWay)
    , img(_img)
{
    pos = *(enemyWay.getStartPos());
    qDebug()<<"Enemy::Enemy"<<pos<<endl;
}

QRectF Enemy::boundingRect()const
{
    return QRectF();
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    qDebug() << "Enemy::paint" <<endl;
    painter->save();
    //QPoint healthBarPoint = pos + QPoint(-Health_Bar_Width / 2 - 5, -ms_fixedSize.height() / 3);
    // 绘制血条
    //painter->setPen(Qt::NoPen);
    //painter->setBrush(Qt::red);
    //QRect healthBarBackRect(healthBarPoint, QSize(Health_Bar_Width, 2));
    //painter->drawRect(healthBarBackRect);

    //painter->setBrush(Qt::green);
    //QRect healthBarRect(healthBarPoint, QSize((double)m_currentHp / m_maxHp * Health_Bar_Width, 2));
    //painter->drawRect(healthBarRect);

    // 绘制偏转坐标,由中心+偏移=左上
    //static const QPoint offsetPoint(-ms_fixedSize.width() / 2, -ms_fixedSize.height() / 2);
    //painter->translate(m_pos);
    //painter->rotate(m_rotationSprite);
    // 绘制敌人
    painter->drawPixmap(pos, img);

    painter->restore();
}

void Enemy::advance(int phase)
{
    qDebug() << "Enemy::advance" << phase<<endl;
//    if (!m_active)
//        return;

  /*  if (collisionWithCircle(m_pos, 1, m_destinationWayPoint->pos(), 1))
    {
        // 敌人抵达了一个航点
        if (m_destinationWayPoint->nextWayPoint())
        {
            // 还有下一个航点
            m_pos = m_destinationWayPoint->pos();
            m_destinationWayPoint = m_destinationWayPoint->nextWayPoint();
        }
        else
        {
            // 表示进入基地
            m_game->getHpDamage();
            m_game->removedEnemy(this);
            return;
        }
    }
*/
    // 还在前往航点的路上
    // 目标航点的坐标
    QPointF targetPoint(500, 500);
    // 未来修改这个可以添加移动状态,加快,减慢,m_walkingSpeed是基准值

    // 向量标准化
    qreal movementSpeed = moveSpeed;
    QVector2D normalized(targetPoint - pos);
    normalized.normalize();
    pos = pos + normalized.toPoint() * movementSpeed;
    qDebug() << pos<< endl;
    // 确定敌人选择方向
    // 默认图片向左,需要修正180度转右
    //m_rotationSprite = qRadiansToDegrees(qAtan2(normalized.y(), normalized.x())) + 180;
}
/*
Enemy::Enemy(WayPoint *startWayPoint, MainWindow *game, const QPixmap &sprite)
    : QObject(0)
    , m_active(false)
    , m_maxHp(40)
    , m_currentHp(40)
    , m_walkingSpeed(1.0)
    , m_rotationSprite(0.0)
    , m_pos(startWayPoint->pos())
    , m_destinationWayPoint(startWayPoint->nextWayPoint())
    , m_game(game)
    , m_sprite(sprite)
{
}
/*
Enemy::~Enemy()
{
    m_attackedTowersList.clear();
    m_destinationWayPoint = NULL;
    m_game = NULL;
}

void Enemy::doActivate()
{
    m_active = true;
}





void Enemy::getRemoved()
{
    if (m_attackedTowersList.empty())
        return;

    foreach (Tower *attacker, m_attackedTowersList)
        attacker->targetKilled();
    // 通知game,此敌人已经阵亡
    m_game->removedEnemy(this);
}

void Enemy::getDamage(int damage)
{
    m_game->audioPlayer()->playSound(LaserShootSound);
    m_currentHp -= damage;

    // 阵亡,需要移除
    if (m_currentHp <= 0)
    {
        m_game->audioPlayer()->playSound(EnemyDestorySound);
        m_game->awardGold(200);
        getRemoved();
    }
}

void Enemy::getAttacked(Tower *attacker)
{
    m_attackedTowersList.push_back(attacker);
}

// 表明敌人已经逃离了攻击范围
void Enemy::gotLostSight(Tower *attacker)
{
    m_attackedTowersList.removeOne(attacker);
}

QPoint Enemy::pos() const
{
    return m_pos;
}
*/
