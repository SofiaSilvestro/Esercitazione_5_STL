#pragma once

#include <iostream>
#include "PolygonalMesh.hpp"

using namespace std;

namespace PolygonalMeshLibrary{

bool ImportMesh(const string &FilePath,
                PolygonalMesh &mesh);

/** This function imports the PolygonalMesh and tests
 *  if the mesh is correct
 *  mesh: given the struct, returns the result of the
 *  reading, true if all went well false otherwise **/


bool ImportCell0D(const string &FileName,
                  PolygonalMesh &mesh);

/** This function imports the properties of Cell0Ds
 *  from the file "Cell0Ds.csv", for the mesh:
 *  the struct PolygonalMesh returns the reading,
 *  true if all went well, false otherwise **/


bool ImportCell1D(const string &FileName,
                  PolygonalMesh &mesh);

/** This function imports the properties of Cell1Ds
 *  from the file "Cell1Ds.csv", for the mesh:
 *  the struct PolygonalMesh returns the reading,
 *  true if all went well, false otherwise **/


bool ImportCell2D(const string &FileName,
                  PolygonalMesh &mesh);

/** This function imports the properties of Cell2Ds
 *  from file "Cell2Ds.csv" for the mesh:
 *  the struct PolygonalMesh returns the reading,
 *  true if always went well, false otherwise **/


void TestLenghtEdges(vector<Vector2d> &COORD,
                     const unsigned int &NUMID);

/** This function calculates the distance between two
 *  vertices with successive indices and comparates
 *  this quantity with an imposed tolerance to
 *  determine if the segment (that is an edge of a
 *  poly) has zero lenght.
 *  Doesn't return anything because is a void
 *  function.
 *  COORD: vector of an Eigen vector dim = 2,
 *  containing double
 *  NUMID: integer number that represents the number
 *  of rows in the file Cell0Ds **/


void TestPolygonArea(const unsigned int &NumId2D,
            vector<unsigned int> &NumVertPoly,
            vector<vector<unsigned int>> &VertPoly,
            vector<Vector2d> &Coord);

/** This function calculates the area of each polygon
 *  by reading datas from files Cell0Ds and Cell2Ds,
 *  in particular:
 *  NumId2D: integer number representing the number
 *  of rows in the file Cell2Ds
 *  NumVertPoly: vector of integers containing the
 *  number of vertices for each polygon
 *  VertPoly: vector of vector of integers containing
 *  the list of vertices forming a polygon in the mesh
 *  Coord: from the file Cell0Ds is a vector of an
 *  Eigen vector dim = 2, containing double and saving
 *  the coordinates of each vertex
 *  To calculate the area of the polygon is
 *  used the formula:
 *  Area = 1/2 * SUM(x(i) * y(i+1) - x(i+1) * y(i))
 *  where i is contained in the interval [0, N-1]
 *  with N = Number of vertices of the poly **/

} // closing namespace
