/*
 * Copyright 2019 Xilinx Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once
#include <xilinx/ai/proto/dpu_model_param.pb.h>
#include <array>
#include <cstdint>
#include <utility>
#include <xilinx/ai/tensor.hpp>
namespace xilinx {
namespace ai {

/**
 * @struct FaceFeatureFloatResult
 * @brief The result of FaceFeature ,its a 512 dimentions vector, float value.
 * */
struct FaceFeatureFloatResult {
  /// width of a input image
  int width;
  /// height of a input image
  int height;
  /// the 512 dimention vector
  using vector_t = std::array<float, 512>;
  std::unique_ptr<vector_t> feature;
};

/**
 * @brief result of FaceFeature
 * it is a 512 dimentions vector, fix point values
 * */
struct FaceFeatureFixedResult {
  /// width of a input image
  int width;
  /// height of a input image
  int height;
  /// the fix point
  float scale;
  /// the 512 dimention vector, in fix point format
  using vector_t = std::array<int8_t, 512>;
  std::unique_ptr<vector_t> feature;
};

FaceFeatureFloatResult face_feature_post_process_float(
    const std::vector<std::vector<xilinx::ai::library::InputTensor>>&
        input_tensors,
    const std::vector<std::vector<xilinx::ai::library::OutputTensor>>&
        output_tensors,
    const xilinx::ai::proto::DpuModelParam& config);

FaceFeatureFixedResult face_feature_post_process_fixed(
    const std::vector<std::vector<xilinx::ai::library::InputTensor>>&
        input_tensors,
    const std::vector<std::vector<xilinx::ai::library::OutputTensor>>&
        output_tensors,
    const xilinx::ai::proto::DpuModelParam& config);

}  // namespace ai
}  // namespace xilinx
