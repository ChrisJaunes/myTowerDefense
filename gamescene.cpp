#include "gamescene.h"
#include "mapblock.h"
#include "enemy.h"
#include "tower.h"

#include <QDebug>
#include <QMimeData>
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPen>
#include <QTimer>

GameScene::GameScene(QWidget *parent):
    QGraphicsScene(parent)
{

}

void GameScene::drawBackground(QPainter *painter, const QRectF &rectF)
{
    qDebug()<<"drawBackground"<<endl;
    QPixmap pix(":/Round1/image/Bg" + round + ".png");
    painter->drawPixmap(0, 0, pix);
}
void GameScene::drawItems(QPainter *painter, int numItems, QGraphicsItem **items, const QStyleOptionGraphicsItem *options, QWidget *widget)
{
    for(int i = 0; i < numItems; i++)
        items[i]->paint(painter, options, widget);
}
QPointF GameScene::getMapBlockIdToPos(int id){
    //qDebug()<<id<<" "<<id / mapR * mapBlockH<<" "<<id % mapR * mapBlockW<<endl;
    return QPointF(id % mapC * mapBlockW, id / mapC * mapBlockH);
}
int GameScene::getMapBlockPosToId(QPointF pos){
    //qDebug()<<id<<" "<<id / mapR * mapBlockH<<" "<<id % mapR * mapBlockW<<endl;
    return 5;
}
void GameScene::setSceneInfo(int _round, int _mapR, int _mapC)
{
    qDebug()<<_round<<" "<<this->sceneRect()<<endl;
    round = QString::number(_round);
    mapR = _mapR;
    mapC = _mapC;
    qDebug()<<sceneRect().height()<<" "<<sceneRect().width()<<endl;
    mapBlockH = sceneRect().height() / mapR;
    mapBlockW = sceneRect().width()  / mapC;

    qDebug()<<round<<" "<<mapR<<" "<<mapC<<" "<<mapBlockH<<" "<<mapBlockW<<" "<<endl;
    towerBase.clear();
    for(int i = 0; i < mapR * mapC; i++) {
        MapBlock *it = new MapBlock(getMapBlockIdToPos(i));
        addItem(it);
    }

    gameTime = nullptr;
    //test;
    EnemyWay *way = new EnemyWay;
    way->setEnemyWay();
    Enemy *peo = new Enemy(*way);
    addItem(peo);
    update();
}
void GameScene::advance() {
    QGraphicsScene::advance();
    update();
}
void GameScene::startGame(int round) {

    delete gameTime;
    gameTime = new QTimer;
    QObject::connect(gameTime, SIGNAL(timeout()), this, SLOT(advance()));
    gameTime->start(100);
}
void GameScene::setTower(const QPointF &pointF, const QString text)
{
    qDebug()<<"GameScene::createRect"<<endl;
    int towerID = getMapBlockPosToId(pointF);
    QPointF pos(50, 50);//towerBase.at(towerID)->pos();
    Tower *tower = new Tower(1,1,1,pointF);

    this->addItem(tower);
    update();
}

void GameScene::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug()<<"GameScene::dragEnterEvent"<<endl;
    if(event->mimeData()->hasFormat("text/plain")){
        event->acceptProposedAction();
    }
}

void GameScene::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug()<<"GameScene::dropEvent"<<endl;
    if (event->mimeData()->hasFormat("text/plain"))
    {
        //QString text=event->mimeData()->text();

        setTower(event->scenePos(), event->mimeData()->text());

        event->acceptProposedAction();
    }
}

void GameScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug()<<"GameScene::dragMoveEvent"<<endl;
    event->accept();
}
