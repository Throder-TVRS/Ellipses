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
        double angle;           // Текущий угол относительно оси ОХ
        QRect rect;             // Прямоугольник, задающий эллипс
        Ellips *parent;         // Указатель на родительский эллипс
        double moving_speed;    // Скорость передвижения по родительскому эллипсу
    };

public:
    MovingProcessor();
    void update(float deltaSeconds);
    void redraw(QPainter& painter);

    std::vector<Ellips> ellipses;
};

#endif // MOVINGPROCESSOR_H
