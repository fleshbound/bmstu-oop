#include "errors.h"

#define FILE_OPEN_ERROR_STR "There was an error while opening the file."
#define FILE_CLOSE_ERROR_STR "There was an error while closing the file."
#define READ_DATA_ERROR_STR "There was an error while reading the file."
#define MEMORY_ALLOCATION_ERROR_STR "There was an error while memory allocation."
#define POINTS_NUMBER_ERROR_STR "Number of points must be positive."
#define EDGES_NUMBER_ERROR_STR "Number of edges must be positive."
#define CANVAS_ERROR_STR "There was an error while drawing the figure."
#define SCALE_COEF_ERROR_STR "Scale coefficients must be a nonzero numbers."
#define FIGURE_NOT_LOADED_ERROR_STR "Figure must be loaded."
#define UNKNOWN_COMMAND_ERROR_STR "Unknown command"
#define NONNULL_PARAM_ERROR_STR "There was an error while calling to function with not NULL parameters"
#define NULL_PARAM_ERROR_STR "There was an error whule calling to function with NULL parameters"
#define UNKNOWN_ERROR_STR "Unknown error"

void show_error_message(const error_t &error_code)
{
    if (error_code == FILE_OPEN_ERROR)
        QMessageBox::critical(NULL, "Error", FILE_OPEN_ERROR_STR);
    else if (error_code == FILE_CLOSE_ERROR)
        QMessageBox::critical(NULL, "Error", FILE_CLOSE_ERROR_STR);
    else if (error_code == READ_DATA_ERROR)
        QMessageBox::critical(NULL, "Error", READ_DATA_ERROR_STR);
    else if (error_code == MEMORY_ALLOCATION_ERROR)
        QMessageBox::critical(NULL, "Error", MEMORY_ALLOCATION_ERROR_STR);
    else if (error_code == POINTS_NUMBER_ERROR)
        QMessageBox::critical(NULL, "Error", POINTS_NUMBER_ERROR_STR);
    else if (error_code == EDGES_NUMBER_ERROR)
        QMessageBox::critical(NULL, "Error", EDGES_NUMBER_ERROR_STR);
    else if (error_code == CANVAS_ERROR)
        QMessageBox::critical(NULL, "Error", CANVAS_ERROR_STR);
    else if (error_code == SCALE_COEF_ERROR)
        QMessageBox::critical(NULL, "Error", SCALE_COEF_ERROR_STR);
    else if (error_code == FIGURE_NOT_LOADED_ERROR)
        QMessageBox::critical(NULL, "Error", FIGURE_NOT_LOADED_ERROR_STR);
    else if (error_code == UNKNOWN_COMMAND_ERROR)
        QMessageBox::critical(NULL, "Error", UNKNOWN_COMMAND_ERROR_STR);
    else if (error_code == NONNULL_PARAM_ERROR)
        QMessageBox::critical(NULL, "Error", NONNULL_PARAM_ERROR_STR);
    else if (error_code == NULL_PARAM_ERROR)
        QMessageBox::critical(NULL, "Error", NULL_PARAM_ERROR_STR);
    else
        QMessageBox::critical(NULL, "Error", UNKNOWN_ERROR_STR);
}
