//
// Created by przemek on 12/27/18.
//

#ifndef GRAPH_BRIDGES_GRAPH_H
#define GRAPH_BRIDGES_GRAPH_H

#include <zconf.h>
#include <list>
#include <vector>

class Graph
{
private:
    class Node
    {
    public:
        Node() : visited(false), processed(false) {}

        std::list<Node*> adjacent_nodes;

        bool visited;
        bool processed;

        u_int value;
    };
public:
    Graph();
    explicit Graph(u_int count);
    void add_edge(u_int node1, u_int node2);
    std::list<std::pair<u_int , u_int>> seek_for_bridge();
    u_int get_size();
    Node * get_node(u_int n);
    u_int test();
private:
    u_int size;
    std::vector<Node> nodes;

    void visit(Node *start);
    u_int check_count(Node *start);
    void check_node(std::list<std::pair<u_int , u_int>> *bridges, Node *node);
};


#endif //GRAPH_BRIDGES_GRAPH_H
