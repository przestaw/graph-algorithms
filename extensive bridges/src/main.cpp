#include <iostream>
#include "../include/Graph.h"

int main()
{
  u_int size;
  std::cin >> size;
  Graph my_graph(size);

  u_int node1, node2;
  while (std::cin >> node1 >> node2)
  {
    my_graph.add_edge(node1, node2);
  }


  auto print_bridge = [](std::pair<u_int, u_int> bridge)
          {
            std::cout << bridge.first << " " << bridge.second << '\n';
          };

  for(auto &it : my_graph.seek_for_bridge())
  {
    print_bridge(it);
  }
  return 0;
}

