// Copyright Open Logistics Foundation
//
// Licensed under the Open Logistics Foundation License 1.3.
// For details on the licensing terms, see the LICENSE file.
// SPDX-License-Identifier: OLFL-1.3
//
//

#include <catch2/catch_all.hpp>
#include <iostream>

#include "generator.h"

template <typename T> void testSerialization(size_t num = 100) {
  std::vector<T> vec(num);

  std::generate(vec.begin(), vec.end(), generator::generate<T>);

  SECTION("Serialization: " + std::string(typeid(T).name())) {
    for (const auto &x : vec) {
      auto ser = nlohmann::json(x).dump();
      T y = nlohmann::json::parse(ser);
      REQUIRE(x == y);
    }
  }
}

template <typename T> void testEquality(size_t num = 100) {
  std::vector<T> vec(num);

  std::generate(vec.begin(), vec.end(), generator::generate<T>);

  SECTION("Equality: " + std::string(typeid(T).name())) {
    for (const auto &x : vec) {
      auto y = x;
      REQUIRE(x == y);
      REQUIRE_FALSE(x != y);
    }
  }
}

TEST_CASE("vda5050_message_structs - serialization", "[vda5050_message_structs][serialization]") {
  generator::RNG::seed(Catch::rngSeed());
  testSerialization<vda5050::AGVPosition>();
  testSerialization<vda5050::Action>();
  testSerialization<vda5050::ActionParameter>();
  testSerialization<vda5050::ActionParameterFactsheet>();
  testSerialization<vda5050::ActionScope>();
  testSerialization<vda5050::ActionState>();
  testSerialization<vda5050::ActionStatus>();
  testSerialization<vda5050::AgvAction>();
  testSerialization<vda5050::AgvFactsheet>();
  testSerialization<vda5050::AgvGeometry>();
  testSerialization<vda5050::BatteryState>();
  testSerialization<vda5050::BlockingType>();
  testSerialization<vda5050::BoundingBoxReference>();
  testSerialization<vda5050::Connection>();
  testSerialization<vda5050::ConnectionState>();
  testSerialization<vda5050::ControlPoint>();
  testSerialization<vda5050::Corridor>();
  testSerialization<vda5050::CorridorRefPoint>();
  testSerialization<vda5050::EStop>();
  testSerialization<vda5050::Edge>();
  testSerialization<vda5050::EdgeState>();
  testSerialization<vda5050::Envelope2d>();
  testSerialization<vda5050::Envelope3d>();
  testSerialization<vda5050::Error>();
  testSerialization<vda5050::ErrorLevel>();
  testSerialization<vda5050::ErrorReference>();
  testSerialization<vda5050::HeaderVDA5050>();
  testSerialization<vda5050::Info>();
  testSerialization<vda5050::InfoLevel>();
  testSerialization<vda5050::InfoReference>();
  testSerialization<vda5050::InstantActions>();
  testSerialization<vda5050::Load>();
  testSerialization<vda5050::LoadDimensions>();
  testSerialization<vda5050::LoadSet>();
  testSerialization<vda5050::LoadSpecification>();
  testSerialization<vda5050::Map>();
  testSerialization<vda5050::MapStatus>();
  testSerialization<vda5050::MaxArrayLens>();
  testSerialization<vda5050::MaxStringLens>();
  testSerialization<vda5050::Network>();
  testSerialization<vda5050::Node>();
  testSerialization<vda5050::NodePosition>();
  testSerialization<vda5050::NodeState>();
  testSerialization<vda5050::OperatingMode>();
  testSerialization<vda5050::OptionalParameter>();
  testSerialization<vda5050::Order>();
  testSerialization<vda5050::OrientationType>();
  testSerialization<vda5050::PhysicalParameters>();
  testSerialization<vda5050::PolygonPoint>();
  testSerialization<vda5050::Position>();
  testSerialization<vda5050::ProtocolFeatures>();
  testSerialization<vda5050::ProtocolLimits>();
  testSerialization<vda5050::SafetyState>();
  testSerialization<vda5050::State>();
  testSerialization<vda5050::Support>();
  testSerialization<vda5050::Timing>();
  testSerialization<vda5050::Trajectory>();
  testSerialization<vda5050::TypeSpecification>();
  testSerialization<vda5050::ValueDataType>();
  testSerialization<vda5050::VehicleConfig>();
  testSerialization<vda5050::Velocity>();
  testSerialization<vda5050::VersionInfo>();
  testSerialization<vda5050::Visualization>();
  testSerialization<vda5050::WheelDefinition>();
  testSerialization<vda5050::WheelType>();
}

TEST_CASE("vda5050_message_structs - equality", "[vda5050_message_structs][equality]") {
  generator::RNG::seed(Catch::rngSeed());
  testEquality<vda5050::AGVPosition>();
  testEquality<vda5050::Action>();
  testEquality<vda5050::ActionParameter>();
  testEquality<vda5050::ActionParameterFactsheet>();
  testEquality<vda5050::ActionScope>();
  testEquality<vda5050::ActionState>();
  testEquality<vda5050::ActionStatus>();
  testEquality<vda5050::AgvAction>();
  testEquality<vda5050::AgvFactsheet>();
  testEquality<vda5050::AgvGeometry>();
  testEquality<vda5050::BatteryState>();
  testEquality<vda5050::BlockingType>();
  testEquality<vda5050::BoundingBoxReference>();
  testEquality<vda5050::Connection>();
  testEquality<vda5050::ConnectionState>();
  testEquality<vda5050::ControlPoint>();
  testEquality<vda5050::Corridor>();
  testEquality<vda5050::CorridorRefPoint>();
  testEquality<vda5050::EStop>();
  testEquality<vda5050::Edge>();
  testEquality<vda5050::EdgeState>();
  testEquality<vda5050::Envelope2d>();
  testEquality<vda5050::Envelope3d>();
  testEquality<vda5050::Error>();
  testEquality<vda5050::ErrorLevel>();
  testEquality<vda5050::ErrorReference>();
  testEquality<vda5050::HeaderVDA5050>();
  testEquality<vda5050::Info>();
  testEquality<vda5050::InfoLevel>();
  testEquality<vda5050::InfoReference>();
  testEquality<vda5050::InstantActions>();
  testEquality<vda5050::Load>();
  testEquality<vda5050::LoadDimensions>();
  testEquality<vda5050::LoadSet>();
  testEquality<vda5050::LoadSpecification>();
  testEquality<vda5050::Map>();
  testEquality<vda5050::MapStatus>();
  testEquality<vda5050::MaxArrayLens>();
  testEquality<vda5050::MaxStringLens>();
  testEquality<vda5050::Network>();
  testEquality<vda5050::Node>();
  testEquality<vda5050::NodePosition>();
  testEquality<vda5050::NodeState>();
  testEquality<vda5050::OperatingMode>();
  testEquality<vda5050::OptionalParameter>();
  testEquality<vda5050::Order>();
  testEquality<vda5050::OrientationType>();
  testEquality<vda5050::PhysicalParameters>();
  testEquality<vda5050::PolygonPoint>();
  testEquality<vda5050::Position>();
  testEquality<vda5050::ProtocolFeatures>();
  testEquality<vda5050::ProtocolLimits>();
  testEquality<vda5050::SafetyState>();
  testEquality<vda5050::State>();
  testEquality<vda5050::Support>();
  testEquality<vda5050::Timing>();
  testEquality<vda5050::Trajectory>();
  testEquality<vda5050::TypeSpecification>();
  testEquality<vda5050::ValueDataType>();
  testEquality<vda5050::VehicleConfig>();
  testEquality<vda5050::Velocity>();
  testEquality<vda5050::VersionInfo>();
  testEquality<vda5050::Visualization>();
  testEquality<vda5050::WheelDefinition>();
  testEquality<vda5050::WheelType>();
}

TEST_CASE("vda5050_message_structs - empty optional network is omitted",
          "[vda5050_message_structs][serialization]") {
  vda5050::VehicleConfig vehicle_config;
  vehicle_config.versions = std::vector<vda5050::VersionInfo>{{"factsheetIndex", "1"}};
  vehicle_config.network = vda5050::Network{};

  const auto serialized_vehicle_config = nlohmann::json(vehicle_config);
  REQUIRE(serialized_vehicle_config.contains("versions"));
  REQUIRE_FALSE(serialized_vehicle_config.contains("network"));

  vda5050::AgvFactsheet factsheet;
  factsheet.vehicleConfig = vehicle_config;

  const auto serialized_factsheet = nlohmann::json(factsheet);
  REQUIRE(serialized_factsheet.contains("vehicleConfig"));
  REQUIRE(serialized_factsheet.at("vehicleConfig").contains("versions"));
  REQUIRE_FALSE(serialized_factsheet.at("vehicleConfig").contains("network"));
}

TEST_CASE("vda5050_message_structs - required optional-only objects serialize as empty objects",
          "[vda5050_message_structs][serialization]") {
  const auto serialized_agv_geometry = nlohmann::json(vda5050::AgvGeometry{});
  REQUIRE(serialized_agv_geometry.is_object());
  REQUIRE(serialized_agv_geometry.empty());

  const auto serialized_load_specification = nlohmann::json(vda5050::LoadSpecification{});
  REQUIRE(serialized_load_specification.is_object());
  REQUIRE(serialized_load_specification.empty());

  const auto serialized_max_string_lens = nlohmann::json(vda5050::MaxStringLens{});
  REQUIRE(serialized_max_string_lens.is_object());
  REQUIRE(serialized_max_string_lens.empty());

  const auto serialized_max_array_lens = nlohmann::json(vda5050::MaxArrayLens{});
  REQUIRE(serialized_max_array_lens.is_object());
  REQUIRE(serialized_max_array_lens.empty());

  vda5050::AgvFactsheet factsheet;
  const auto serialized_factsheet = nlohmann::json(factsheet);
  REQUIRE(serialized_factsheet.at("agvGeometry").is_object());
  REQUIRE(serialized_factsheet.at("agvGeometry").empty());
  REQUIRE(serialized_factsheet.at("loadSpecification").is_object());
  REQUIRE(serialized_factsheet.at("loadSpecification").empty());
  REQUIRE(serialized_factsheet.at("protocolLimits").at("maxStringLens").is_object());
  REQUIRE(serialized_factsheet.at("protocolLimits").at("maxStringLens").empty());
  REQUIRE(serialized_factsheet.at("protocolLimits").at("maxArrayLens").is_object());
  REQUIRE(serialized_factsheet.at("protocolLimits").at("maxArrayLens").empty());
}
