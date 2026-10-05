// Copyright (C) 2024 Intel Corporation
// SPDX-License-Identifier: MIT
#pragma once

namespace Microsoft_Windows_DxgKrnl {
namespace Win7 {

struct __declspec(uuid("{65cd4c8a-0848-4583-92a0-31c0fbaf00c0}")) GUID_STRUCT;
struct __declspec(uuid("{069f67f2-c380-4a65-8a61-071cd4a87275}")) BLT_GUID_STRUCT;
struct __declspec(uuid("{22412531-670b-4cd3-81d1-e709c154ae3d}")) FLIP_GUID_STRUCT;
struct __declspec(uuid("{c19f763a-c0c1-479d-9f74-22abfc3a5f0a}")) PRESENTHISTORY_GUID_STRUCT;
struct __declspec(uuid("{295e0d8e-51ec-43b8-9cc6-9f79331d27d6}")) QUEUEPACKET_GUID_STRUCT;
struct __declspec(uuid("{5ccf1378-6b2c-4c0f-bd56-8eeb9e4c5c77}")) VSYNCDPC_GUID_STRUCT;
struct __declspec(uuid("{547820fe-5666-4b41-93dc-6cfd5dea28cc}")) MMIOFLIP_GUID_STRUCT;
#if defined(__MINGW32__)
static const auto GUID                = ::GUID{0x65cd4c8a, 0x0848, 0x4583, {0x92, 0xa0, 0x31, 0xc0, 0xfb, 0xaf, 0x00, 0xc0}};
static const auto BLT_GUID            = ::GUID{0x069f67f2, 0xc380, 0x4a65, {0x8a, 0x61, 0x07, 0x1c, 0xd4, 0xa8, 0x72, 0x75}};
static const auto FLIP_GUID           = ::GUID{0x22412531, 0x670b, 0x4cd3, {0x81, 0xd1, 0xe7, 0x09, 0xc1, 0x54, 0xae, 0x3d}};
static const auto PRESENTHISTORY_GUID = ::GUID{0xc19f763a, 0xc0c1, 0x479d, {0x9f, 0x74, 0x22, 0xab, 0xfc, 0x3a, 0x5f, 0x0a}};
static const auto QUEUEPACKET_GUID    = ::GUID{0x295e0d8e, 0x51ec, 0x43b8, {0x9c, 0xc6, 0x9f, 0x79, 0x33, 0x1d, 0x27, 0xd6}};
static const auto VSYNCDPC_GUID       = ::GUID{0x5ccf1378, 0x6b2c, 0x4c0f, {0xbd, 0x56, 0x8e, 0xeb, 0x9e, 0x4c, 0x5c, 0x77}};
static const auto MMIOFLIP_GUID       = ::GUID{0x547820fe, 0x5666, 0x4b41, {0x93, 0xdc, 0x6c, 0xfd, 0x5d, 0xea, 0x28, 0xcc}};
#else
static const auto GUID                = __uuidof(GUID_STRUCT);
static const auto BLT_GUID            = __uuidof(BLT_GUID_STRUCT);
static const auto FLIP_GUID           = __uuidof(FLIP_GUID_STRUCT);
static const auto PRESENTHISTORY_GUID = __uuidof(PRESENTHISTORY_GUID_STRUCT);
static const auto QUEUEPACKET_GUID    = __uuidof(QUEUEPACKET_GUID_STRUCT);
static const auto VSYNCDPC_GUID       = __uuidof(VSYNCDPC_GUID_STRUCT);
static const auto MMIOFLIP_GUID       = __uuidof(MMIOFLIP_GUID_STRUCT);
#endif

typedef LARGE_INTEGER PHYSICAL_ADDRESS;

#pragma pack(push)
#pragma pack(1)

typedef struct _DXGKETW_BLTEVENT {
    ULONGLONG                  hwnd;
    ULONGLONG                  pDmaBuffer;
    ULONGLONG                  PresentHistoryToken;
    ULONGLONG                  hSourceAllocation;
    ULONGLONG                  hDestAllocation;
    BOOL                       bSubmit;
    BOOL                       bRedirectedPresent;
    UINT                       Flags; // DXGKETW_PRESENTFLAGS
    RECT                       SourceRect;
    RECT                       DestRect;
    UINT                       SubRectCount; // followed by variable number of ETWGUID_DXGKBLTRECT events
} DXGKETW_BLTEVENT;

typedef struct _DXGKETW_FLIPEVENT {
    ULONGLONG                  pDmaBuffer;
    ULONG                      VidPnSourceId;
    ULONGLONG                  FlipToAllocation;
    UINT                       FlipInterval; // D3DDDI_FLIPINTERVAL_TYPE
    BOOLEAN                    FlipWithNoWait;
    BOOLEAN                    MMIOFlip;
} DXGKETW_FLIPEVENT;

typedef struct _DXGKETW_PRESENTHISTORYEVENT {
    ULONGLONG             hAdapter;
    ULONGLONG             Token;
    ULONG                 Model;     // available only for _STOP event type.
    UINT                  TokenSize; // available only for _STOP event type.
} DXGKETW_PRESENTHISTORYEVENT;

typedef struct _DXGKETW_QUEUESUBMITEVENT {
    ULONGLONG                  hContext;
    ULONG                      PacketType; // DXGKETW_QUEUE_PACKET_TYPE
    ULONG                      SubmitSequence;
    ULONGLONG                  DmaBufferSize;
    UINT                       AllocationListSize;
    UINT                       PatchLocationListSize;
    BOOL                       bPresent;
    ULONGLONG                  hDmaBuffer;
} DXGKETW_QUEUESUBMITEVENT;

typedef struct _DXGKETW_QUEUECOMPLETEEVENT {
    ULONGLONG                  hContext;
    ULONG                      PacketType;
    ULONG                      SubmitSequence;
    union {
        BOOL                   bPreempted;
        BOOL                   bTimeouted; // PacketType is WaitCommandBuffer.
    };
} DXGKETW_QUEUECOMPLETEEVENT;

typedef struct _DXGKETW_SCHEDULER_VSYNC_DPC {
    ULONGLONG                 pDxgAdapter;
    UINT                      VidPnTargetId;
    PHYSICAL_ADDRESS          ScannedPhysicalAddress;
    UINT                      VidPnSourceId;
    UINT                      FrameNumber;
    LONGLONG                  FrameQPCTime;
    ULONGLONG                 hFlipDevice;
    UINT                      FlipType; // DXGKETW_FLIPMODE_TYPE
    union
    {
        ULARGE_INTEGER        FlipFenceId;
        PHYSICAL_ADDRESS      FlipToAddress;
    };
} DXGKETW_SCHEDULER_VSYNC_DPC;

typedef struct _DXGKETW_SCHEDULER_MMIO_FLIP_32 {
    ULONGLONG        pDxgAdapter;
    UINT             VidPnSourceId;
    ULONG            FlipSubmitSequence; // ContextUserSubmissionId
    UINT             FlipToDriverAllocation;
    PHYSICAL_ADDRESS FlipToPhysicalAddress;
    UINT             FlipToSegmentId;
    UINT             FlipPresentId;
    UINT             FlipPhysicalAdapterMask;
    ULONG            Flags;
} DXGKETW_SCHEDULER_MMIO_FLIP_32;

typedef struct _DXGKETW_SCHEDULER_MMIO_FLIP_64 {
    ULONGLONG        pDxgAdapter;
    UINT             VidPnSourceId;
    ULONG            FlipSubmitSequence; // ContextUserSubmissionId
    ULONGLONG        FlipToDriverAllocation;
    PHYSICAL_ADDRESS FlipToPhysicalAddress;
    UINT             FlipToSegmentId;
    UINT             FlipPresentId;
    UINT             FlipPhysicalAdapterMask;
    ULONG            Flags;
} DXGKETW_SCHEDULER_MMIO_FLIP_64;

#pragma pack(pop)

}
}
