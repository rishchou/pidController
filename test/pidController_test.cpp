/**============================================================================
 * @file         pidController_test.cpp
 * Author      : Rishabh Choudhary
 * Version     : 1.0
 * @Copyright  : GNU Public License
 * Copyright 2018 RishabhChoudhary
 * @brief        Class declaration for pidController
 *============================================================================
 */

#include <gtest/gtest.h>

#include "../include/pidController.h"

/**
 * @brief Testing with zero control variables
 */
TEST(Zero, shouldPass) {
  pidController pid;
  pid.setParamkp(0.0);
  pid.setParamki(0.0);
  pid.setParamkd(0.0);
  pid.setParamdt(0.1);
  pid.setParampE(0.0);
  EXPECT_FLOAT_EQ(0.0, pid.compute(40, 35));
}

/**
 * @brief Testing with positive control variables
 */
TEST(positive, shouldPass) {
  pidController pid;
  double unit = 1;
  pid.setParamkp(unit);
  EXPECT_EQ(unit, pid.getParamkp());
  pid.setParamki(unit);
  EXPECT_EQ(unit, pid.getParamki());
  pid.setParamkd(unit);
  EXPECT_EQ(unit, pid.getParamkd());
  pid.setParamkp(0.1);
  pid.setParamki(0.2);
  pid.setParamkd(0.3);
  pid.setParamdt(0.1);
  pid.setParampE(0.0);
  EXPECT_GE(40, pid.compute(40, 35));
}

/**
 * @brief Testing with negative control variables
 */
TEST(negative, shouldPass) {
  pidController pid;
  pid.setParamkp(-0.1);
  pid.setParamki(-0.2);
  pid.setParamkd(-0.3);
  pid.setParamdt(0.1);
  pid.setParampE(0.0);
  EXPECT_LE(pid.compute(40, 35), 40);
}

