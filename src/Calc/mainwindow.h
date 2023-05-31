#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Del_clicked();

    void on_Mul_clicked();

    void on_button_tchk_clicked();

    void on_Minus_clicked();

    void on_plus_clicked();

    void on_C_clicked();

    void on_percent_clicked();

    void on_AC_clicked();

    void on_button_0_clicked();

    void on_button_00_clicked();

    void on_button_1_clicked();

    void on_button_2_clicked();

    void on_button_3_clicked();

    void on_button_4_clicked();

    void on_button_5_clicked();

    void on_button_6_clicked();

    void on_button_7_clicked();

    void on_button_8_clicked();

    void on_buton_9_clicked();

    void on_Sqrt_clicked();

    void on_UnarPL_clicked();

    void on_L_BR_clicked();

    void on_R_BR_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
