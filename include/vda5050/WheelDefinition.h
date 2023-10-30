// Copyright Open Logistics Foundation
//
// Licensed under the Open Logistics Foundation License 1.3.
// For details on the licensing terms, see the LICENSE file.
// SPDX-License-Identifier: OLFL-1.3
//

#ifndef VDA5050_WHEELDEFINITION_H_
#define VDA5050_WHEELDEFINITION_H_

#include <nlohmann/json.hpp>
#include <optional>
#include <string>

#include "vda5050/Position.h"
#include "vda5050/WheelType.h"

namespace vda5050 {

struct WheelDefinition {
  /// Wheel type DRIVE, CASTER, FIXED, MECANUM.
  WheelType type;

  /// "true": wheel is actively driven (de: angetrieben).
  bool isActiveDriven;

  /// "true": wheel is actively steered (de: aktiv gelenkt).
  bool isActiveSteered;

  Position position;

  /// [m], nominal diameter of wheel.
  double diameter;

  /// [m], nominal width of wheel.
  double width;

  /// [m], nominal displacement of the wheel’s center to the rotation point (necessary for caster
  /// wheels). If the parameter is not defined, it is assumed to be 0.
  std::optional<double> centerDisplacement;

  /// Free-form text: can be used by the manufacturer to define constraints.
  std::optional<std::string> constrains;

  ///
  ///\brief Equality operator
  ///
  ///\param other the other object to compare to
  ///\return is equal?
  ///
  inline bool operator==(const WheelDefinition &other) const {
    if (this->type != other.type) return false;
    if (this->isActiveDriven != other.isActiveDriven) return false;
    if (this->isActiveSteered != other.isActiveSteered) return false;
    if (this->position != other.position) return false;
    if (this->diameter != other.diameter) return false;
    if (this->width != other.width) return false;
    if (this->centerDisplacement != other.centerDisplacement) return false;
    if (this->constrains != other.constrains) return false;

    return true;
  }

  ///
  ///\brief Inequality operator
  ///
  ///\param other the other object to compare to
  ///\return is not equal?
  ///
  inline bool operator!=(const WheelDefinition &other) const { return !this->operator==(other); }
};

using json = nlohmann::json;
void to_json(json &j, const WheelDefinition &d);
void from_json(const json &j, WheelDefinition &d);

}  // namespace vda5050
#endif  // VDA5050_WHEELDEFINITION_H_
