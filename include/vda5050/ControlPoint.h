// Copyright Open Logistics Foundation
//
// Licensed under the Open Logistics Foundation License 1.3.
// For details on the licensing terms, see the LICENSE file.
// SPDX-License-Identifier: OLFL-1.3
//


#ifndef INCLUDE_VDA5050_CONTROLPOINT_H_
#define INCLUDE_VDA5050_CONTROLPOINT_H_

#include <nlohmann/json.hpp>
#include <optional>

namespace vda5050 {
/// ControlPoint describing a trajectory (NURBS)
struct ControlPoint {
  /// X coordinate described in the world coordinate system.
  double x = 0.0;

  /// Y coordinate described in the world coordinate system.
  double y = 0.0;

  /// [rad] Range: [-π ... π]
  /// Orientation of the AGV on this position of the curve. The orientation is in
  /// world coordinates. When not defined the orientation of the AGV will be
  /// tangential to the curve.
  std::optional<double> orientation;

  /// Range : (0 ... ∞)
  /// The weight with which this control point pulls on the curve. When not defined,
  /// the default will be 1.0.
  double weight = 1.0;

  ///
  ///\brief Equality operator
  ///
  ///\param other the other object to compare to
  ///\return is equal?
  ///
  inline bool operator==(const ControlPoint &other) const {
    if (this->x != other.x) return false;
    if (this->y != other.y) return false;
    if (this->orientation != other.orientation) return false;
    if (this->weight != other.weight) return false;

    return true;
  }

  ///
  ///\brief Inequality operator
  ///
  ///\param other the other object to compare to
  ///\return is not equal?
  ///
  inline bool operator!=(const ControlPoint &other) const { return !this->operator==(other); }
};

using json = nlohmann::json;
void to_json(json &j, const ControlPoint &d);
void from_json(const json &j, ControlPoint &d);

}  // namespace vda5050
#endif  // INCLUDE_VDA5050_CONTROLPOINT_H_
