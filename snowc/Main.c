#include <wlr/util/log.h>

#include <snowc/Server.h>

INT32 main(VOID) {
	SNOWC_SERVER Server = { 0 };

	wlr_log_init(WLR_DEBUG, NULL);

	SNOWLOG(DEBUG, "initializing snowc server");

	if (!SnowcServerInit(&Server)) {
		SNOWLOG(INFO, "encountered an error; exiting");
		return 1;
	}

	SnowcServerRun(&Server);

	SnowcServerFinish(&Server);

	return 0;
}
