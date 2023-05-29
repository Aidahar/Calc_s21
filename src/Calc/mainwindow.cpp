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

void MainWindow::on_Del_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        if (ui->parsed_string->text().contains("ERROR!")) {
            ui->parsed_string->clear();
            ui->parsed_string->insert( button->text() );
        } else {
            ui->parsed_string->insert( button->text() );
        }
    }
}


void MainWindow::on_Mul_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        if (ui->parsed_string->text().contains("ERROR!")) {
            ui->parsed_string->clear();
            ui->parsed_string->insert( button->text() );
        } else {
            ui->parsed_string->insert( button->text() );
        }
    }
}

void MainWindow::on_button_tchk_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        ui->parsed_string->insert( button->text() );
    }
}


void MainWindow::on_Minus_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        if (ui->parsed_string->text().contains("ERROR!")) {
            ui->parsed_string->clear();
            ui->parsed_string->insert( button->text() );
        } else {
            ui->parsed_string->insert( button->text() );
        }
    }
}


void MainWindow::on_plus_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        if (ui->parsed_string->text().contains("ERROR!")) {
            ui->parsed_string->clear();
            ui->parsed_string->insert( button->text() );
        } else {
            ui->parsed_string->insert( button->text() );
        }
    }
}


void MainWindow::on_C_clicked()
{
    if (ui->parsed_string->text().contains("ERROR!")) {
        ui->parsed_string->clear();
    } else {
        ui->parsed_string->backspace();
    }
}


void MainWindow::on_percent_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        ui->parsed_string->insert( button->text() );
    }
}


void MainWindow::on_AC_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        ui->parsed_string->clear();
    }
}


void MainWindow::on_button_0_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        if (ui->parsed_string->text().contains("ERROR!")) {
            ui->parsed_string->clear();
            ui->parsed_string->insert( button->text() );
        } else {
            ui->parsed_string->insert( button->text() );
        }
    }
}


void MainWindow::on_button_00_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        if (ui->parsed_string->text().contains("ERROR!")) {
            ui->parsed_string->clear();
            ui->parsed_string->insert( button->text() );
        } else {
            ui->parsed_string->insert( button->text() );
        }
    }
}


void MainWindow::on_button_1_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        if (ui->parsed_string->text().contains("ERROR!")) {
            ui->parsed_string->clear();
            ui->parsed_string->insert( button->text() );
        } else {
            ui->parsed_string->insert( button->text() );
        }
    }
}


void MainWindow::on_button_2_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        if (ui->parsed_string->text().contains("ERROR!")) {
            ui->parsed_string->clear();
            ui->parsed_string->insert( button->text() );
        } else {
            ui->parsed_string->insert( button->text() );
        }
    }
}


void MainWindow::on_button_3_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        if (ui->parsed_string->text().contains("ERROR!")) {
            ui->parsed_string->clear();
            ui->parsed_string->insert( button->text() );
        } else {
            ui->parsed_string->insert( button->text() );
        }
    }
}


void MainWindow::on_button_4_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        if (ui->parsed_string->text().contains("ERROR!")) {
            ui->parsed_string->clear();
            ui->parsed_string->insert( button->text() );
        } else {
            ui->parsed_string->insert( button->text() );
        }
    }
}


void MainWindow::on_button_5_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        if (ui->parsed_string->text().contains("ERROR!")) {
            ui->parsed_string->clear();
            ui->parsed_string->insert( button->text() );
        } else {
            ui->parsed_string->insert( button->text() );
        }
    }
}


void MainWindow::on_button_6_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        if (ui->parsed_string->text().contains("ERROR!")) {
            ui->parsed_string->clear();
            ui->parsed_string->insert( button->text() );
        } else {
            ui->parsed_string->insert( button->text() );
        }
    }
}


void MainWindow::on_button_7_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        if (ui->parsed_string->text().contains("ERROR!")) {
            ui->parsed_string->clear();
            ui->parsed_string->insert( button->text() );
        } else {
            ui->parsed_string->insert( button->text() );
        }
    }
}


void MainWindow::on_button_8_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        if (ui->parsed_string->text().contains("ERROR!")) {
            ui->parsed_string->clear();
            ui->parsed_string->insert( button->text() );
        } else {
            ui->parsed_string->insert( button->text() );
        }
    }
}


void MainWindow::on_buton_9_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );
    if ( button )
    {
        if (ui->parsed_string->text().contains("ERROR!")) {
            ui->parsed_string->clear();
            ui->parsed_string->insert( button->text() );
        } else {
            ui->parsed_string->insert( button->text() );
        }
    }
}

