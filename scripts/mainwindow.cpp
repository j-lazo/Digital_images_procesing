#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //QString location_image;
    //location_image = "/home/jl/Desktop/folder/the_girl_and_the_horse.jpg";
    //QPixmap pix(location_image);
    //int width_1 = ui->label_pic_1->width();
    //int height_1 = ui->label_pic_1->height();
    //int width_2 = ui->label_pic_2->width();
    //int height_2 = ui->label_pic_2->height();

    //ui->label_pic_1->setPixmap(pix.scaled(width_1,height_1,Qt::KeepAspectRatio));
    //ui->label_pic_2->setPixmap(pix.scaled(width_2,height_2,Qt::KeepAspectRatio));


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
        QImage image;
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
