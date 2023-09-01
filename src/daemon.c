/*
 *  Name: onsokumaru
 *  Email: 11082686+onsokumaru@users.noreply.github.com
 *  Date: 2023-09-01
 *  File: daemon.c
 *  License: GPL v3.0
 *  
 *  Copyright 2023 Mike Furtado
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses\>.
 *
 */

// daemon.c

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <syslog.h>
#include <signal.h>
#include "daemon.h"

volatile sig_atomic_t keep_running = 1;

void handle_signal(int signum) {
    if (signum == SIGTERM || signum == SIGINT) {
        syslog(LOG_INFO, "Received termination signal. Shutting down...");
        keep_running = 0;
    }
}

void run_daemon() {
    // Set up signal handling
    signal(SIGTERM, handle_signal);
    signal(SIGINT, handle_signal);

    // Daemonization code (similar to previous examples)

    while (keep_running) {
        syslog(LOG_INFO, "Daemon is running");
        // Your daemon logic goes here
        sleep(10);
    }

    // Clean up and exit
    closelog();
    syslog(LOG_INFO, "Daemon has been shut down");
}

