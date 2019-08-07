#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>

class GameScene;

namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = nullptr);
    ~GameWidget();

private:
    Ui::GameWidget  *ui;
    GameScene       *gameScene;
};

//#include "towerbase.h"
//#include "tower.h"
//#include "enemyway.h"
//#include "enemy.h"
//#include "bullet.h"


//namespace Ui {
//class GameWidget;
//}
//class GameWidget : public QWidget
//{
//    Q_OBJECT
//
//public:
//    explicit GameWidget(QWidget *parent = nullptr, QWidget *infoWidget = nullptr);
//    ~GameWidget();

//protected:
//    void loadTowerBasePositions();
//    void paintEvent(QPaintEvent *);
//    void mousePressEvent(QMouseEvent *);

//private:
//    Ui::GameWidget          *ui;
//    QString                 mapBackGround;
//    QWidget                 *infoWidget;
//    QList<TowerBase *>	    towerBaseList;
    //QList<Tower *>			towersList;
    //QList<EnemyWay *>       enemyWayList;
    //QList<Enemy *>			enemyList;
    //QList<Bullet *>         bulletList;
    

    /*int						m_waves;
    int						m_playerHp;
    int						m_playrGold;
    int                     m_round;
    bool					m_gameEnded;
    bool					m_gameWin;
    AudioPlayer *			m_audioPlayer;
    QList<QVariant>			m_wavesInfo;

    QList<WayPoint *>		m_wayPointsList;

    QList<Bullet *>			m_bulletList;*/
    /*、void getHpDamage(int damage = 1);
    void removeEnemy(Enemy *enemy);
    void removedBullet(Bullet *bullet);
    void addBullet(Bullet *bullet);
    void awardGold(int gold);

    AudioPlayer* audioPlayer() const;
    QList<Enemy *> enemyList() const;


private slots:
    void updateMap();
    void gameStart();

private:
    void loadTowerPositions();
    void addWayPoints();
    bool loadWave();
    bool canBuyTower() const;
    void drawWave(QPainter *painter);
    void drawHP(QPainter *painter);
    void drawPlayerGold(QPainter *painter);
    void drawRound(QPainter *painter);
    void drawRoundChoose(QPainter * painter);
    void doGameOver();
    void preLoadWavesInfo();
*/

//};

#endif // GAMEWIDGET_H
