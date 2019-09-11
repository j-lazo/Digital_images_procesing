#include "high_contrast_window.h"
#include "ui_high_contrast_window.h"

High_contrast_window::High_contrast_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::High_contrast_window)
{
    ui->setupUi(this);

    //Define the minimum and the maximum of the Slider and the spinBox
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(255);

    ui->spinBox->setMinimum(0);
    ui->spinBox->setMaximum(255);

    //Connect the Slider and the SpinBox

    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),
            ui->spinBox,SLOT(setValue(int)));

}

bool inverse=false;

void High_contrast_window::on_horizontalSlider_valueChanged(int value)
{
    //Change the value of the spinBox according to the Slider

    inverse = ui->checkBox->isTristate();
    //emit the value of the spinBox
    emit sendContrast_value(ui->horizontalSlider->value());
}

High_contrast_window::~High_contrast_window()
{
    delete ui;
}

void High_contrast_window::on_spinBox_valueChanged(int arg1)
{
    //Change the value of the Slider according to the spinBox

    inverse = ui->checkBox->isTristate();
    //emit the value of the spinBox
    emit sendContrast_value(ui->horizontalSlider->value());
}
