//产生动态数组，编写程序，输入数组大小后，通过动态分配内存函数malloc产生数组。
#include <stdio.h>
typedef struct
{
    int *array;
    int length;
}Array;
int main(void)
{
    Array a;
    int n,i;
    printf("Enter array size:");
    scanf("%d",&n);
    a.array=(int*)malloc(sizeof(int)*n);
    if (a.array==NULL)
    {
    printf("memory is not enough!");
    }
    else
    {
        a.length=n;
        for (i=0;i<a.length;i++)
        {
            scanf("%d",&a.array[i]);
        }
    }
    for (i=0;i<a.length;i++)
    printf("array[%d]=%d\n",i,a.array[i]);
    free(a.array);
}    