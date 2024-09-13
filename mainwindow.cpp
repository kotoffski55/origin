#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stopwatch.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->pb_start_stop->setCheckable(true);
    ui->pb_start_stop->setText("СТАРТ");
    ui->lab_time->setText("0.0");
    ui->pb_lap->setText("КРУГ");
    ui->pb_lap->setEnabled(false);
    m_stopwatch = new Stopwatch(this);
    connect(m_stopwatch, &Stopwatch::sig_set_time, this, &MainWindow::setTime);
    connect(m_stopwatch, &Stopwatch::sig_lap, this, &MainWindow::setInfo);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setInfo(int lapCount, double LapTime)
{
    ui->tb_info->append(QString("Круг %1, время: %2 сек").arg(lapCount).arg(LapTime));
}

void MainWindow::on_pb_start_stop_clicked(bool checked)
{
    if(checked)
    {
        ui->pb_start_stop->setText("СТОП");
        m_stopwatch->start();
        ui->pb_lap->setEnabled(true);

    }
    else
    {
        ui->pb_start_stop->setText("СТАРТ");
        m_stopwatch->stop();
    }

}
void MainWindow::setTime(double time)
{

    ui->lab_time->setText(QString::number(time));
}



void MainWindow::on_pb_clear_clicked()
{
    m_stopwatch->clear();
    ui->lab_time->setText("0.0");
    lapCount = 0;
    lastLapTime = 0;
    ui->tb_info->clear();
}


void MainWindow::on_pb_lap_clicked()
{
   m_stopwatch->lap();
}

