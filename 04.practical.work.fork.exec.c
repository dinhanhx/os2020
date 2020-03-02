#include <stdio.h>
#include <unistd.h>

int main(void)
{
	printf("Main before fork()\n");
	int pid_1 = fork();

	if (pid_1 == 0)
	{
		// Begin
		printf("Main before fork() again\n");
		int pid_2 = fork();

		if (pid_2 == 0)
		{
			printf("I am child after fork() again, launching tree -h\n");
			char *args[] = {"tree", "-h", NULL};
			sleep(1); // To make this displays before ps -ef 5 seconds and after folk() 6 seconds
			execvp("tree",args);
		}
		else
		{
			printf("I am parent after fork() again, child is %d\n", pid_2);
		}
		// End

		printf("I am child after fork(), launching ps -ef\n");
		char *args[] = {"/bin/ps", "-ef", NULL};
		sleep(6); // To make this displays after tree -h 5 seconds
		execvp("/bin/ps",args);
	}
	else printf("I am parent after fork(), child is %d\n", pid_1);

	return 0;
}
