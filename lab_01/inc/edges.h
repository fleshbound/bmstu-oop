#ifndef EDGES_H
#define EDGES_H

#include "data.h"
#include "errors.h"
#include "fileio.h"

error_t read_edges(edge_arr_t &edges, file_ptr const f);
error_t free_edges(edge_arr_t &edges);
void init_edges(edge_arr_t &edges);

#endif // EDGES_H
