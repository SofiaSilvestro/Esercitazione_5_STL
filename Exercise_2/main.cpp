#include <iostream>
#include "Utils.hpp"
#include "PolygonalMesh.hpp"

using namespace std;
using namespace Eigen;
using namespace PolygonalMeshLibrary;

int main()
{
    PolygonalMesh mesh; // struct
    string FilePath = "./PolygonalMesh";

    // Checking the import
    if(!ImportMesh(FilePath,
                    mesh))
        return 1; /* Even just one of the "if" in
                   * "Utils.cpp" returns false */
    else
    {
        /* Tests on the polygonal mesh on edges and
         * on areas of polygons */

        TestLenghtEdges(mesh.CoorCell0D,
                        mesh.NumberCell0D);

        TestPolygonArea(mesh.NumberCell2D,
                        mesh.NumberVerticesCell2D,
                        mesh.VerticesCell2D,
                        mesh.CoorCell0D);
        return 0; // If in ImportMesh all goes well
    }

}
