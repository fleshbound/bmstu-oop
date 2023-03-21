#ifndef POINTS_H
#define POINTS_H

#include "data.h"
#include "errors.h"
#include "fileio.h"

error_t read_points(point_arr_t &points, file_ptr const f);
error_t free_points(point_arr_t &points);
error_t scale_points(point_arr_t &points, mod_data_t mod_data);
error_t shift_points(point_arr_t &points, mod_data_t mod_data);
error_t rotate_points(point_arr_t &points, mod_data_t mod_data);
void init_points(point_arr_t &points);
error_t alloc_points_data(point_t **data, const int &number);

#endif // POINTS_H
