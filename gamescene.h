#ifndef TOWERSCENE_H
#define TOWERSCENE_H

#include <QObject>
#include <QVector>
#include <QGraphicsView>

class MapBlock;
class Enemy;

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GameScene(QWidget *parent = nullptr);
    void setSceneInfo(int round, int _mapR = 6, int mapC = 9);

    int getMapBlockPosToId(QPointF pos);
    QPointF getMapBlockIdToPos(int id);
    void setTower(const QPointF &pointF, const QString text);
    void startGame(int round = 1);

    QVector<MapBlock *>  towerBase;
    QVector<Enemy *>     enemyList;

public slots:
    void advance();

protected:
    void drawBackground(QPainter *painter, const QRectF& rectF);
    void drawItems(QPainter *painter, int numItems, QGraphicsItem *items[], const QStyleOptionGraphicsItem options[], QWidget *widget = nullptr);

    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dropEvent(QGraphicsSceneDragDropEvent* event);
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event);



private:
    QString              round;
    int                  mapR;
    int                  mapC;
    qreal                mapBlockH;
    qreal                mapBlockW;

    QTimer               *gameTime;
};

#endif // TOWERSCENE_H
