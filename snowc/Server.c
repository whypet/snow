#include <assert.h>
#include <stdlib.h>

#include <wayland-server-core.h>
#include <wlr/backend.h>
#include <wlr/render/allocator.h>
#include <wlr/render/wlr_renderer.h>
#include <wlr/types/wlr_compositor.h>
#include <wlr/types/wlr_data_device.h>
#include <wlr/types/wlr_output_layout.h>
#include <wlr/types/wlr_scene.h>
#include <wlr/types/wlr_subcompositor.h>
#include <wlr/util/log.h>

#include <snowc/Server.h>

#define NULLCHECK(Type, Value)                     \
	do {                                           \
		if ((Value) == NULL) {                     \
			Log(ERROR, "failed to create " #Type); \
			SnowcServerFinish(Server);             \
			return FALSE;                          \
		}                                          \
	} while (0)

BOOL
SNOWAPI
SnowcServerInit(
	OUT SNOWC_SERVER *Server
	)
{
	assert(Server != NULL);

	NULLCHECK(wl_display, Server->Display = wl_display_create());

	NULLCHECK(wlr_backend,  Server->Backend = wlr_backend_autocreate(Server->Display, NULL));
	NULLCHECK(wlr_renderer, Server->Renderer = wlr_renderer_autocreate(Server->Backend));

	Server->Allocator = wlr_allocator_autocreate(
		Server->Backend,
		Server->Renderer
		);

	NULLCHECK(wlr_allocator, Server->Allocator);

	Server->Compositor = wlr_compositor_create(
		Server->Display,
		5,
		Server->Renderer);

	NULLCHECK(wlr_compositor,          Server->Compositor);
	NULLCHECK(wlr_subcompositor,       Server->Subcompositor = wlr_subcompositor_create(Server->Display));
	NULLCHECK(wlr_data_device_manager, Server->DataDevMan = wlr_data_device_manager_create(Server->Display));

	NULLCHECK(wlr_output_layout, Server->OutputLayout = wlr_output_layout_create());

	NULLCHECK(wlr_scene, Server->Scene = wlr_scene_create());

	Server->SceneLayout = wlr_scene_attach_output_layout(
		Server->Scene,
		Server->OutputLayout
		);

	NULLCHECK(wlr_scene_output_layout, Server->SceneLayout);

	NULLCHECK(socket, Server->Socket = wl_display_add_socket_auto(Server->Display));

	return TRUE;
}

VOID
SNOWAPI
SnowcServerFinish(
	IN const SNOWC_SERVER *Server
	)
{
	assert(Server != NULL);

	if (Server->Display != NULL)
		wl_display_destroy_clients(Server->Display);

	if (Server->OutputLayout != NULL)
		wlr_output_layout_destroy(Server->OutputLayout);

	if (Server->Allocator != NULL)
		wlr_allocator_destroy(Server->Allocator);
	if (Server->Renderer != NULL)
		wlr_renderer_destroy(Server->Renderer);
	if (Server->Backend != NULL)
		wlr_backend_destroy(Server->Backend);

	if (Server->Display != NULL)
		wl_display_destroy(Server->Display);
}


BOOL
SNOWAPI
SnowcServerRun(
	IN const SNOWC_SERVER *Server
	)
{
	if (!wlr_backend_start(Server->Backend)) {
		Log(ERROR, "failed to start wlr_backend");
		return FALSE;
	}

	setenv("WAYLAND_DISPLAY", Server->Socket, TRUE);

	Log(INFO, "running on \"WAYLAND_DISPLAY=%s\"", Server->Socket);

	wl_display_run(Server->Display);

	return TRUE;
}
