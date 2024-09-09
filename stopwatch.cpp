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

void Stopwatch::set_time()
{
   time++;
   emit sig_set_time(time);
}

