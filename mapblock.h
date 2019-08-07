#ifndef MAPBLOCK_H
#define MAPBLOCK_H

#include <QPoint>
#include <QSize>
#include <QPixmap>
#include <QPainter>
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QButtonGroup>
#include <QGridLayout>
#include <QGraphicsItem>

#include "tower.h"

class MapBlock : public QGraphicsItem
{
public:
    MapBlock(QPointF _pos, const QPixmap &img = QPixmap(":/utiliy/image/towerBase1.png"), QGraphicsItem *parent = nullptr);

    //void draw(QPainter *painter) const;
    //bool hasTower() const;
    //Tower* getTower() const;

    //void getInfo(QWidget *parent);

public slots:
    //void setTower(int _towertype);

protected:
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

private:
    QPointF     pos;
    QPixmap		img;
    Tower		*tower;
};

#endif // MAPBLOCK_H
