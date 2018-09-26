/**============================================================================
 * @file         pidController.cpp
 * Author      : Jerrar Bukhari, Rishabh Choudhary
 * Version     : 1.0
 * @Copyright  : GNU Public License
 * Copyright 2018 RishabhChoudhary
 * @brief        Class definition for pidController
 *============================================================================
 */

#include "../include/pidController.h"

pidController::pidController()
    : kp(0.0),
      ki(0.0),
      kd(0.0),
      dt(0),
      prevError(0) {
}

/**
 * @brief get kp
 * @return kp
 */
double pidController::getParamkp() {
  return kp;
}

/**
 * @brief get ki
 * @return ki
 */
double pidController::getParamki() {
  return ki;
}

/**
 * @brief get kd
 * @return kd
 */
double pidController::getParamkd() {
  return kd;
}

/**
 * @brief set kp
 * @param new kp
 */
void pidController::setParamkp(double kp_) {
  kp = kp_;
}

/**
 * @brief set ki
 * @param new ki
 */
void pidController::setParamki(double ki_) {
  ki = ki_;
}

/**
 * @brief set kd
 * @param new kd
 */
void pidController::setParamkd(double kd_) {
  kd = kd_;
}

/**
 * @brief set dt time interval
 * @param new dt
 */
void pidController::setParamdt(double dt_) {
  dt = dt_;
}

/**
 * @brief set pE previous error
 * @param pE
 */
void pidController::setParampE(double pE_) {
  prevError = pE_;
}

pidController::~pidController() {
}

/**
 * @brief Compute the actuation signal of the pidController
 * @param setpoint the desired target to reach
 * @param cV current velocity
 * @return output the computed pid actuation signal
 */
double pidController::compute(double setPoint, double cV) {
  double error = 0.0;
  double output = 0.0;
  error = setPoint - cV;
  double derivative = (error - prevError) / dt;
  double integral = 0.0;
  integral = integral + error * dt;
  output = kp * error + kd * derivative + ki * integral;
  prevError = error;

  return output;
}
