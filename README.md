# cylinder-library 

**Library to control switching valves for pneumatic cylinders .**


Library Functions
---------------

	
	// CREATE AN INSTANCE OF THE LIBRARY CLASS:
	Cylinder ExampleCylinder(CYLINDER_VALVE_PIN);
	
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
      // if stroke is completed, do stuff}
	}
 

**An example of how the functions can be used can be found in the example code "cylinder_example_code".**	
  

Installation
------------
The Library can be installed by cloning or downloading it to Arduinos default library location, e.g. user/documents/Arduino/libraries/.

