#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "brigthnes_dialog.h"
#include "high_contrast_window.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    void on_pushButton_clicked();

private slots:
    void on_pushButton_clicked();

    void on_actionLoad_Image_triggered();

    void on_actionEscala_de_Grises_triggered();

    void on_actionRed_triggered();

    void on_actionGreen_triggered();

    void on_actionBlue_triggered();

    void on_actionBrillo_triggered();

    void on_actionRed_2_triggered();

    void on_actionGreen_2_triggered();

    void on_actionBlue_2_triggered();

    void on_actionDefault_triggered();

    void on_actionCustom_triggered();

public slots:

    int receiveMessage(int brightness_value);

    void Change_Contrast(float contrast_value);

    void High_Contrast(int value_of_contrast);

    void edit_image(QImage image);



private:
    Ui::MainWindow *ui;
public:
    Brigthnes_Dialog *brightnes_dial;
    High_contrast_window *high_contrast_window;
};

#endif // MAINWINDOW_H
