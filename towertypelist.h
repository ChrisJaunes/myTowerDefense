#ifndef TOWERTYPELIST_H
#define TOWERTYPELIST_H

#include <QWidget>
#include <QListWidget>

namespace Ui {
class TowerTypeList;
}

class TowerTypeList : public QListWidget
{
    Q_OBJECT

public:
    explicit TowerTypeList(QWidget *parent = nullptr);
    ~TowerTypeList();
    void setTowerType(int round);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    QPoint            dragPosition; // 拖放起点
    QListWidgetItem   *dragItem;    // 被拖放的item
};

#endif // TOWERTYPELIST_H
