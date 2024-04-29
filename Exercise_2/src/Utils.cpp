#include "Utils.hpp"
#include <sstream>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

namespace PolygonalMeshLibrary{

bool ImportMesh(const string &FilePath,
                PolygonalMesh &mesh)
{
    // Checking the import of the 0D file
    if(!ImportCell0D(FilePath + "/Cell0Ds.csv",
                      mesh))
        return false;
    else
    {
        // Marker tests
        cout << "Markers Cells0D:" << endl;
        for(auto it = mesh.MarkerCell0D.begin();
             it != mesh.MarkerCell0D.end(); it++)
        {
            cout << "key:\t" << it -> first
                 << "\tvalues:";
            for(const unsigned int id : it -> second)
                cout << "\t" << id;
            cout << endl;
        }
        cout << endl;
    }

    // Checking the import of the 1D file
    if(!ImportCell1D(FilePath + "/Cell1Ds.csv",
                      mesh))
        return false;
    else
    {
        // Marker tests
        cout << "Markers Cells1D:" << endl;
        for(auto it = mesh.MarkerCell1D.begin();
             it != mesh.MarkerCell1D.end(); it++)
        {
            cout << "key:\t" << it -> first
                 << "\tvalues:";
            for(const unsigned int id : it -> second)
                cout << "\t" << id;
            cout << endl;
        }
        cout << endl;
    }

    // Checking the import of the 2D file
    if(!ImportCell2D(FilePath + "/Cell2Ds.csv",
                      mesh))
        return false;
    else
    {
        // Marker tests
        cout << "Markers Cells2D:" << endl;
        for(auto it = mesh.MarkerCell2D.begin();
             it != mesh.MarkerCell2D.end(); it++)
        {
            cout << "key:\t" << it -> first
                 << "\nvalues:\n";
            for(const unsigned int id : it -> second)
                cout << id << "\t";
            cout << endl;
        }
        cout << endl;
    }
    // If all three ImportCell go well
    return true;

} // Closing function ImportMesh

bool ImportCell0D(const string &FileName,
                  PolygonalMesh &mesh)
{
    ifstream File; // Create stream object
    File.open(FileName); // Open the file
    // Check if the file is opened correctly
    if(File.fail())
        return false;

    // Declare a list of strings
    list<string> ListLines;
    // Declare a void string
    string Line;

    /* Read one line at a time from the file and
     * put each row in the stream object */
    while(getline(File, Line))
    {
     // replace(first el, last el, old val, new val)
        replace(Line.begin(), Line.end(), ';', ' ');
     // Push each line in the list of strings
        ListLines.push_back(Line);
    }
    // Delete header line in the list of strings
    ListLines.pop_front();

    /* Count the number of rows in the list of strings
     * to initialize the number of Cell0D */
    mesh.NumberCell0D = ListLines.size();

    /* Check that the number of Cell0D
     * is different from zero */
    if(mesh.NumberCell0D == 0)
    {
        cerr << "There aren't 0D Cells" << endl;
        return false;
    }

    /* Keep the quantity of memory needed
     * to fill vectors */
    mesh.IdCell0D.reserve(mesh.NumberCell0D);
    mesh.CoorCell0D.reserve(mesh.NumberCell0D);

    /* Iteration on the list of strings
     * to fill vectors */
    for(const string &Line : ListLines)
    {
        // Create a stream object
        istringstream convert0D(Line);

        // Declare temporary variables
        unsigned int id;
        unsigned int marker;
        Vector2d coor;

        // Put elements in the stream object
        convert0D >> id >> marker >> coor(0)
            >> coor(1);

        // Push elements in vectors
        mesh.IdCell0D.push_back(id);
        mesh.CoorCell0D.push_back(coor);

        // Marker tests
        if(marker != 0)
        {
            auto return0D
            = mesh.MarkerCell0D.insert({marker,{id}});

            if(!return0D.second)
                (return0D.first)
                    -> second.push_back(id);
        }
    }
    File.close(); // Closing file
    return true;
} // Closing function ImportCell0D

bool ImportCell1D(const string &FileName,
                  PolygonalMesh &mesh)
{
    ifstream File; // Create stream object
    File.open(FileName); // Open the file
    // Check if the file is opened correctly
    if(File.fail())
        return false;

    // Declare a list of strings
    list<string> ListLines;
    // Declare a void string
    string Line;

    /* Read one line at a time from the file and
     * put each row in the stream object */
    while(getline(File, Line))
    {
     // replace(first el, last el, old val, new val)
        replace(Line.begin(), Line.end(), ';', ' ');
     // Push each line in the list of strings
        ListLines.push_back(Line);
    }
    // Delete header line in the list of strings
    ListLines.pop_front();

    /* Count the number of rows in the list of strings
     * to initialize the number of Cell1D */
    mesh.NumberCell1D = ListLines.size();

    /* Check that the number of Cell1D
     * is different from zero */
    if(mesh.NumberCell1D == 0)
    {
        cerr << "There aren't 1D Cells" << endl;
        return false;
    }

    /* Keep the quantity of memory needed
     * to fill vectors */
    mesh.IdCell1D.reserve(mesh.NumberCell1D);
    mesh.VerticesCell1D.reserve(mesh.NumberCell1D);

    /* Iteration on the list of strings
     * to fill vectors */
    for(const string &Line : ListLines)
    {
        // Create a stream object
        istringstream convert1D(Line);

        // Declare temporary variables
        unsigned int id;
        unsigned int marker;
        Vector2i vertices;

        // Put elements in the stream object
        convert1D >> id >> marker >> vertices(0)
            >> vertices(1);

        // Push elements in vectors
        mesh.IdCell1D.push_back(id);
        mesh.VerticesCell1D.push_back(vertices);

        // Marker tests
        if(marker != 0)
        {
            auto return1D
            = mesh.MarkerCell1D.insert({marker,{id}});

            if(!return1D.second)
                (return1D.first)
                    -> second.push_back(id);
        }
    }
    File.close(); // Closing file
    return true;
} // Closing function ImportCell1D

bool ImportCell2D(const string &FileName,
                  PolygonalMesh &mesh)
{
    ifstream File; // Create stream object
    File.open(FileName); // Open the file
    // Check if the file is opened correctly
    if(File.fail())
        return false;

    // Declare a list of strings
    list<string> ListLines;
    // Declare a void string
    string Line;

    /* Read one line at a time from the file and
     * put each row in the stream object */
    while(getline(File, Line))
    {
     // replace(first el, last el, old val, new val)
        replace(Line.begin(), Line.end(), ';', ' ');
     // Push each line in the list of strings
        ListLines.push_back(Line);
    }
    // Delete header line in the list of strings
    ListLines.pop_front();

    /* Count the number of rows in the list of strings
     * to initialize the number of Cell2D */
    mesh.NumberCell2D = ListLines.size();

    /* Check that the number of Cell2D
     * is different from zero */
    if(mesh.NumberCell2D == 0)
    {
        cerr << "There aren't 2D Cells" << endl;
        return false;
    }

    /* Keep the quantity of memory needed
     * to fill vectors */
    mesh.IdCell2D.reserve(mesh.NumberCell2D);
    mesh.NumberVerticesCell2D.
        reserve(mesh.NumberCell2D);
    mesh.VerticesCell2D.reserve(mesh.NumberCell2D);
    mesh.NumberEdgesCell2D.reserve(mesh.NumberCell2D);
    mesh.EdgesCell2D.reserve(mesh.NumberCell2D);

    /* Iteration on the list of strings
     * to fill vectors */
    for(const string &Line : ListLines)
    {
        // Create a stream object
        istringstream convert2D(Line);

        // Declare temporary variables
        unsigned int id;
        unsigned int marker;
        unsigned int NumberVertices;
        unsigned int NumberEdges;

        /* Put elements in the stream object,
         * also using iterations "for" */
        convert2D >> id >> marker >> NumberVertices;

        vector<unsigned int> Vertices(NumberVertices);

        for(unsigned int i = 0;
             i < NumberVertices; i++)
            convert2D >> Vertices[i];

        convert2D >> NumberEdges;

        vector<unsigned int> Edges(NumberEdges);

        for(unsigned int i = 0; i < NumberEdges; i++)
            convert2D >> Edges[i];

        // Push elements in vectors
        mesh.IdCell2D.push_back(id);
        mesh.NumberVerticesCell2D.
            push_back(NumberVertices);
        mesh.VerticesCell2D.push_back(Vertices);
        mesh.NumberEdgesCell2D.push_back(NumberEdges);
        mesh.EdgesCell2D.push_back(Edges);

        /* All markers have been stored correctly:
         * prove that all markers are equal to 0 */
        if(marker == 0)
        {
            auto return2D
            = mesh.MarkerCell2D.insert({marker,{id}});

            if(!return2D.second)
                (return2D.first)
                    -> second.push_back(id);
        }
    }
    File.close(); // Closing file
    return true;
} // Closing function ImportCell2D

void TestLenghtEdges(vector<Vector2d> &COORD,
                     const unsigned int &NUMID)
{
    cout << "Test Lenght Edges:" << endl;
    // Set tolerance for non-zero length
    const double tolerance = 1e-6;

    // Declare temporary variables
    unsigned int i;
    unsigned int j = 0;
    unsigned int k;

    // Iteration working on rows of the file Cell0Ds
    for(i = 0; i < NUMID + 1; i++)
    {
        /* Declare variables to save coordinates of
         * the vertex 'origin' */
        const double Vert1x = COORD[i][0];
        const double Vert1y = COORD[i][1];

        // Index second vertex
        for(k = i + 1; k < NUMID; k++)
        {
            /* Declare variables to save coordinates
             * of the vertex 'end' */
            const double Vert2x = COORD[k][0];
            const double Vert2y = COORD[k][1];

            /* Calculate the lenght of each edge by
             * using coordinates (X, Y) */
            double lenghtx = pow(Vert1x - Vert2x, 2);
            /* Another way to write the square of a
             * difference:
             * double lenghtx
             * =(Vert1x - Vert2x)*(Vert1x - Vert2x);*/
            double lenghty = pow(Vert1y - Vert2y, 2);
            /* double lenghty
             * =(Vert1y - Vert2y)*(Vert1y - Vert2y);*/
            double lenghttot
                = sqrt(lenghtx + lenghty);

            /* Check if edges of each polygon have
             * non-zero length */
            if(lenghttot < tolerance)
            {                
                j += 1; // Counter
                cerr << "Attention! The lenght of the"
                        " edge between the vertex "
                     << i << " and the vertex " << k
                     << " is equal to zero with"
                        " tolerance = "
                     << tolerance << "." << endl;
            }
            /* If you want to print all distances,
             * also used to test if the function
             * is correct */
            // cout << "The lenght between "
            // << i << " and " << k << " is "
            // << lenghttot << "\n";
        }
    }
    if(j == 0)
        cout << "There are no edges with lenght equal"
                " to zero with tolerance = "
             << tolerance << ".";
    cout << "\n" << endl;
} // Closing function TestLenghtEdges

void TestPolygonArea(const unsigned int &NumId2D,
            vector<unsigned int> &NumVertPoly,
            vector<vector<unsigned int>> &VertPoly,
            vector<Vector2d> &Coord)
{
    cout << "Test Polygonal Areas:" << endl;
    // Declaration and initialization of tolerance
    const double tolerance = 1e-6;

    // Declaration and initialization of variables
    double Area = 0.0;    
    int Count = 0;
    double AreaTot = 0.0;

    /* Initialization of the number of polygons in
     * the mesh, by using the number of rows
     * in the file Cell2Ds */
    int numPoly = NumId2D;
    // Iteration working on rows of the file Cell2Ds
    for(int j = 0; j < numPoly; ++j)
    {
        // Get the number of vertices of each polygon
        int numVertices = NumVertPoly[j];

        // Iteration to read vertices of each polygon
        for (int i = 0; i < numVertices; ++i)
        {
            // Memorize first vertex
            int vertex1 = VertPoly[j][i];
            /* Calculate the index of the
             * following vertex */
            int nextIndex = i + 1;
            /* Go back to the first vertex of the
             * poly if vertex1 is the last element in
             * the vector of vertices */
            if (nextIndex == numVertices)
                nextIndex = 0;

            // Memorize second vertex
            int vertex2 = VertPoly[j][nextIndex];
            // Calculate the area of the poly
            Area += (Coord[vertex1][0]
                         * Coord[vertex2][1]
                     - Coord[vertex2][0]
                           * Coord[vertex1][1]) / 2.;
        }        
        // Variable to test the sum of all areas
        AreaTot += Area;

        /* Test if some polygon has area equal to zero
         * with an imposed tolerance */
        if(abs(Area) < tolerance)
        {
            cerr << "Error! The area of the polygon "
                 << j
                 << " is equal to zero"
                    " with tolerance = "
                 << tolerance << "." << endl;
            // Count of poly with area equal to zero
            Count += 1;
        }
        /* If you want to print all areas,
         * also used to test if the function
         * is correct */
        // else
        //     cout << "Polygon " << j
        //          << " area = " << Area << endl;

        // Clear the variable
        Area = 0.0;
    }

    if(Count == 0)
        cout << "Any polygon has area equal to zero "
             << "considering the tolerance "
             << tolerance << "." << endl;

    if(1. - AreaTot < tolerance)
        cout << "The total area as the sum of all "
                "the polygons areas is "
             << AreaTot
             << ", so is equal to one considering"
                " the tolerance "
             << tolerance << ".\n" << endl;

    else
        cout << "The total area as the sum of all "
                 "the polygons areas is "
             << AreaTot
             << " so the difference between 1 and the"
                " sum of areas is lower then "
                "the tolerance "
             << tolerance << ".\n" << endl;

} // Closing function TestPolygonalArea

} // Closing namespace
