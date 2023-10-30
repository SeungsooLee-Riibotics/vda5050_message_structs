// Copyright Open Logistics Foundation
//
// Licensed under the Open Logistics Foundation License 1.3.
// For details on the licensing terms, see the LICENSE file.
// SPDX-License-Identifier: OLFL-1.3
//


#ifndef INCLUDE_VDA5050_VISUALIZATION_H_
#define INCLUDE_VDA5050_VISUALIZATION_H_

#include "vda5050/AGVPosition.h"
#include "Header_vda5050.h"
#include "vda5050/Velocity.h"
#include <nlohmann/json.hpp>

namespace vda5050 {
/// VD(M)A 5050 Visualization message
struct Visualization {
  /// Message header
  HeaderVDA5050 header;
  /// The AGV's position
  AGVPosition agvPosition;
  /// The AGV's velocity in vehicle coordinates
  Velocity velocity;

  inline bool operator==(const Visualization &other) const {
    if (header != other.header) return false;
    if (agvPosition != other.agvPosition) return false;
    if (velocity != other.velocity) return false;
    return true;
  }
  inline bool operator!=(const Visualization &other) const { return !(this->operator==(other)); }
};

using json = nlohmann::json;
void to_json(json &j, const Visualization &d);
void from_json(const json &j, Visualization &d);

}  // namespace vda5050
#endif  // INCLUDE_VDA5050_VISUALIZATION_H_
