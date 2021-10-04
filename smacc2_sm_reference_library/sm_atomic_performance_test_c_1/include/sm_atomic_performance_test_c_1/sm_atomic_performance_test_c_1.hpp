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

#include <smacc2/smacc.hpp>

// CLIENTS
#include <keyboard_client/cl_keyboard.hpp>
#include <ros_timer_client/cl_ros_timer.hpp>

// ORTHOGONALS
#include <sm_atomic_performance_test_c_1/orthogonals/or_keyboard.hpp>
#include <sm_atomic_performance_test_c_1/orthogonals/or_timer.hpp>

using namespace cl_ros_timer;
using namespace cl_keyboard;

// CLIENT BEHAVIORS
#include <keyboard_client/client_behaviors/cb_default_keyboard_behavior.hpp>

//#include <ros_timer_client/client_behaviors/cb_ros_timer.hpp>
#include <ros_timer_client/client_behaviors/cb_timer_countdown_once.hpp>

// STATE REACTORS
#include <sr_all_events_go/sr_all_events_go.hpp>

using namespace smacc2;
using namespace smacc2::state_reactors;
using namespace smacc2::default_events;

namespace sm_atomic_performance_test_c_1
{
// SUPERSTATES
namespace SS1
{
class Ss1;
}  // namespace SS1

// STATES
class StState1;  // first state specially needs a forward declaration

class MsRun;

struct EvToDeep : sc::event<EvToDeep>
{
};

struct EvFail : sc::event<EvFail>
{
};

// STATE MACHINE
struct SmAtomicPerformanceTestC1 : public smacc2::SmaccStateMachineBase<SmAtomicPerformanceTestC1, MsRun>
{
  using SmaccStateMachineBase::SmaccStateMachineBase;

  void onInitialize() override
  {
    this->createOrthogonal<OrTimer>();
  }
};
}  // namespace sm_atomic_performance_test_c_1

// MODE STATES
#include <sm_atomic_performance_test_c_1/mode_states/ms_run.hpp>

// STATES
#include <sm_atomic_performance_test_c_1/states/st_state_1.hpp>

#include <sm_atomic_performance_test_c_1/superstates/ss_superstate_1.hpp>