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

#include <smacc2/smacc.hpp>

// CLIENTS
#include <ros_timer_client/cl_ros_timer.hpp>
#include "clients/cl_temperature_sensor/cl_temperature_sensor.hpp"
#include "clients/cl_subscriber/cl_subscriber.hpp"

//CLIENT BEHAVIORS
#include <ros_timer_client/client_behaviors/cb_timer_countdown_loop.hpp>
#include <ros_timer_client/client_behaviors/cb_timer_countdown_once.hpp>
#include "clients/cl_temperature_sensor/client_behaviors/cb_custom_condition_temperature_sensor.hpp"
#include "clients/cl_subscriber/client_behaviors/cb_default_subscriber_behavior.hpp"

// ORTHOGONALS
#include "orthogonals/or_timer.hpp"
#include "orthogonals/or_temperature_sensor.hpp"
#include "orthogonals/or_subscriber.hpp"

using namespace boost;
using namespace smacc2;

using namespace sm_atomic::cl_temperature_sensor;
using namespace sm_atomic::cl_subscriber;

namespace sm_atomic
{
//STATE
class State1;
class State2;

//--------------------------------------------------------------------
//STATE_MACHINE
struct SmAtomic : public smacc2::SmaccStateMachineBase<SmAtomic, State1>
{
  using SmaccStateMachineBase::SmaccStateMachineBase;

  virtual void onInitialize() override
  {
    this->createOrthogonal<OrTimer>();
    this->createOrthogonal<OrTemperatureSensor>();
    // this->createOrthogonal<OrSubscriber>();
  }
};

}  // namespace sm_atomic

#include "states/st_state_1.hpp"
#include "states/st_state_2.hpp"
