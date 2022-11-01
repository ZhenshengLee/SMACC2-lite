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

#pragma once
#include <smacc2/client_bases/smacc_subscriber_client.hpp>
#include <std_msgs/msg/u_int16.hpp>

namespace sm_atomic
{
namespace cl_subscriber
{

template <typename AsyncCB, typename Orthogonal>
struct EvEnemyDetected : sc::event<EvEnemyDetected<AsyncCB, Orthogonal>>
{
};

template <typename AsyncCB, typename Orthogonal>
struct EvEnemyClusterDetected : sc::event<EvEnemyClusterDetected<AsyncCB, Orthogonal>>
{
};

template <typename AsyncCB, typename Orthogonal>
struct EvEnemyClusterFireDistance : sc::event<EvEnemyClusterFireDistance<AsyncCB, Orthogonal>>
{
};

class ClSubscriber : public smacc2::client_bases::SmaccSubscriberClient<std_msgs::msg::UInt16>
{
public:

  template <typename TOrthogonal, typename TSourceObject>
  void onOrthogonalAllocation()
  {
    smacc2::client_bases::SmaccSubscriberClient<std_msgs::msg::UInt16>::
      onOrthogonalAllocation<TOrthogonal, TSourceObject>();

    this->postEvEnemyDetected = [this]()
    { this->postEvent<EvEnemyDetected<TSourceObject, TOrthogonal>>(); };

    this->postEvEnemyClusterDetected = [this]()
    { this->postEvent<EvEnemyClusterDetected<TSourceObject, TOrthogonal>>(); };

    this->postEvEnemyClusterFireDistance = [this]()
    { this->postEvent<EvEnemyClusterFireDistance<TSourceObject, TOrthogonal>>(); };
  }

  void MessageCallback(const std_msgs::msg::UInt16 & detectedMsg)
  {
    RCLCPP_ERROR(getLogger(), "[ClSubscriber] MessageCallback");
  }

  void onInitialize() override
  {
    smacc2::client_bases::SmaccSubscriberClient<
      std_msgs::msg::UInt16>::onInitialize();
    this->onMessageReceived(&ClSubscriber::MessageCallback, this);
  }

private:
  std::function<void()> postEvEnemyDetected;
  std::function<void()> postEvEnemyClusterDetected;
  std::function<void()> postEvEnemyClusterFireDistance;

};
}  // namespace cl_subscriber
}  // namespace sm_atomic
