#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_minusOn, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(binary_math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(binary_math_operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(binary_math_operations()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(binary_math_operations()));
    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(unary_math_operations()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(unary_math_operations()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(unary_math_operations()));
    connect(ui->pushButton_degree, SIGNAL(clicked()), this, SLOT(binary_math_operations()));

    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);
    ui->pushButton_sin->setCheckable(true);
    ui->pushButton_cos->setCheckable(true);
    ui->pushButton_tan->setCheckable(true);
    ui->pushButton_degree->setCheckable(true);
    ui->memory_show->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_numbers() {
    QPushButton *button = (QPushButton*)sender();

    double all_numbers;
    QString new_label;

    if(ui->result_show->text().contains(".") && button->text() == "0") {
        new_label = ui->result_show->text() + button->text();
    }
    else {
        all_numbers = (ui->result_show->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g', 15);
    }

    ui->result_show->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->result_show->text().contains("."))) {
        ui->result_show->setText(ui->result_show->text() + ".");
    }
}

void MainWindow::operations() {
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;

    if(button->text() == "+/-") {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = all_numbers * -1.0;
        new_label = QString::number(all_numbers, 'g', 15);

        ui->result_show->setText(new_label);
    }
    else if(button->text() == "%") {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers, 'g', 15);

        ui->result_show->setText(new_label);
    }
}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_mult->setChecked(false);
    ui->pushButton_sin->setChecked(false);
    ui->pushButton_cos->setChecked(false);
    ui->pushButton_tan->setChecked(false);
    ui->pushButton_degree->setChecked(false);
    ui->pushButton_memory->setChecked(false);

    ui->result_show->setText("0");
}

void MainWindow::on_pushButton_calculate_clicked()
{
    QPushButton *button = (QPushButton *) sender();
    double labelNumber, num_second;
    QString new_label;

    num_second = ui->result_show->text().toDouble();

    if(ui->pushButton_divide->isChecked()) {
        if(num_second == 0) {
            ui->result_show->setText("Divide by 0!");
        }
        else {
            labelNumber = num_first / num_second;
            new_label = QString::number(labelNumber, 'g', 15);

            ui->result_show->setText(new_label);
        }
        ui->pushButton_divide->setChecked(false);
        button = ui->pushButton_divide;
    }
    else if(ui->pushButton_minus->isChecked()) {
        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->result_show->setText(new_label);
        ui->pushButton_minus->setChecked(false);
        button = ui->pushButton_minus;
    }
    else if(ui->pushButton_plus->isChecked()) {
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->result_show->setText(new_label);
        ui->pushButton_plus->setChecked(false);
        button = ui->pushButton_plus;
    }
    else if(ui->pushButton_mult->isChecked()) {
        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->result_show->setText(new_label);
        ui->pushButton_mult->setChecked(false);
        button = ui->pushButton_mult;
    }
    else if(ui->pushButton_degree->isChecked()) {
        labelNumber = pow(num_first, num_second);
        new_label = QString::number(labelNumber, 'g', 15);

        ui->result_show->setText(new_label);
        ui->pushButton_mult->setChecked(false);
        button = ui->pushButton_degree;
    }
    else if(ui->pushButton_sin->isChecked()) {
        labelNumber = sin(num_first);
        new_label = QString::number(labelNumber, 'g', 15);

        ui->result_show->setText(new_label);
        ui->pushButton_mult->setChecked(false);
        button = ui->pushButton_sin;
    }
    else if(ui->pushButton_cos->isChecked()) {
        labelNumber = cos(num_first);
        new_label = QString::number(labelNumber, 'g', 15);

        ui->result_show->setText(new_label);
        ui->pushButton_mult->setChecked(false);
        button = ui->pushButton_cos;
    }
    else if(ui->pushButton_tan->isChecked()) {
        labelNumber = tan(num_first);
        new_label = QString::number(labelNumber, 'g', 15);

        ui->result_show->setText(new_label);
        ui->pushButton_mult->setChecked(false);
        button = ui->pushButton_tan;
    }
    if(button == ui->pushButton_divide || button == ui->pushButton_minus || button == ui->pushButton_plus
            || button == ui->pushButton_mult || button == ui->pushButton_degree) {
        ui->example_label->setText(QString::number(num_first) + " " + button->text() + " "
                               + QString::number(num_second) + " = " + ui->result_show->text());
    }
    else ui->example_label->setText(button->text() + "(" + QString::number(num_first) + ")" + " = " + ui->result_show->text());
}

void MainWindow::binary_math_operations()
{
    QPushButton *button = (QPushButton *) sender();

    num_first = ui->result_show->text().toDouble();
    ui->result_show->setText("");
    button->setChecked(true);
}

void MainWindow::unary_math_operations() {
    QPushButton *button = (QPushButton *) sender();
    QString qstr = button->objectName().remove(0, 11) + "(";

    num_first = ui->result_show->text().toDouble();
    qstr += QString::number(num_first);
    qstr += ")";
    ui->result_show->setText(qstr);
    button->setChecked(true);
}

void MainWindow::on_pushButton_memory_clicked()
{
    if(ui->memory_show->text() == "M") {
        ui->memory_show->setVisible(true);
        ui->memory_show->setText("M " + ui->result_show->text());
    }
    else {
        ui->memory_show->setVisible(false);
        ui->result_show->setText(ui->memory_show->text().remove(0, 2));
        ui->memory_show->setText("M");
    }
}
