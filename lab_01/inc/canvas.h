#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsView>

#include "data.h"
#include "errors.h"

struct canvas
{
    QGraphicsScene *scene;
    double width;
    double height;
};

struct edge_line
{
    point_t beg_point;
    point_t end_point;
};

using edge_line_t = struct edge_line;
using canvas_t = struct canvas;

error_t clear_canvas(const canvas_t &canvas);
error_t draw_figure(canvas_t &canvas, const figure_t &figure);

#endif // CANVAS_H
