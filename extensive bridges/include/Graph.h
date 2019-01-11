//
// Created by przemek on 12/27/18.
//

#ifndef EXTENSIVE_BRIDGES_GRAPH_H
#define EXTENSIVE_BRIDGES_GRAPH_H

#include <list>
#include <vector>
namespace ps_graph
{
    class Graph
    {
    private:
        struct Node
        {
            //public:
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
        //u_int get_size();
        //Node * get_node(u_int n);
        u_int test();
    private:
        u_int size;
        std::vector<Node> nodes;

        void visit(Node *start);
        template<typename F> void visit(Node *start, F action) {
			if (start->processed) return;
			visit(start);
			action(start);
			for(auto &it : start->adjacent_nodes)
			{
              if(!it->visited && !it->processed)
              { //if it's already visited or currently processed we don't need to visit this node
                visit(it);
              }
            }
		}
        u_int check_count(Node *start);
        void check_node(std::list<std::pair<u_int , u_int>> *bridges, Node *node);
    };
}
#endif //EXTENSIVE_BRIDGES_GRAPH_H
