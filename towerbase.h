#ifndef TOWERBASE_H
#define TOWERBASE_H

#include <QPoint>
#include <QSize>
#include <QPixmap>
#include <QPainter>
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QButtonGroup>
#include <QGridLayout>

#include "tower.h"

class TowerBase : QObject
{
public:
    TowerBase(QPoint pos, const QPixmap &img = QPixmap(":/utiliy/image/towerBase1.png"));


    void draw(QPainter *painter) const;
    bool checkPoint(const QPoint &_pos) const;
    bool hasTower() const;
    Tower* getTower() const;

    void getInfo(QWidget *parent);

public slots:
    void setTower(int _towertype);

private:
    QPoint		pos;
    QPixmap		img;
    Tower		*tower;
};

#endif // TOWERBASE_H
