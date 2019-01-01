//
// Created by przemek on 12/27/18.
//

#ifndef GRAPH_BRIDGES_ALGORITHM_H
#define GRAPH_BRIDGES_ALGORITHM_H


#include <istream>
#include "Graph.h"

class Algorithm {
public:
    Algorithm();
    void load_graph(std::istream input);
    void run_algorithm();
private:
    Graph my_graph;
    bool loaded;
};


#endif //GRAPH_BRIDGES_ALGORITHM_H
