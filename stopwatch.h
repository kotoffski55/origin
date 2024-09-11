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
    double Time() const { return time; }

signals:
    void sig_clear();
    void sig_set_time(double time);

private slots:
  void set_time();


private:
    QTimer *m_timer;
    double time;

};

#endif // STOPWATCH_H
