// Copyright 2024 Student

#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "circle.h"
#include "tasks.h"

TEST(CircleTest, ConstructorAndGetters) {
  Circle circle(5.0);

  EXPECT_DOUBLE_EQ(5.0, circle.getRadius());
  EXPECT_NEAR(2 * 3.1415 * 5.0, circle.getFerenc(), 1e-10);
  EXPECT_NEAR(3.1415 * 25.0, circle.getAre(), 1e-10);
}

TEST(CircleTest, ZeroRadius) {
  Circle circle(0.0);

  EXPECT_DOUBLE_EQ(0.0, circle.getRadius());
  EXPECT_DOUBLE_EQ(0.0, circle.getFerenc());
  EXPECT_DOUBLE_EQ(0.0, circle.getAre());
}

TEST(CircleTest, NegativeRadiusInConstructor) {
  EXPECT_THROW({
    Circle circle(-5.0);
  }, std::invalid_argument);
}

TEST(CircleTest, SetRadius) {
  Circle circle(1.0);
  circle.setRadius(3.0);

  EXPECT_DOUBLE_EQ(3.0, circle.getRadius());
  EXPECT_NEAR(2 * 3.1415 * 3.0, circle.getFerenc(), 1e-10);
  EXPECT_NEAR(3.1415 * 9.0, circle.getAre(), 1e-10);
}

TEST(CircleTest, SetNegativeRadius) {
  Circle circle(1.0);

  EXPECT_THROW({
    circle.setRadius(-2.0);
  }, std::invalid_argument);

  EXPECT_DOUBLE_EQ(1.0, circle.getRadius());
  EXPECT_NEAR(2 * 3.1415, circle.getFerenc(), 1e-10);
  EXPECT_NEAR(3.1415, circle.getAre(), 1e-10);
}

TEST(CircleTest, SetZeroRadius) {
  Circle circle(1.0);

  EXPECT_NO_THROW(circle.setRadius(0.0););

  EXPECT_DOUBLE_EQ(0.0, circle.getRadius());
  EXPECT_DOUBLE_EQ(0.0, circle.getFerenc());
  EXPECT_DOUBLE_EQ(0.0, circle.getAre());
}

TEST(CircleTest, setFerenc) {
  Circle circle(1.0);
  double newFerence = 10.0;
  circle.setFerenc(newFerence);

  double expectedRadius = newFerence / (2 * 3.1415);
  double expectedArea = 3.1415 * expectedRadius * expectedRadius;

  EXPECT_NEAR(expectedRadius, circle.getRadius(), 1e-10);
  EXPECT_DOUBLE_EQ(newFerence, circle.getFerenc());
  EXPECT_NEAR(expectedArea, circle.getAre(), 1e-10);
}

TEST(CircleTest, SetNegativeFerence) {
  Circle circle(1.0);
  double oldFerence = circle.getFerenc();
  double oldRadius = circle.getRadius();
  double oldArea = circle.getAre();

  EXPECT_THROW({
    circle.setFerenc(-5.0);
  }, std::invalid_argument);

  EXPECT_DOUBLE_EQ(oldRadius, circle.getRadius());
  EXPECT_DOUBLE_EQ(oldFerence, circle.getFerenc());
  EXPECT_DOUBLE_EQ(oldArea, circle.getAre());
}

TEST(CircleTest, SetZeroFerence) {
  Circle circle(1.0);
  circle.setFerenc(0.0);

  EXPECT_DOUBLE_EQ(0.0, circle.getRadius());
  EXPECT_DOUBLE_EQ(0.0, circle.getFerenc());
  EXPECT_DOUBLE_EQ(0.0, circle.getAre());
}

TEST(CircleTest, setAre) {
  Circle circle(1.0);
  double newArea = 50.0;
  circle.setAre(newArea);

  double expectedRadius = std::sqrt(newArea / 3.1415);
  double expectedFerence = 2 * 3.1415 * expectedRadius;

  EXPECT_NEAR(expectedRadius, circle.getRadius(), 1e-10);
  EXPECT_NEAR(expectedFerence, circle.getFerenc(), 1e-10);
  EXPECT_NEAR(newArea, circle.getAre(), 1e-10);
}

TEST(CircleTest, SetNegativeArea) {
  Circle circle(1.0);
  double oldArea = circle.getAre();
  double oldRadius = circle.getRadius();
  double oldFerence = circle.getFerenc();

  EXPECT_THROW({
    circle.setAre(-10.0);
  }, std::invalid_argument);

  EXPECT_DOUBLE_EQ(oldRadius, circle.getRadius());
  EXPECT_DOUBLE_EQ(oldFerence, circle.getFerenc());
  EXPECT_DOUBLE_EQ(oldArea, circle.getAre());
}

TEST(CircleTest, SetZeroArea) {
  Circle circle(1.0);
  circle.setAre(0.0);

  EXPECT_DOUBLE_EQ(0.0, circle.getRadius());
  EXPECT_DOUBLE_EQ(0.0, circle.getFerenc());
  EXPECT_DOUBLE_EQ(0.0, circle.getAre());
}

TEST(CircleTest, SequentialChanges) {
  Circle circle(2.0);

  circle.setRadius(3.0);
  EXPECT_NEAR(3.0, circle.getRadius(), 1e-10);
  EXPECT_NEAR(2 * 3.1415 * 3.0, circle.getFerenc(), 1e-10);
  EXPECT_NEAR(3.1415 * 9.0, circle.getAre(), 1e-10);

  circle.setFerenc(20.0);
  double r = 20.0 / (2 * 3.1415);
  EXPECT_NEAR(r, circle.getRadius(), 1e-10);
  EXPECT_NEAR(20.0, circle.getFerenc(), 1e-10);
  EXPECT_NEAR(3.1415 * r * r, circle.getAre(), 1e-10);

  circle.setAre(100.0);
  r = std::sqrt(100.0 / 3.1415);
  EXPECT_NEAR(r, circle.getRadius(), 1e-10);
  EXPECT_NEAR(2 * 3.1415 * r, circle.getFerenc(), 1e-10);
  EXPECT_NEAR(100.0, circle.getAre(), 1e-10);
}

TEST(CircleTest, FerenceGettingFormula) {
  Circle circle(4.0);

  EXPECT_NEAR(2 * 3.1415 * circle.getRadius(), circle.getFerenc(), 1e-10);
}

TEST(CircleTest, SquareGettingFormula) {
  Circle circle(4.0);

  EXPECT_NEAR(3.1415 * circle.getRadius() * circle.getRadius(),
              circle.getAre(), 1e-10);
}

TEST(CircleTest, RadiusGettingFormulas) {
  Circle circle(4.0);

  EXPECT_NEAR(circle.getFerenc() / (2 * 3.1415), circle.getRadius(), 1e-10);

  EXPECT_NEAR(std::sqrt(circle.getAre() / 3.1415), circle.getRadius(), 1e-10);
}

TEST(CircleTest, MathematicalProperties) {
  Circle circle(3.0);

  EXPECT_NEAR(circle.getFerenc() / circle.getRadius(), 2 * 3.1415, 1e-10);

  EXPECT_NEAR(circle.getAre() / (circle.getRadius() * circle.getRadius()),
              3.1415, 1e-10);

  EXPECT_NEAR(circle.getFerenc() * circle.getFerenc(),
              4 * 3.1415 * circle.getAre(), 1e-8);
}

TEST(CircleTest, LargeNumbers) {
  double largeRadius = 1e6;
  Circle circle(largeRadius);

  EXPECT_NEAR(largeRadius, circle.getRadius(), 1e-6);
  EXPECT_NEAR(2 * 3.1415 * largeRadius, circle.getFerenc(), 1e-6);
  EXPECT_NEAR(3.1415 * largeRadius * largeRadius, circle.getAre(), 1e-6);
}

TEST(CircleTest, VerySmallNumbers) {
  double smallRadius = 1e-6;
  Circle circle(smallRadius);

  EXPECT_NEAR(smallRadius, circle.getRadius(), 1e-12);
  EXPECT_NEAR(2 * 3.1415 * smallRadius, circle.getFerenc(), 1e-12);
  EXPECT_NEAR(3.1415 * smallRadius * smallRadius, circle.getAre(), 1e-12);
}

TEST(CircleTest, PrecisionWithPI) {
  Circle circle(1.0);

  EXPECT_NEAR(2 * 3.1415, circle.getFerenc(), 1e-10);

  circle.setFerenc(6.283);
  EXPECT_NEAR(1.0, circle.getRadius(), 0.001);

  circle.setRadius(2.0);
  EXPECT_NEAR(4 * 3.1415, circle.getAre(), 1e-10);
}

TEST(EarthTaskTest, CorrectCalcTask) {
  EXPECT_NEAR(earthRopeEnd(), 0.15916, 1e-5);
}

TEST(PoolTaskTest, CorrectCalcTask) {
  EXPECT_NEAR(calculateMaterialPr(), 59600, 100.0);
}
