// Copyright (C) 2017-2024 Intel Corporation
// SPDX-License-Identifier: MIT
#pragma once

namespace Microsoft_Windows_Dwm_Core {
namespace Win7 {

struct __declspec(uuid("{8c9dd1ad-e6e5-4b07-b455-684a9d879900}")) GUID_STRUCT;
#if defined(__MINGW32__)
static const auto GUID = ::GUID{0x8c9dd1ad, 0xe6e5, 0x4b07, {0xb4, 0x55, 0x68, 0x4a, 0x9d, 0x87, 0x99, 0x00}};
#else
static const auto GUID = __uuidof(GUID_STRUCT);
#endif

}
}
