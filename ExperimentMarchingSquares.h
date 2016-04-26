//---------------------------------------------------------------------------
#ifndef ExperimentMarchingSquaresH
#define ExperimentMarchingSquaresH
//---------------------------------------------------------------------------
#include "Experiment.h"
#include "LinearAlgebra.h"
#include "GLGeometryViewer.h"

//---------------------------------------------------------------------------


/// This is an example experiment.
///
/// The code is meant to demonstrate how
///  to use the GeoX framework
///
class ExperimentMarchingSquares : public Experiment
{
	GEOX_CLASS(ExperimentMarchingSquares)

		//Constructor / Destructor
public:
	ExperimentMarchingSquares();
	virtual ~ExperimentMarchingSquares();

	//Methods
public:
	void LoadCSVData();
	virtual QWidget* createViewer();
	void midPointDecider();
	void findBoxes();
	//Attributes
protected:
	GLGeometryViewer* viewer;
	//int circles;
	//int grids;
	

private:

	string FileName;
	float isovalue = 0;
	bool MarchingDecider = 0;
	
};

#endif
