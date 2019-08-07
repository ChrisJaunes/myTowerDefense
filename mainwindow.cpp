#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i = 0; i < 5; i++) {
        QWidget *it = new QWidget();
        //gameWidge.push_back(new GameWidget(it, ui->info));
        ui->gameStackedWidget->addWidget(it);
        ui->roundComboBox->addItem(QString("Round" + QString::number(i + 1)));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_roundComboBox_currentIndexChanged(int index)
{
    ui->gameStackedWidget->setCurrentIndex(index);
}
