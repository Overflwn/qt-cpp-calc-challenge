#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->button_0, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->button_1, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->button_2, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->button_3, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->button_4, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->button_5, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->button_6, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->button_7, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->button_8, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->button_9, SIGNAL(released()), this, SLOT(digit_pressed()));

    connect(ui->button_clear, SIGNAL(released()), this, SLOT(clear_pressed()));
    connect(ui->button_add, SIGNAL(released()), this, SLOT(add_pressed()));
    connect(ui->button_subtract, SIGNAL(released()), this, SLOT(subtract_pressed()));
    connect(ui->button_multiply, SIGNAL(released()), this, SLOT(multiply_pressed()));
    connect(ui->button_divide, SIGNAL(released()), this, SLOT(divide_pressed()));
    connect(ui->button_plusminus, SIGNAL(released()), this, SLOT(plusminus_pressed()));
    connect(ui->button_percent, SIGNAL(released()), this, SLOT(percentage_pressed()));
    connect(ui->button_dot, SIGNAL(released()), this, SLOT(dot_pressed()));
    connect(ui->button_calculate, SIGNAL(released()), this, SLOT(calculate_pressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    if(ui->label->text() == "0")
    {
        ui->label->setText("");
    }
    qDebug() << "TEST";
    QPushButton* button = (QPushButton*)sender();
    double num;
    QString numStr;
    num = (ui->label->text() + button->text()).toDouble();
    qDebug() << num;
    numStr = QString::number(num,'g',15);
    ui->label->setText(ui->label->text() + button->text());
}

void MainWindow::clear_pressed()
{
    number1 = 0.0;
    number2 = 0.0;
    ui->label->setText("0");
    dot_exists = false;
}
void MainWindow::add_pressed()
{
    if(operand != ' ')
    {
        calculate_pressed();
    }
    operand = '+';
    number1 = (ui->label->text()).toDouble();
    number2 = 0.0;
    ui->label->setText("0");
    dot_exists = false;
}
void MainWindow::subtract_pressed()
{
    if(operand != ' ')
    {
        calculate_pressed();
    }
    operand = '-';
    number1 = (ui->label->text()).toDouble();
    number2 = 0.0;
    ui->label->setText("0");
    dot_exists = false;
}
void MainWindow::multiply_pressed()
{
    if(operand != ' ')
    {
        calculate_pressed();
    }
        operand = '*';
        number1 = (ui->label->text()).toDouble();
        number2 = 0.0;
        ui->label->setText("0");
        dot_exists = false;
}
void MainWindow::dot_pressed()
{
    if(!dot_exists)
    {
        ui->label->setText(ui->label->text() + ".");
        dot_exists = true;
    }
}
void MainWindow::divide_pressed()
{
    if(operand != ' ')
    {
        calculate_pressed();
    }
        operand = '/';
        number1 = (ui->label->text()).toDouble();
        number2 = 0.0;
        ui->label->setText("0");
        dot_exists = false;
}
void MainWindow::percentage_pressed()
{
    double num = ui->label->text().toDouble();
    double percentage = num/100;
    double temp;
    if(modf(percentage, &temp) != 0)
    {
        dot_exists = true;
    }else
    {
        dot_exists = false;
    }
    ui->label->setText(QString::number(percentage, 'g', 15));
}
void MainWindow::plusminus_pressed()
{
    double num = ui->label->text().toDouble();
    if(num != 0.0)
    {
        num = -num;
        ui->label->setText(QString::number(num, 'g', 15));
    }
}

void MainWindow::calculate_pressed()
{
    if(operand != ' ')
    {
        number2 = ui->label->text().toDouble();
        double result = 0.0;
        switch(operand)
        {
        case '+':
            result = number1+number2;
            break;
        case '-':
            result = number1-number2;
            break;
        case '*':
            result = number1*number2;
            break;
        case '/':
            result = number1/number2;
        }
        number1 = result;
        number2 = 0.0;
        ui->label->setText(QString::number(result, 'g', 15));
        operand = ' ';
        double temp;
        if(modf(result, &temp) != 0)
        {
            dot_exists = true;
        }else
        {
            dot_exists = false;
        }
    }
}
