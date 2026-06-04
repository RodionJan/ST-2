// Copyright 2025 UNN-CS
#include "tasks.h"

double earthRopeEnd() {
  constexpr double earth_rad = 6378.1 * 1000.0;
  Circle new_earth(earth_rad);
  new_earth.setFerenc(new_earth.getFerenc() + 1.0);

  return new_earth.getRadius() - earth_rad;
}

double calculateMaterialPr() {
  constexpr double cement_pr = 1000.0;
  constexpr double fence_meter_pr = 2000.0;
  constexpr double pool_rad = 3.0;
  constexpr double walkway_widt = 1.0;

  Circle pool(pool_rad);
  Circle around_pool(pool_rad + walkway_widt);
  double fence_price = 0.0;
  double cement_walkway_price = 0.0;

  fence_price = pool.getFerenc() * fence_meter_pr;
  cement_walkway_price = (around_pool.getAre() - pool.getAre())
                         * cement_pr;
  return fence_price + cement_walkway_price;
}
