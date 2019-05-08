#include <iostream>
#include <string>
#include <vector>
#include <ed/Entity/Graph.hpp>
#include <ed/Algorithm/algo.hpp>


int main()
{
	std::cout << "hello, world\n";
    Graph<std::string, int> graph;

    graph.print();
    std::cout<<"--------------------\n";
    floyd(graph);

    return 0;
}
