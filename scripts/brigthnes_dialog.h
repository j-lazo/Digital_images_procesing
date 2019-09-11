#ifndef BRIGTHNES_DIALOG_H
#define BRIGTHNES_DIALOG_H

#include <QDialog>
#include <QMdiSubWindow>

namespace Ui {
class Brigthnes_Dialog;
}

class Brigthnes_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Brigthnes_Dialog(QWidget *parent = 0);
    ~Brigthnes_Dialog();

public slots:
    void on_horizontalSlider_sliderMoved(int position);


public:
    Ui::Brigthnes_Dialog *ui;

    void on_doubleSpinBox_valueChanged();


signals:
    void sendMessage(int);
    void sendContrast_value(float);

private slots:
    void on_horizontalSlider_2_valueChanged();
    void on_doubleSpinBox_2_valueChanged();
};

#endif // BRIGTHNES_DIALOG_H
