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

namespace sm_multi_stage_1
{

// STATE DECLARATION
struct ACCycleLoop3 : smacc2::SmaccState<ACCycleLoop3, MsRun3>
{
public:
  using SmaccState::SmaccState;

  // TRANSITION TABLE
  typedef mpl::list<

     Transition<EvLoopContinue<ACCycleLoop3>, SsACCycle3, CONTINUELOOP>

    >reactions;

  // STATE FUNCTIONS
  static void staticConfigure() {}

  void runtimeConfigure() {}

  bool loopWhileCondition()
  {
    auto & superstate = this->context<MsRun3>();

    RCLCPP_INFO(
      getLogger(), "Loop start, current iterations: %d, total iterations: %d",
      superstate.ziteration_count, superstate.ztotal_iterations());
    return superstate.ziteration_count++ < superstate.ztotal_iterations();
  }

  void onEntry()
  {
    RCLCPP_INFO(getLogger(), "LOOP START ON ENTRY");
    checkWhileLoopConditionAndThrowEvent(&ACCycleLoop3::loopWhileCondition);
  }
};
}  // namespace sm_multi_stage_1