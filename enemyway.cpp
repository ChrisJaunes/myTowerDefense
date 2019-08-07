#include "enemyway.h"
#include <QMessageBox>
#include <QDebug>
#include <QFile>

void EnemyWay::setEnemyWay(const QString &fileName)
{
    qDebug() <<"EnemyWay::setEnemyWay";
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        //QMessageBox::warning(this, "TowerDefense", "Cannot Open File");
        return;
    }
    QTextStream  in( &file );
    for(QString  x ,y;!in.atEnd();) {
        in>>x>>y;
        way.push_back(QPointF(x.toInt(), y.toInt()));
        qDebug() << x <<" " << y<<endl;
    }
    file.close();
}
QPointF* EnemyWay::getStartPos()
{
    it = way.begin();
    return &(*it);
}
QPointF* EnemyWay::getNextPos()
{
   if(++it == way.end())
       return nullptr;
   return &(*it);
}
