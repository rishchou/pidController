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
  pid.setParamkp(0.1);
  pid.setParamki(0.2);
  pid.setParamkd(0.3);
  pid.setParamdt(0.1);
  pid.setParampE(0.0);
  std::cout << " kp = " << pid.getParamkp() << std::endl;
  std::cout << " ki = " << pid.getParamki() << std::endl;
  std::cout << " kd = " << pid.getParamkd() << std::endl;
  double output = pid.compute(40, 35);
  std::cout << " output = " << output << std::endl;
}
