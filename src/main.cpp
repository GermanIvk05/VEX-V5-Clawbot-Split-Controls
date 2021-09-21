/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       German_Ivk05                                            */
/*    Created:      Mon Sep 20 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LeftMotor            motor         1               
// RightMotor           motor         10              
// ClawMotor            motor         3               
// ArmMotor             motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

// TODO:
// 1. Reassign different control system if needed and make robot more responsive and precise.
// 2. Find out if robot overturn is caused by high acceleration or deceleration.
// 3. Try using the "setMaxTourque" on LeftMotor and RightMotor to try to remove the overturn problem.
// 4. Have fun coding some ideas to increase the robot's functionality.

// IDEAS:
// 1. Make robot open claw to a specific degree which is perfect for quick ball grabbing.
// 2. Make robot lift arm to a specific degree by a press of a botton and lower arm back by press of the other botton.
//    This should allow the driver to concentrate on driving rather than lifting arm by holding the botton.


#include "vex.h"

using namespace vex;

// Declaration of functions.
void controller_L1_Pressed();
void controller_L2_Pressed();
void controller_R1_Pressed();
void controller_R2_Pressed();

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  // Create Controller callback events - 15 msec delay to ensure events get registered.
  Controller1.ButtonL1.pressed(controller_L1_Pressed);
  Controller1.ButtonL1.pressed(controller_L2_Pressed);
  Controller1.ButtonL1.pressed(controller_R1_Pressed);
  Controller1.ButtonL1.pressed(controller_R2_Pressed);
  wait(15, msec);

  // Different Motor Configuration (MAY NEED TO EXPERIMENT)
  ArmMotor.setStopping(hold);
  ClawMotor.setStopping(hold);
  ArmMotor.setVelocity(60, percent); // Controlls the speed of Arm
  ClawMotor.setVelocity(30, percent); // Controlls the speed of Claw

  // Main Controller loop to set motors to controller axis positions
  while (true) {
    LeftMotor.setVelocity(Controller1.Axis3.position(), percent);
    RightMotor.setVelocity(Controller1.Axis2.position(), percent);
    LeftMotor.spin(forward);
    RightMotor.spin(forward);
    wait(5, msec);
  }
}

void controller_L1_Pressed() {
  // ArmMotor.spinFor(forward, 90, degrees, true); // TRY WITH FALSE to ensure that movement commands are not blocked
  ArmMotor.spin(forward);
  while (Controller1.ButtonL1.pressing()) {
    wait(5, msec);
  }
  ArmMotor.stop();
}

void controller_L2_Pressed() {
  // ArmMotor.spinFor(reverse, 90, degrees, true); // TRY WITH FALSE to ensure that movement commands are not blocked
  ArmMotor.spin(reverse);
  while (Controller1.ButtonL1.pressing()) {
    wait(5, msec);
  }
  ArmMotor.stop();
}

void controller_R1_Pressed() {
  // ClawMotor.spinFor(forward, 90, degrees, true); // TRY WITH FALSE to ensure that movement commands are not blocked
  ClawMotor.spin(forward);
  while (Controller1.ButtonL1.pressing()) {
    wait(5, msec);
  }
  ClawMotor.stop();
}

void controller_R2_Pressed() {
  ClawMotor.spin(reverse);
  while (Controller1.ButtonL1.pressing()) {
    wait(5, msec);
  }
  ClawMotor.stop();
}