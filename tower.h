#ifndef TOWER_H
#define TOWER_H

#include <QObject>

#include <QPoint>
#include <QSize>
#include <QPixmap>
#include <QObject>
#include <QGraphicsItem>

class QPainter;
class Enemy;
class MainWindow;
class QTimer;

class Tower : public QGraphicsItem
{
public:
    Tower(int _attackRange, int _attackDamage, int _attackSpeed,
          QPointF pos, const QPixmap &sprite = QPixmap(":/utiliy/image/tower2.png"));
    ~Tower();

	/*void checkEnemyInRange();
	void targetKilled();
	void attackEnemy();
	void chooseEnemyForAttack(Enemy *enemy);
	void removeBullet();
	void damageEnemy();
	void lostSightOfEnemy();*/

protected:
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

protected slots:
    void advance(int phase);

private slots:
	//void shootWeapon();

private:
    bool            attacking;

    int             attackRange;
    int             attackDamage;
    int             attackSpeed;
    const QPointF   pos;
    const QPixmap	img;
    //qreal			m_rotationSprite;

    //Enemy *         enemy;
    //MainWindow *	m_game;
    //QTimer *		m_fireRateTimer;
};

#endif // TOWER_H
