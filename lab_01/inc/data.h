#ifndef DATA_H
#define DATA_H

// Points
struct point
{
    double x;
    double y;
    double z;
};

using point_t = struct point;

struct point_arr
{
    int number;
    point_t *data;
};

using point_arr_t = struct point_arr;

// Edges
struct edge
{
    int beg_pind;
    int end_pind;
};

using edge_t = struct edge;

struct arr_edges
{
    int number;
    edge_t *data;
};

using edge_arr_t = struct arr_edges;

// Figure
struct figure
{
    point_arr_t points;
    edge_arr_t edges;
};

using figure_t = struct figure;

enum mod_func_code
{
    SCALE_CODE,
    SHIFT_CODE,
    ROTATE_CODE
};

using mod_func_code_t = enum mod_func_code;

// Data
struct modification_data
{
    double mod_x;
    double mod_y;
    double mod_z;
};

using mod_data_t = struct modification_data;

#endif // DATA_H
