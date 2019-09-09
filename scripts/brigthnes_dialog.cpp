#include "brigthnes_dialog.h"
#include "ui_brigthnes_dialog.h"
#include "mainwindow.h"
#include <unistd.h>

int brillo = 0;

Brigthnes_Dialog::Brigthnes_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Brigthnes_Dialog)

{
    ui->setupUi(this);

    // Define the minimum and maximum values of the Horizontal Sliders
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(101);

    // Definet he minimum and maximum values of the SpinBox
    ui->doubleSpinBox->setMinimum(0);
    ui->doubleSpinBox->setMaximum(101);

    // Connects the value of the horizontaSlider and the SpinBox
    connect(ui->horizontalSlider,SIGNAL(valueChanged(float)),
                                        ui->buttonBox,SLOT(setValue(float)));

}


void Brigthnes_Dialog::on_horizontalSlider_sliderMoved(int position)
{
    // change the value of the spinBox according to the Slider
    ui->doubleSpinBox->setValue(ui->horizontalSlider->value());
    brillo = ui->horizontalSlider->value();

    // connect the signal 'clicked' to the 'button Clicked' signal
    connect(ui->horizontalSlider,SIGNAL(valueChanged(float)),
                                        this,SLOT(on_doubleSpinBox_valueChanged));

    // connect the child's "Send Message Signal" to the parent's receiveMessage slot
    //connect(this, SIGNAL(sendMessage(QString)),parent, SLOT(receiveMessage(QString)));
    //connect(this, SIGNAL(sendMessage(QString)), parent, SLOT(receiveMessage(QString)));

}


void Brigthnes_Dialog::on_doubleSpinBox_valueChanged(double arg1)
{
    // change the value of the Slider according to the SpinBox
    ui->horizontalSlider->setValue(ui->doubleSpinBox->value());
    brillo = ui->doubleSpinBox->value();
    emit sendMessage("This is a message sent by Batman");
}


// close the brightness dialog
Brigthnes_Dialog::~Brigthnes_Dialog()
{
    delete ui;
}
