// Copyright 2025 Trossen Robotics
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//    * Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
//
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
//
//    * Neither the name of the the copyright holder nor the names of its
//      contributors may be used to endorse or promote products derived from
//      this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef LIBTROSSEN_ARM__TROSSEN_ARM_INTERPOLATE_HPP_
#define LIBTROSSEN_ARM__TROSSEN_ARM_INTERPOLATE_HPP_

#include <array>

namespace trossen_arm
{

/// @brief Quintic Hermite Interpolator
class QuinticHermiteInterpolator
{
public:
  /**
   * @brief Compute the coefficients for the quintic hermite interpolation y = f(x)
   *
   * @param x0 Initial x value
   * @param x1 Final x value
   * @param y0 Initial y value, f(x0)
   * @param y1 Final y value, f(x1)
   * @param dy0 Initial first order derivative, f'(x0)
   * @param dy1 Final first order derivative, f'(x1)
   * @param ddy0 Initial second order derivative, f''(x0)
   * @param ddy1 Final second order derivative, f''(x1)
   */
  void compute_coefficients(
    float x0,
    float x1,
    float y0,
    float y1,
    float dy0,
    float dy1,
    float ddy0,
    float ddy1);

  /// @brief Evaluate f(x)
  float y(float x);

  /// @brief Evaluate f'(x)
  float dy(float x);

  /// @brief Evaluate f''(x)
  float ddy(float x);

private:
  // Coefficients
  std::array<float, 6> a_;

  // Bounds
  float x0_{0.0f};
  float x1_{0.0f};
  float y0_{0.0f};
  float y1_{0.0f};
  float dy0_{0.0f};
  float dy1_{0.0f};
  float ddy0_{0.0f};
  float ddy1_{0.0f};
};

}  // namespace trossen_arm

#endif  // LIBTROSSEN_ARM__TROSSEN_ARM_INTERPOLATE_HPP_
