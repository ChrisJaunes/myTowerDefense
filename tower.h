#ifndef TOWER_H
#define TOWER_H

#include <QObject>

#include <QPoint>
#include <QSize>
#include <QPixmap>
#include <QObject>

class QPainter;
class Enemy;
class MainWindow;
class QTimer;

class Tower : QObject
{
    Q_OBJECT
public:
    Tower(int _attackRange, int _attackDamage, int _attackInterval,
          QPoint pos, const QPixmap &sprite = QPixmap(":/image/tower.png"));
    ~Tower();

    void draw(QPainter *painter) const;
	/*void checkEnemyInRange();
	void targetKilled();
	void attackEnemy();
	void chooseEnemyForAttack(Enemy *enemy);
	void removeBullet();
	void damageEnemy();
	void lostSightOfEnemy();*/

private slots:
	//void shootWeapon();

private:
    bool            attacking;

    int             attackRange;
    int             attackDamage;
    int             attackInterval;
    const QPoint	pos;
    const QPixmap	img;
    //qreal			m_rotationSprite;

    //Enemy *         enemy;
    //MainWindow *	m_game;
    //QTimer *		m_fireRateTimer;
};

#endif // TOWER_H
