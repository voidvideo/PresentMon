// Copyright (C) 2017-2024 Intel Corporation
// SPDX-License-Identifier: MIT
#pragma once

namespace Microsoft_Windows_EventMetadata {

struct __declspec(uuid("{bbccf6c1-6cd1-48C4-80ff-839482e37671}")) GUID_STRUCT;
#if defined(__MINGW32__)
static const auto GUID = ::GUID{0xbbccf6c1, 0x6cd1, 0x48c4, {0x80, 0xff, 0x83, 0x94, 0x82, 0xe3, 0x76, 0x71}};
#else
static const auto GUID = __uuidof(GUID_STRUCT);
#endif

// Event descriptors:
#define EVENT_DESCRIPTOR_DECL(name_, id_, version_, channel_, level_, opcode_, task_, keyword_) struct name_ { \
    static constexpr uint16_t Id      = id_; \
    static constexpr uint8_t Version = version_; \
    static constexpr uint8_t Channel = channel_; \
    static constexpr uint8_t Level   = level_; \
    static constexpr uint8_t Opcode  = opcode_; \
    static constexpr uint16_t Task    = task_; \
    static uint64_t const Keyword = keyword_; \
};

EVENT_DESCRIPTOR_DECL(EventInfo, 0x0000, 0x00, 0x00, 0x00, 0x20, 0x0000, 0x0000000000000000)

#undef EVENT_DESCRIPTOR_DECL

}
