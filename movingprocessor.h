#ifndef MOVINGPROCESSOR_H
#define MOVINGPROCESSOR_H
#include <vector>
#include <QRect>
#include <QtGui/QPainter>
#include <iostream>
#include <cmath>

class MovingProcessor
{
    struct Ellips {
        double rotating_speed;  // Скорость вращения
        double rot_angle;       // Угол поворота эллипса относительно оси ОХ
        QRect rect;             // Прямоугольник, задающий эллипс
        Ellips *parent;         // Указатель на родительский эллипс
        double moving_speed;    // Скорость передвижения по родительскому эллипсу
        double mov_angle;       // Угол поворота центра эллипса по родительскому эллипсу
    };

public:
    MovingProcessor();
    void update();
    void redraw(QPainter& painter);

    std::vector<Ellips> ellipses;
};

#endif // MOVINGPROCESSOR_H
