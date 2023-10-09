#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <syslog.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define PID_FILE "/tmp/jpswd.pid"

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

int main() {
    // Open syslog with a custom identifier
    openlog("jpswd", LOG_PID, LOG_DAEMON);

    // Check if another instance is already running
    int pid_file_fd = open(PID_FILE, O_RDONLY);
    if (pid_file_fd != -1) {
        syslog(LOG_ERR, "Another instance of the daemon is already running.");
        close(pid_file_fd);
        closelog();
        return 1;
    }

    // Create the PID file
    if (create_pid_file() == -1) {
        closelog();
        return 1;
    }

    // Set up signal handlers
    signal(SIGTERM, sigterm_handler);
    signal(SIGINT, sigint_handler);

    syslog(LOG_INFO, "jpswd started.");

    // Main daemon loop
    while (!flag) {
        // Your daemon's work here
        syslog(LOG_INFO, "jpswd is running...");
        sleep(10);
    }

    // Clean up and exit
    remove(PID_FILE);
    syslog(LOG_INFO, "jpswd exiting.");
    closelog();

    return 0;
}

