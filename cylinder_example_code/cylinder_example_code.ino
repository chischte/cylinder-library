#include <Cylinder.h> //https://github.com/chischte/cylinder-library.git

const byte CYLINDER_VALVE_PIN = 4;

// CREATE AN INSTANCE OF THE LIBRARY CLASS:
Cylinder example_cylinder(CYLINDER_VALVE_PIN);

void setup() {
  Serial.begin(9600);
  Serial.println("EXIT SETUP");
}

void loop() {

  example_cylinder.set(1); // push cylinder out
  example_cylinder.set(0); // pull cylinder back
  example_cylinder.toggle(); // change cylinder state

  if (example_cylinder.get_state()) {
    // if cylinder is extended, do stuff
  }

  if (!example_cylinder.get_state()) {
    // if cylinder is pulled back, do stuff
  }

  example_cylinder.stroke(1500, 500); // (push time,pull time)

  if (example_cylinder.stroke_completed()) {
    // if cylinder stroke is completed, do stuff}
  }
  example_cylinder.invert_cylinder_logic(1);
  // inverts the cylinder states and movements
}
