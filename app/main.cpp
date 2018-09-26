/**============================================================================
 * @file         main.cpp
 * Author      : Jerrar Bukhari, Rishabh Choudhary
 * Version     : 1.0
 * @Copyright  : GNU Public License
 * Copyright 2018 RishabhChoudhary
 * @brief        Calculate setpoint form current velocity
 *============================================================================
 */

#include "../include/pidController.h"
#include <iostream>

int main() {
  pidController pid;
  pid.setParamkp(0.1);  ///< set proportional gain
  pid.setParamki(0.2);  ///< set integral gain
  pid.setParamkd(0.3);  ///< set derivative gain
  pid.setParamdt(0.1);  ///< set time step interval
  pid.setParampE(0.0);  ///< set previous error to zero
  std::cout << " kp = " << pid.getParamkp() << std::endl;
  std::cout << " ki = " << pid.getParamki() << std::endl;
  std::cout << " kd = " << pid.getParamkd() << std::endl;
  double output = pid.compute(40, 35);  ///< calculate pid output
  std::cout << " output = " << output << std::endl;
}
