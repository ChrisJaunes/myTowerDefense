#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamewidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_roundComboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow         *ui;
    QList<GameWidget*>     gameWidge;

};

#endif // MAINWINDOW_H
