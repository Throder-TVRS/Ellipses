#pragma once
#include <QtGui/QWindow>
#include <QtGui/QPainter>
#include <QtGui/QResizeEvent>
#include <QtGui/QExposeEvent>
#include <QtGui/QBackingStore>
#include <movingprocessor.h>
#include <QtCore/QElapsedTimer>
#include <memory>

class RasterWindow : public QWindow
{
    Q_OBJECT

public:
    explicit RasterWindow(MovingProcessor* mp, QWindow *parent = 0);
    bool isAnimating() const;
    void setAnimating(bool isAnimating);

protected:
    bool event(QEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void exposeEvent(QExposeEvent *event) override;

private:
    void renderLater();
    void renderNow();
    void updateScene();
    void renderScene();

    QBackingStore *m_backingStore = nullptr;
    MovingProcessor*  mp;
    QElapsedTimer m_updateTimer;
    bool m_isAnimating = false;
};
