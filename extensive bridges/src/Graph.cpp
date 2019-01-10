//
// Created by przemek on 12/27/18.
//

#include <stdexcept>
#include "../include/Graph.h"
namespace ps_graph
{
    Graph::Graph() :size(0)
    {}

    Graph::Graph(u_int count)
    {
      nodes.resize(count);
      u_int i = 0;
      for(auto &it : nodes)
      {
        it.value = i++;
      }
      size = count;
    }

    void Graph::add_edge(u_int node1, u_int node2)
    {
      if(node1 >= size || node2 >= size)
      {
        throw std::out_of_range("Not an edge in this graph");
      }
      nodes[node1].adjacent_nodes.push_back(&nodes[node2]);
      nodes[node2].adjacent_nodes.push_back(&nodes[node1]);
    }

    Graph::Node *Graph::get_node(u_int n) {
      if(n < size)
      {
        return &nodes[n];
      }
      else
      {
        throw std::out_of_range("Not a node");
      }
    }

    u_int Graph::get_size()
    {
      return size;
    }

    u_int Graph::check_count(Node * start)
    {
      u_int ret = 0;
      visit(start);
      for(auto &it : nodes)
      { //check how many nodes as been visited
        if(it.visited)
        { //uncheck visited to allow next check operation
          it.visited = false;
          ret++;
        }
      }
      return ret;
    }

    void Graph::visit(Node * start)
    {
      if(!start->processed)
      { //if node is already visited - return
        start->visited = true;
        for(auto &it : start->adjacent_nodes)
        {
          if(!it->visited && !it->processed)
          { //if it's already visited or currently processed we don't need to visit this node
            visit(it);
          }
        }
      }
    }

    u_int Graph::test() {
      for(auto &it : nodes)
      {
        if(!it.processed)
        {  //to test we can use any node which is not currently processed
          return check_count(&it);
        }
      }
      return 0;
    }

    std::list<std::pair<u_int, u_int>> Graph::seek_for_bridge()
    {
      std::list<std::pair<u_int, u_int>> bridges;
      if(size > 2)
      {//if size is less than two there is no bridge
        for(auto &it : nodes)
        {//for each node we check edges with smaller end value than this node - to avoid duplicate checking
          check_node(&bridges, &it);
        }
      }
      return bridges;
    }

    void Graph::check_node(std::list<std::pair<u_int, u_int>> *bridges, Node *node)
    {
      //'remove' edge
      node->processed = true;
      for(auto &current : node->adjacent_nodes)
      {//iter by all edges [with *node as one end]
        if(node->value < (current)->value)
        {// to avoid checking and printing both 3-6 and 6-3
          //'remove' edge
          current->processed = true;
          if(test() < size-2)
          {
            bridges->push_back(std::make_pair(node->value, current->value));
          }
          //'restore' edge
          current->processed = false;
        }
      }
      //'restore' edge
      node->processed = false;
    }
}
