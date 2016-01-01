#include "get_vertex_iterators.h"

#include "get_vertex_iterators_demo.impl"

#include <iostream>

#include "create_empty_directed_graph.h"
#include "create_empty_undirected_graph.h"
#include "create_k2_graph.h"

#include "create_named_edges_and_vertices_k3_graph.h"


void get_vertex_iterators_test() noexcept
{
  //Empty undirected graph: vertex iterators will both point beyond the last non-existent vertex
  {
    const auto g = create_empty_undirected_graph();
    const auto vip_a = get_vertex_iterators(g);
    assert(vip_a.first == vip_a.second);
  }
  //Empty directed graph: vertex iterators will both point beyond the last non-existent vertex
  {
    const auto g = create_empty_directed_graph();
    const auto vip_a = get_vertex_iterators(g);
    assert(vip_a.first == vip_a.second);
  }
  //Undirected K2 graph
  {
    const auto g = create_k2_graph();
    const auto vip_a = get_vertex_iterators(g);
    assert(vip_a.first != vip_a.second);
  }
  get_vertex_iterators_demo();
  

}

