#include <ed/Entity/Graph.hpp>


template<class T_NODE, class T_EDGE>
Graph<T_NODE, T_EDGE>::Graph(const Graph<T_NODE, T_EDGE> &g)
{
    this->edges_=g.edges_;
    this->nodes_=g.nodes_;
    this->visited_ = false;
}

template<class T_NODE, class T_EDGE>
Graph<T_NODE, T_EDGE>::Graph(const std::string &filePath)
{
    this->LoadFromFile(filePath);
    this->visited_ = false;
}

template<class T_NODE, class T_EDGE>
bool Graph<T_NODE, T_EDGE>::LoadFromFile(const std::string &filePath)
{
    return true;
}

template<class T_NODE, class T_EDGE>
const Graph<T_NODE, T_EDGE>& Graph<T_NODE, T_EDGE>::operator=(const Graph<T_NODE, T_EDGE> &rhs)
{
    if (this == &rhs)
        return *new Graph<T_NODE, T_EDGE>;

    this->nodes_=rhs.nodes_;
    this->edges_=rhs.edges_;

    return *this;
}
