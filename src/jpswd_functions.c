/*
 *  Name: onsokumaru
 *  Email: 11082686+onsokumaru@users.noreply.github.com
 *  Date: 2023-09-28
 *  File: jpswd_functions.c
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

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <syslog.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "jpswd_functions.h"

volatile sig_atomic_t flag = 0;

void sigterm_handler(int signum) {
    syslog(LOG_INFO, "Received SIGTERM. Exiting...");
    flag = 1;
}

void sigint_handler(int signum) {
    syslog(LOG_INFO, "Received SIGINT. Exiting...");
    flag = 1;
}

int create_pid_file() {
    int pid_file_fd = open(PID_FILE, O_CREAT | O_RDWR | O_EXCL, 0644);

    if (pid_file_fd == -1) {
        syslog(LOG_ERR, "Failed to create PID file.");
        return -1;
    }

    char pid_str[20];
    snprintf(pid_str, sizeof(pid_str), "%d\n", getpid());
    write(pid_file_fd, pid_str, strlen(pid_str));
    close(pid_file_fd);

    return 0;
}

/* TODO create function for jpswd daemon -- Thu 28 Sep 2023 12:24:04 EDT */

