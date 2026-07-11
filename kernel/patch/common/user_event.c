/* SPDX-License-Identifier: GPL-2.0-or-later */
/* 
 * Copyright (C) 2024 bmax121. All Rights Reserved.
 */

#include <user_event.h>
#include <baselib.h>
#include <log.h>

int report_user_event(const char *event, const char *args)
{
    const char *safe_event = event ? event : "";
    const char *safe_args = args ? args : "";

    #ifdef ANDROID
    if (lib_strcmp(safe_event, "post-fs-data") == 0) {
        log_boot("post-fs-data event received\n");
    }
    else if (lib_strcmp(safe_event, "boot-completed") == 0) {
        log_boot("boot-completed event received\n");
    }
    else if (lib_strcmp(safe_event, "uid_listener") == 0) {
        log_boot("uid_listener event: %s\n", safe_args);
    }
    #endif
    logki("user report event: %s, args: %s\n", safe_event, safe_args);
    return 0;
}