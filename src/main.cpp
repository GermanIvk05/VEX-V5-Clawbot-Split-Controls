/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       GermanIvk05                                               */
/*    Created:      Mon Sep 20 2021                                           */
/*    Description:  Slit controls for VEX Clawbot                             */
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
  ArmMotor.spin(forward);
  while (Controller1.ButtonL1.pressing()) {
    wait(5, msec);
  }
  ArmMotor.stop();
}

void controller_L2_Pressed() {
  ArmMotor.spin(reverse);
  while (Controller1.ButtonL1.pressing()) {
    wait(5, msec);
  }
  ArmMotor.stop();
}

void controller_R1_Pressed() {
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
