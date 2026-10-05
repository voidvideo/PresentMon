project('voidvideo-presentmon', 'cpp', version: '2.3.1-4')

if host_machine.system() != 'windows' or host_machine.cpu_family() != 'x86_64'
  error('voidvideo-presentmon supplies only the Windows x86_64 LLVM-mingw static library')
endif

voidvideo_presentmon_dep = declare_dependency(
  include_directories: include_directories('include'),
  link_args: [
    meson.current_source_dir() / 'lib/libVoidVideoPresentMon.a',
    '-ltdh',
    '-ladvapi32',
  ],
)
meson.override_dependency('voidvideo-presentmon', voidvideo_presentmon_dep)
