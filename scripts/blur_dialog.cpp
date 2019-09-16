#include "blur_dialog.h"
#include "ui_blur_dialog.h"
#include <QTextStream>


QString type_of_blur; // Global variable to define the type of Blur
int value_1, value_2; // Global variables to the parameters of the Blur function

Blur_Dialog::Blur_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Blur_Dialog)
{
    ui->setupUi(this);

    //Define the minimum and maximum of the Sliders
    //Slider size
    ui->horizontalSlider->setMaximum(100);
    ui->horizontalSlider->setMinimum(0);
    //Slider Angle

    ui->horizontalSlider_2->setMinimum(0);
    ui->horizontalSlider_2->setMaximum(90);

   // Define the limits for the SpinBoxes
   // X position recangle/center point
   ui->spinBox->setMinimum(1);
   ui->spinBox->setMaximum(200);
   // Y position recangle/center point
   ui->spinBox_2->setMinimum(1);
   ui->spinBox_2->setMaximum(200);
   // Zoom blur size
   ui->spinBox_3->setMinimum(0);
   ui->spinBox_3->setMaximum(100);
   // Zoom blur angle
   ui->spinBox_4->setMinimum(0);
   ui->spinBox_4->setMaximum(90);

   // By default the Rectangular Blur radioButton is checked

   ui->radioButton->setChecked('true');

   // connect the Sliders 1 &2 with the Spinbox 3 & 4

   connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),
           ui->spinBox_3,SLOT(setValue(int)));

   connect(ui->horizontalSlider_2,SIGNAL(valueChanged(int)),
           ui->spinBox_4,SLOT(setValue(int)));


}

Blur_Dialog::~Blur_Dialog()
{
    delete ui;
}


// Choose as type of Blur Recangular
void Blur_Dialog::on_radioButton_clicked(bool checked)
{
    if (checked == true)
    {
        type_of_blur = QString('Rectangle');
    }
}

// Choose as type of Blur Radial
void Blur_Dialog::on_radioButton_2_clicked(bool checked)
{
    if (checked == true)
    {
        type_of_blur = QString('Radial');
    }
}

// Choose as type of Blur Zoom
void Blur_Dialog::on_radioButton_3_clicked(bool checked)
{
    if (checked == true)
    {
        type_of_blur = QString('Zoom');
    }
}

// moving the Slider sets the Spinbox 3 to the same value
void Blur_Dialog::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox_3->setValue(ui->horizontalSlider->value());
}

// moving the Slider_2 sets the Spinbox 4 to the same value
void Blur_Dialog::on_horizontalSlider_2_valueChanged(int value)
{
    ui->spinBox_4->setValue(ui->horizontalSlider_2->value());
}

// Changing the value of SpinBox 3 changes the value of Slider
void Blur_Dialog::on_spinBox_3_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(ui->spinBox_3->value());
}

// Changing the value of SpinBox 4 changes the value of Slider 2
void Blur_Dialog::on_spinBox_4_valueChanged(int arg1)
{
    ui->horizontalSlider_2->setValue(ui->spinBox_4->value());
}


// when clicked ok send the information back to the MainWindow
void Blur_Dialog::on_buttonBox_accepted()
{
    // if the type Zoom is selected the information of SpinBoxes 3 & 4 is sended
    if (type_of_blur == QString('Zoom'))
    {
        value_1 = ui->spinBox_3->value();
        value_2 = ui->spinBox_4->value();
        emit sendBlur_information(type_of_blur,value_1,value_2);
    }
    // otherwise informaton from SpinBoxes 1 & 2 is sended
    else
    {
        value_1 = ui->spinBox->value();
        value_2 = ui->spinBox_2->value();
        emit sendBlur_information(type_of_blur,value_1,value_2);
    }

}


