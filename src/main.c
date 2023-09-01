/*
 *  Name: onsokumaru
 *  Email: 11082686+onsokumaru@users.noreply.github.com
 *  Date: 2023-09-01
 *  File: main.c
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

// main.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>
#include "daemon.h"

int main() {
    openlog("SimpleDaemon", LOG_PID, LOG_DAEMON);

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        // Parent process
        exit(EXIT_SUCCESS);
    }

    umask(0);
    pid_t sid = setsid();

    if (sid < 0) {
        perror("Failed to create new session");
        exit(EXIT_FAILURE);
    }

    // Change working directory if necessary
    // chdir("/");

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // Run the daemon
    run_daemon();

    return 0;
}

