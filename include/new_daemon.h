/*
 *  Name: onsokumaru
 *  Email: 11082686+onsokumaru@users.noreply.github.com
 *  Date: 2023-09-28
 *  File: new_daemon.h
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

#define PID_FILE "/tmp/jpswd.pid" /* location of PID file  */
#define BUF_SIZE 100  // large enough to hold maximum PID as a string 

void sigterm_handler(int signum);
void sigint_handler(int signum);
int create_pid_file();
