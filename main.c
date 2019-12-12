//
// Created by LiuYang on 2019/12/12.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * get_str(const char *start, int length);

int main(void)
{
    char a[] = "abcdef";
    char b[] = "abcddef";
    char *temp;
    unsigned long long length, start;
    int flag = 0;
    if(strlen(a) > strlen(b))
    {
        temp = (char *)malloc(sizeof(a));
        strcpy(temp, a);
        strcpy(a, b);
        strcpy(b, temp);
    }
    for(length = strlen(a);length >= 2;length--)
    {
        for(start = 0;start <= strlen(a) - length;start++)
        {
            temp = get_str(a + start, (int)length);
            if(strstr(b, temp) != NULL)
            {
                printf("%s\n", temp);
                flag = 1;
            }
        }
        if(flag)
        {
            break;
        }
    }
    return 0;
}

char * get_str(const char *start, int length)
{
    char *out = (char *)malloc((length + 1) * sizeof(char));
    char *b = out;
    int i;
    for(i = 0;i < length;i++,b++)
    {
        *b = start[i];
    }
    *b = '\0';
    return out;
}