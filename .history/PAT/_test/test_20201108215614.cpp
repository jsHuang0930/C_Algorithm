#include <stdio.h>
int main()
{
    char str[15];
    for (int i = 0; i < 3; i++)
    {
        str[i] = getchar(); /* code */
    }
    str[3] = '\0';
    puts(str);

    return 0;
}