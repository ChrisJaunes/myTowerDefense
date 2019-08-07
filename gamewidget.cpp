#include "gameWidget.h"
#include "ui_gamewidget.h"
#include "gamescene.h"

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget)
{
    ui->setupUi(this);

    ui->towerTypeList->setTowerType(1);

    gameScene = new GameScene;
    gameScene->setSceneRect(0,0,ui->gameView->width(),ui->gameView->height());
    gameScene->setSceneInfo(1);

    ui->gameView->setStyleSheet("padding: 0px; border: 0px;");
    ui->gameView->setScene(gameScene);

    gameScene->startGame();
}

GameWidget::~GameWidget()
{
    delete ui;
}
