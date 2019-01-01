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
  start->visited = true;
  for(auto &it : start->adjacent_nodes)
  {
    if(!it->visited)
    {
      visit(it);
    }
  }
}

u_int Graph::test() {
  return check_count(&nodes.back());
}

std::list<std::pair<u_int, u_int>> Graph::seek_for_bridge()
{
  std::list<std::pair<u_int, u_int>> bridges;
  for(auto &it : nodes)
  {
    check_node(&bridges, &it);
  }
  return bridges;
}

void Graph::check_node(std::list<std::pair<u_int, u_int>> *bridges, Node *node)
{
  Node * current;
  for(auto i = node->adjacent_nodes.size(); i > 0; i--)
  {
    current = node->adjacent_nodes.back();//no matter front/back - it's a list
    if(node->value < (current)->value) // to avoid printing both 3-6 and 6-3
    {
      //remove edge
      node->adjacent_nodes.remove(current);
      current->adjacent_nodes.remove(node);
      if(check_count(node) < size || check_count(current) < size)
      {
        bridges->push_back(std::make_pair(node->value, current->value));
      }
      //restore edge
      node->adjacent_nodes.push_front(current);
      current->adjacent_nodes.push_front(node);
    }
  }
}
