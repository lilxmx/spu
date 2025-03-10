// Copyright 2023 Ant Group Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

// Defines function/macros that nearly modules required.

// SPU prefer exception to status code.
#include "yacl/base/exception.h"

// forward macros
#define SPU_THROW YACL_THROW
#define SPU_ENFORCE_EQ YACL_ENFORCE_EQ
#define SPU_ENFORCE_NE YACL_ENFORCE_NE
#define SPU_ENFORCE_LE YACL_ENFORCE_LE
#define SPU_ENFORCE_LT YACL_ENFORCE_LT
#define SPU_ENFORCE_GE YACL_ENFORCE_GE
#define SPU_ENFORCE_GT YACL_ENFORCE_GT

// #define SPU_THROW(...) YACL_THROW(__VA_ARGS__)
// #define SPU_ENFORCE_EQ(...) YACL_ENFORCE_EQ(__VA_ARGS__)
// #define SPU_ENFORCE_NE(...) YACL_ENFORCE_NE(__VA_ARGS__)
// #define SPU_ENFORCE_LE(...) YACL_ENFORCE_LE(__VA_ARGS__)
// #define SPU_ENFORCE_LT(...) YACL_ENFORCE_LT(__VA_ARGS__)
// #define SPU_ENFORCE_GE(...) YACL_ENFORCE_GE(__VA_ARGS__)
// #define SPU_ENFORCE_GT(...) YACL_ENFORCE_GT(__VA_ARGS__)

// clang-tidy: readability-simplify-boolean-expr
#define SPU_ENFORCE(COND, ...) \
  YACL_ENFORCE((COND),         \
               __VA_ARGS__)  // NOLINT, readability-simplify-boolean-expr

#ifdef NDEBUG
#define SPU_DEBUG_ONLY_THROW(...) static_cast<void>(0)
#define SPU_DEBUG_ONLY_ENFORCE(...) static_cast<void>(0)
#else
#define SPU_DEBUG_ONLY_THROW(...) YACL_THROW(__VA_ARGS__)
#define SPU_DEBUG_ONLY_ENFORCE(COND, ...) SPU_ENFORCE(COND, __VA_ARGS__)
#endif

// Force compiler to inline something regardless of optimization level.
#define SPU_ALWAYS_INLINE inline __attribute__((always_inline))

// forward scope guard related macros
#include "yacl/utils/scope_guard.h"  // IWYU pragma: keep

// Format
#include "fmt/ostream.h"

#include "libspu/spu.h"

namespace fmt {

template <>
struct formatter<spu::FieldType> : ostream_formatter {};

template <>
struct formatter<spu::DataType> : ostream_formatter {};

template <>
struct formatter<spu::PtType> : ostream_formatter {};

template <>
struct formatter<spu::Visibility> : ostream_formatter {};

template <>
struct formatter<spu::ProtocolKind> : ostream_formatter {};

template <>
struct formatter<spu::RuntimeConfig::BeaverType> : ostream_formatter {};

template <>
struct formatter<spu::RuntimeConfig::ExpMode> : ostream_formatter {};

template <>
struct formatter<spu::RuntimeConfig::LogMode> : ostream_formatter {};

template <>
struct formatter<spu::RuntimeConfig::SigmoidMode> : ostream_formatter {};

template <>
struct formatter<spu::SourceIRType> : ostream_formatter {};

template <>
struct formatter<spu::RuntimeConfig::SortMethod> : ostream_formatter {};

}  // namespace fmt
