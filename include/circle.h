// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

#include <cmath>
#include <stdexcept>

class Circle {
 private:
  double radius;
  double ference;
  double area;

  static constexpr double PI = 3.1415;

 public:
  explicit Circle(double x);

  void setRadius(double x);
  void setFerenc(double fer);
  void setAre(double a);

  double getRadius() const;
  double getFerenc() const;
  double getAre() const;

 private:
  void updateRadius();
  void updateFerence();
  void updateArea();
};

#endif  // INCLUDE_CIRCLE_H_
