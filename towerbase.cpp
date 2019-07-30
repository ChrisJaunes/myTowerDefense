#include "towerbase.h"

TowerBase::TowerBase(QPoint _pos, const QPixmap &_img)
    : pos(_pos), img(_img), tower(nullptr)
{
}

void TowerBase::draw(QPainter *painter) const
{
    painter->drawPixmap(pos.x(), pos.y(), img);
}

bool TowerBase::checkPoint(const QPoint &_pos) const
{
    bool isXInHere = pos.x() < _pos.x() && _pos.x() < (pos.x() + 44);
    bool isYInHere = pos.y() < _pos.y() && _pos.y() < (pos.y() + 44);
    return isXInHere && isYInHere;
}

bool TowerBase::hasTower() const
{
    return tower != nullptr;
}

Tower* TowerBase::getTower() const
{
    return tower;
}

void TowerBase::setTower(int towerType)
{
    switch (towerType) {
    case 0 : tower = new Tower(1, 2 , 3, pos); break;
    case 1 : tower = new Tower(1, 2 , 3, pos); break;
    }
}

void TowerBase::getInfo(QWidget *InfoWidget)
{
    QPushButton *towerA = new QPushButton("A");
    QPushButton *towerB = new QPushButton("B");
    QPushButton *towerC = new QPushButton("C");

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(towerA);
    layout->addWidget(towerB);
    layout->addWidget(towerC);

    InfoWidget->setLayout(layout);

    QButtonGroup *btnG = new QButtonGroup();
    btnG->addButton(towerA, 0);
    btnG->addButton(towerB, 1);
    btnG->addButton(towerC, 2);
    connect(btnG, SIGNAL(buttonClicked(int)), this, SLOT(setTower(int)));
}
/*const QPoint TowerPosition::centerPos() const
{
    QPoint offsetPoint(ms_fixedSize.width() / 2, ms_fixedSize.height() / 2);
    return m_pos + offsetPoint;
}




*/
