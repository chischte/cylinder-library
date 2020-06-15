# cylinder-library 

**Library to control switching valves for pneumatic cylinders .**

The library can be usefull for all other two-state-actors as well.

Library Functions
---------------

	
	// CREATE AN INSTANCE OF THE LIBRARY CLASS:
	Cylinder example_cylinder(CYLINDER_VALVE_PIN);
	// the pin will be set as an output pin
	
	// PUSH CYLINDER OUT:
	example_cylinder.set(1);
	
	// PULL CYLINDER BACK:
	example_cylinder.set(0);
	
	// CHANGE CYLINDER STATE
	example_cylinder.toggle();
	
	// REQUEST STATE:
	if (example_cylinder.request_state()) {
      // if cylinder is extended, do stuff
	}
	
	if (!example_cylinder.request_state()) {
      // if cylinder is pulled back, do stuff
	}
	
	// STROKE:
	example_cylinder.stroke(1500, 500); // (push time,pull time)
	if (example_cylinder.stroke_completed()) {
      // if stroke is completed, do stuff
	}

	// INVERT CYLINDER LOGIC:
	example_cylinder.invert_cylinder_logic(1);
	// inverts the cylinder states and movements

	// ABORT STROKE:
	example_cylinder.mark_stroke_completed;
	// Sets the cylinder back to its low state and marks the stroke as completed.

**An example of how the functions can be used can be found in the example code.**	
  

Installation
------------
The Library can be installed by cloning or downloading it to Arduinos default library location, e.g. user/documents/Arduino/libraries/.

