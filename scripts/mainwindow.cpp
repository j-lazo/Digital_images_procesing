#include <QMessageBox>
#include <QPixmap>
#include <QImage>
#include <QFileDialog>
#include <iostream>
#include <QDebug>
#include <QTextStream>
#include <typeinfo>
#include <unistd.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "brigthnes_dialog.cpp"
#include <math.h>

QTextStream out(stdout);
QImage image;
QString name_image;

float Pi=3.14159;

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

        // set the Image in the Labels 1 and 2
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

// Original_imagescale filter

void MainWindow::on_actionEscala_de_Grises_triggered()
{
    // Read the Image

    QImage Copy_image = image;

    for(int row=0; row< Copy_image.width(); row++)
        {
        for (int col=0; col< Copy_image.height(); col++)
            {
            // Get the color of the Pixel
            QColor clrCurrent(Copy_image.pixel(row, col));

            int new_color_value, average_value;
            average_value = (clrCurrent.red() + clrCurrent.green() + clrCurrent.blue())/3;
            //average_value = (clrCurrent.red()*0.3 + clrCurrent.green()*0.59 + clrCurrent.blue()*0.11);
            // Set the average color as the color of the new pixel
            new_color_value = QColor(average_value, average_value, average_value).rgba();
            Copy_image.setPixel(row,col, new_color_value);

            }
        }

    ui->label_pic_2->setPixmap(QPixmap::fromImage(Copy_image).scaled(ui->label_pic_2->width(),ui->label_pic_2->height(),Qt::KeepAspectRatio));
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
    QImage Original_image = image;
    qDebug() << "you just clicked ok";
    int image_width = Original_image.width();
    int image_height = Original_image.height();
    int img_dept = Original_image.depth();

    QImage gris(img_dept, img_dept, QImage::Format_Mono);
                //Format_RGB888);

    for(int row=0; row< Original_image.width(); row++)
        {
        for (int col=0; col< Original_image.height(); col++)
            {

            QColor clrCurrent(Original_image.pixel( row, col ) );

            int value, average;
            average = (clrCurrent.red() + clrCurrent.green() + clrCurrent.blue())/3;
            //average = (clrCurrent.red()*0.3 + clrCurrent.green()*0.59 + clrCurrent.blue()*0.11);
            value = QColor(average, 0, 0).rgba();
            Original_image.setPixel(row,col, value);
            }
        }

    ui->label_pic_2->setPixmap(QPixmap::fromImage(Original_image).scaled(ui->label_pic_2->width(),ui->label_pic_2->height(),Qt::KeepAspectRatio));
}

void MainWindow::on_actionGreen_2_triggered()
{
    QImage Original_image = image;

    int img_dept = Original_image.depth();

    QImage gris(img_dept, img_dept, QImage::Format_Mono);
                //Format_RGB888);

    for(int row=0; row< Original_image.width(); row++)
        {
        for (int col=0; col< Original_image.height(); col++)
            {

            QColor clrCurrent(Original_image.pixel( row, col ) );

            int value, average;
            average = (clrCurrent.red() + clrCurrent.green() + clrCurrent.blue())/3;
            //average = (clrCurrent.red()*0.3 + clrCurrent.green()*0.59 + clrCurrent.blue()*0.11);
            value = QColor(0, average, 0).rgba();
            Original_image.setPixel(row,col, value);
            }
        }

    ui->label_pic_2->setPixmap(QPixmap::fromImage(Original_image).scaled(ui->label_pic_2->width(),ui->label_pic_2->height(),Qt::KeepAspectRatio));

}

// Apply Blue Filter

void MainWindow::on_actionBlue_2_triggered()
{
    QImage Original_image = image;
    int img_dept = Original_image.depth();

    QImage gris(img_dept, img_dept, QImage::Format_Mono);

    for(int row=0; row< Original_image.width(); row++)
        {
        for (int col=0; col< Original_image.height(); col++)
            {

            QColor clrCurrent(Original_image.pixel( row, col ) );

            int value, average;
            average = (clrCurrent.red() + clrCurrent.green() + clrCurrent.blue())/3;

            value = QColor(0,0,average).rgba();
            Original_image.setPixel(row,col, value);
            }
        }

    ui->label_pic_2->setPixmap(QPixmap::fromImage(Original_image).scaled(ui->label_pic_2->width(),ui->label_pic_2->height(),Qt::KeepAspectRatio));
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

void MainWindow::High_Contrast(int threshold, bool inverse)
{
    QImage Original_image = image;

    int new_value;
    int img_dept = Original_image.depth();

    // Set the image on label 1

    QImage gris(img_dept, img_dept, QImage::Format_Mono);
                //Format_RGB888);

    if (inverse==true)
    {

    for(int row=0; row< Original_image.width(); row++)
        {
        for (int col=0; col< Original_image.height(); col++)
            {

            QColor clrCurrent(Original_image.pixel( row, col ) );

            int value, average;
            average = (clrCurrent.red() + clrCurrent.green() + clrCurrent.blue())/3;

            if (average > threshold)
            {
                new_value = 0;
             }
            else
                {
                        new_value = 254;}

            value = QColor(new_value, new_value, new_value).rgba();
            Original_image.setPixel(row,col, value);
            }
        }

    ui->label_pic_2->setPixmap(QPixmap::fromImage(Original_image).scaled(ui->label_pic_2->width(),ui->label_pic_2->height(),Qt::KeepAspectRatio));

    }

    else {

        for(int row=0; row< Original_image.width(); row++)
            {
            for (int col=0; col< Original_image.height(); col++)
                {

                QColor clrCurrent(Original_image.pixel( row, col ) );

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
                Original_image.setPixel(row,col, value);
                }
            }

    ui->label_pic_2->setPixmap(QPixmap::fromImage(Original_image).scaled(ui->label_pic_2->width(),ui->label_pic_2->height(),Qt::KeepAspectRatio));

    }



}



int MainWindow::receiveMessage(int valor)
{
    out << int(valor) << endl;

    valor = float(valor);
    // Read the Image

    QImage Original_image = image;

    // Set the image on label 1


    for(int row=0; row< Original_image.width(); row++)
        {
        for (int col=0; col< Original_image.height(); col++)
            {

            QColor clrCurrent(Original_image.pixel( row, col ) );

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

            Original_image.setPixel(row,col, value);
            }
        }

    ui->label_pic_2->setPixmap(QPixmap::fromImage(Original_image).scaled(ui->label_pic_2->width(),ui->label_pic_2->height(),Qt::KeepAspectRatio));


    return valor;
}


void MainWindow::Change_Contrast(float new_contrast)
{
    // Read the Image
    out << new_contrast <<endl;
    QImage Original_image = image;

    // Set the image on label 1


    for(int row=0; row< Original_image.width(); row++)
        {
        for (int col=0; col< Original_image.height(); col++)
            {

            QColor clrCurrent(Original_image.pixel(row, col ));

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

            Original_image.setPixel(row,col, value);
            }
        }

    ui->label_pic_2->setPixmap(QPixmap::fromImage(Original_image).scaled(ui->label_pic_2->width(),ui->label_pic_2->height(),Qt::KeepAspectRatio));

}




void MainWindow:: edit_image(QImage edited_image)
{
    ui->label_pic_2->setPixmap(QPixmap::fromImage(edited_image).scaled(ui->label_pic_2->width(),ui->label_pic_2->height(),Qt::KeepAspectRatio));
}


// Aplica Alto Contraste con valores por "default"
void MainWindow::on_actionDefault_triggered()
{
    QImage Original_image = image;

    int new_value;

    int img_dept = Original_image.depth();

    // Set the image on label 1

    QImage gris(img_dept, img_dept, QImage::Format_Mono);
                //Format_RGB888);

    for(int row=0; row< Original_image.width(); row++)
        {
        for (int col=0; col< Original_image.height(); col++)
            {

            QColor clrCurrent(Original_image.pixel( row, col ) );

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
            Original_image.setPixel(row,col, value);
            }
        }

    ui->label_pic_2->setPixmap(QPixmap::fromImage(Original_image).scaled(ui->label_pic_2->width(),ui->label_pic_2->height(),Qt::KeepAspectRatio));


}


// call the high contrast Window
void MainWindow::on_actionCustom_triggered()
{
    // set-up the high-brightness dialog window
    high_contrast_window = new High_contrast_window(this);
    high_contrast_window->show();

    //connect brightness dial with MainWindow
    connect(high_contrast_window,SIGNAL(sendContrast_value(int, bool)),this,SLOT(High_Contrast(int, bool)));

}


//Call the Blur Window
void MainWindow::on_actionBlur_triggered()
{
    // set-up the Blur dialog Window

    blur_dialog = new Blur_Dialog(this);
    blur_dialog->show();

    //connect the Blur widget with the MainWindow
    connect(blur_dialog,SIGNAL(sendBlur_information(QString,int,int)),this,SLOT(Blur_Image(QString,int,int)));

}

void MainWindow::Convolution_2D(int kernel_cols, int kernel_rows, int rows, int columns)
{/*
    // find center position of kernel (half of kernel size)
    kernel_CenterX = kernel_cols / 2;
    kernel_CenterY = kernel_rows / 2;

    for(i=0; i < rows; ++i)              // rows
    {
        for(j=0; j < columns; ++j)          // columns
        {
            for(m=0; m < kernel_rows; ++m)     // kernel rows
            {
                mm = kRows - 1 - m;      // row index of flipped kernel

                for(n=0; n < kernel_cols; ++n) // kernel columns
                {
                    nn = kernel_cols - 1 - n;  // column index of flipped kernel

                    // index of input signal, used for checking boundary
                    ii = i + (kernel_CenterY - mm);
                    jj = j + (kernel_CenterX - nn);

                    // ignore input samples which are out of bound
                    if( ii >= 0 && ii < rows && jj >= 0 && jj < columns )
                        out[i][j] += in[ii][jj] * kernel[mm][nn];
                }
            }
        }
    }*/
}


void MainWindow::Blur_Image(QString type_of_blur, int value_1, int value_2)

{

    QImage New_image = image;
    QImage Original_image = image;

    int img_width = New_image.width();
    int img_height = New_image.height();
    int img_dept = New_image.depth();


    //qDebug() << "C++ Style Debug Message";
    if (type_of_blur == QString('Radial'))
    {

    }
    else if (type_of_blur == QString('Zoom'))
    {
        out<< 'Zoom' << endl;
        out<< value_1 << value_2 <<endl;

    }
    else {

        int step_in_x, step_in_y;
        step_in_x = value_1;
        step_in_y = value_2;

        for(int row=0; row< (Original_image.width()-1); row += step_in_x)
            {
            for (int col=0; col< (Original_image.height()-1); col += step_in_y)
                {
                // declare some auxiliar variables to calculate the averages
                float auxiliar_average_red=0, auxiliar_average_green=0, auxiliar_average_blue=0, auxiliar_alpha =0;
                // create an auxiliar array to store the neighborhood
                //float auxiliar_array[step_in_x][step_in_y][3];

                // iterate over a cycle of the size of steps selected
                for (int auxiliar_x = 0; auxiliar_x<step_in_x; auxiliar_x++)
                {
                    for (int auxiliar_y = 0; auxiliar_y<step_in_y; auxiliar_y++)
                    {
                        if (row+auxiliar_x<Original_image.width() && col+auxiliar_y <Original_image.height())
                        {
                        QColor clrCurrent(Original_image.pixel(row+auxiliar_x,col+auxiliar_y));
                        /*auxiliar_array[auxiliar_x][auxiliar_y][0] = clrCurrent.red();
                        auxiliar_array[auxiliar_x][auxiliar_y][1] = clrCurrent.green();
                        auxiliar_array[auxiliar_x][auxiliar_y][2] = clrCurrent.blue();*/

                        // calculate the average for each color
                        auxiliar_alpha = auxiliar_alpha + clrCurrent.alpha();
                        auxiliar_average_red = auxiliar_average_red + clrCurrent.red();
                        auxiliar_average_green = auxiliar_average_green + clrCurrent.green();
                        auxiliar_average_blue = auxiliar_average_blue + clrCurrent.blue();
                        }
                    }
                }
                auxiliar_average_red = auxiliar_average_red/(step_in_x*step_in_y);
                auxiliar_average_green = auxiliar_average_green/(step_in_x*step_in_y);
                auxiliar_average_blue = auxiliar_average_blue/(step_in_x*step_in_y);
                auxiliar_alpha = auxiliar_alpha/(step_in_x*step_in_y);


                //calculate the standard deviation of each of the neighbors in the 3 channels
                /*float stdv_chanel_1, stdv_chanel_2, stdv_chanel_3;
                int aux_x = 0, aux_y = 0;
                for (aux_x=0; aux_x<step_in_x; aux_x++)
                {
                    for (aux_y=0; aux_y<step_in_y; aux_y++)
                    {
                        stdv_chanel_1 = pow(auxiliar_array[aux_x][aux_y][0]-auxiliar_average_red,2);
                        stdv_chanel_2 = pow(auxiliar_array[aux_x][aux_y][1]-auxiliar_average_green,2);
                        stdv_chanel_3 = pow(auxiliar_array[aux_x][aux_y][2]-auxiliar_average_blue,2);
                    }
                }

                stdv_chanel_1 = stdv_chanel_1/((step_in_x*step_in_y)-1);
                stdv_chanel_2 = stdv_chanel_2/((step_in_x*step_in_y)-1);
                stdv_chanel_3 = stdv_chanel_3/((step_in_x*step_in_y)-1);

                */

                float new_pixel_value;
                int auxi_x = 0, auxi_y = 0;
                for (auxi_x=0; auxi_x<step_in_x; auxi_x++)
                {
                    for (auxi_y=0; auxi_y<step_in_y; auxi_y++)
                    {

                     if (row+auxi_x<Original_image.width() && col+auxi_y <Original_image.height())
                     {
                     auxiliar_average_red = auxiliar_average_red;
                     auxiliar_average_green = auxiliar_average_green;
                     auxiliar_average_blue = auxiliar_average_blue;
                     auxiliar_alpha = auxiliar_alpha;
                     new_pixel_value = QColor(auxiliar_average_red,auxiliar_average_green, auxiliar_average_blue,auxiliar_alpha).rgba();
                     New_image.setPixel(row+auxi_x,col+auxi_y, new_pixel_value);
                     }
                    }
                }
                }
            }

        ui->label_pic_2->setPixmap(QPixmap::fromImage(New_image).scaled(ui->label_pic_2->width(),ui->label_pic_2->height(),Qt::KeepAspectRatio));


    // Calculate the Gaussian

    }
}

void MainWindow::Send_information_Image(int x_size, int y_size, int depth)
{

}
