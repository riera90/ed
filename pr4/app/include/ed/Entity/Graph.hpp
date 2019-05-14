#ifndef _ED_GRAPH_
#define _ED_GRAPH_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

template<class T_NODE, class T_EDGE>
class Graph
{
private:
    std::vector<T_NODE> nodes_;
    std::vector<std::vector<T_EDGE>> edges_;

public:
    Graph()
    {
        /*this->nodes_ = {"Almeria","Cadiz","Cordoba","Granada","Huelva","Jaen","Malaga","Sevilla"};
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
        };*/
    }
    Graph(const Graph<T_NODE, T_EDGE> &g)
    {
        this->edges_=g.edges_;
        this->nodes_=g.nodes_;
    }


    Graph(const std::string &nodes_path, const std::string &edges_path)
    {
        this->LoadFromFile(nodes_path, edges_path);
    }

    ~Graph(){}

    void clear(){this->edges_.clear();this->nodes_.clear();};

    std::vector<T_NODE> getNodes() const {return this->nodes_;};
    std::vector<std::vector<T_EDGE>> getEdges() const {return this->edges_;};

    bool LoadFromFile(const std::string &nodes_path, const std::string &edges_path)
    {
        std::ifstream nodes(nodes_path.c_str());
        std::ifstream edges(edges_path.c_str());
        char buffer[1024];
        std::string string_buffer;

        while ( std::getline(nodes, string_buffer) ){
            // pushes the buffer (minus the \n) into the nodes
            this->nodes_.push_back(string_buffer.substr(0,string_buffer.size()-1));
        }
        // the last one does not has a \n
        this->nodes_[this->nodes_.size()-1] = string_buffer;

        int pos, i = 0;
        std::vector<T_EDGE> row;
        T_EDGE value;
        std::string buf;

        while (edges.getline(buffer, 1024, '\n')){
            //std::cout <<"reading line!\n";
            row.clear();
            buf = buffer;
            while (buf.find(' ')!=std::string::npos) {
                //std::cout <<"\treading field!\n";
                value =  atoi(buf.substr(0, buf.find(' ')).c_str()); // that atoi is a little dirty, I know..., but hey, it works ¯\_(ツ)_/¯
                buf =buf.substr(buf.find(' ') + 1, buf.size());
                row.push_back(value);
            }
            //std::cout <<"\treading field!\n";
            value =  atoi(buf.substr(0, buf.find('\n')).c_str());
            row.push_back(value);
            this->edges_.push_back(row);
            i++;
        }

        edges.close();
        nodes.close();
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


    void print() const
    {
        for (auto &node : this->nodes_){
            std::cout << "<" << node << ">\n";
        }


        for (auto &row : this->getEdges()){
            for (auto &item : row){
                std::cout << item << ", ";
            }
            std::cout << std::endl;
        }
    }


    int getEdgeIndex(T_NODE _node) const
    {
        for (int i = 0; i < this->nodes_.size(); ++i) {
            if (_node == this->nodes_[i])
                return i;
        }
        std::cout << "error, node does not exists\n";
        return -1;
    }


    bool contains(T_NODE _node) const
    {
        for (int i = 0; i < this->nodes_.size(); ++i) {
            if (_node == this->nodes_[i])
                return true;
        }
        return false;
    }


    T_NODE getNodeFromIndex(int index) const
    {
        return this->nodes_[index];
    }


    bool existsPath(T_NODE origin, T_NODE target, std::vector<std::vector<T_EDGE>> = *new std::vector<std::vector<T_EDGE>>) const
    {
        return true;
    }
};


#endif