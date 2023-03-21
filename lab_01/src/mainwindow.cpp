#include "action.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* Setting scene for drawing */
    QGraphicsScene *scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->graphicsView->setStyleSheet("QGraphicsView {background-color: black}");

    scene->setSceneRect(0, 0, WIN_WIDTH, WIN_HEIGHT);
}

/* Closing window */
MainWindow::~MainWindow()
{
    request_t request;
    request.action_type = QUIT;
    handle_action(request);

    delete ui;
}

/* Drawing current figure */
error_t MainWindow::draw_figure(void)
{
    canvas_t canvas;

    canvas.scene = ui->graphicsView->scene();
    canvas.width = canvas.scene->width();
    canvas.height = canvas.scene->height();

    request_t request;
    request.action_type = DRAW_FIGURE;
    request.canvas = canvas;

    return handle_action(request);
}

/* Scaling figure and drawing it */
void MainWindow::on_pushButton_scale_clicked()
{
    request_t request;
    request.action_type = SCALE_FIGURE;
    request.scale_data.mod_x = ui->doubleSpinBox_kx->value();
    request.scale_data.mod_y = ui->doubleSpinBox_ky->value();
    request.scale_data.mod_z = ui->doubleSpinBox_kz->value();

    error_t rc = handle_action(request);

    if (rc != SUCCESS)
        show_error_message(rc);
    else
    {
        rc = draw_figure();

        if (rc != SUCCESS)
            show_error_message(rc);
    }
}

/* Shifting figure and drawing it */
void MainWindow::on_pushButton_shift_clicked()
{
    request_t request;
    request.action_type = SHIFT_FIGURE;
    request.shift_data.mod_x = ui->doubleSpinBox_dx->value();
    request.shift_data.mod_y = -ui->doubleSpinBox_dy->value();
    request.shift_data.mod_z = ui->doubleSpinBox_dz->value();

    error_t rc = handle_action(request);

    if (rc != SUCCESS)
        show_error_message(rc);
    else
    {
        rc = draw_figure();

        if (rc != SUCCESS)
            show_error_message(rc);
    }
}

/* Rotating figure and drawing it */
void MainWindow::on_pushButton_rotate_clicked()
{
    request_t request;
    request.action_type = ROTATE_FIGURE;
    request.rotate_data.mod_x = ui->doubleSpinBox_angle_x->value();
    request.rotate_data.mod_y = ui->doubleSpinBox_angle_y->value();
    request.rotate_data.mod_z = ui->doubleSpinBox_angle_z->value();

    error_t rc = handle_action(request);

    if (rc != SUCCESS)
        show_error_message(rc);
    else
    {
        rc = draw_figure();

        if (rc != SUCCESS)
            show_error_message(rc);
    }
}

/* Loading figure and drawing it */
void MainWindow::on_pushButton_load_clicked()
{
    request_t request;
    request.action_type = LOAD_FIGURE;
    request.file_name = "C:/Users/valer/qt/oop/lab_01/data.txt";

    error_t rc = handle_action(request);

    if (rc != SUCCESS)
        show_error_message(rc);
    else
    {
        rc = draw_figure();

        if (rc != SUCCESS)
            show_error_message(rc);
    }
}

