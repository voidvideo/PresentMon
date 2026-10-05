// Copyright (C) 2026 VoidVideo
// SPDX-License-Identifier: MIT
#pragma once

// llvm-mingw currently omits several ETW declarations that are present in the
// Windows SDK. Keep their SDK values here so the collector can be compiled by
// the same GNU/LLVM toolchain as VoidVideo.
#if defined(__MINGW32__)

#ifndef MAX_EVENT_FILTER_EVENT_ID_COUNT
#define MAX_EVENT_FILTER_EVENT_ID_COUNT 64
typedef struct _EVENT_FILTER_EVENT_ID {
    BOOLEAN FilterIn;
    UCHAR Reserved;
    USHORT Count;
    USHORT Events[ANYSIZE_ARRAY];
} EVENT_FILTER_EVENT_ID, *PEVENT_FILTER_EVENT_ID;
#define EVENT_FILTER_TYPE_EVENT_ID 0x80000200
#define EVENT_ENABLE_PROPERTY_IGNORE_KEYWORD_0 0x00000010
#endif

#ifndef PropertyParamFixedCount
#define PropertyParamFixedCount 0x20
#endif
#ifndef TDH_INTYPE_UNICODESTRING
#define TDH_INTYPE_UNICODESTRING 1
#define TDH_INTYPE_ANSISTRING 2
#define TDH_INTYPE_INT8 3
#define TDH_INTYPE_UINT8 4
#define TDH_INTYPE_INT16 5
#define TDH_INTYPE_UINT16 6
#define TDH_INTYPE_INT32 7
#define TDH_INTYPE_UINT32 8
#define TDH_INTYPE_POINTER 16
#define TDH_INTYPE_SID 19
#define TDH_INTYPE_SIZET 308
#define TDH_INTYPE_WBEMSID 310
#endif
#ifndef DecodingSourceTlg
#define DecodingSourceTlg 3
#endif
#ifndef TEI_PROPERTY_NAME
#define TEI_PROPERTY_NAME(EventInfo, Property) \
    ((Property)->NameOffset == 0 ? nullptr : (PWSTR) ((PBYTE) (EventInfo) + (Property)->NameOffset))
#endif

#endif
