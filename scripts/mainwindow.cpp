#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QImage>
#include <QFileDialog>
#include <iostream>
#include <QDebug>
#include <QTextStream>
#include <typeinfo>
#include <unistd.h>
#include "brigthnes_dialog.cpp"

QTextStream out(stdout);
QImage image;
QString name_image;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}



// Load the Image
void MainWindow::on_pushButton_clicked()
{
    MainWindow::on_actionLoad_Image_triggered();
}


void MainWindow::on_actionLoad_Image_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this, tr("Choose the Image to Load"), "", tr("Images(*.png *.jpg *.jpeg *.PNG* *.JPG* *.JPEG)"));

    if (QString::compare(file_name, QString())!= 0)
    {
        // QImage image;
        bool valid = image.load(file_name);

        out << typeid(image).name()<< endl;

        if(valid)
        {

        int width_1 = ui->label_pic_1->width();
        int height_1 = ui->label_pic_1->height();
        int width_2 = ui->label_pic_2->width();
        int height_2 = ui->label_pic_2->height();

        ui->label_pic_1->setPixmap(QPixmap::fromImage(image).scaled(width_1,height_1,Qt::KeepAspectRatio));
        ui->label_pic_2->setPixmap(QPixmap::fromImage(image).scaled(width_2,height_2,Qt::KeepAspectRatio));

        }

        else
        {
                    //Error handling

            QMessageBox::critical(this, "Error", "Error no image selected");
        }
    }

}

// Grayscale filter

void MainWindow::on_actionEscala_de_Grises_triggered()
{
    // Read the Image

    QImage gray = image;
    int image_width = gray.width();
    int image_height = gray.height();

    out<< image_width << "," << image_height <<endl;

    for(int row=0; row< gray.width(); row++)
        {
        for (int col=0; col< gray.height(); col++)
            {

            QColor clrCurrent(gray.pixel( row, col ) );

            int value, average;
            average = (clrCurrent.red() + clrCurrent.green() + clrCurrent.blue())/3;
            //average = (clrCurrent.red()*0.3 + clrCurrent.green()*0.59 + clrCurrent.blue()*0.11);
            value = QColor(average, average, average).rgba();
            gray.setPixel(row,col, value);
            }
        }

    ui->label_pic_2->setPixmap(QPixmap::fromImage(gray).scaled(ui->label_pic_2->width(),ui->label_pic_2->height(),Qt::KeepAspectRatio));


}


// Green  Filter
void MainWindow::on_actionGreen_triggered()
{
}


// Blue filter
void MainWindow::on_actionBlue_triggered()
{

}

void MainWindow::on_actionRed_triggered()
{

}


// Apply Red Filter

void MainWindow::on_actionRed_2_triggered()
{
    QImage gray = image;
    qDebug() << "you just clicked ok";
    int image_width = gray.width();
    int image_height = gray.height();
    int img_dept = gray.depth();
    out <<img_dept <<endl;

    out << ui->label_pic_2->width() << ui->label_pic_2->height()<< endl;
    out << image_width << ',' << image_height<<endl;

    QImage gris(img_dept, img_dept, QImage::Format_Mono);
                //Format_RGB888);

    out<< gris.width() << gris.height() <<endl;

    //int planes=gray.bitPlaneCount();
    //out <<planes<<endl;

    out<< image_width << "," << image_height <<endl;

    for(int row=0; row< gray.width(); row++)
        {
        for (int col=0; col< gray.height(); col++)
            {

            QColor clrCurrent(gray.pixel( row, col ) );

            int value, average;
            average = (clrCurrent.red() + clrCurrent.green() + clrCurrent.blue())/3;
            //average = (clrCurrent.red()*0.3 + clrCurrent.green()*0.59 + clrCurrent.blue()*0.11);
            value = QColor(average, 0, 0).rgba();
            gray.setPixel(row,col, value);
            }
        }

    ui->label_pic_2->setPixmap(QPixmap::fromImage(gray).scaled(ui->label_pic_2->width(),ui->label_pic_2->height(),Qt::KeepAspectRatio));
}

void MainWindow::on_actionGreen_2_triggered()
{
    QImage gray = image;
    qDebug() << "you just clicked ok";
    int image_width = gray.width();
    int image_height = gray.height();
    int img_dept = gray.depth();
    out <<img_dept <<endl;

    out << ui->label_pic_2->width() << ui->label_pic_2->height()<< endl;
    out << image_width << ',' << image_height<<endl;

    QImage gris(img_dept, img_dept, QImage::Format_Mono);
                //Format_RGB888);

    out<< gris.width() << gris.height() <<endl;

    //int planes=gray.bitPlaneCount();
    //out <<planes<<endl;

    out<< image_width << "," << image_height <<endl;

    for(int row=0; row< gray.width(); row++)
        {
        for (int col=0; col< gray.height(); col++)
            {

            QColor clrCurrent(gray.pixel( row, col ) );

            int value, average;
            average = (clrCurrent.red() + clrCurrent.green() + clrCurrent.blue())/3;
            //average = (clrCurrent.red()*0.3 + clrCurrent.green()*0.59 + clrCurrent.blue()*0.11);
            value = QColor(0, average, 0).rgba();
            gray.setPixel(row,col, value);
            }
        }

    ui->label_pic_2->setPixmap(QPixmap::fromImage(gray).scaled(ui->label_pic_2->width(),ui->label_pic_2->height(),Qt::KeepAspectRatio));

}

// Apply Blue Filter

void MainWindow::on_actionBlue_2_triggered()
{
    QImage gray = image;
    qDebug() << "you just clicked ok";

    int img_dept = gray.depth();
    out <<img_dept <<endl;

    //out << ui->label_pic_2->width() << ui->label_pic_2->height()<< endl;
    //out << image_width << ',' << image_height<<endl;



    QImage gris(img_dept, img_dept, QImage::Format_Mono);

    //out<< gris.width() << gris.height() <<endl;
    //out<< image_width << "," << image_height <<endl;

    for(int row=0; row< gray.width(); row++)
        {
        for (int col=0; col< gray.height(); col++)
            {

            QColor clrCurrent(gray.pixel( row, col ) );

            int value, average;
            average = (clrCurrent.red() + clrCurrent.green() + clrCurrent.blue())/3;
            //average = (clrCurrent.red()*0.3 + clrCurrent.green()*0.59 + clrCurrent.blue()*0.11);
            value = QColor(0,0,average).rgba();
            gray.setPixel(row,col, value);
            }
        }

    ui->label_pic_2->setPixmap(QPixmap::fromImage(gray).scaled(ui->label_pic_2->width(),ui->label_pic_2->height(),Qt::KeepAspectRatio));
}



// Call the Brgthness Widget

void MainWindow::on_actionBrillo_triggered()
{

    // set-up the brightness dialog window
    brightnes_dial = new Brigthnes_Dialog(this);
    brightnes_dial->show();

    //connect brightness dial with MainWindow
    connect(brightnes_dial,SIGNAL(sendMessage(int)),this,SLOT(receiveMessage(int)));

    //connect contrast dial with MainWindow
    connect(brightnes_dial,SIGNAL(sendContrast_value(float)),this,SLOT(Change_Contrast(float)));


}

void MainWindow::High_Contrast(int threshold)
{
    QImage gray = image;

    int new_value;
    int img_dept = gray.depth();

    out <<threshold << endl;

    // Set the image on label 1

    QImage gris(img_dept, img_dept, QImage::Format_Mono);
                //Format_RGB888);

    for(int row=0; row< gray.width(); row++)
        {
        for (int col=0; col< gray.height(); col++)
            {

            QColor clrCurrent(gray.pixel( row, col ) );

            int value, average;
            average = (clrCurrent.red() + clrCurrent.green() + clrCurrent.blue())/3;

            if (average > threshold)
            {
                new_value = 254;
             }
            else
                {
                        new_value = 0;}

            value = QColor(new_value, new_value, new_value).rgba();
            gray.setPixel(row,col, value);
            }
        }

    ui->label_pic_2->setPixmap(QPixmap::fromImage(gray).scaled(ui->label_pic_2->width(),ui->label_pic_2->height(),Qt::KeepAspectRatio));

}



int MainWindow::receiveMessage(int valor)
{
    out << int(valor) << endl;

    valor = float(valor);
    // Read the Image

    QImage gray = image;

    // Set the image on label 1


    for(int row=0; row< gray.width(); row++)
        {
        for (int col=0; col< gray.height(); col++)
            {

            QColor clrCurrent(gray.pixel( row, col ) );

            int new_red;
            int new_green;
            int new_blue;

            new_red = clrCurrent.red() + valor;
            new_green = clrCurrent.green()+ valor;
            new_blue = clrCurrent.blue() + valor;

            if (new_red < 0)
            {
                new_red = 0;}
            if (new_red > 254){
                new_red = 254;}

            if (new_green < 0)
            {
                new_green = 0;}

            if (new_green > 254){
                        new_green = 254;}

            if (new_blue < 0)
            {
                new_blue = 0;}
            if (new_blue > 254){
                new_blue = 254;}


            int value;
            value = QColor(new_red, new_green, new_blue).rgba();

            gray.setPixel(row,col, value);
            }
        }

    ui->label_pic_2->setPixmap(QPixmap::fromImage(gray).scaled(ui->label_pic_2->width(),ui->label_pic_2->height(),Qt::KeepAspectRatio));


    return valor;
}


void MainWindow::Change_Contrast(float new_contrast)
{
    // Read the Image
    out << new_contrast <<endl;
    QImage gray = image;

    // Set the image on label 1


    for(int row=0; row< gray.width(); row++)
        {
        for (int col=0; col< gray.height(); col++)
            {

            QColor clrCurrent(gray.pixel(row, col ));

            int new_red;
            int new_green;
            int new_blue;

            float adjust_value;

            adjust_value = (259*(new_contrast+255))/(255*(259-new_contrast));

            new_red = adjust_value*(clrCurrent.red()-128)+128;
            new_green = adjust_value*(clrCurrent.green()-128)+ 128;
            new_blue = adjust_value*(clrCurrent.blue()-128) + 128;

            if (new_red < 0)
            {
                new_red = 0;}
            if (new_red > 254){
                new_red = 254;}

            if (new_green < 0)
            {
                new_green = 0;}

            if (new_green > 254){
                        new_green = 254;}

            if (new_blue < 0)
            {
                new_blue = 0;}
            if (new_blue > 254){
                new_blue = 254;}


            int value;
            value = QColor(new_red, new_green, new_blue).rgba();

            gray.setPixel(row,col, value);
            }
        }

    ui->label_pic_2->setPixmap(QPixmap::fromImage(gray).scaled(ui->label_pic_2->width(),ui->label_pic_2->height(),Qt::KeepAspectRatio));

}




void MainWindow:: edit_image(QImage edited_image)
{
    ui->label_pic_2->setPixmap(QPixmap::fromImage(edited_image).scaled(ui->label_pic_2->width(),ui->label_pic_2->height(),Qt::KeepAspectRatio));
}


// Aplica Alto Contraste con valores por "default"
void MainWindow::on_actionDefault_triggered()
{
    QImage gray = image;

    int new_value;

    int img_dept = gray.depth();
    out <<img_dept <<endl;

    // Set the image on label 1

    QImage gris(img_dept, img_dept, QImage::Format_Mono);
                //Format_RGB888);

    for(int row=0; row< gray.width(); row++)
        {
        for (int col=0; col< gray.height(); col++)
            {

            QColor clrCurrent(gray.pixel( row, col ) );

            int value, average;
            average = (clrCurrent.red() + clrCurrent.green() + clrCurrent.blue())/3;

            if (average > 128)
            {
                new_value = 254;
             }
            else
                {
                        new_value = 0;}

            value = QColor(new_value, new_value, new_value).rgba();
            gray.setPixel(row,col, value);
            }
        }

    ui->label_pic_2->setPixmap(QPixmap::fromImage(gray).scaled(ui->label_pic_2->width(),ui->label_pic_2->height(),Qt::KeepAspectRatio));


}


// call the high contrast Window
void MainWindow::on_actionCustom_triggered()
{
    // set-up the high-brightness dialog window
    high_contrast_window = new High_contrast_window(this);
    high_contrast_window->show();

    //connect brightness dial with MainWindow
    connect(high_contrast_window,SIGNAL(sendContrast_value(int)),this,SLOT(High_Contrast(int)));

}
