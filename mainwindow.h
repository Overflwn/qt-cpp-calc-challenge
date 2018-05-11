#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    double number1;
    double number2;
    char operand = ' ';
    bool dot_exists = false;

private slots:
    void digit_pressed();
    void clear_pressed();
    void add_pressed();
    void subtract_pressed();
    void multiply_pressed();
    void dot_pressed();
    void divide_pressed();
    void percentage_pressed();
    void plusminus_pressed();
    void calculate_pressed();
};

#endif // MAINWINDOW_H
