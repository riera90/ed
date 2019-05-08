#ifndef _ED_ALGORITHM_ALGO_
#define _ED_ALGORITHM_ALGO_

#include <iostream>

#include <ed/Entity/Graph.hpp>

template<class T_NODE, class T_EDGE>
void floyd(const Graph<T_NODE, T_EDGE> &graph)
{
    std::vector<std::vector<T_EDGE>> matrix = graph.getEdges();
    std::vector<std::vector<T_EDGE>> path;
    path.resize(matrix.size());
    for (int i = 0; i < matrix.size(); ++i) {
        path[i].resize(matrix.size());
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


    for (auto &row : path) {
        for (auto &item : row) {
                    std::cout << item <<", ";
        }
        std::cout << "\n";
    }
}


#endif
