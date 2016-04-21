#pragma once
//---------------------------------------------------------------------------
#ifndef Experiment2DH
#define Experiment2DH
//---------------------------------------------------------------------------
#include "Experiment.h"
#include "LinearAlgebra.h"
#include "GLGeometryViewer.h"

#include <list>
#include <vector>
#include <iostream>
//---------------------------------------------------------------------------

class Experiment2D : public Experiment {
	GEOX_CLASS(Experiment2D)

		//Constructor / Destructor
public:
	Experiment2D();
	virtual ~Experiment2D();

	//Methods
public:
	void scatterPlot(vector<Point2D> data, vector<float> scales);
	void drawaxis();
	void Problem2_1a();
	void Problem2_1b();
	void Problem2_1c();
	void Problem2_1d();
	vector<float> calculateScales(vector<Point2D>);
	void parallelPlot(vector<Point2D> data, vector<float> scales);
	virtual QWidget* createViewer();

	//Attributes
protected:
	GLGeometryViewer* viewer;

};
#endif