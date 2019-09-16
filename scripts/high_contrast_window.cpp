#include "high_contrast_window.h"
#include "ui_high_contrast_window.h"
#include <QTextStream>

QTextStream outa(stdout);

bool inverse;

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


void High_contrast_window::on_horizontalSlider_valueChanged(int value)
{
    //Change the value of the spinBox according to the Slider
    ui->spinBox->setValue(ui->horizontalSlider->value());
    if (ui->checkBox->isChecked())
    {
        inverse = true;
    }

    else
    {
        inverse = false;
    }

    //emit the value of the spinBox
    emit sendContrast_value(ui->horizontalSlider->value(), inverse);
}

High_contrast_window::~High_contrast_window()
{
    delete ui;
}

void High_contrast_window::on_spinBox_valueChanged(int arg1)
{
    //Change the value of the Slider according to the spinBox
    ui->horizontalSlider->setValue(ui->spinBox->value());

    if (ui->checkBox->isChecked())
    {
        inverse = true;
    }

    //emit the value of the spinBox
    emit sendContrast_value(ui->horizontalSlider->value(), inverse);
}

void High_contrast_window::on_checkBox_clicked()
{

    if (ui->checkBox->isChecked())
    {
        inverse = true;
    }

    emit sendContrast_value(ui->horizontalSlider->value(), inverse);
}
