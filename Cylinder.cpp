/*
 * *****************************************************************************
 * Cylinder.cpp
 * Library to control switching valves for pneumatic cylinders
 * Michael Wettstein
 * November 2018, Zürich
 * *****************************************************************************
 */

#include "Arduino.h"
#include "Cylinder.h"

Cylinder::Cylinder(int pin) {
  pinMode(pin, OUTPUT);
  _pin = pin;
}
//***************************************************************************
//LIBRARY FUNCTIONS:
//***************************************************************************
void Cylinder::stroke(unsigned int push_time, unsigned int release_time) {
  if (_stroke_completed == true) // reset timer once at beginning
          {
    if (!_invertLogic) {
      digitalWrite(_pin, HIGH);
    } else {
      digitalWrite(_pin, LOW);
    }
    _state = HIGH;
    _prev_time = millis();
    _stroke_completed = false;
  }
  if (millis() - _prev_time > push_time) {
    if (!_invertLogic) {
      digitalWrite(_pin, LOW);
    } else {
      digitalWrite(_pin, HIGH);
    }
    _state = LOW;
    if (millis() - _prev_time > (push_time + release_time)) {
      _stroke_completed = true; // triggers next cycle state
    }
  }
}

bool Cylinder::stroke_completed() {
  return _stroke_completed;
}

void Cylinder::abort_stroke() {
  if (!_invertLogic) {
    digitalWrite(_pin, LOW);
  } else {
    digitalWrite(_pin, HIGH);
  }
  _stroke_completed = true;
}

void Cylinder::toggle() {
  _state = !_state;
  if (!_invertLogic) {
    digitalWrite(_pin, _state);
  } else {
    digitalWrite(_pin, !_state);
  }
}

void Cylinder::set(bool set_state) {
  if (!_invertLogic) {
    digitalWrite(_pin, set_state);
  } else {
    digitalWrite(_pin, !set_state);
  }
  _state = set_state;
}

bool Cylinder::request_state() {
  if (!_invertLogic) {
    _state = digitalRead(_pin);
  } else {
    _state = !digitalRead(_pin);
  }
  return _state;
}
void Cylinder::invertCylinderLogic(bool invertLogic) {
  _invertLogic = invertLogic;
}
