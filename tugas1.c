

#include <stdio.h>
#include <conio.h>

void isia()
{
	int a=0,b=0,i=0;
	while(b!=4)
	{
		if (a==0)
		{
			a=3;
			i+=1;
			printf("\n%d.Isi A\nA=%d\nB=%d\n",i,a,b);
			
		}
		if(a!=0)
		{
			if(a+b>5)
			{
				a=b+a-5;
				b=5;
				
			}
			else
			{
				b=b+a;
				a=0;
			}
			i+=1;
			printf("\n%d.Tuang A ke B\nA=%d\nB=%d\n",i,a,b);
		}
		if(b==5)
		{
			b=0;
			i+=1;
			printf("\n%d.Kosongkan B\nA=%d\nB=%d\n",i,a,b);
		}
	}
	printf("\nHasil \nA=%d\nB=%d\nstep=%d",a,b,i);
}
void isib()
{
	int a=0,b=0,i=0;
	while(b!=4)
	{
		if (b==0)
		{
			b=5;
			i+=1;
			printf("\n%d.Isi B\nA=%d\nB=%d\n",i,a,b);
		}
		if(b!=0)
		{
			if(a+b>3)
			{
				b=b+a-3;
				a=3;
			}
			else
			{
				a=b+a;
				b=0;
			}
			i+=1;
			printf("\n%d.Tuang B ke A\nA=%d\nB=%d\n",i,a,b);
		}
		if(a==3)
		{
			a=0;
			i+=1;
			printf("\n%d.Kosongkan A\nA=%d\nB=%d\n",i,a,b);
		}
	}
	printf("\nHasil \nA=%d\nB=%d\nstep=%d",a,b,i);
	
}
int main(int argc, char **argv)
{
	int choose;
	do
	{
		printf("\nOpsi:\n1.Mengukur dengan A\n2.Mengukur dengan B\n\n");
		scanf("%d",&choose);
		if(choose==1)
		{
			isia();
		}else if(choose==2)
		{
			isib();
		}
	} while ((choose<1) || (choose>2));
	
	
	
	return 0;
}

