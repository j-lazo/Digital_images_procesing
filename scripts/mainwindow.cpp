#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QImage>
#include <QFileDialog>
#include <iostream>
#include<QDebug>
#include <QTextStream>
#include <typeinfo>
#include <unistd.h>

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



void MainWindow::on_pushButton_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, tr("Choose the Image to Load"), "", tr("Images(*.png *.jpg *.jpeg *.PNG* *.JPG* *.JPEG)"));

    if (QString::compare(file_name, QString())!= 0)
    {
        //QImage image;
        bool valid = image.load(file_name);

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

void MainWindow::on_actionEscala_de_Grises_triggered()
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
            //out <<gray.pixel((row, col))<< endl;
            // Uncoment bellow to see the color of each pixel
            /*
            out << "Pixel at [" << row << "," << col << "] contains color ("
                              << clrCurrent.red() << ", "
                              << clrCurrent.green() << ", "
                              << clrCurrent.blue() << ", "
                              << clrCurrent.alpha() << ")."
                              << endl;
            usleep(30000);*/
            int value, average;
            average = (clrCurrent.red() + clrCurrent.green() + clrCurrent.blue())/3;
            //average = (clrCurrent.red()*0.3 + clrCurrent.green()*0.59 + clrCurrent.blue()*0.11);
            value = QColor(average, average, average).rgba();
            gray.setPixel(row,col, value);
            }
        }

    ui->label_pic_2->setPixmap(QPixmap::fromImage(gray).scaled(ui->label_pic_2->width(),ui->label_pic_2->height(),Qt::KeepAspectRatio));


}

void MainWindow::on_actionRed_triggered()
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

void MainWindow::on_actionGreen_triggered()
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

void MainWindow::on_actionBlue_triggered()
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
            value = QColor(0,0,average).rgba();
            gray.setPixel(row,col, value);
            }
        }

    ui->label_pic_2->setPixmap(QPixmap::fromImage(gray).scaled(ui->label_pic_2->width(),ui->label_pic_2->height(),Qt::KeepAspectRatio));

}
