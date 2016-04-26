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
#include <cmath>
//---------------------------------------------------------------------------

IMPLEMENT_GEOX_CLASS(ExperimentMarchingSquares, 0)
{
	BEGIN_CLASS_INIT(ExperimentMarchingSquares);
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
	FileName = "C:/Users/Varsha Kirani/Documents/KTH Courses/Visualization/Assignments/Assignment03/SimpleGrid.am";
	viewer = NULL;

}

ExperimentMarchingSquares::~ExperimentMarchingSquares() {

	FileName = "/VamshiMainFolder/KTH_Acads/Visualization/Software/GeoX/MarchingSquaresData/SmallGrid.am";

	isovalue = 0.25;

}

void ExperimentMarchingSquares::findBoxes() {

	ScalarField2 field;
	bool fExists = field.load(FileName);

	if (!fExists)
	{
		output << "Error loading field file " << FileName << "\n";
		return;
	}

	int xDir = field.dims()[0];
	int yDir = field.dims()[1];

	float isoDiff;
	float isoDiffy2;
	float isoDiffx2;
	Point2D isoIntersecty;
	
	Point2D isoIntersectx;

	for (int i = 0;i < xDir-1;i++) {
		for (int j = 0;j < yDir-1;j++) {
			
			isoDiff = field.nodeScalar(i, j) - isovalue;
			isoDiffy2 = field.nodeScalar(i, j + 1) - isovalue;
			float ty, tx;
			//checking two adjacent vertical points are opposite signs
			if ((isoDiff * isoDiffy2 ) < 0) {
				ty = (isovalue - field.nodeScalar(i, j)) / (field.nodeScalar(i, j + 1) - field.nodeScalar(i, j));
				isoIntersecty.position[0] = field.nodePosition(i, j)[0];
				isoIntersecty.position[1] = field.nodePosition(i, j)[1] + abs(ty);
		//		isoIntersecty.color = makeVector4f(1, 0, 0, 0);
				viewer->addPoint(isoIntersecty);
			}
			
			 


			isoDiffx2 = field.nodeScalar(i+1, j) - isovalue;

			//checking two adjacent horizontal points are opposite signs
			if ((isoDiff * isoDiffx2) < 0) {
				tx = (isovalue - field.nodeScalar(i, j)) / (field.nodeScalar(i + 1 , j) - field.nodeScalar(i, j));
				isoIntersectx.position[0] = field.nodePosition(i, j)[0] + abs(tx);
				isoIntersectx.position[1] = field.nodePosition(i, j)[1];
	//			isoIntersectx.color = makeVector4f(0, 1, 0, 0);
				viewer->addPoint(isoIntersectx);
			}
					
		}
	}

	viewer->refresh();
}
void ExperimentMarchingSquares::midPointDecider() {
	
}

void ExperimentMarchingSquares::LoadCSVData() {

	viewer->clear();

	//Load scalar field
	float x_coord;
	float y_coord;
	ScalarField2 field;
	Vector2ui dims;
	bool fExists = field.load(FileName);

	if (!fExists)
	{
		output << "Error loading field file " << FileName << "\n";
		return;
	}

	
	//dims = field.dims();

	for (int i = 0; i<field.dims()[0]; i++) {
		for (int j = 0; j<field.dims()[1]; j++) {

			//int main = viewer->addPoint(m1);

			Line gridLine;

			Point2D m1 = field.nodePosition(i, j);
			int main1 = viewer->addPoint(m1);

			if (j<field.dims()[1] - 1) {

				Point2D m2 = field.nodePosition(i, j + 1);
				int main2 = viewer->addPoint(m2);

				gridLine.vertices[0] = main1;
				gridLine.vertices[1] = main2;

				viewer->addLine(gridLine);

			}

			if (i<field.dims()[0] - 1) {

				Point2D m2 = field.nodePosition((i + 1), j);
				int main2 = viewer->addPoint(m2);

				gridLine.vertices[0] = main1;
				gridLine.vertices[1] = main2;

				viewer->addLine(gridLine);

			}

			//gridLine.vertices[0] = main;

			output << " " << field.nodeScalar(i, j);
		}
		output << "\n ";
	}

	/*viewer->addPoint(field.boundMax());
	viewer->addPoint(field.boundMin());*/
	//viewer->addPoint(field.nodePosition(0, 0));
 
    findBoxes();
	viewer->refresh();
	
}


