#ifndef _ED_ALGORITHM_ALGO_
#define _ED_ALGORITHM_ALGO_

#include <iostream>

#include <ed/Entity/Graph.hpp>

template<class T_NODE, class T_EDGE>
std::vector<std::vector<T_EDGE>> floyd(const Graph<T_NODE, T_EDGE> &graph)
{
    std::vector<std::vector<T_EDGE>> matrix = graph.getEdges();
    for (int l = 0; l < matrix.size(); ++l) {
        matrix[l][l] = 0;
    }

    for (int k = 0; k < matrix.size(); ++k) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j]){
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }

    return matrix;
}

template<class T_NODE, class T_EDGE>
std::vector<std::vector<T_EDGE>> floyd_warshall(const Graph<T_NODE, T_EDGE> &graph)
{
    std::vector<std::vector<T_EDGE>> matrix = graph.getEdges();
    for (int l = 0; l < matrix.size(); ++l) {
        matrix[l][l] = 0;
    }
    std::vector<std::vector<T_EDGE>> path;
    path.resize(matrix.size());
    for (int i = 0; i < matrix.size(); ++i) {
        path[i].resize(matrix.size());
    }

    for (int i = 0; i < path.size(); ++i) {
        for (int j = 0; j < path[i].size(); ++j) {
            path[i][j] = -1;
        }
    }

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

    return path;
}


template<class T_NODE, class T_EDGE>
std::vector<T_NODE> getPathFromFloyd(const Graph<T_NODE, T_EDGE> &graph, std::string origin, std::string target)
{
    // get the row of the origin
    std::vector<std::vector<int>> floydWarshall_matrix = floyd_warshall(graph);
    std::cout << "size of matrix: "<<floydWarshall_matrix.size()<<"x"<<floydWarshall_matrix[0].size()<<"\n";
    std::vector<int> origin_row = floydWarshall_matrix[graph.getEdgeIndex(origin)];
    std::cout << "size of row: "<<origin_row.size()<<"\n";


    for (auto & item : origin_row){
        std::cout << item<< " ";
    }
    std::cout <<"\n";

    std::vector<T_NODE> path;
    bool found = false;
    int index = graph.getEdgeIndex(target);

    path.push_back(target);

    while ( !found ) {
        std::cout << "it index:"<<index<<"\n";
        if (origin_row[index] == -1){
            std::cout << "finish!\n";
            found = true;
            path.push_back(origin);
        }else{
            std::cout << "appending no" << index << "\n";
            std::cout << "\t in string:" << graph.getNodeFromIndex(index) << "\n";

            index = origin_row[index];
            path.push_back(graph.getNodeFromIndex(index));
        }

    }

    return path;
}

#endif
