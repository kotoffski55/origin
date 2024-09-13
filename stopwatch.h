#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class Stopwatch : public QObject {
    Q_OBJECT

public:
    Stopwatch(QObject *parent = nullptr);
    void start();
    void stop();
    void clear();
    void lap();



signals:
    void sig_clear();
    void sig_set_time(double time);
    void sig_lap(int lapCount, double LapTime);

private slots:
  void set_time();



private:
    QTimer *m_timer;
    double time;
    int lapCount = 0;
    double currentLapTime = 0;
    double lastLapTime = 0;

};

#endif // STOPWATCH_H
