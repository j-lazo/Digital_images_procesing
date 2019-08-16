#include "brigthnes_dialog.h"
#include "ui_brigthnes_dialog.h"
#include "mainwindow.h"

Brigthnes_Dialog::Brigthnes_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Brigthnes_Dialog)
{
    ui->setupUi(this);
}

Brigthnes_Dialog::~Brigthnes_Dialog()
{
    delete ui;
}

void Brigthnes_Dialog::on_horizontalSlider_sliderMoved(int position)
{
    /*QImage gray = image;
    qDebug() << "you just clicked ok";
    int image_width = gray.width();
    int image_height = gray.height();
    int img_dept = gray.depth();
    //out <<img_dept <<endl;

    //out << ui->label_pic_2->width() << ui->label_pic_2->height()<< endl;
    //out << image_width << ',' << image_height<<endl;

    QImage gris(img_dept, img_dept, QImage::Format_Mono);
                //Format_RGB888);

    //out<< gris.width() << gris.height() <<endl;

    //int planes=gray.bitPlaneCount();
    //out <<planes<<endl;

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
    MainWindow.ui->label_pic_2->setPixmap(QPixmap::fromImage(gray).scaled(ui->label_pic_2->width(),ui->label_pic_2->height(),Qt::KeepAspectRatio));
    */
}

