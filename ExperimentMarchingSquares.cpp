//---------------------------------------------------------------------------
#include "stdafx.h"
//---------------------------------------------------------------------------
#include "ExperimentMarchingSquares.h"
//---------------------------------------------------------------------------
#include "Properties.h"
#include "GLGeometryViewer.h"
#include "GeoXOutput.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include "Field2.hpp"
//---------------------------------------------------------------------------

IMPLEMENT_GEOX_CLASS( ExperimentMarchingSquares, 0)
{
    BEGIN_CLASS_INIT( ExperimentMarchingSquares );
    ADD_SEPARATOR("FileName")
    ADD_STRING_PROP(FileName, 0)
    ADD_FLOAT32_PROP(isovalue, 0)
    ADD_BOOLEAN_PROP(MarchingDecider, 0)
    //ADD_INT32_PROP( circles, 0 )
    //ADD_INT32_PROP( grids, 0 )
    ADD_NOARGS_METHOD(ExperimentMarchingSquares::LoadCSVData)
    //ADD_NOARGS_METHOD(ExperimentMarchingSquares::drawCircles)
}

QWidget* ExperimentMarchingSquares::createViewer()
{
    viewer = new GLGeometryViewer();
    return viewer;
    
}

ExperimentMarchingSquares::ExperimentMarchingSquares()
{
    //numberB = 23.0f;
    //circles = 5;
    //grids = 6;
    viewer = NULL;
    
}

ExperimentMarchingSquares::~ExperimentMarchingSquares() {

FileName = "/VamshiMainFolder/KTH_Acads/Visualization/Software/GeoX/MarchingSquaresData/SmallGrid.am";

    isovalue = 0.25;
    
}


void ExperimentMarchingSquares::LoadCSVData(){

    viewer->clear();
    
    //Load scalar field
    float x_coord;
    float y_coord;
    ScalarField2 field;
    Vector2ui dims;
    
    if (!field.load(FileName))
    {
        output << "Error loading field file " << FileName << "\n";
        return;
    }
    
    dims = field.dims();

    for(int i=0; i<field.dims()[0] ; i++){
        for(int j=0; j<field.dims()[1]; j++){
            
            //int main = viewer->addPoint(m1);
            
            Line gridLine;
            
            Point2D m1 = field.nodePosition(i, j);
            int main1 = viewer->addPoint(m1);
            
            if(j<field.dims()[1]-1){
                
                Point2D m2 = field.nodePosition(i, j+1);
                int main2 = viewer->addPoint(m2);
                
                gridLine.vertices[0] = main1;
                gridLine.vertices[1] = main2;
                
                viewer->addLine(gridLine);
                
            }
            
            if(i<field.dims()[0]-1){
                
                Point2D m2 = field.nodePosition(i+1, j);
                int main2 = viewer->addPoint(m2);
                
                gridLine.vertices[0] = main1;
                gridLine.vertices[1] = main2;
                
                viewer->addLine(gridLine);
                
            }
            
            //gridLine.vertices[0] = main;
            

        }
    }
    
    /*viewer->addPoint(field.boundMax());
    viewer->addPoint(field.boundMin());*/
    //viewer->addPoint(field.nodePosition(0, 0));
    
    
    viewer->refresh();
}


                    