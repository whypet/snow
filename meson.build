project(
    'snow',
    'c',
    default_options: [
        'c_std=gnu11',
        'warning_level=everything',
        'werror=true',
    ],
)

add_project_arguments(
    [
        '-Wpedantic',
        '-Wno-gnu-zero-variadic-macro-arguments',
    ],
    language: 'c',
)

if get_option('buildtype') == 'debug'
    add_project_arguments('-DDEBUG', language: 'c')
else
    add_project_arguments('-DDEBUG=0', language: 'c')
endif

targets = [
    'snowc',
]

foreach target : targets
    inc_dirs = [include_directories('inc')] # include_directories('inc' / target)
    subdir(target)
endforeach
