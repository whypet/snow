executable(
    'snowc',
    sources: [
        'Main.c',
        'Server.c',
    ],
    include_directories: inc_dirs,
    dependencies: [
        dependency('wlroots'),
        dependency('wayland-protocols'),
        dependency('wayland-server'),
    ],
    c_args: ['-DWLR_USE_UNSTABLE'],
)
