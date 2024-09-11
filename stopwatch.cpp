#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject(parent)
{
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &Stopwatch::set_time);
}

void Stopwatch::start()
{
    m_timer->start(100);

}

void Stopwatch::stop()
{
    m_timer->stop();
}

void Stopwatch::clear()
{
   time = 0;
   emit sig_set_time(time);
}

void Stopwatch::set_time()
{
   time += 0.1;
   emit sig_set_time(time);
}

