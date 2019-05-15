#ifndef _ED_GRAPH_
#define _ED_GRAPH_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

/**
 * Graph class
 *
 * Full header definition
 *
 * Implemented with two vectors of the std library, one for nodes and a double vector for the edges
 *
 * @tparam T_NODE
 * @tparam T_EDGE
 */
template<class T_NODE, class T_EDGE>
class Graph
{
private:
    std::vector<T_NODE> nodes_;
    std::vector<std::vector<T_EDGE>> edges_;

public:
    /**
     * Default builder, creates a empty graph
     */
    Graph() {};

    /**
     * Copy contructor
     * @param g: Graph to copy from
     */
    Graph(const Graph<T_NODE, T_EDGE> &g)
    {
        this->edges_=g.edges_;
        this->nodes_=g.nodes_;
    }

    /**
     * Contructor from graph files
     * @param nodes_path: path to nodes file
     * @param edges_path: path to edges file
     */
    Graph(const std::string &nodes_path, const std::string &edges_path)
    {
        this->LoadFromFile(nodes_path, edges_path);
    }

    /**
     * Destructor
     */
    ~Graph(){};

    /**
     * Clears the Graph (Both  edges and nodes)
     */
    void clear(){this->edges_.clear();this->nodes_.clear();};

    /**
     * gets the nodes of the graph
     * @return vector of T_NODE (vector of std)
     */
    std::vector<T_NODE> getNodes() const {return this->nodes_;};

    /**
     * Gets the edges of the Graph (dense matrix)
     * @return matrix of T_EDGE (vectors of std)
     */
    std::vector<std::vector<T_EDGE>> getEdges() const {return this->edges_;};

    /**
     * Loader of Graph from files
     * @param nodes_path: string containing the path to the nodes file
     * @param edges_path: string containing the path to the edges file
     * @return Boolean: true if the load was successful
     */
    bool LoadFromFile(const std::string &nodes_path, const std::string &edges_path)
    {
        // opens both files into streams
        std::ifstream nodes(nodes_path.c_str());
        std::ifstream edges(edges_path.c_str());

        // checks if the files are open
        if ( !nodes.is_open() )
            return false;

        if ( !edges.is_open() )
            return false;

        // creates a, auxiliary buffer to read each line
        std::string buffer;

        // reads the nodes
        while ( std::getline(nodes, buffer) ){
            // pushes the buffer (minus the \n) into the nodes
            this->nodes_.push_back(buffer.substr(0,buffer.size()-1));
        }
        // the last one does not has a \n, so overwrite it with the correct value
        this->nodes_[this->nodes_.size()-1] = buffer;

        // lets read the edges
        // creates the auxiliary variables (position in the buffer, row of edges for inserting into matrix and value to insert into row)
        int pos;
        std::vector<T_EDGE> row;
        T_EDGE value;

        // while there are lines, read
        while ( std::getline(edges, buffer) ){
            // clears the row from the previous iteration
            row.clear();
            // cuts the individual values of the line and pushes it into the row
            while (buffer.find(' ')!=std::string::npos) {
                value = atoi(buffer.substr(0, buffer.find(' ')).c_str()); // that atoi is a little spaghetti, I know..., but hey, it works ¯\_(ツ)_/¯
                buffer =buffer.substr(buffer.find(' ') + 1, buffer.size());
                row.push_back(value);
            }
            // push the last value into the row
            value = atoi(buffer.substr(0, buffer.find('\n')).c_str());
            row.push_back(value);

            // push the row into the matrix
            this->edges_.push_back(row);
        }

        // closes the streams
        edges.close();
        nodes.close();

        // return true as the process was successful
        return true;
    }

    /**
     * assignation operator
     * @param rhs : Graph to copy from
     * @return actualized Graph
     */
    const Graph& operator=(const Graph<T_NODE, T_EDGE> &rhs)
    {
        if (this == &rhs)
            return *new Graph<T_NODE, T_EDGE>;

        this->nodes_=rhs.nodes_;
        this->edges_=rhs.edges_;

        return *this;
    }

    /**
     * debug function
     *
     * dumps the memory of the Graph
     */
    void dump() const
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

    /**
     * get the edge from its value
     * @param _node: T_NODE
     * @return index of given node
     */
    int getEdgeIndex(T_NODE _node) const
    {
        for (int i = 0; i < this->nodes_.size(); ++i) {
            if (_node == this->nodes_[i])
                return i;
        }
        return -1;
    }

    /**
     * logical observator for node existance
     * @param _node : T_NODE to check for in the Graph
     * @return Logical: true if it is found in the Graph, false elseways
     */
    bool contains(T_NODE _node) const
    {
        for (int i = 0; i < this->nodes_.size(); ++i) {
            if (_node == this->nodes_[i])
                return true;
        }
        return false;
    }

    /**
     * Observator of node by its index
     * @param index : index of node
     * @return T_NODE: node with given index
     */
    T_NODE getNodeFromIndex(int index) const
    {
        if ( index >= this->nodes_.size() )
            return * new T_NODE;

        return this->nodes_[index];
    }

    // TODO: finish this function.
    /**
     * Logical observator for path existance in the Graph betwen two nodes
     * @param origin : T_NODE node of origin
     * @param target : T_NODE target node
     * @return Logica: true if some path exists, false elseway
     */
    bool existsPath(T_NODE origin, T_NODE target, std::vector<std::vector<T_EDGE>> = *new std::vector<std::vector<T_EDGE>>) const
    {
        return true;
    }
};


#endif