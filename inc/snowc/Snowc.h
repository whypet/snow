#pragma once

#include <Snowdef.h>

#define SNOWLOG(Verb, Format, ...) \
	wlr_log(WLR_##Verb, "snow: " Format, ##__VA_ARGS__)

#if DEBUG
	#define SNOWLOG_INIT() wlr_log_init(WLR_DEBUG, NULL)
#else
	#define SNOWLOG_INIT() wlr_log_init(WLR_INFO, NULL)
#endif
