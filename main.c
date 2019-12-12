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
    if(strlen(a) > strlen(b))                               /*使字符串a始终为两个字符串中较短的一个*/
    {
        temp = (char *)malloc(sizeof(a));                   /*若a长度大于b长度，二者交换*/
        strcpy(temp, a);
        strcpy(a, b);
        strcpy(b, temp);
        free(temp);
    }
    for(length = strlen(a);length >= 2;length--)            /*子串长度，从字符串长度到2递减*/
    {
        for(start = 0;start <= strlen(a) - length;start++)  /*子串开始处，用数组方法表示*/
        {
            temp = get_str(a + start, (int)length);
            if(strstr(b, temp) != NULL)                     /*若子串再字符串b中存在，则打印*/
            {
                printf("%s\n", temp);
                flag = 1;                                   /*有打印的字符串使，flag设为1*/
            }
            free(temp);
        }
        if(flag)
        {
            break;
        }
    }
    return 0;
}

char * get_str(const char *start, int length)
/*get_str() 函数：将从指针start开始的length个字符提取出来形成一个字符串，返回这个字符串的地址
参数列表：
 const char *start:提取字符串的开始地址
 int length:提取字符串的长度*/
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