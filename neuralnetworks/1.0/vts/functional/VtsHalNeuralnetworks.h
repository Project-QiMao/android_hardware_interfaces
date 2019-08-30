/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_HARDWARE_NEURALNETWORKS_V1_0_VTS_HAL_NEURALNETWORKS_H
#define ANDROID_HARDWARE_NEURALNETWORKS_V1_0_VTS_HAL_NEURALNETWORKS_H

#include <android/hardware/neuralnetworks/1.0/IDevice.h>
#include <android/hardware/neuralnetworks/1.0/types.h>

#include <VtsHalHidlTargetTestBase.h>
#include <VtsHalHidlTargetTestEnvBase.h>

#include <android-base/macros.h>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

#include "TestHarness.h"

namespace android::hardware::neuralnetworks::V1_0::vts::functional {

// A class for test environment setup
class NeuralnetworksHidlEnvironment : public ::testing::VtsHalHidlTargetTestEnvBase {
    DISALLOW_COPY_AND_ASSIGN(NeuralnetworksHidlEnvironment);
    NeuralnetworksHidlEnvironment() = default;

  public:
    static NeuralnetworksHidlEnvironment* getInstance();
    void registerTestServices() override;
};

// The main test class for NEURALNETWORKS HIDL HAL.
class NeuralnetworksHidlTest : public ::testing::VtsHalHidlTargetTestBase {
    DISALLOW_COPY_AND_ASSIGN(NeuralnetworksHidlTest);

  public:
    NeuralnetworksHidlTest() = default;
    void SetUp() override;
    void TearDown() override;

  protected:
    const sp<IDevice> device = ::testing::VtsHalHidlTargetTestBase::getService<IDevice>(
            NeuralnetworksHidlEnvironment::getInstance());
};

}  // namespace android::hardware::neuralnetworks::V1_0::vts::functional

namespace android::hardware::neuralnetworks::V1_0 {

// pretty-print values for error messages
::std::ostream& operator<<(::std::ostream& os, ErrorStatus errorStatus);
::std::ostream& operator<<(::std::ostream& os, DeviceStatus deviceStatus);

}  // namespace android::hardware::neuralnetworks::V1_0

#endif  // ANDROID_HARDWARE_NEURALNETWORKS_V1_0_VTS_HAL_NEURALNETWORKS_H
