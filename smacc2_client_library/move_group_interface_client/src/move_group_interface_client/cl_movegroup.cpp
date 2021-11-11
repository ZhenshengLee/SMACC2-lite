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

#include <move_group_interface_client/cl_movegroup.hpp>

using namespace std::chrono_literals;
using namespace moveit::planning_interface;

namespace cl_move_group_interface
{
ClMoveGroup::ClMoveGroup(std::string groupName)
: moveGroupClientInterface(getNode(), MoveGroupInterface::Options(groupName))
{
  rclcpp::sleep_for(10s);
}

ClMoveGroup::~ClMoveGroup() {}

void ClMoveGroup::postEventMotionExecutionSucceded()
{
  RCLCPP_INFO(getLogger(), "[ClMoveGroup] Post Motion Success Event");
  postEventMotionExecutionSucceded_();
}

void ClMoveGroup::postEventMotionExecutionFailed()
{
  RCLCPP_INFO(getLogger(), "[ClMoveGroup] Post Motion Failure Event");
  postEventMotionExecutionFailed_();
}

}  // namespace cl_move_group_interface