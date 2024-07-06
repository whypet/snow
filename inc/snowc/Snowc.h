#pragma once

#include <Snowdef.h>

#define Log(Verb, Format, ...) \
	wlr_log(WLR_##Verb, "snow: " Format, ##__VA_ARGS__)

#if DEBUG
	#define LogInit() wlr_log_init(WLR_DEBUG, NULL)
#else
	#define LogInit() wlr_log_init(WLR_INFO, NULL)
#endif
