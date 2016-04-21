#include "stdafx.h"
//---------------------------------------------------------------------------
#include "Experiment2D.h"
//---------------------------------------------------------------------------
#include "Properties.h"
#include "GLGeometryViewer.h"
#include "GeoXOutput.h"
#include <math.h>
#include <list>
#include <vector>
#include <iostream>
//---------------------------------------------------------------------------

#define PI 3.1415
IMPLEMENT_GEOX_CLASS(Experiment2D, 0)
{
	BEGIN_CLASS_INIT(Experiment2D);
	ADD_NOARGS_METHOD(Experiment2D::Problem2_1a)
	ADD_NOARGS_METHOD(Experiment2D::Problem2_1b)
	ADD_NOARGS_METHOD(Experiment2D::Problem2_1c)
	ADD_NOARGS_METHOD(Experiment2D::Problem2_1d)
}

QWidget* Experiment2D::createViewer()
{
	viewer = new GLGeometryViewer();
	return viewer;
}

Experiment2D::Experiment2D()
{
	viewer = NULL;
}

Experiment2D::~Experiment2D() {}

vector<float> Experiment2D::calculateScales(vector<Point2D> pData) {
	vector<float> resScales;
	for (int j = 0;j < 2;j++) {
		float max = 0;
		for (int i = 0;i < pData.size();i++) {
			if (pData[i].position[j] > max) {
				max = pData[i].position[j];
			}
		}
		if (max < 11) {
			resScales.push_back(1);
			continue;
		}
		float temp;
		temp = 8 / max;
		resScales.push_back(temp);
		}
		return resScales;
}

void Experiment2D::drawaxis() {
	Line xAxis;
	xAxis.vertices[0] = viewer->addPoint(makeVector2f(0, 0));
	xAxis.vertices[1] = viewer->addPoint(makeVector2f(0, 10));
	viewer->addLine(xAxis);
	Line yAxis;
	yAxis.vertices[0] = viewer->addPoint(makeVector2f(0, 0));
	yAxis.vertices[1] = viewer->addPoint(makeVector2f(10, 0));
	viewer->addLine(yAxis);

	Line xParallelAxis;
	Line yParallelAxis;

	xParallelAxis.vertices[0] = viewer->addPoint(makeVector2f(12,0));
	xParallelAxis.vertices[1] = viewer->addPoint(makeVector2f(12,10));
	yParallelAxis.vertices[0] = viewer->addPoint(makeVector2f(18,0));
	yParallelAxis.vertices[1] = viewer->addPoint(makeVector2f(18,10));

	viewer->addLine(xParallelAxis);
	viewer->addLine(yParallelAxis);
}
void Experiment2D::scatterPlot(vector<Point2D> data ,vector<float> scales) {

	
	Point2D temp;
	for (int j = 0;j <scales.size();j++)
	{
		for (unsigned int i = 0;i<data.size();i++)
	
		{
			data[i].position[j] = data[i].position[j] * scales[j];
		}
	}
	for (unsigned int i = 0;i<data.size();i++)
	{
		viewer->addPoint(data[i]);
		output << data[i].position[0] << data[i].position[1]<<"\n";
	}
}

void Experiment2D::parallelPlot(vector<Point2D> data, vector<float> scales) {

	for (int j = 0;j <scales.size();j++)
	{
		for (unsigned int i = 0;i<data.size();i++)
		{
			data[i].position[j] = data[i].position[j] * scales[j];
		}
	}
	vector<Point2D> temp ;
	int lHandle;
	for (int i = 0;i < data.size();i++)
	{
		viewer->addLine(makeVector2f(12,data[i].position[0]),makeVector2f(18,data[i].position[1]));
	}

}

void Experiment2D::Problem2_1a() {
	viewer->clear();
	vector<Point2D> pData;
	Point2D p1;
	p1.position = makeVector2f(50.0f, 5.0f);
	Point2D p2;
	p2.position = makeVector2f(5.0f, 31.0f);
	pData.push_back(p1);
	pData.push_back(p2);
	output << "data points " << "(" << pData[0].position[0] << "," << pData[0].position[1] << ");" 
		<< "(" << pData[1].position[0] << ","<< pData[1].position[1] << ");" <<"\n";
	vector<float> scales = calculateScales(pData);
	output << "x - scale:" << scales[0] << " ;y - scale:" << scales[1] << "\n";
	drawaxis();
	scatterPlot(pData,scales);
	parallelPlot(pData, scales);
	viewer->refresh();

	
}

void Experiment2D::Problem2_1b() {
	viewer->clear();
	drawaxis();
	//here data is circle;
	int i = 0;
	Point2D p1;
	Point2D p2;
	double radius = 2;
	double theta = 0;
	double incTheta = 10;

	vector<Point2D> pData;
	while (i <= 360)
	{
		p1.position = makeVector2f((radius * cos((theta + i* incTheta)* PI / 180)) + 5 , (radius * sin((theta + i * incTheta)  * PI / 180))+5);
		i++;
		p2.position = makeVector2f((radius * cos((theta + i* incTheta)* PI / 180))+5, (radius * sin((theta + i * incTheta)  * PI / 180))+5);
		//int p1Handle = viewer->addPoint(p1);
		//int p2Handle = viewer->addPoint(p2);
		pData.push_back(p1);
	}
	pData.push_back(p2);
	vector<float> scales = calculateScales(pData);
	output << "x - scale:" << scales[0] << " ;y - scale:" << scales[1] << "\n";
	drawaxis();
	scatterPlot(pData, scales);
	parallelPlot(pData, scales);
	viewer->refresh();
}
void Experiment2D::Problem2_1c() {
	//data is hyperbola
	//x = a cosh mu
	//y = b sinh mu

	viewer->clear();
	double a = -1;
	double b = 1;
	vector<Point2D> pData;
	double mu = 0.3;
	Point2D p1;
	Point2D p2;
	int k = -7;
	while (k <= 7) {
		
		p1.position = makeVector2f((a * cosh(mu*k))+5, (b * sinh(mu*k))+5);
		k++;
		//p2.position = makeVector2f((a * cosh(mu*k)), (b * sinh(mu*k)));
		pData.push_back(p1);
	}
	pData.push_back(p1);
	vector<float> scales = calculateScales(pData);
	output << "x - scale:" << scales[0] << " ;y - scale:" << scales[1] << "\n";
	drawaxis();
	scatterPlot(pData, scales);
	parallelPlot(pData, scales);
	viewer->refresh();
}
void Experiment2D::Problem2_1d() {
	// should show both the arma of hyperbola from Problem c
	//data is two hyperbolas
	//x = a cosh mu
	//y = b sinh mu

	viewer->clear();
	//first hyperbola
	double a = -1;
	double b = 1;
	vector<Point2D> pData;
	double mu = 0.3;
	Point2D p1;
	Point2D p2;
	int k = -5;
	while (k <= 5) {

		p1.position = makeVector2f((a * cosh(mu*k)) + 5, (b * sinh(mu*k)) + 5);
		k++;
		pData.push_back(p1);
	}
	pData.push_back(p1);
	//second hyperbola
	a = 1;
	b = -1;
	k = -5;
	while (k <= 5) {

		p1.position = makeVector2f((a * cosh(mu*k)) + 5, (b * sinh(mu*k)) + 5);
		k++;
		pData.push_back(p1);
	}
	pData.push_back(p1);
	
	vector<float> scales = calculateScales(pData);
	output << "x - scale:" << scales[0] << " ;y - scale:" << scales[1] << "\n";
	drawaxis();
	scatterPlot(pData, scales);
	parallelPlot(pData, scales);
	viewer->refresh();
}