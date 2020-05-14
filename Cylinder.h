/*
 * *****************************************************************************
 * Cylinder.h
 * Library to control switching valves for pneumatic cylinders
 * Michael Wettstein
 * November 2018, Zürich
 * *****************************************************************************
 */

#ifndef Cylinder_h
#define Cylinder_h

#include "Arduino.h"

class Cylinder {
public:
  // FUNTIONS:
  Cylinder(int pin);
  void abort_stroke();
  void stroke(unsigned long push_time, unsigned long release_time);
  void toggle();
  void invertCylinderLogic(bool invertLogic);
  void set(bool set_state);
  bool get_state();
  bool stroke_completed();

  // VARIABLES:

private:
  // FUNTIONS:
  // n.a.

  // VARIABLES:
  unsigned long _prev_time = 0;
  bool _state = 0;
  bool _stroke_completed = true;
  int _pin = 0;
  bool _invertLogic = false;
};

#endif
