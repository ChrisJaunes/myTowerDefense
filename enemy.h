#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QPoint>
#include <QSize>
#include <QPixmap>

/*class WayPoint;
class QPainter;
class MainWindow;
class Tower;

class Enemy : public QObject
{
	Q_OBJECT
public:
    Enemy(WayPoint *startWayPoint, MainWindow *game, const QPixmap &sprite = QPixmap(":/image/enemy.png"));
	~Enemy();

	void draw(QPainter *painter) const;
    //void move();
    //void getDamage(int damage);
    //void getRemoved();
    //void getAttacked(Tower *attacker);
    //void gotLostSight(Tower *attacker);
    //QPoint getpos() const;

public slots:
	void doActivate();

    protected:
	bool			m_active;
    int				maxHp;
    int				currentHp;
    qreal			walkingSpeed;
    qreal			rotationSprite;

    QPoint			pos;
    Enemy*		    destinationWayPoint;
	MainWindow *	m_game;
    QList<Tower *>	attackedTowersList;

    const QPixmap	img;
    static const QSize ms_fixedSize;
};
*/
#endif // ENEMY_H
