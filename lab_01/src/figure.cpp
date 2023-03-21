#include "edges.h"
#include "figure.h"
#include "fileio.h"
#include "points.h"

static bool is_empty_figure(const figure_t &figure)
{
    return ((point_arr_has_empty_data(figure.points)) || (edge_arr_has_empty_data(figure.edges)));
}

figure_t &init_figure(void)
{
    static figure_t figure;

    init_points(figure.points);
    init_edges(figure.edges);

    return figure;
}

error_t free_figure(figure_t &figure)
{
    if (is_empty_figure(figure))
        return NULL_PARAM_ERROR;

    error_t rc = free_points(figure.points);

    if (rc == SUCCESS)
        rc = free_edges(figure.edges);

    return rc;
}

static error_t read_figure(figure_t &figure, file_ptr const f)
{
    if (f == NULL)
        return NULL_PARAM_ERROR;

  error_t rc = read_points(figure.points, f);

    if (rc == SUCCESS)
    {
        rc = read_edges(figure.edges, f);

        if (rc != SUCCESS)
            rc = free_points(figure.points);
    }

    return rc;
}

static error_t fget_figure(figure_t &figure, file_ptr const f)
{
    figure_t tmp_figure;
    error_t rc = read_figure(tmp_figure, f);

    if (rc == SUCCESS)
    {
        free_figure(figure);
        figure = tmp_figure;
    }

    return rc;
}

error_t load_figure(figure_t &figure, const char *file_name)
{
    if (file_name == NULL)
        return NULL_PARAM_ERROR;

    file_ptr f = NULL;
    error_t rc = open_file(f, file_name), rc_close = SUCCESS;

    if (rc == SUCCESS)
    {
        rc = fget_figure(figure, f);
        rc_close = close_file(f);
    }

    if (rc_close != SUCCESS)
        return rc_close;

    return rc;
}

error_t rotate_figure(figure_t &figure, mod_data_t mod_data)
{
    if (is_empty_figure(figure))
        return NULL_PARAM_ERROR;

    return rotate_points(figure.points, mod_data);
}

error_t shift_figure(figure_t &figure, mod_data_t mod_data)
{
    if (is_empty_figure(figure))
        return NULL_PARAM_ERROR;

    return shift_points(figure.points, mod_data);
}

error_t scale_figure(figure_t &figure, mod_data_t mod_data)
{
    if (is_empty_figure(figure))
        return NULL_PARAM_ERROR;

    return scale_points(figure.points, mod_data);
}
