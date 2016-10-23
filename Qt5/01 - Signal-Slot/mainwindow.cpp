#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dispatcher.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            ui->progressBar, SLOT(setValue(int)));

    ui->horizontalSlider->setValue(0);
    ui->progressBar->setValue(0);

    dispatcher d;

    connect(&d, SIGNAL(valueChanged(int)), ui->horizontalSlider, SLOT(setValue(int)));

    d.setValue(33);

}

MainWindow::~MainWindow()
{
    delete ui;
}
