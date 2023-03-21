#include "canvas.h"
#include "points.h"

static bool has_empty_scene(const canvas_t &canvas)
{
    return canvas.scene == NULL;
}

error_t clear_canvas(const canvas_t &canvas)
{
    if (has_empty_scene(canvas))
        return CANVAS_ERROR;

    canvas.scene->clear();

    return SUCCESS;
}

static error_t draw_line(const canvas_t &canvas, const point_t p1, const point_t p2)
{
    if (has_empty_scene(canvas))
        return CANVAS_ERROR;

    canvas.scene->addLine(p1.x, p1.y, p2.x, p2.y, QPen(Qt::white, 2));

    return SUCCESS;
}

static point_t get_canvas_coordinates(point_t point, const canvas_t &canvas)
{
    point.x += canvas.width / 2;
    point.y += canvas.height / 2;

    return point;
}

static edge_line_t init_edge_line(void)
{
    edge_line_t line = {{0, 0, 0}, {0, 0, 0}};

    return line;
}

// get line verteces
static edge_line_t get_edge_line(const edge_t &edge, const point_t *point_data)
{
    edge_line_t edge_line = init_edge_line();

    if (point_data != NULL)
    {
        edge_line.beg_point = point_data[edge.beg_pind];
        edge_line.end_point = point_data[edge.end_pind];
    }

    return edge_line;
}

static error_t get_canvas_points(point_arr_t &canvas_points, const canvas_t &canvas, const point_arr_t &points)
{
    if (points.data == NULL)
        return NULL_PARAM_ERROR;

    if (points.number == 0)
        return POINTS_NUMBER_ERROR;

    init_points(canvas_points);
    canvas_points.number = points.number;
    error_t rc = alloc_points_data(&canvas_points.data, canvas_points.number);

    for (int i = 0; (rc == SUCCESS) && (i < points.number); i++)
        canvas_points.data[i] = get_canvas_coordinates(points.data[i], canvas);

    return rc;
}

static error_t draw_edges(const canvas_t &canvas, const point_arr_t &canvas_points, const edge_arr_t &edges)
{
    if ((canvas_points.data == NULL) || (edges.data == NULL))
        return NULL_PARAM_ERROR;

    if (has_empty_scene(canvas))
        return CANVAS_ERROR;

    edge_line_t curr_edge_line;
    error_t rc = SUCCESS;

    for (int i = 0; (rc == SUCCESS) && (i < edges.number); i++)
    {
        curr_edge_line = get_edge_line(edges.data[i], canvas_points.data);
        rc = draw_line(canvas, curr_edge_line.beg_point, curr_edge_line.end_point);
    }

    return rc;
}

error_t draw_figure(canvas_t &canvas, const figure_t &figure)
{
    if (has_empty_scene(canvas))
        return CANVAS_ERROR;

    error_t rc = clear_canvas(canvas);
    point_arr_t canvas_points;

    if (rc == SUCCESS)
        rc = get_canvas_points(canvas_points, canvas, figure.points);

    if (rc == SUCCESS)
        rc = draw_edges(canvas, canvas_points, figure.edges);

    if (rc == SUCCESS)
        rc = free_points(canvas_points);

    return rc;
}
