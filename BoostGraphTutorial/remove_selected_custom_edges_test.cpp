#include "remove_selected_custom_edges.h"
#include "remove_selected_custom_edges_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_custom_and_selectable_edges_and_vertices_path_graph.h"

BOOST_AUTO_TEST_CASE(remove_selected_custom_edges_remove_one_edge)
{
  const std::vector<my_custom_vertex> my_custom_vertexes =
  {
    my_custom_vertex("X"),
    my_custom_vertex("Y")
  };
  const std::vector<my_custom_edge> my_custom_and_selectable_edges =
  {
    my_custom_edge("1")
  };
  const auto g = create_custom_and_selectable_edges_and_vertices_path_graph(
    my_custom_and_selectable_edges,
    { true }, //Will be remove
    my_custom_vertexes,
    { false, true }
  );
  BOOST_CHECK(boost::num_edges(g) == 1);
  BOOST_CHECK(boost::num_vertices(g) == 2);
  const auto h = remove_selected_custom_edges(g);
  BOOST_CHECK(boost::num_edges(h) == 0);
  BOOST_CHECK(boost::num_vertices(h) == 2);
}

BOOST_AUTO_TEST_CASE(remove_selected_custom_edges_remove_no_edge)
{
  const std::vector<my_custom_vertex> my_custom_vertexes =
  {
    my_custom_vertex("X"),
    my_custom_vertex("Y")
  };
  const std::vector<my_custom_edge> my_custom_and_selectable_edges =
  {
    my_custom_edge("1")
  };
  const auto g = create_custom_and_selectable_edges_and_vertices_path_graph(
    my_custom_and_selectable_edges,
    { false }, //Only edge is not selected
    my_custom_vertexes,
    { false, true }
  );
  BOOST_CHECK(boost::num_edges(g) == 1);
  BOOST_CHECK(boost::num_vertices(g) == 2);
  const auto h = remove_selected_custom_edges(g);
  BOOST_CHECK(boost::num_edges(h) == 1);
  BOOST_CHECK(boost::num_vertices(h) == 2);
}
