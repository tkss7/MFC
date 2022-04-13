#include <stdio.h>

int main(void)
{
    printf("%d \n",555);
    printf("/%d/ \n",555);
    printf("/%10d/ \n",555);
    printf("/%-10d/ \n",555);
    printf("/%010d/ \n\n",555);

    printf("/%f/ \n",8192.1978);
    printf("/%13f/ \n",8192.1978);
    printf("/%13.2f/ \n",8192.1978);
    printf("/%-13.2f/ \n\n",8192.1978);

    printf("%c %d %c %d \n",'A','A',97,97);
    printf("%s \n", "C Language...");
    printf("%5s\n", "C Language...");
    printf("%.5s \n\n", "C Language...");

    printf("%d %o %x \n",67,67,67);
    printf("%d %#o %#x \n",067,067,067);
    printf("%d %#o %#x \n",0x67,0x67,0x67);

	 return 0 ;
}

