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

    void on_doubleSpinBox_valueChanged(double arg1);


signals:
    void sendMessage(int);
private slots:
    void on_doubleSpinBox_valueChanged(const QString &arg1);
};

#endif // BRIGTHNES_DIALOG_H
