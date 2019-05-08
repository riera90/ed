#ifndef _ED_GRAPH_
#define _ED_GRAPH_

#include <string>
#include <vector>

template<class T_NODE, class T_EDGE>
class Graph
{
private:
    std::vector<T_NODE> nodes_;
    std::vector<std::vector<T_EDGE>> edges_;
    bool visited_{};

public:
    Graph(): visited_(false){};
    Graph(const Graph<T_NODE, T_EDGE> &g);
    Graph(const std::string &filePath);

    ~Graph(){};



    bool LoadFromFile(const std::string &filePath);

    const Graph<T_NODE, T_EDGE>& operator=(const Graph<T_NODE, T_EDGE> &rhs);
};


#endif