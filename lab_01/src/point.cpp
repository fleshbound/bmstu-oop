#include "math.h"
#include "point.h"

/* Reading point coordinates (x, y, z) */
error_t read_point(point_t &point, file_ptr const f)
{
    if (f == NULL)
        return NULL_PARAM_ERROR;

    error_t rc = SUCCESS;
    rc = read_double(point.x, f);

    if (rc == SUCCESS)
        rc = read_double(point.y, f);

    if (rc == SUCCESS)
    {
        point.y *= -1;
        rc = read_double(point.z, f);
    }

    return rc;
}

void shift_point(point_t &point, mod_data_t mod_data)
{
    point.x += mod_data.mod_x;
    point.y += mod_data.mod_y;
    point.z += mod_data.mod_z;
}

static void yz_rotate_point(point_t &point, const double angle)
{
    double curr_cos = get_cos(angle);
    double curr_sin = get_sin(angle);
    double tmp_y = point.y;

    point.y = point.y * curr_cos + point.z * curr_sin;
    point.z = -tmp_y * curr_sin + point.z * curr_cos;
}

static void xz_rotate_point(point_t &point, const double angle)
{
    double curr_cos = get_cos(angle);
    double curr_sin = get_sin(angle);
    double tmp_x = point.x;

    point.x = point.x * curr_cos + point.z * curr_sin;
    point.z = -tmp_x * curr_sin + point.z * curr_cos;
}

static void xy_rotate_point(point_t &point, const double angle)
{
    double curr_cos = get_cos(angle);
    double curr_sin = get_sin(angle);
    double tmp_x = point.x;

    point.x = point.x * curr_cos + point.y * curr_sin;
    point.y = -tmp_x * curr_sin + point.y * curr_cos;
}

void rotate_point(point_t &point, mod_data_t mod_data)
{
    yz_rotate_point(point, mod_data.mod_x);
    xz_rotate_point(point, mod_data.mod_y);
    xy_rotate_point(point, mod_data.mod_z);
}

void scale_point(point_t &point, mod_data_t mod_data)
{
    point.x *= mod_data.mod_x;
    point.y *= mod_data.mod_y;
    point.z *= mod_data.mod_z;
}
