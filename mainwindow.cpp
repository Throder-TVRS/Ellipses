#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(MovingProcessor* mp, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mp(mp)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_first_ellips_rotation_speed_spinbox_valueChanged(int arg)
{
    mp->ellipses[0].rotating_speed = 3.1415 / 20.0 * arg;
}

void MainWindow::on_second_ellips_rotation_speed_spinbox_valueChanged(int arg)
{
    mp->ellipses[1].rotating_speed = 3.1415 / 20.0 * arg;
}

void MainWindow::on_second_ellips_moving_speed_spinbox_valueChanged(int arg)
{
    mp->ellipses[1].moving_speed = 3.1415 / 20.0 * arg;
}

void MainWindow::on_third_ellips_rotation_speed_spinbox_valueChanged(int arg)
{
    mp->ellipses[2].rotating_speed = 3.1415 / 20.0 * arg;
}

void MainWindow::on_third_ellips_moving_speed_spinbox_valueChanged(int arg)
{
    mp->ellipses[2].moving_speed = 3.1415 / 20.0 * arg;
}
