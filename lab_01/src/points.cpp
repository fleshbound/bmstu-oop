#include "point.h"
#include "points.h"

void init_points(point_arr_t &points)
{
    points.data = NULL;
    points.number = 0;
}

bool point_arr_has_empty_data(const point_arr_t &points)
{
    return (points.data == NULL);
}

static error_t read_points_number(int &points_number, file_ptr const f)
{
    if (f == NULL)
        return NULL_PARAM_ERROR;

    error_t rc = read_integer(points_number, f);

    if ((rc == SUCCESS) && (points_number <= 0))
        rc = POINTS_NUMBER_ERROR;

    return rc;
}

error_t alloc_points_data(point_t **data, const int &number)
{
    if (data == NULL)
        return NULL_PARAM_ERROR;

    if (number <= 0)
        return POINTS_NUMBER_ERROR;

    error_t rc = SUCCESS;
    point_t *tmp = (point_t *) calloc(number, sizeof(point_t));

    if (tmp == NULL)
        rc = MEMORY_ALLOCATION_ERROR;

    if (rc == SUCCESS)
        *data = tmp;

    return SUCCESS;
}

static error_t read_points_data(point_t **data, const int &number, file_ptr const f)
{
    if ((f == NULL) || (data == NULL) || (*data == NULL))
        return NULL_PARAM_ERROR;

    if (number <= 0)
        return POINTS_NUMBER_ERROR;

    error_t rc = SUCCESS;

    for (int i = 0; (rc == SUCCESS) && (i < number); i++)
        rc = read_point((*data)[i], f);

    return rc;
}

static error_t free_points_data(point_t **data)
{
    if ((data == NULL) || (*data == NULL))
        return NULL_PARAM_ERROR;

    free(*data);

    return SUCCESS;
}

error_t free_points(point_arr_t &points)
{
    points.number = 0;

    return free_points_data(&points.data);
}

/* Reading all figure points */
error_t read_points(point_arr_t &points, file_ptr const f)
{
    if (f == NULL)
        return NULL_PARAM_ERROR;

    init_points(points);
    error_t rc = read_points_number(points.number, f);

    if (rc == SUCCESS)
        rc = alloc_points_data(&points.data, points.number);

    if (rc == SUCCESS)
    {
        rc = read_points_data(&points.data, points.number, f);

        if (rc == READ_DATA_ERROR)
            free_points_data(&points.data);
    }

    return rc;
}

error_t rotate_points(point_arr_t &points, mod_data_t mod_data)
{
    if (points.data == NULL)
        return NULL_PARAM_ERROR;

    if (points.number <= 0)
        return POINTS_NUMBER_ERROR;

    for (int i = 0; i < points.number; i++)
        rotate_point(points.data[i], mod_data);

    return SUCCESS;
}

error_t scale_points(point_arr_t &points, mod_data_t mod_data)
{
    if (points.data == NULL)
        return NULL_PARAM_ERROR;

    if (points.number <= 0)
        return POINTS_NUMBER_ERROR;

    for (int i = 0; i < points.number; i++)
        scale_point(points.data[i], mod_data);

    return SUCCESS;
}


error_t shift_points(point_arr_t &points, mod_data_t mod_data)
{
    if (points.data == NULL)
        return NULL_PARAM_ERROR;

    if (points.number <= 0)
        return POINTS_NUMBER_ERROR;

    for (int i = 0; i < points.number; i++)
        shift_point(points.data[i], mod_data);

    return SUCCESS;
}
