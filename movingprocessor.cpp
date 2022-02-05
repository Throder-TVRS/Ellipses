#include "movingprocessor.h"

MovingProcessor::MovingProcessor()
{
    ellipses.resize(3);
    ellipses[1].parent = &ellipses[0];
    ellipses[2].parent = &ellipses[1];
}

void MovingProcessor::update()
{
    for(auto& ellips : ellipses) {
        ellips.rot_angle += ellips.rotating_speed;

        if(ellips.parent == nullptr)
            continue;

        double a = ellips.parent->rect.width()  / 2,
               b = ellips.parent->rect.height() / 2;

        ellips.mov_angle += ellips.moving_speed * 0.02;
        double rho =  a * b / std::sqrt(b * b * cos(ellips.mov_angle) * cos (ellips.mov_angle) +
                                        a * a * sin(ellips.mov_angle) * sin(ellips.mov_angle));

        double x = ellips.parent->rect.center().x() + rho * cos(ellips.mov_angle) - ellips.rect.width() / 2;
        double y = ellips.parent->rect.center().y() + rho * sin(ellips.mov_angle) - ellips.rect.height() / 2;

        QSize size = ellips.rect.size();
        ellips.rect.setX(x);
        ellips.rect.setY(y);
        ellips.rect.setSize(size);
    }
}

void MovingProcessor::redraw(QPainter &painter)
{
    painter.setRenderHint(QPainter::Antialiasing);

    for(auto& ellips : ellipses) {
        QPoint center = ellips.rect.center();

        if(ellips.rot_angle) {
            painter.translate(center.x(), center.y());
            painter.rotate(ellips.rot_angle);
            painter.translate(-center.x(), -center.y());
        }

        painter.drawEllipse(ellips.rect);
    }
}
