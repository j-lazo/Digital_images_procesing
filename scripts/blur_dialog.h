#ifndef BLUR_DIALOG_H
#define BLUR_DIALOG_H

#include <QDialog>

namespace Ui {
class Blur_Dialog;
}

class Blur_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Blur_Dialog(QWidget *parent = 0);
    ~Blur_Dialog();

signals:
    void sendBlur_information(QString typeof_blur, int value_1, int value_2);

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_radioButton_clicked(bool checked);

    void on_radioButton_2_clicked(bool checked);

    void on_radioButton_3_clicked(bool checked);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_spinBox_3_valueChanged(int arg1);

    void on_spinBox_4_valueChanged(int arg1);

    void on_buttonBox_accepted();

private:
    Ui::Blur_Dialog *ui;
};

#endif // BLUR_DIALOG_H
