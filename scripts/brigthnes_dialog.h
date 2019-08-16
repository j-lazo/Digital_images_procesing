#ifndef BRIGTHNES_DIALOG_H
#define BRIGTHNES_DIALOG_H

#include <QDialog>

namespace Ui {
class Brigthnes_Dialog;
}

class Brigthnes_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Brigthnes_Dialog(QWidget *parent = 0);
    ~Brigthnes_Dialog();

private slots:
    void on_horizontalSlider_sliderMoved(int position);

private:
    Ui::Brigthnes_Dialog *ui;
};

#endif // BRIGTHNES_DIALOG_H
