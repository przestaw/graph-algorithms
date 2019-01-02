//
// Created by przemek on 12/27/18.
//

#include <stdexcept>
#include "../include/Graph.h"

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
    throw std::out_of_range("Not an edge in graph");
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
  {
    if(it.visited)
    {
      it.visited = false;
      ret++;
    }
  }
  return ret;
}

void Graph::visit(Node * start)
{
  if(!start->processed)
  {
    start->visited = true;
    for(auto &it : start->adjacent_nodes)
    {
      if(!it->visited && !it->processed)
      {
        visit(it);
      }
    }
  }
}

u_int Graph::test() {
  for(auto &it : nodes)
  {
    if(!it.processed)
    {
      return check_count(&it);
    }
  }
  return 0;
}

std::list<std::pair<u_int, u_int>> Graph::seek_for_bridge()
{
  std::list<std::pair<u_int, u_int>> bridges;
  if(size > 2)
  {
    for(auto &it : nodes)
    {
      check_node(&bridges, &it);
    }
  }
  return bridges;
}

void Graph::check_node(std::list<std::pair<u_int, u_int>> *bridges, Node *node)
{
  node->processed = true;
  for(auto &current : node->adjacent_nodes)
  {
    if(node->value < (current)->value) // to avoid printing both 3-6 and 6-3
    {
      //remove
      current->processed = true;
      if(test() < size-2)
      {
        bridges->push_back(std::make_pair(node->value, current->value));
      }
      //restore edge
      current->processed = false;
    }
  }
  node->processed = false;
}
