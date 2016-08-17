#pragma once

// This file is generated by a script.  Do not edit!
// See drake/examples/Cars/lcm_vector_gen.py.

#include <stdexcept>
#include <string>
#include <Eigen/Core>

#include "drake/systems/framework/basic_state_and_output_vector.h"
#include "lcmtypes/drake/lcmt_simple_car_state_t.hpp"

namespace drake {

/// Describes the row indices of a SimpleCarState.
struct SimpleCarStateIndices {
  /// The total number of rows (coordinates).
  static const int kNumCoordinates = 4;

  // The index of each individual coordinate.
  static const int kX = 0;
  static const int kY = 1;
  static const int kHeading = 2;
  static const int kVelocity = 3;
};

/// Specializes BasicStateAndOutputVector with specific getters and setters.
template <typename T>
class SimpleCarState : public systems::BasicStateAndOutputVector<T> {
 public:
  // An abbreviation for our row index constants.
  typedef SimpleCarStateIndices K;

  /// Default constructor.  Sets all rows to zero.
  SimpleCarState() : systems::BasicStateAndOutputVector<T>(K::kNumCoordinates) {
    this->SetFromVector(VectorX<T>::Zero(K::kNumCoordinates));
  }

  /// @name Getters and Setters
  //@{
  const T x() const { return this->GetAtIndex(K::kX); }
  void set_x(const T& x) { this->SetAtIndex(K::kX, x); }
  const T y() const { return this->GetAtIndex(K::kY); }
  void set_y(const T& y) { this->SetAtIndex(K::kY, y); }
  const T heading() const { return this->GetAtIndex(K::kHeading); }
  void set_heading(const T& heading) { this->SetAtIndex(K::kHeading, heading); }
  const T velocity() const { return this->GetAtIndex(K::kVelocity); }
  void set_velocity(const T& velocity) {
    this->SetAtIndex(K::kVelocity, velocity);
  }
  //@}

  /// @name Implement the LCMVector concept
  //@{
  typedef drake::lcmt_simple_car_state_t LCMMessageType;
  static std::string channel() { return "SIMPLE_CAR_STATE"; }
  //@}
};

template <typename ScalarType>
bool encode(const double& t, const SimpleCarState<ScalarType>& wrap,
            // NOLINTNEXTLINE(runtime/references)
            drake::lcmt_simple_car_state_t& msg) {
  msg.timestamp = static_cast<int64_t>(t * 1000);
  msg.x = wrap.x();
  msg.y = wrap.y();
  msg.heading = wrap.heading();
  msg.velocity = wrap.velocity();
  return true;
}

template <typename ScalarType>
bool decode(const drake::lcmt_simple_car_state_t& msg,
            // NOLINTNEXTLINE(runtime/references)
            double& t,
            // NOLINTNEXTLINE(runtime/references)
            SimpleCarState<ScalarType>& wrap) {
  t = static_cast<double>(msg.timestamp) / 1000.0;
  wrap.set_x(msg.x);
  wrap.set_y(msg.y);
  wrap.set_heading(msg.heading);
  wrap.set_velocity(msg.velocity);
  return true;
}

}  // namespace drake
