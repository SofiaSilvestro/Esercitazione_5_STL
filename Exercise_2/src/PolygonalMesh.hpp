#pragma once

#include <vector>
#include <iostream>
#include <Eigen/Eigen>

using namespace Eigen;
using namespace std;

namespace PolygonalMeshLibrary{

struct PolygonalMesh
{
    // Cell0D = Vertices
    /* Number of cells0D */
    unsigned int NumberCell0D = 0;

    /* Identifiers Id,
     * dim 1 x NumberCell0D */
    vector<unsigned int> IdCell0D = {};

    /* Coordinates,
     * dim 2 x NumberCell0D, format (X,Y) */
    vector<Vector2d> CoorCell0D = {};

    /* Properties of Cells0D, define a map where:
     * key = maker
     * value = vertex
     * dim 1 x NumberCell0D */
    map<unsigned int,
        list<unsigned int>> MarkerCell0D = {};


    // Cell1D = Edges
    /* Number of cells1D */
    unsigned int NumberCell1D = 0;

    /* Identifiers Id,
     * dim 1 x NumberCell1D */
    vector<unsigned int> IdCell1D = {};

    /* Index vertices,
     * dim 2 x NumberCell1D,
     * format (origin, end) */
    vector<Vector2i> VerticesCell1D = {};

    /* Properties of Cells1D, define a map where:
     * key = marker
     * value = vertices (origin, end)
     * dim 1 x NumberCell1D */
    map<unsigned int,
        list<unsigned int>> MarkerCell1D = {};


    // Cell2D = Polygons
    /* Number of cell2D */
    unsigned int NumberCell2D = 0;

    /* Identifiers Id,
     * dim 1 x NumberCell2D */
    vector<unsigned int> IdCell2D = {};

    /* Number of vertices memorized in a single
     * column of integers
     * dim = 1 x NumberCell2D */
    vector<unsigned int> NumberVerticesCell2D = {};
    /* Index vertices,
     * dim NumVertici x NumberCell2D */
    vector<vector<unsigned int>> VerticesCell2D = {};

    /* Number of edges memorized in a single
     * column of integers
     * dim = 1 x NumberCell2D */
    vector<unsigned int> NumberEdgesCell2D = {};
    /* Index edges,
     * dim NumberEdges x NumberCell2D */
    vector<vector<unsigned int>> EdgesCell2D = {};

    /* Properties of Cells2D, define a map where:
     * key = marker
     * value = vertices
     * dim 1 x NumberCell2D */
    map<unsigned int,
        list<unsigned int>> MarkerCell2D = {};

}; // closing struct

} // closing namespace


