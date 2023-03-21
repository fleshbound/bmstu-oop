#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "errors.h"

#define WIN_HEIGHT 618
#define WIN_WIDTH 655

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    error_t draw_figure(void);

    void on_pushButton_scale_clicked();

    void on_pushButton_shift_clicked();

    void on_pushButton_rotate_clicked();

    void on_pushButton_load_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
