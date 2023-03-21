#include "edges.h"

static error_t read_edges_number(int &edges_number, file_ptr const f)
{
    if (f == NULL)
        return NULL_PARAM_ERROR;

    error_t rc = read_integer(edges_number, f);

    if ((rc == SUCCESS) && (edges_number <= 0))
        rc = EDGES_NUMBER_ERROR;

    return rc;
}

bool edge_arr_has_empty_data(const edge_arr_t &edges)
{
    return (edges.data == NULL);
}

static error_t free_edges_data(edge_t **data)
{
    if ((data == NULL) || (*data == NULL))
        return NULL_PARAM_ERROR;

    free(*data);

    return SUCCESS;
}

void init_edges(edge_arr_t &edges)
{
    edges.data = NULL;
    edges.number = 0;
}

static error_t alloc_edges_data(edge_t **data, const int &number)
{
    if (number <= 0)
        return EDGES_NUMBER_ERROR;

    error_t rc = SUCCESS;
    edge_t *tmp = (edge_t *) calloc(number, sizeof(edge_t));

    if (tmp == NULL)
        rc = MEMORY_ALLOCATION_ERROR;

    if (rc == SUCCESS)
        *data = tmp;

    return rc;
}

static error_t read_edge(edge_t &edge, file_ptr const f)
{
    if (f == NULL)
        return NULL_PARAM_ERROR;

    error_t rc = read_integer(edge.beg_pind, f);

    if (rc == SUCCESS)
        rc = read_integer(edge.end_pind, f);

    return rc;
}

static error_t read_edges_data(edge_t **data, int &number, file_ptr const f)
{
    if ((f == NULL) || (data == NULL) || (*data == NULL))
        return NULL_PARAM_ERROR;

    if (number <= 0)
        return EDGES_NUMBER_ERROR;

    error_t rc = SUCCESS;

    for (int i = 0; (rc == SUCCESS) && (i < number); i++)
        rc = read_edge((*data)[i], f);

    return rc;
}

error_t read_edges(edge_arr_t &edges, file_ptr const f)
{
    if (f == NULL)
        return NULL_PARAM_ERROR;

    init_edges(edges);
    error_t rc = read_edges_number(edges.number, f);

    if (rc == SUCCESS)
        rc = alloc_edges_data(&edges.data, edges.number);

    if (rc == SUCCESS)
    {
        rc = read_edges_data(&edges.data, edges.number, f);

        if (rc == READ_DATA_ERROR)
            free_edges_data(&edges.data);
    }

    return rc;
}

error_t free_edges(edge_arr_t &edges)
{
    edges.number = 0;

    return free_edges_data(&edges.data);
}
