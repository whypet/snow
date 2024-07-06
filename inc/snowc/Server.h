#pragma once

#include <snowc/Snowc.h>

struct wl_display;
struct wlr_allocator;
struct wlr_backend;
struct wlr_compositor;
struct wlr_data_device_manager;
struct wlr_output_layout;
struct wlr_renderer;
struct wlr_scene;
struct wlr_scene_output_layout;
struct wlr_subcompositor;

typedef struct {
	struct wl_display              *Display;

	struct wlr_backend             *Backend;
	struct wlr_renderer            *Renderer;
	struct wlr_allocator           *Allocator;

	struct wlr_compositor          *Compositor;
	struct wlr_subcompositor       *Subcompositor;
	struct wlr_data_device_manager *DataDevMan;

	struct wlr_output_layout       *OutputLayout;

	struct wlr_scene               *Scene;
	struct wlr_scene_output_layout *SceneLayout;

	const CHAR8                    *Socket;
} SNOWC_SERVER;

BOOL
SNOWAPI
SnowcServerInit(
	OUT SNOWC_SERVER *Server
	);

VOID
SNOWAPI
SnowcServerFinish(
	IN const SNOWC_SERVER *Server
	);

BOOL
SNOWAPI
SnowcServerRun(
	IN const SNOWC_SERVER *Server
	);
