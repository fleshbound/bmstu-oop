#include "action.h"
#include "figure.h"

error_t handle_action(request_t &request)
{
    error_t rc = SUCCESS;
    static figure_t figure = init_figure();

    if (request.action_type == SHIFT_FIGURE)
        rc = shift_figure(figure, request.shift_data);
    else if (request.action_type == ROTATE_FIGURE)
        rc = rotate_figure(figure, request.rotate_data);
    else if (request.action_type == SCALE_FIGURE)
        rc = scale_figure(figure, request.scale_data);
    else if (request.action_type == QUIT)
        free_figure(figure);
    else if (request.action_type == LOAD_FIGURE)
        rc = load_figure(figure, request.file_name);
    else if (request.action_type == DRAW_FIGURE)
        rc = draw_figure(request.canvas, figure);
    else
        rc = UNKNOWN_COMMAND_ERROR;

    return rc;
}
