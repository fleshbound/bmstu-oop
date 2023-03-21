#ifndef FILEIO_H
#define FILEIO_H

/* Wrap-functions for working with file */

#include <cstdio>
#include "errors.h"

#define READ_COUNT 1

using file_ptr = FILE *;

error_t open_file(file_ptr &f, const char *file_name);
error_t close_file(file_ptr &f);
error_t read_double(double &n, file_ptr const f);
error_t read_integer(int &n, file_ptr const f);

#endif // FILEIO_H
