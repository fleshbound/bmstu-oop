#ifndef FIGURE_H
#define FIGURE_H

#include "data.h"
#include "errors.h"

figure_t &init_figure(void);
error_t free_figure(figure_t &figure);
error_t load_figure(figure_t &figure, const char *file_name);
error_t shift_figure(figure_t &figure, mod_data_t mod_data);
error_t rotate_figure(figure_t &figure, mod_data_t mod_data);
error_t scale_figure(figure_t &figure, mod_data_t mod_data);

#endif // FIGURE_H
