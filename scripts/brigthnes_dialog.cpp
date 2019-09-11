#include "brigthnes_dialog.h"
#include "ui_brigthnes_dialog.h"
#include "mainwindow.h"
#include <unistd.h>

Brigthnes_Dialog::Brigthnes_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Brigthnes_Dialog)

{
    ui->setupUi(this);

    // Define the minimum and maximum values of the Horizontal Sliders

    //Brightness
    ui->horizontalSlider->setMinimum(-255);
    ui->horizontalSlider->setMaximum(255);

    //Contrast
    ui->horizontalSlider_2->setMaximum(255);
    ui->horizontalSlider_2->setMinimum(0);

    //ui->horizontalSlider->setTickPosition(0);

    // Definet he minimum and maximum values of the SpinBoxes

    //Brightness
    ui->doubleSpinBox->setMinimum(-255);
    ui->doubleSpinBox->setMaximum(255);

    //Contrat

    ui->doubleSpinBox_2->setMinimum(0);
    ui->doubleSpinBox_2->setMaximum(255);

    // Connects the value of the horizontaSlider and the SpinBox
    //connect(ui->horizontalSlider,SIGNAL(valueChanged(float)),
    //        ui->doubleSpinBox,SLOT(setValue(float)));


    //connect(ui->horizontalSlider_2,SIGNAL(valueChanged(int)),
    //        ui->doubleSpinBox_2,SLOT(setValue(double)));
}

// change the value on the Brightness Slider
void Brigthnes_Dialog::on_horizontalSlider_sliderMoved(int)
{
    // change the value of the spinBox according to the Slider
    // Brightness
    ui->doubleSpinBox->setValue(ui->horizontalSlider->value());

    // emit the value of the Slider
    emit sendMessage(ui->doubleSpinBox->value());

}

// change the value on the SpinBox
void Brigthnes_Dialog::on_doubleSpinBox_valueChanged()
{
    // change the value of the Slider according to the SpinBox
    ui->horizontalSlider->setValue(ui->doubleSpinBox->value());

    // emit the value of the SpinBox
    emit sendMessage(ui->doubleSpinBox->value());
}


// change the value on the Contrast Slider
void Brigthnes_Dialog::on_horizontalSlider_2_valueChanged()
{
    // change the value of the spinBox according to the Slider
    ui->doubleSpinBox_2->setValue(ui->horizontalSlider_2->value());

    // emit the value of the SpinBox
    emit sendContrast_value(ui->doubleSpinBox_2->value());
}


// close the brightness dialog
Brigthnes_Dialog::~Brigthnes_Dialog()
{
    emit sendMessage(ui->doubleSpinBox->value());
    emit sendContrast_value(ui->doubleSpinBox_2->value());
    delete ui;
}

// Change the value on the Contrast SpinBox
void Brigthnes_Dialog::on_doubleSpinBox_2_valueChanged()
{
    // change the value of the Slider according to the SpinBox
    ui->horizontalSlider_2->setValue(ui->doubleSpinBox_2->value());

    // emit the value of the SpinBox
    emit sendContrast_value(ui->doubleSpinBox_2->value());
}
