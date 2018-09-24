/**============================================================================
 * @file         pidController.h
 * Author      : Rishabh Choudhary
 * Version     : 1.0
 * @Copyright  : GNU Public License
 * Copyright 2018 RishabhChoudhary
 * @brief        Class declaration for pidController
 *============================================================================
 */

#ifndef PIDCONTROLLER_H_
#define PIDCONTROLLER_H_

/**
 * @brief pidController class
 */
class pidController {
 private:
  double kp;                           // Proportional constant
  double ki;                           // Integral constant
  double kd;                           // Derivative constant
  double dt;                           // Incremental time
  double prevError;                    // Previous Error

 public:

  /**
   * @brief Constructor for PID class
   * @param none
   * @return none
   */
  pidController();

  /**
   * @brief Destructor for PID class
   * @param none
   * @return none
   */
  ~pidController();

  /**
   * @brief Computes output from given setpoint and current velocity
   * @param setPoint setpoint
   * @param cV current velocity
   * @return double computed PID value
   */
  double compute(double setPoint, double cV);

  /**
   * @brief sets kp value
   * @param kp control variable
   * @return none
   */
  void setParamkp(double kp_);

  /**
   * @brief sets ki value
   * @param ki control variable
   * @return none
   */
  void setParamki(double ki_);

  /**
   * @brief sets kd value
   * @param kd control variable
   * @return none
   */
  void setParamkd(double kd_);

  /**
   * @brief sets dt value
   * @param dt time interval
   * @return none
   */
  void setParamdt(double dt_);

  /**
   * @brief sets pE value
   * @param pE previous error value from controller
   * @return none
   */
  void setParampE(double pE_);

  /**
   * @brief gets kp value
   * @param none
   * @return double kp value
   */
  double getParamkp();

  /**
   * @brief gets ki value
   * @param none
   * @return double ki value
   */
  double getParamki();

  /**
   * @brief gets kd value
   * @param none
   * @return double kd value
   */
  double getParamkd();
};

#endif /* PIDCONTROLLER_H_ */
