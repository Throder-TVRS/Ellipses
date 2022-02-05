#include "rasterwindow.h"

RasterWindow::RasterWindow(MovingProcessor* mp, QWindow *parent)
    : QWindow(parent)
    , m_backingStore(new QBackingStore(this))
    , mp(mp)
{
    setMinimumSize(QSize(600, 600));
}

bool RasterWindow::event(QEvent *event)
{
    if (event->type() == QEvent::UpdateRequest) {
        renderNow();
        return true;
    }
    return QWindow::event(event);
}

void RasterWindow::exposeEvent(QExposeEvent *)
{
    if (isExposed())
    {
        renderNow();
    }
}

void RasterWindow::resizeEvent(QResizeEvent *resizeEvent)
{
    m_backingStore->resize(resizeEvent->size());
    mp->ellipses[0].rect = QRect(width() / 4, height() / 4, width() / 2, height() / 2);
    mp->ellipses[1].rect = QRect(width() / 8 * 5, height() / 8 * 3, width() / 4, height() / 4);
    mp->ellipses[2].rect = QRect(width() / 16 * 13, height() / 16 * 7, width() / 8, height() / 8);
    if (isExposed())
    {
        renderNow();
    }
}

void RasterWindow::renderLater()
{
    requestUpdate();
}

void RasterWindow::renderNow()
{
    if (!isExposed())
    {
        return;
    }

    updateScene();
    renderScene();

    if (m_isAnimating)
    {
        renderLater();
    }
}

void RasterWindow::updateScene()
{
    float elapsedSeconds = float(m_updateTimer.elapsed()) / 1000.f;
    std::cerr << elapsedSeconds << std::endl;

    m_updateTimer.restart();
    mp->update(elapsedSeconds);
}

void RasterWindow::renderScene()
{
    QRect rect(0, 0, width(), height());
    m_backingStore->beginPaint(rect);

    QPaintDevice *device = m_backingStore->paintDevice();
    QPainter painter(device);

    painter.fillRect(0, 0, width(), height(), Qt::white);
    mp->redraw(painter);
    painter.end();

    m_backingStore->endPaint();
    m_backingStore->flush(rect);
}

bool RasterWindow::isAnimating() const
{
    return m_isAnimating;
}

void RasterWindow::setAnimating(bool isAnimating)
{
    m_isAnimating = isAnimating;
    if (isAnimating)
    {
        renderLater();
    }
}
