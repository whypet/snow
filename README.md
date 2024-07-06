# snow

**snow** is a retro Windows style wlroots-based compositor.

Named after the Windows for Workgroups 3.11 codename, &ldquo;**Snowball**,&rdquo; its primary objective is to look and feel like a Windows 3.x environment under Wayland.

In the future, snow will work either as a dynamic tiler or a stacking window manager, which would be changed in the configuration.

## Components

- `snowc`: the wlroots compositor

There will be more down the line as to make parts of snow more modular.

## Building

snow uses the Meson build system.

The following dependencies are required:
- `wlroots`
- `wayland-protocols`

You will need to install these on your system before building. Their respective package names may be different for your distribution.
