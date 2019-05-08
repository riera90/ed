#ifndef _ED_GRAPH_
#define _ED_GRAPH_

#include <string>
#include <vector>
#include <iostream>

template<class T_NODE, class T_EDGE>
class Graph
{
private:
    std::vector<T_NODE> nodes_;
    std::vector<std::vector<T_EDGE>> edges_;

public:
    Graph()
    {
        this->nodes_ = {"Almeria","Cadiz","Cordoba","Granada","Huelva","Jaen","Malaga","Sevilla"};
        this->edges_ =
        {
            {32000, 32000, 32000, 166, 32000, 228, 219, 32000},
            {32000 ,32000 ,32000 ,32000 ,219 ,32000 ,265 ,125},
            {32000 ,32000 ,32000 ,166 ,32000 ,104 ,187 ,138},
            {166 ,32000 ,166 ,32000 ,32000 ,99 ,129 ,256},
            {32000 ,219 ,32000 ,32000 ,32000 ,32000 ,32000 ,94},
            {228 ,32000 ,104 ,99 ,32000 ,32000 ,209 ,32000},
            {219 ,265 ,187 ,129 ,32000 ,209 ,32000 ,219},
            {32000 ,125 ,138 ,256 ,94 ,32000 ,219 ,320}
        };
    }
    Graph(const Graph<T_NODE, T_EDGE> &g)
    {
        this->edges_=g.edges_;
        this->nodes_=g.nodes_;
    }


    Graph(const std::string &filePath)
    {
        this->LoadFromFile(filePath);
    }

    ~Graph(){}

    std::vector<T_NODE> getNodes() const {return this->nodes_;};
    std::vector<std::vector<T_EDGE>> getEdges() const {return this->edges_;};

    bool LoadFromFile(const std::string &filePath)
    {
        return true;
    }


    const Graph& operator=(const Graph<T_NODE, T_EDGE> &rhs)
    {
        if (this == &rhs)
            return *new Graph<T_NODE, T_EDGE>;

        this->nodes_=rhs.nodes_;
        this->edges_=rhs.edges_;

        return *this;
    }


    void print() {
        for (auto &node : this->getNodes()){
            std::cout << node << ", ";
        }
        std::cout << std::endl;

        for (auto &row : this->getEdges()){
            for (auto &item : row){
                std::cout << item << ", ";
            }
            std::cout << std::endl;
        }
    }
};


#endif