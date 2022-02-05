#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "movingprocessor.h"
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(MovingProcessor* mp, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_first_ellips_rotation_speed_spinbox_valueChanged(int arg1);

    void on_second_ellips_rotation_speed_spinbox_valueChanged(int arg1);

    void on_second_ellips_moving_speed_spinbox_valueChanged(int arg1);

    void on_third_ellips_rotation_speed_spinbox_valueChanged(int arg1);

    void on_third_ellips_moving_speed_spinbox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    MovingProcessor* mp;
};
#endif // MAINWINDOW_H
