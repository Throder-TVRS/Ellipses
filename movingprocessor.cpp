#include "movingprocessor.h"

MovingProcessor::MovingProcessor()
{
    ellipses.resize(3);
    ellipses[1].parent = &ellipses[0];
    ellipses[2].parent = &ellipses[1];
}

void MovingProcessor::update(float deltaSeconds)
{
    static double time = 0;
    time += deltaSeconds;
    for(auto& ellips : ellipses) {
        ellips.angle += ellips.rotating_speed;

        if(ellips.parent == nullptr)
            continue;

        double a = ellips.parent->rect.width() / 2, b = ellips.parent->rect.height() / 2;
        double phi = ellips.moving_speed * time;
        double rho =  a * b / std::sqrt(b * b * cos(phi) * cos (phi) + a * a * sin(phi) * sin(phi));
        double x = ellips.parent->rect.center().x() + rho * cos(phi) - ellips.rect.width() / 2;
        double y = ellips.parent->rect.center().y() + rho * sin(phi) - ellips.rect.height() / 2;

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

        if(ellips.angle) {
            painter.translate(center.x(), center.y());
            painter.rotate(ellips.angle);
            painter.translate(-center.x(), -center.y());
        }

        painter.drawEllipse(ellips.rect);
    }
}
