#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
