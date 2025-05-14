#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main() {
	struct sigaction sa;
	sa.sa_handler = SIG_IGN;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	printf("Process is running with pid %d\n", getpid());
	printf("Trying to ignore all signals...\n");
	for (int sig = 1; sig < NSIG; sig++) {
		if (sigaction(sig, &sa, NULL) == -1) {
			fprintf(stderr, "Cannot ignore signal %d: %s\n", sig, strerror(errno));
		}
	}
	printf("Sleeping for 30 seconds. Try sending signals now.\n");
	int delay = 30;
	sleep(delay);
	printf("Finished sleeping. Exiting normally.\n");
	return 0;
}

