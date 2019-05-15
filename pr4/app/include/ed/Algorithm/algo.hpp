#ifndef _ED_ALGORITHM_ALGO_
#define _ED_ALGORITHM_ALGO_

#include <iostream>

#include <ed/Entity/Graph.hpp>

/**
 * Floyd algorithm over a Graph
 * @param graph: Graph to aply floyd
 * @return Floyd minimun distance matrix
 */
template<class T_NODE, class T_EDGE>
std::vector<std::vector<T_EDGE>> floyd(const Graph<T_NODE, T_EDGE> &graph)
{
    // gets a copy of the edges of the given graph
    std::vector<std::vector<T_EDGE>> matrix = graph.getEdges();
    // sets the diagonal to zero
    for (int l = 0; l < matrix.size(); ++l) {
        matrix[l][l] = 0;
    }
    // floyd algorithm
    for (int k = 0; k < matrix.size(); ++k) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j]){
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }

    // return the min distances matrix
    return matrix;
}


/**
 * Floyd-Warshall Algorithm over a Graph
 * @param graph : Graph to aply the algoritm
 * @return path matrix (also seen as next matrix)
 */
template<class T_NODE, class T_EDGE>
std::vector<std::vector<T_EDGE>> floyd_warshall(const Graph<T_NODE, T_EDGE> &graph)
{
    // gets a copy of the edges of the given graph
    std::vector<std::vector<T_EDGE>> matrix = graph.getEdges();
    // sets the diagonal to zero
    for (int l = 0; l < matrix.size(); ++l) {
        matrix[l][l] = 0;
    }

    // reserves the memory for the path/next matrix
    std::vector<std::vector<T_EDGE>> path;
    path.resize(matrix.size());
    for (int i = 0; i < matrix.size(); ++i) {
        path[i].resize(matrix.size());
    }

    // sets the next matrix to -1 (no connection)
    for (int i = 0; i < path.size(); ++i) {
        for (int j = 0; j < path[i].size(); ++j) {
            path[i][j] = -1;
        }
    }

    // Floyd Warshall algorithm
    for (int k = 0; k < matrix.size(); ++k) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j]){
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    path[i][j] = k;
                }
            }
        }
    }

    // return the path matrix
    return path;
}

/**
 * Path constructor from origin to target in graph ussing the Floyd-Warshall algorithm
 * @param graph : Graph to get the path from
 * @param origin : origin node
 * @param target  : target node
 * @return vector of T_NODE from origin to target
 */
template<class T_NODE, class T_EDGE>
std::vector<T_NODE> getPathFromFloyd(const Graph<T_NODE, T_EDGE> &graph, std::string origin, std::string target)
{
    // gets the Floyd-Warshall path matrix of the given graph
    std::vector<std::vector<int>> floydWarshall_matrix = floyd_warshall(graph);

    // get the row of the origin node from the matrix
    std::vector<int> origin_row = floydWarshall_matrix[graph.getEdgeIndex(origin)];

    // initializes the auxiliary variables
    std::vector<T_NODE> path;
    bool found = false;
    int index = graph.getEdgeIndex(target);

    // pushes back the target to the vector as the head
    path.push_back(target);

    while ( !found ) {
        // checks if the actual node is the origin
        if (origin_row[index] == -1){
            // sets fund to true and pushes the origin into the vector
            found = true;
            path.push_back(origin);
        }else{
            // get the next node index and and pushes the node from that index into the vector
            index = origin_row[index];
            path.push_back(graph.getNodeFromIndex(index));
        }

    }
    // returns the vector of nodes
    return path;
}

#endif
