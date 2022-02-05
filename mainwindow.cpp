#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(MovingProcessor* mp, QWidget *parent)
    : QMainWindow(parent)
    , mp(mp)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_first_ellips_rotation_speed_spinbox_valueChanged(int arg)
{
    mp->ellipses[0].rotating_speed = 1. / 8 * arg;
}

void MainWindow::on_second_ellips_rotation_speed_spinbox_valueChanged(int arg)
{
    mp->ellipses[1].rotating_speed = 1. / 8 * arg;
}

void MainWindow::on_second_ellips_moving_speed_spinbox_valueChanged(int arg)
{
    mp->ellipses[1].moving_speed = 1. / 8 * arg;
}

void MainWindow::on_third_ellips_rotation_speed_spinbox_valueChanged(int arg)
{
    mp->ellipses[2].rotating_speed = 1. / 8 * arg;
}

void MainWindow::on_third_ellips_moving_speed_spinbox_valueChanged(int arg)
{
    mp->ellipses[2].moving_speed = 1. / 8 * arg;
}
