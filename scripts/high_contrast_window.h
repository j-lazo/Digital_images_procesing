#ifndef HIGH_CONTRAST_WINDOW_H
#define HIGH_CONTRAST_WINDOW_H

#include <QDialog>

namespace Ui {
class High_contrast_window;
}

class High_contrast_window : public QDialog
{
    Q_OBJECT

public:
    explicit High_contrast_window(QWidget *parent = 0);
    ~High_contrast_window();

signals:
    void sendContrast_value(int threshold_value, bool inverse);

private slots:

    void on_horizontalSlider_valueChanged(int value);
    void on_spinBox_valueChanged(int arg1);
    void on_checkBox_clicked();

private:
    Ui::High_contrast_window *ui;
};

#endif // HIGH_CONTRAST_WINDOW_H
