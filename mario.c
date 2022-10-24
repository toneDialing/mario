#include <stdio.h>

void mario(int n); //builds a Mario block tower of height n, where 1<=n<=8
void pdot(int k, int i); //prints requisite dots
void phash(int k, int i); //prints requisite hashes
void readline(void); //reads input char by char until newline, using extern variables

int n, c, extrachar;

/* If user enters a number n between 1 and 8, program runs mario(n). Else, user is re-prompted. */
/* User can exit program anytime by typing 'q' and pressing ENTER */

int main(void)
{
	extern int n, c, extrachar;
	extrachar = 0;
    
	printf("It's a-me, Mario! Please enter an integer between 1 and 8 inclusive: ");
	readline();

	/* User can enter 'q' at any time to quit */
	while(n!='q' && n!=EOF)
	{
		/* This block re-prompts user if input is wrong */
		if(extrachar!=0 || n<'1' || n>'8')
		{
			if(n=='q' || n==EOF) break;
			extrachar=0;

			printf("Oh-ho-ho no-o! You must enter an integer between 1 and 8: ");
			readline();

			/* This block re-prompts again repeatedly if input is still wrong */
			while(extrachar!=0 || n<'1' || n>'8')
			{
				if(n=='q' || n==EOF) break;
				extrachar=0;

				printf("Mamma mia! Try again: ");
				readline();
			}
		}
		if(n=='q' || n==EOF) break;
		extrachar=0;

		/* Once input is correct, run mario() */
		mario(n-'0');

		printf("Thank you so much! Enter another integer or type 'q' to quit: ");
		readline();
	}
    if(n==EOF) return 1;
	return 0;
}

void mario(int n) //builds a Mario block tower of height n, where 1<=n<=8
{
	for(int i = 0; i<n; i++)
	{
		int k = 0;
		pdot(k, i);
		phash(k, i);
		printf(" ");
		phash(k, i);
		pdot(k, i);
		printf("\n");
	}
}

void pdot(int k, int i) //prints requisite dots (note 7 is hard-coded for formatting)
{
	while(k<(7-i))
	{
		printf(".");
		k++;
	}
}

void phash(int k, int i) //prints requisite hashes
{
	do
	{
		printf("#");
		k++;
	}
	while(k<(i+1));
}

void readline(void) //reads input char by char until newline, using extern variables
{
	extern int n, c, extrachar;

	n = getchar();
	while((c=getchar()) != '\n')
	{
		if(c==EOF)
		{
			n = c;
			break;
		}
		extrachar++;
	}
}