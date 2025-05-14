#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void my_handler(int sig){
	printf("Enter signal handler %d\n", sig);
	sleep(3);
	printf("Leave signal handler %d\n", sig);
}

int main(){
	struct sigaction sa;
	sa.sa_handler = my_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	printf("Process is running with pid %d\n", getpid());
	printf("Trying to ignore all signals...\n\n");
	for (int sig = 1; sig < NSIG; sig++) {
		if (sigaction(sig, &sa, NULL) == -1) {
			fprintf(stderr, "Cannot ignore signal %d: %s\n", sig, strerror(errno));
		}
	}
	printf("\nSleeping for 30 seconds. Try sending signals now.\n");
	int delay = 30;
	sleep(delay);
	printf("\nFinished sleeping. Exiting normally.\n");
	return 0;
}

