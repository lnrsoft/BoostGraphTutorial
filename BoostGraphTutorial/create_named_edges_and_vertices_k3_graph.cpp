#include "create_named_edges_and_vertices_k3_graph.h"

#include "create_named_edges_and_vertices_k3_graph.impl"

#include "create_empty_undirected_named_edges_and_vertices_graph.h"
#include "create_named_edges_and_vertices_k3_graph_demo.impl"
#include <cassert>
#include <iostream>
#include "get_edge_names.h"
#include "get_vertex_names.h"
#include "save_named_edges_and_vertices_graph_to_dot.h"
#include "copy_file.h"
#include "convert_dot_to_svg.h"

void create_named_edges_and_vertices_k3_graph_test() noexcept
{
  //Basic functions
  {
    const auto g = create_named_edges_and_vertices_k3_graph();
    assert(boost::num_edges(g) == 3);
    assert(boost::num_vertices(g) == 3);
    const std::vector<std::string> expected_vertex_names{"top", "right", "left"};
    const std::vector<std::string> vertex_names{get_vertex_names(g)};
    assert(expected_vertex_names == vertex_names);
    const std::vector<std::string> expected_edge_names{"AB", "BC", "CA"};
    const std::vector<std::string> edge_names{get_edge_names(g)};
    assert(expected_edge_names == edge_names);
  }
  //Create the create_named_edges_and_vertices_k3_graph .dot and .svg files
  {
    const auto g = create_named_edges_and_vertices_k3_graph();
    const std::string base_filename{"create_named_edges_and_vertices_k3_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_named_edges_and_vertices_graph_to_dot(g,dot_filename);
    convert_dot_to_svg(dot_filename,svg_filename);
    copy_file(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
  }
  create_named_edges_and_vertices_k3_graph_demo();
  
}
