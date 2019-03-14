#include<stdio.h>
int main(int argc, char ** argv)
{
    printf("%p\n", argv);
    printf("%p\n", argv+1);
    printf("%p\n", argv+2);
    printf("\n");
    printf("%p\n", *argv);
    printf("%p\n", *argv+1);
    printf("%p\n", *argv+2);
    printf("\n");
    printf("%s\n", *argv);
    printf("%s\n", *argv+1);
    printf("%s\n", *argv+2);
    printf("\n");
    printf("%s\n", argv[0]);
    printf("%s\n", argv[1]);
    printf("%c\n", argv[0][0]);
    printf("%c\n", argv[1][0]);
    printf("\n");
    printf("%s\n", *(argv+1));
    printf("%s\n", *(argv+1)+1);
    printf("%s\n", *(argv+1)+2);
    printf("\n");
    printf("%c\n", **argv);
    printf("%c\n", *(*argv+1));
    printf("%c\n", *(*argv+2));
    printf("%c\n", **(argv+1));
    printf("%c\n", *(*(argv+1)+1));
    printf("%c\n", *(*(argv+1)+2));
    printf("\n");
    return 0;
}
