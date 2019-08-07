#include "towertypelist.h"

#include <QMouseEvent>
#include <QListWidgetItem>
#include <QDrag>
#include <QApplication>
#include <QMimeData>
#include <QPainter>
#include <QPixmap>
#include <QDebug>

TowerTypeList::TowerTypeList(QWidget *parent):
    QListWidget(parent)
{

}

TowerTypeList::~TowerTypeList(){

}

void TowerTypeList::setTowerType(int round) {
    round = 0;
    QStringList strList;
    strList.append("矩形");
    strList.append("tower1");
    strList.append("tower2");
    insertItems(0,strList);
    setDragEnabled(true);
}
void TowerTypeList::mouseMoveEvent(QMouseEvent *event) {
    qDebug()<<"TowerTypeList::mouseMoveEvent "<<endl;

    if(!(event->buttons() & Qt::LeftButton))
        return;
    if((event->pos()-dragPosition).manhattanLength() < QApplication::startDragDistance())
        return;
    if(!dragItem)
        return;

    QDrag *drag=new QDrag(this);
    QMimeData *mimeData=new QMimeData;
    mimeData->setText(currentItem()->text());
    drag->setMimeData(mimeData);

    QPixmap dragImg(":/utiliy/image/"+mimeData->text() + ".png");
    drag->setPixmap(dragImg);

    drag->exec(Qt::CopyAction|Qt::MoveAction);
}

void TowerTypeList::mousePressEvent(QMouseEvent *event) {
    qDebug()<<"TowerTypeList::mousePressEvent"<<endl;
    dragPosition = event->pos();
    dragItem     = this->itemAt(event->pos());

    //保持父类继承下来的按键行为
    QListWidget::mousePressEvent(event);
}
