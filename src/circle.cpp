#include <cstdint>
#include <cmath>
#include <stdexcept>
#include "circle.h"

Circle::Circle(double x) {
  setRadius(x);
}

void Circle::setRadius(double x) {
  if (x < 0) {
    throw std::invalid_argument(
        "Радиус отрицательным быть не может");
  }
  radius = x;
  updateRadius();
}

void Circle::setFerenc(double fer) {
  if (fer < 0) {
    throw std::invalid_argument(
        "Длина окружности отрицательной быть не может");
  }
  ference = fer;
  updateFerence();
}

void Circle::setAre(double ar) {
  if (ar < 0) {
    throw std::invalid_argument(
        "Площадь отрицательной быть не может");
  }
  area = ar;
  updateArea();
}

double Circle::getRadius() const {
  return radius;
}

double Circle::getFerenc() const {
  return ference;
}

double Circle::getAre() const {
  return area;
}

void Circle::updateRadius() {
  ference = 2.0 * PI * radius;
  area = PI * radius * radius;
}

void Circle::updateFerence() {
  radius = ference / (PI * 2.0);
  area = PI * radius * radius;
}

void Circle::updateArea() {
  radius = std::sqrt(area / PI);
  ference = 2.0 * PI * radius;
}
