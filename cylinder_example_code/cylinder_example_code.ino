#include <Cylinder.h> //https://github.com/chischte/cylinder-library.git

const byte CYLINDER_VALVE_PIN = 4;

// CREATE AN INSTANCE OF THE LIBRARY CLASS:
Cylinder ExampleCylinder(CYLINDER_VALVE_PIN);

void setup() {
  Serial.begin(9600);
  Serial.println("EXIT SETUP");
}

void loop() {

  ExampleCylinder.set(1); // push cylinder out
  ExampleCylinder.set(0); // pull cylinder back
  ExampleCylinder.toggle(); // change cylinder state

  if (ExampleCylinder.request_state()) {
    // if cylinder is extended, do stuff
  }

  if (!ExampleCylinder.request_state()) {
    // if cylinder is pulled back, do stuff
  }

  ExampleCylinder.stroke(1500, 500); // (push time,pull time)

  if (ExampleCylinder.stroke_completed()) {
    // if cylinder stroke is completed, do stuff}
  }
}
