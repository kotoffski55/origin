#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "stopwatch.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pb_start_stop->setCheckable(true);
    ui->pb_start_stop->setText("СТАРТ");
    ui->lab_time->setText("0.00");
    ui->pb_lap->setText("КРУГ");
    ui->pb_lap->setEnabled(false);
    m_stopwatch = new Stopwatch(this);
    connect(m_stopwatch, &Stopwatch::sig_set_time, this, &MainWindow::setTime);
    //connect(m_stopwatch, &Stopwatch::sig_start, this, &MainWindow::setTime);

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pb_start_stop_clicked(bool checked)
{
    if(checked)
    {
        ui->pb_start_stop->setText("СТОП");
        m_stopwatch->start();

    }
}
void MainWindow::setTime(double time)
{

    ui->lab_time->setText(QString::number(time));
}

