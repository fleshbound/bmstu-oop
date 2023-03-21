#ifndef ACTION_H
#define ACTION_H

#include "canvas.h"
#include "data.h"
#include "errors.h"

enum action_code
{
    SHIFT_FIGURE,
    ROTATE_FIGURE,
    SCALE_FIGURE,
    QUIT,
    LOAD_FIGURE,
    DRAW_FIGURE
};

using action_code_t = enum action_code;

struct request
{
    action_code_t action_type;

    const char *file_name;
    mod_data_t shift_data;
    mod_data_t rotate_data;
    mod_data_t scale_data;
    canvas_t canvas;
};

using request_t = struct request;

error_t handle_action(request_t &request);

#endif // ACTION_H
