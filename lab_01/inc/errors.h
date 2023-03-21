#ifndef ERRORS_H
#define ERRORS_H

#include <QMessageBox>

enum error_code
{
    SUCCESS,
    FILE_OPEN_ERROR,
    FILE_CLOSE_ERROR,
    READ_DATA_ERROR,
    MEMORY_ALLOCATION_ERROR,
    POINTS_NUMBER_ERROR,
    EDGES_NUMBER_ERROR,
    CANVAS_ERROR,
    SCALE_COEF_ERROR,
    FIGURE_NOT_LOADED_ERROR,
    UNKNOWN_COMMAND_ERROR,
    NULL_PARAM_ERROR,
    NONNULL_PARAM_ERROR
};

using error_t = enum error_code;

void show_error_message(const error_t &error_code);

#endif // ERRORS_H
