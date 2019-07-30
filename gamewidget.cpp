#include "gamewidget.h"
#include "ui_gamewidget.h"
#include <qtextstream.h>
#include <QMouseEvent>
#include <QMessageBox>
#include <QPainter>
#include <QPoint>
#include <QFile>
#include <QDebug>
GameWidget::GameWidget(QWidget *parent,  QWidget *_infoWidget) :
    QWidget(parent),
    infoWidget(_infoWidget),
    ui(new Ui::GameWidget)
{
    qDebug() <<"GameWidget::GameWidget";
    loadTowerBasePositions();
    ui->setupUi(this);

    //QWidget *tmp = new QWidget(infoWidget);
}

GameWidget::~GameWidget()
{
    delete ui;
}
void GameWidget::paintEvent(QPaintEvent *)
{
    qDebug() <<"GameWidget::paintEvent";
    QPixmap Pix(":/Round1/image/Bg1.png");
    QPainter pixPainter(&Pix);

    foreach (const TowerBase *towerBase, towerBaseList)
        towerBase->draw(&pixPainter);

    /*foreach (const Tower *tower, towersList)
        tower->draw(&pixPainter);

    foreach (const EnemyWay *enemyWay, enemyWayList)
        enemyWay->draw(&pixPainter);

    foreach (const Enemy *enemy, enemyList)
        enemy->draw(&pixPainter);

    foreach (const Bullet *bullet, bulletList)
        bullet->draw(&pixPainter);
        */
    QPainter painter(this);
    painter.drawPixmap(0, 0, Pix);
}

void GameWidget::loadTowerBasePositions()
{
    qDebug() <<"GameWidget::loadTowerBasePositions";
    QFile file(":/Round1/config/TowerBasePosition1.txt");

    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "TowerDefense", "Cannot Open File");
        return;
    }
    QTextStream  in( &file );

    for(QString  x ,y;!in.atEnd();){
        in>>x>>y;
        TowerBase *tmp = new TowerBase(QPoint(x.toInt(), y.toInt()));
        towerBaseList.push_back(tmp);
    }
    file.close();

}
void GameWidget::mousePressEvent(QMouseEvent *event)
{
    QPoint point = event->pos();
    foreach (TowerBase *towerBase, towerBaseList) {
        if (towerBase->checkPoint(point)) {
            if(towerBase->hasTower()) {
                qDebug() << "mousePressEvent A" <<endl;
            }else{
                qDebug() << "mousePressEvent B" <<endl;
                towerBase->getInfo(infoWidget);
            }

            //m_playrGold -= TowerCost;
            //it->setHasTower();

            //Tower *tower = new Tower(it->centerPos(), this);
            //m_towersList.push_back(tower);
            update();
            break;
        }

        //++it;
    }
}
