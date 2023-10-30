// Copyright Open Logistics Foundation
//
// Licensed under the Open Logistics Foundation License 1.3.
// For details on the licensing terms, see the LICENSE file.
// SPDX-License-Identifier: OLFL-1.3
//

#ifndef INCLUDE_VDA5050_DATA_H_
#define INCLUDE_VDA5050_DATA_H_

#include <nlohmann/json.hpp>
#include <string>
namespace vda5050 {

struct Data {
  std::string type;
  std::string description;

  ///
  ///\brief Equality operator
  ///
  ///\param other the other object to compare to
  ///\return is equal?
  ///
  inline bool operator==(const Data &other) const {
    if (this->type != other.type) return false;
    if (this->description != other.description) return false;

    return true;
  }

  ///
  ///\brief Inequality operator
  ///
  ///\param other the other object to compare to
  ///\return is not equal?
  ///
  inline bool operator!=(const Data &other) const { return !this->operator==(other); }
};

using json = nlohmann::json;
void to_json(json &j, const Data &d);
void from_json(const json &j, Data &d);

}  // namespace vda5050
#endif  // INCLUDE_VDA5050_DATA_H_
