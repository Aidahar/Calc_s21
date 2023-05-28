#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_7_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );

    if ( button )
    {
        ui->lineEdit->insert( button->text() );
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );

    if ( button )
    {
        ui->lineEdit->insert( button->text() );
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );

    if ( button )
    {
        ui->lineEdit->insert( button->text() );
    }
}


void MainWindow::on_pushButton_10_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );

    if ( button )
    {
        ui->lineEdit->insert( button->text() );
    }
}


void MainWindow::on_pushButton_11_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );

    if ( button )
    {
        ui->lineEdit->insert( button->text() );
    }
}


void MainWindow::on_pushButton_12_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        ui->lineEdit->insert( button->text() );
    }
}


void MainWindow::on_pushButton_13_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        ui->lineEdit->insert( button->text() );
    }
}


void MainWindow::on_pushButton_14_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        ui->lineEdit->insert( button->text() );
    }
}


void MainWindow::on_pushButton_15_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        ui->lineEdit->insert( button->text() );
    }
}


void MainWindow::on_pushButton_16_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        ui->lineEdit->insert( button->text() );
    }
}


void MainWindow::on_pushButton_17_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        ui->lineEdit->insert( button->text() );
    }
}


void MainWindow::on_pushButton_18_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        if (ui->lineEdit->text().contains('.')) {
            ui->lineEdit->setText("ERROR!");
        } else {
            ui->lineEdit->insert( button->text() );
        }
    }
}

