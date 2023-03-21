#include "fileio.h"

error_t open_file(file_ptr &f, const char *file_name)
{
    if (file_name == NULL)
        return NULL_PARAM_ERROR;

    if (f != NULL)
        return NONNULL_PARAM_ERROR;

    error_t rc = SUCCESS;
    f = fopen(file_name, "r");

    if (f == NULL)
        rc = FILE_OPEN_ERROR;

    return rc;
}

error_t close_file(file_ptr &f)
{
    if (f == NULL)
        return NULL_PARAM_ERROR;

    if (fclose(f) == EOF)
        return FILE_CLOSE_ERROR;

    return SUCCESS;
}

error_t read_double(double &n, file_ptr const f)
{
    if (f == NULL)
        return NULL_PARAM_ERROR;

    error_t rc = SUCCESS;

    if (fscanf(f, "%lf", &n) != READ_COUNT)
        rc = READ_DATA_ERROR;

    return rc;
}

error_t read_integer(int &n, file_ptr const f)
{
    if (f == NULL)
        return NULL_PARAM_ERROR;

    error_t rc = SUCCESS;

    if (fscanf(f, "%d", &n) != READ_COUNT)
        rc = READ_DATA_ERROR;

    return rc;
}
