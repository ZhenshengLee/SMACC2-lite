// Copyright 2021 RobosoftAI Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*****************************************************************************************************************
 *
 * 	 Authors: Pablo Inigo Blasco, Brett Aldrich
 *
 ******************************************************************************************************************/
#pragma once

#include <nav2z_client/components/waypoints_navigator/waypoints_navigator.hpp>
#include <nav2z_client/nav2z_client.hpp>
#include "cb_nav2z_client_behavior_base.hpp"
#include "cb_navigate_next_waypoint.hpp"

namespace cl_nav2z
{
class CbNavigateNamedWaypoint : public CbNavigateNextWaypoint
{
public:
  CbNavigateNamedWaypoint(
    std::string waypointname, std::optional<NavigateNextWaypointOptions> options = std::nullopt);

  virtual ~CbNavigateNamedWaypoint();

  void onEntry() override;

  void onExit() override;

  WaypointNavigator * waypointsNavigator_;

  std::string waypointname_;
};
}  // namespace cl_nav2z