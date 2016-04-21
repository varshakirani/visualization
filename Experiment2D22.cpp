#include "stdafx.h"
//---------------------------------------------------------------------------
#include "Experiment2D22.h"
//---------------------------------------------------------------------------
#include "Properties.h"
#include "GLGeometryViewer.h"
#include "GeoXOutput.h"
#include <math.h>
#include <iostream>
#include <fstream>


//---------------------------------------------------------------------------

IMPLEMENT_GEOX_CLASS(Experiment2D22, 0)
{
	BEGIN_CLASS_INIT(Experiment2D22)
	ADD_SEPARATOR("Filename")
		ADD_STRING_PROP(CSVFileName, 0)

		ADD_NOARGS_METHOD(Experiment2D22::readCSV)
		//ADD_INT32_PROP(numberA, 0)               
		//ADD_FLOAT32_PROP(numberB, 0)
	//ADD_NOARGS_METHOD(ExampleExperiment2DGraphics::drawSquares)
	//ADD_NOARGS_METHOD(ExampleExperiment2DGraphics::drawCircles)
	//ADD_NOARGS_METHOD(Experiment2D::scatterPlot)
}

void Experiment2D22::split(const string& s, char c,	vector<string>& v) {
	string::size_type i = 0;
	string::size_type j = s.find(c);

	while (j != string::npos) {
		v.push_back(s.substr(i, j - i));
		i = ++j;
		j = s.find(c, j);

		if (j == string::npos)
			v.push_back(s.substr(i, s.length()));
	}
}

QWidget* Experiment2D22::createViewer()
{
	viewer = new GLGeometryViewer();
	return viewer;
}

Experiment2D22::Experiment2D22()
{
	CSVFileName = "C:/Users/Varsha Kirani/Documents/KTH Courses/Visualization/Assignments/Theory/Assignment2/Assignment02/Cars.csv";
	viewer = NULL;
}

Experiment2D22::~Experiment2D22() {}

void Experiment2D22::readCSV()
{
	ifstream csvReadFile;
	csvReadFile.open(CSVFileName);
	vector<vector<float>> pData;
	
	string delimiter = ",";
	string value;
	if (!csvReadFile.good()) {
		output << "File does not exists" << "\n";
	}
	getline(csvReadFile, value, '\n');
	output << value << "\n";
	vector<string> names;
	split(value,',',names);
	//size_t pos = 0;
	//string token;
	//while (pos = value.find(delimiter) != string::npos) {
		//token = value.substr(0, pos);
		//output << token << "\n";
		//names.push_back(token);
		//value.erase(0, pos + 1);
	//}

	for (int i = 0;i < names.size();i++) {
		output << " " << names[i] << " ";
	}
	output << "\n";
	while (csvReadFile.good()) {
		output << "File can be read" << "\n";
		vector<float> temp;
		getline(csvReadFile, value, '\n');
		size_t pos = 0;
		string token;
		while (pos = value.find(delimiter) != string::npos) {
			token = value.substr(0, pos);
			double t = atof(token.c_str());
			temp.push_back(t);
			value.erase(0, pos + 1);
		}
		pData.push_back(temp);
	}

	
}