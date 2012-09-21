/*
  testinotify.c
  Copyright (C) 2010       Stef Bon

  This program can be distributed under the terms of the GNU GPL.

  gcc -Wall testinotify.c -o testinotify
*/

#ifdef linux
/* For pread()/pwrite() */
#define _XOPEN_SOURCE 500
#endif


#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/inotify.h>
#include <sys/epoll.h>


#define WATCHPATH "/home/bryan/builds/fusetest/mnt/immutable_directory"
#define MAXPOLLSIZE 256

#define INOTIFY_EVENT_SIZE (sizeof (struct inotify_event))

#define INOTIFY_BUF_LEN (1024 * (INOTIFY_EVENT_SIZE + 16))

int main(void)
{
	int inotify_init_fd;
	int inotify_watch_fd;
	int epoll_fd;
	struct epoll_event epoll_events[MAXPOLLSIZE];
	char inotify_buf[INOTIFY_BUF_LEN];
	int inotify_buf_len;
	int i,j;


	// create an initofy instance
	
	inotify_init_fd = inotify_init();
	
	// handle error here if fd not valid


	epoll_fd=epoll_create(MAXPOLLSIZE);

	
	// add the inotify_init_fd to the epoll instance

	static struct epoll_event ev;
	ev.events=EPOLLIN | EPOLLPRI;
	ev.data.fd=inotify_init_fd;
	(void) epoll_ctl(epoll_fd, EPOLL_CTL_ADD, inotify_init_fd, &ev);
	

	inotify_watch_fd=inotify_add_watch(inotify_init_fd, WATCHPATH, IN_CREATE | IN_DELETE | IN_CLOSE_WRITE | IN_MODIFY);


	// handle error here when fd not set/valid


	while (1) {



		int number_of_fds=epoll_wait(epoll_fd, epoll_events, MAXPOLLSIZE, -1);



		if (number_of_fds < 0) {
			perror("epoll_wait");
			return 1;
		}
		
		for (i = 0; i < number_of_fds; i++) {
		
		    int fd = epoll_events[i].data.fd;

		    if ( fd == inotify_init_fd ) {


			// it's an inotify thing

			inotify_buf_len = read (fd, inotify_buf, INOTIFY_BUF_LEN);
			
			j=0;

			while ( j < inotify_buf_len) {

			    struct inotify_event *tmp_event;

			    tmp_event = (struct inotify_event *) &inotify_buf[j];
			    
			    printf ("wd=%d mask=%u cookie=%u len=%u\n", tmp_event->wd, tmp_event->mask, tmp_event->cookie, tmp_event->len);
			    
			    if (tmp_event->len) printf("name=%s\n", tmp_event->name);
			    
			    j += INOTIFY_EVENT_SIZE + tmp_event->len;
			    
			}
			
		    }
		}
	    }

}
