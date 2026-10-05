#!/usr/bin/env bash
set -euo pipefail

root=$(cd "$(dirname "$0")/.." && pwd)
output="$root/VoidVideoPresentMon/out"
objects="$output/objects"
stage="$output/stage"
compiler=x86_64-w64-mingw32-g++
archiver=x86_64-w64-mingw32-ar

rm -rf "$output"
mkdir -p "$objects" "$stage/include" "$stage/lib"

sources=(
  IntelPresentMon/CommonUtilities/Hash.cpp
  PresentData/Debug.cpp
  PresentData/GpuTrace.cpp
  PresentData/PresentMonTraceConsumer.cpp
  PresentData/PresentMonTraceSession.cpp
  PresentData/TraceConsumer.cpp
)

for source in "${sources[@]}"; do
  "$compiler" -std=c++23 -fms-extensions -D_WIN32 -DPRESENTMON_ENABLE_DEBUG_TRACE=0 \
    -I"$root" -c "$root/$source" -o "$objects/$(basename "$source").o"
done

"$archiver" rcs "$stage/lib/libVoidVideoPresentMon.a" "$objects"/*.o

cp -a "$root/PresentData" "$stage/include/PresentData"
rm -f "$stage/include/PresentData"/*.cpp
rm -f "$stage/include/PresentData"/*.vcxproj "$stage/include/PresentData"/*.vcxproj.filters
mkdir -p "$stage/include/IntelPresentMon/CommonUtilities/win"
cp "$root/IntelPresentMon/CommonUtilities/Hash.h" "$stage/include/IntelPresentMon/CommonUtilities/"
cp "$root/IntelPresentMon/CommonUtilities/win/WinAPI.h" "$stage/include/IntelPresentMon/CommonUtilities/win/"
cp "$root/LICENSE.txt" "$stage/LICENSE.txt"
cp "$root/VoidVideoPresentMon/meson.build" "$stage/meson.build"
