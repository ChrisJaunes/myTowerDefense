#include "tower.h"
#include "enemy.h"
#include "attack.h"
#include "gamescene.h"
#include "mainwindow.h"
//#include "utility.h"
#include <QPainter>
#include <QColor>
#include <QTimer>
#include <QVector2D>
#include <QtMath>
#include <QDebug>

//const QSize Tower::ms_fixedSize(42, 42);
Tower::Tower(GameScene *_gameScene,
             int _attackRange, int _attackDamage, int _attackSpeed,
             QPointF _pos, const QPixmap &_img)
    : gameScene(_gameScene)
    , attackRange(_attackRange)
    , attackDamage(_attackDamage)
    , attackSpeed(_attackSpeed)
    , pos(_pos)
    , img(_img)
{
    attacking = false;
    //connect(m_fireRateTimer, SIGNAL(timeout()), this, SLOT(shootWeapon()));
}

Tower::~Tower()
{
    //delete m_fireRateTimer;
    //m_fireRateTimer = NULL;
}

QRectF Tower::boundingRect() const
{
    return QRectF(0,0,0,0);
}

void Tower::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    qDebug() << "Tower::paint" << pos<<endl;
    //painter->save();
    painter->drawPixmap(pos,img);
    //painter->restore();
}
void Tower::advance(int phase) {
    qDebug()<<"Tower::advance"<<endl;
    foreach (Enemy *it, gameScene->enemyList) {
        qDebug()<<pos<<" "<<it->getpos()<<endl;
        OrdinaryBullet *ita = new OrdinaryBullet(pos, it);
        gameScene->addItem((QGraphicsItem *) ita);
    };
}
/*
void Tower::checkEnemyInRange()
{
    if (m_chooseEnemy)
    {
        // 这种情况下,需要旋转炮台对准敌人
        // 向量标准化
        QVector2D normalized(m_chooseEnemy->pos() - m_pos);
        normalized.normalize();
        m_rotationSprite = qRadiansToDegrees(qAtan2(normalized.y(), normalized.x())) - 90;

        // 如果敌人脱离攻击范围
        if (!collisionWithCircle(m_pos, m_attackRange, m_chooseEnemy->pos(), 1))
            lostSightOfEnemy();
    }
    else
    {
        // 遍历敌人,看是否有敌人在攻击范围内
        QList<Enemy *> enemyList = m_game->enemyList();
        foreach (Enemy *enemy, enemyList)
        {
            if (collisionWithCircle(m_pos, m_attackRange, enemy->pos(), 1))
            {
                chooseEnemyForAttack(enemy);
                break;
            }
        }
    }
}



void Tower::attackEnemy()
{
    m_fireRateTimer->start(m_fireRate);
}

void Tower::chooseEnemyForAttack(Enemy *enemy)
{
    m_chooseEnemy = enemy;
    attackEnemy();
    m_chooseEnemy->getAttacked(this);
}

void Tower::shootWeapon()
{
    Bullet *bullet = new Bullet(m_pos, m_chooseEnemy->pos(), m_damage, m_chooseEnemy, m_game);
    bullet->move();
    m_game->addBullet(bullet);
}

void Tower::targetKilled()
{
    if (m_chooseEnemy)
        m_chooseEnemy = NULL;

    m_fireRateTimer->stop();
    m_rotationSprite = 0.0;
}

void Tower::lostSightOfEnemy()
{
    m_chooseEnemy->gotLostSight(this);
    if (m_chooseEnemy)
        m_chooseEnemy = NULL;

    m_fireRateTimer->stop();
    m_rotationSprite = 0.0;
}
*/
