#pragma once
#ifndef Experiment2D22H
#define Experiment2D22H
//---------------------------------------------------------------------------
#include "Experiment.h"
#include "LinearAlgebra.h"
#include "GLGeometryViewer.h"
//---------------------------------------------------------------------------

class Experiment2D22 : public Experiment {
	GEOX_CLASS(Experiment2D22)

		//Constructor / Destructor
public:
	Experiment2D22();
	virtual ~Experiment2D22();

	//Methods
public:
	//void scatterPlot(int x, int y);
	//void drawaxis();
	//void Problem2_1a();
	void readCSV();
	virtual QWidget* createViewer();

	//Attributes
protected:
	GLGeometryViewer* viewer;

private:
	string CSVFileName;

};
#endif