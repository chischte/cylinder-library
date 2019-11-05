# cylinder-library 

**Library to control switching valves for pneumatic cylinders .**

The library can be usefull for all other two-state-actors as well.

Library Functions
---------------

	
	// CREATE AN INSTANCE OF THE LIBRARY CLASS:
	Cylinder ExampleCylinder(CYLINDER_VALVE_PIN);
	// the pin will be set as an output pin
	
	// PUSH CYLINDER OUT:
	ExampleCylinder.set(1);
	
	// PULL CYLINDER BACK:
	ExampleCylinder.set(0);
	
	// CHANGE CYLINDER STATE
	ExampleCylinder.toggle();
	
	// REQUEST STATE:
	if (ExampleCylinder.request_state()) {
      // if cylinder is extended, do stuff
	}
	
	if (!ExampleCylinder.request_state()) {
      // if cylinder is pulled back, do stuff
	}
	
	// STROKE:
	ExampleCylinder.stroke(1500, 500); // (push time,pull time)
	if (ExampleCylinder.stroke_completed()) {
      // if stroke is completed, do stuff
	}

	// INVERT CYLINDER LOGIC:
	ExampleCylinder.invertCylinderLogic(1);
	// inverts the cylinder states and movements

	// MARK STROKE COMPLETED:
	ExampleCylinder.mark_stroke_completed;
	// This function is usually not required.
	// It is to mark a stroke as completed, in case of it has been early aborted, by an emergency stop for example.
	// Marked as completed, the cylinder will be ready again in the next loop.

**An example of how the functions can be used can be found in the example code.**	
  

Installation
------------
The Library can be installed by cloning or downloading it to Arduinos default library location, e.g. user/documents/Arduino/libraries/.

