#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int myComparator(void *left,void *right)
{
int *i,*j;
i=(int *)left;
j=(int *)right;
return (*i)-(*j);
}
void Sort(void *ptr,int size,int esize,int (*ptf)(void *,void *))
{
int e,f,g,w;
void *a,*b,*c;
w=0;
c=(void *)malloc(esize);
e=0;
while(e<=size-2)
{
f=e+1;
while(f<=size-1)
{
a=ptr+(e*esize);
b=ptr+(f*esize);
w=ptf(a,b);
if(w>0)
{
memcpy(c,(const void *)a,esize);
memcpy(a,(const void *)b,esize);
memcpy(b,(const void *)c,esize);
}
f++;
}
e++;
}
free(c);
}


int main()
{
int y,req,e,f,g;
int *x;
y=0;
printf("Enter a requirement ");
scanf("%d",&req);
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Memory coud not be allocated for requirement %d",req);
return 0;
}
while(y<req)
{
printf("Enter a number ");
scanf("%d",&x[y]);
y++;
}
Sort(x,req,sizeof(int),myComparator);
y=0;
while(y<req)
{
printf("%d\n",x[y]);
y++;
}
free(x);
return 0;
}
