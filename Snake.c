#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void display();
void play();
char b[1000][1000],s,l;
int h1,h2,x,y,tx[1000],ty[1000],k,len=5,r1,r2;
h1=5;
h2=5;
x=3;
y=7;
int main(void)
{
	system("clear");
	box();
	while(1)
	{
		display();
		play();
	}//end of while
	return 0;
}
void box()//generates box for the snake
{
	int i,j;
	s=h1;
	system("clear");	
	for(i=0;i<15;i++)
		{
			for(j=0;j<30;j++)
			{	
				if(i==0 || i==14)
				b[i][j]='_';
				else if(j==29 || j==0)
				b[i][j]='|';
				else
				b[i][j]=' ';
				b[x][y]='*';
				for(l=s;l<s+5;l++)
				{
					b[s][l]='x';
				}
					
			}// end of 2nd for j for
		}//end of first for i for
	for(i=0;i<15;i++)
	{
		for(j=0;j<30;j++)
		{
			if(b[i][j]=='x')
			{
				tx[k]=i;
				ty[k]=j;
				k++;
			}
		}
	}
}	// end of the function box
void display()//display the movement of snake
{
	int i,j;
	printf("\n\n");
	system("clear");
	k=0;
	for(i=0;i<15;i++)
	{
		for(j=0;j<30;j++)
		{
			printf("%c",b[i][j]);
		}
		printf("\n");
	}
}//end of the function display
void play()
{
	srand((time(NULL)));
	char ch,ch1;
	int p,q,i,j,tempx,tempy;
	p=h1;
	q=h2;
	k=0;
	printf("\nEnter w to move up, \nEnter s to move down, \nEnter a to move left and \nEnter d to move right : ");
	printf("\n");
	scanf("\n%c%*c",&ch1);
	if(ch1=='w')		// this if make snake move up
	{
		k=0;
		if(b[tx[k]-1][tx[k]]=='_')
		{
			printf("\nGame Over");
			exit(0);
		}
		else
		{	
			if(b[tx[k]-1][ty[k]]=='x')
			{
				printf("\nInvalid move\nTry to move snake in different direction");
			}
			else
			{
				k=0;
				if( (b[tx[k]-1][ty[k]]) == '*')
				{	
					len++;
					b[tx[k]-1][ty[k]]='x';
					b[tx[k+len]][ty[k+len]]='x';
					p=tx[k]-1;
					q=ty[k];
					a1 :
					r1=(rand()%15);
					r2=(rand()%30);
					if(r1 <= 3 || r1 >= 12)
					{
						goto a1;
					}
					if (r2 <= 3 || r2 >= 25)
					{
						goto a1;
					}
					for(j=0;j<len;j++)
					{
						if(r1==tx[j] && r2==ty[j])
						{
							goto a1;
						}
					}
					b[r1][r2]='*';
					display();
				}
				else
				{
					b[tx[k]-1][ty[k]]='x';
					p=tx[k]-1;
					q=ty[k];
				}
				while(1)
				{
					if(b[tx[k+1]][ty[k+1]]=='x')
					{
						b[tx[k]][ty[k]]='x';
						k++;
					}
					else
					{
						b[tx[k]][ty[k]]=' ';
						k++;
						break;
					} //else
				}//end of while
				for(i=0;i<k;i++)
				{
					tempx=tx[i];
					tempy=ty[i];
					tx[i]=p;
					ty[i]=q;
					p=tempx;
					q=tempy;
				}
			}//end of else
		} //else of coding to move in left
	} //else if of choice "w"
	else if(ch1=='s')
	{
		if(b[tx[k]+1][tx[k]]=='_')
		{
			printf("game over");
			exit(1);
		}
		else
		{
			if(b[tx[k]+1][ty[k]]=='x')
			printf("\nillegal move\nMOVE SNAKE IN CORRECT DIRECTION ");
			else
			{
				k=0;
				if( (b[tx[k]+1][ty[k]]) == '*')
				{	
					len++;
					b[tx[k]+1][ty[k]]='x';
					b[tx[k+len]][ty[k+len]]='x';
					p=tx[k]+1;
					q=ty[k];
					a2 :
					r1=(2+rand()%15);
					r2=(2+rand()%30);
					if(r1 <= 3 || r1 >= 12)
					{
						goto a2;
					}
					if (r2 <= 3 || r2 >= 25)
					{
						goto a1;
					}
					for(j=0;j<len;j++)
					{
						if(r1==tx[j] && r2==ty[j])
						{
							goto a2;
						}
					}
					b[r1][r2]='*';
					display();
				}
				else
				{
					b[tx[k]+1][ty[k]]='x';
					p=tx[k]+1;
					q=ty[k];
				}
				while(1)
				{
					if(b[tx[k+1]][ty[k+1]]=='x')
					{
						b[tx[k]][ty[k]]='x';
						k++;
					}
					else
					{
						b[tx[k]][ty[k]]=' ';
						k++;
						break;
					} //else
				}//end of while
				for(i=0;i<k;i++)
				{
					tempx=tx[i];
					tempy=ty[i];
					tx[i]=p;
					ty[i]=q;
					p=tempx;
					q=tempy;
				}
			}//end of else
		} //else of coding to move in left
	}//end of else which move snake downward
	else if(ch1=='a')
	{
		if(b[tx[k]][ty[k]-1] == '|')
		{
			printf("game over");
			exit(1);
		}
		else
		{
			if(b[tx[k]][ty[k]-1]=='x')
			printf("\nillegal move\nMOVE SNAKE IN CORRECT DIRECTION ");
			else
			{
				k=0;
				if( (b[tx[k]][ty[k]-1]) == '*')
				{	
					len++;
					b[tx[k]][ty[k]-1]='x';
					b[tx[k+len]][ty[k+len]]='x';
					p=tx[k];
					q=ty[k]-1;
					a3 :
					r1=(2+rand()%15);
					r2=(2+rand()%30);
					if(r1 <= 3 || r1 >= 12)
					{
						goto a3;
					}
					if (r2 <= 3 || r2 >= 25)
					{
						goto a3;
					}
					for(j=0;j<len;j++)
					{
						if(r1==tx[j] && r2==ty[j])
						{
							goto a3;
						}
					}
					b[r1][r2]='*';
					display();
				}
				else
				{
					b[tx[k]][ty[k]-1]='x';
					p=tx[k];
					q=ty[k]-1;
				}
				while(1)
				{
					if(b[tx[k+1]][ty[k+1]]=='x')
					{
						b[tx[k]][ty[k]]='x';
						k++;
					}
					else
					{
						b[tx[k]][ty[k]]=' ';
						k++;
						break;
					} //else
				}//end of while
				for(i=0;i<k;i++)
				{
					tempx=tx[i];
					tempy=ty[i];
					tx[i]=p;
					ty[i]=q;
					p=tempx;
					q=tempy;
				}
			}//end of else
		} //else of coding to move in left
	}//end of if a which moves snake left
	else if(ch1=='d')
	{
		if(b[tx[k]][ty[k]+1] == '|')
		{
			printf("game over");
			exit(1);
		}
		else
		{
			if(b[tx[k]][ty[k]+1]=='x')
			printf("\nillegal move\nMOVE SNAKE IN CORRECT DIRECTION ");
			else
			{
				k=0;
				if( (b[tx[k]][ty[k]+1]) == '*')
				{	
					len++;
					b[tx[k]][ty[k]+1]='x';
					b[tx[k+len]][ty[k+len]]='x';
					p=tx[k];
					q=ty[k]+1;
					a4 :
					r1=(2+rand()%15);
					r2=(2+rand()%30);
					if(r1 <= 3 || r1 >= 12)
					{
						goto a4;
					}
					if (r2 <= 3 || r2 >= 25)
					{
						goto a1;
					}
					for(j=0;j<len;j++)
					{
						if(r1==tx[j] && r2==ty[j])
						{
							goto a4;
						}
					}
					b[r1][r2]='*';
					display();
				}
				else
				{
					b[tx[k]][ty[k]+1]='x';
					p=tx[k];
					q=ty[k]+1;
				}
				while(1)
				{
					if(b[tx[k+1]][ty[k+1]]=='x')
					{
						b[tx[k]][ty[k]]='x';
						k++;
					}
					else
					{
						b[tx[k]][ty[k]]=' ';
						k++;
						break;
					} //else
				}//end of while
				for(i=0;i<k;i++)
				{
					tempx=tx[i];
					tempy=ty[i];
					tx[i]=p;
					ty[i]=q;
					p=tempx;
					q=tempy;
				}
			}//end of else
		} //else of coding to move in left
	}//end of d end of movement of snake in right
}// closing of function play
