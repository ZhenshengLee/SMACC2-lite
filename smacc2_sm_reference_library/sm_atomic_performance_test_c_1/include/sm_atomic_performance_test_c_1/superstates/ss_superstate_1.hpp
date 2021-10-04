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

namespace sm_atomic_performance_test_c_1
{
namespace SS1
{
namespace sm_atomic_performance_test_c_1
{
namespace inner_states
{
// FORWARD DECLARATIONS OF ALL INNER STATES
class StiState1;
class StiState3;
}  // namespace inner_states
}  // namespace sm_atomic_performance_test_c_1

using namespace sm_atomic_performance_test_c_1::inner_states;

// STATE DECLARATION
struct Ss1 : smacc2::SmaccState<Ss1, MsRun, StiState1>
{
public:
  using SmaccState::SmaccState;

  // TRANSITION TABLE
  typedef mpl::list<

    Transition<EvLoopEnd<StiState1>, StState1>

    >reactions;

  // STATE VARIABLES
  static constexpr int total_iterations() { return 1000; }
  int iteration_count = 0;

  // STATE FUNCTIONS
  static void staticConfigure() {}

  void runtimeConfigure() {}
};  // namespace SS4

// forward declaration for the superstate
using SS = SS1::Ss1;

#include <sm_atomic_performance_test_c_1/states/inner_states/sti_state_1.hpp>
#include <sm_atomic_performance_test_c_1/states/inner_states/sti_state_3.hpp>

}  // namespace SS1
}  // namespace sm_atomic_performance_test_c_1