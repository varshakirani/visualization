//---------------------------------------------------------------------------
#include "stdafx.h"
//---------------------------------------------------------------------------
#include "InitGeoX.h"
//---------------------------------------------------------------------------
#include "Camera.h"
#include "ViewFrustum.h"
#include "CameraController.h"
#include "ClassCreator.h"
#include "ClassEditor.h"
#include "ExaminerCameraController.h"
#include "Persistent.h"
#include "PropertyBrowser.h"
#include "PropertyEditor.h"
#include "WalkthroughCameraController.h"
#include "StreamClassTable.h"
#include "LegacyClassNameTranslation.h"

#include "BooleanPropertyEditor.h"
#include "ObjectPropertyEditor.h"
#include "FixedArrayPropertyEditor.h"
#include "ClassTypeClassProperty.h"
#include "ClassTypeClassPropertyEditorWidget.h"

#include "Experiment.h"
#include "ExampleExperiment.h"
#include "ExampleExperiment2DGraphics.h"
#include "ExampleExperiment3DGraphics.h"
#include "ExampleExperimentMarchingCubes.h"
#include "ExampleExperimentFields.h"
#include "ExampleExperimentScatterPlot.h"
#include "Experiment2D.h"
#include "Experiment2D22.h"
// ...
// include your experiments here

// ...

//---------------------------------------------------------------------------

void init()
{
    Object::init(NULL);
    ClassCreator::init(Object::getClass());
    PropertyEditor::init(Object::getClass());
    BooleanPropertyEditor::init(PropertyEditor::getClass());
    ObjectPropertyEditor::init(PropertyEditor::getClass());
    FixedArrayPropertyEditor::init(PropertyEditor::getClass());
    ClassEditor::init(Object::getClass());
    PropertyBrowser::init(ClassEditor::getClass());
    Persistent::init(Object::getClass());
    StreamClassTable::init(Persistent::getClass());
    Camera::init(Persistent::getClass());
    ViewFrustum::init(Persistent::getClass());
    CameraController::init(Persistent::getClass());
    ExaminerCameraController::init(CameraController::getClass());
    WalkthroughCameraController::init(CameraController::getClass());

    Experiment::init(Persistent::getClass());
    ExampleExperiment::init(Experiment::getClass());
    ExampleExperiment2DGraphics::init(Experiment::getClass());
    ExampleExperiment3DGraphics::init(Experiment::getClass());
    ExampleExperimentMarchingCubes::init(Experiment::getClass());
    ExampleExperimentFields::init(Experiment::getClass());
    ExampleExperimentScatterPlot::init(Experiment::getClass());
	
	Experiment2D::init(Experiment::getClass());
	Experiment2D22::init(Experiment::getClass());
	// ...
    // register your experiments here

    // ...
}

void shutdown()
{
    Object::shutdown();
    ClassEditor::shutdown();
    Persistent::shutdown();
    StreamClassTable::shutdown();
    Camera::shutdown();
    ViewFrustum::shutdown();
    CameraController::shutdown();
    ExaminerCameraController::shutdown();
    WalkthroughCameraController::shutdown();
    BooleanPropertyEditor::shutdown();
    ObjectPropertyEditor::shutdown();
    FixedArrayPropertyEditor::shutdown();
    PropertyBrowser::shutdown();

    Experiment::shutdown();
    ExampleExperiment::shutdown();
    ExampleExperiment2DGraphics::shutdown();
    ExampleExperiment3DGraphics::shutdown();
    ExampleExperimentMarchingCubes::shutdown();
    ExampleExperimentFields::shutdown();
    ExampleExperimentScatterPlot::shutdown();
	
	Experiment2D::shutdown();
	Experiment2D22::shutdown();
    // ...
    // unregister your experiments here

    // ...
}
