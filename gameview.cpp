#include "gameview.h"
#include "gamescene.h"
#include <QDragEnterEvent>
#include <QMimeData>
#include <QDebug>

GameView::GameView(QWidget *parent) :
    QGraphicsView(parent)
{
}

GameView::~GameView()
{
}


void GameView::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug()<<"GameView::dragEnterEvent"<<endl;
    if(event->mimeData()->hasFormat("text/plain")){
        event->acceptProposedAction();
    }
    QGraphicsView::dragEnterEvent(event);
}

void GameView::dropEvent(QDropEvent *event)
{
    qDebug()<<"GameView::dropEvent"<<endl;
    //if (event->mimeData()->hasFormat("text/plain"))
    //{

    //    QString text=event->mimeData()->text();
    //    GameScene *scene=(GameScene*) (this->scene());
    //    scene->createLine(mapToScene(event->pos()));

    //    event->acceptProposedAction();
    //}

    QGraphicsView::dropEvent(event);
}
