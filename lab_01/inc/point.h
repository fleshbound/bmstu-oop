#ifndef POINT_H
#define POINT_H

#include "data.h"
#include "errors.h"
#include "fileio.h"

error_t read_point(point_t &point, file_ptr f);
void shift_point(point_t &point, mod_data_t mod_data);
void rotate_point(point_t &point, mod_data_t mod_data);
void scale_point(point_t &point, mod_data_t mod_data);

#endif // POINT_H
