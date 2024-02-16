#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

struct element{
		char name[20];
		char sb[5];
		int atm;
		float atms;
		char block;
		char atc[20];
		char prop[250];
	       }p,q;

	
int rw,cl;
FILE*fp;
void add();
void explor();
void print();
void mainscreen();
int main()
{
	int a,i,n,y;
	char c,d;
	char date1[15],date2[15],string1[20];
	unsigned int tsz;

system("cls"); 
	mainscreen();
	label1:


	printf("\n\t\t\t\t\t\t\t\t\t\tEnter the corresponding no\n");//(22,19);//(10);
	printf("\n\t\t\t\t\t\t\t\t\t\t1.Add new Element Information\n");//(22,21);
	printf("\n\t\t\t\t\t\t\t\t\t\t2.Explore\n");//(22,23);
	printf("\n\t\t\t\t\t\t\t\t\t\t3.Quit\n");//(22,25);
       	
	fflush(stdin);
	d=getchar();
	switch(d)
	{
		case '1':
		      {
			add();
		       
			break;
		      }
		case '2':
		      {
			explor();
			break;

			}
		case '3':
		      {
			system("cls"); 
			mainscreen();
			
			printf("\n\t\t\t\tTHANK U");
			printf("\n\t\t\t\tBYE...........");
			getchar();
			exit(1);
			break;
			}







		default:
		       {
			system("cls"); 
			mainscreen();
			//(12+128);//(22,11);
			printf("\n\t\t\t\tWrong choice");//(22,13);//(15);
			 printf("\n\t\t\t\tRetype choice");
			goto label1;
			}

	}
	system("cls"); 
	mainscreen();
	goto label1;
	return 0;
}
void mainscreen()
{
	int i,j;
	system("cls"); 
	for(i=2,j=2;i<rw;j++)
	{
		if(j>15)
		j=2;

		//(j);
		//(i,2);
		printf("\n\t\t\t\t%c",'*');
		//(i,cl-1);
		printf("\n\t\t\t\t%c",'*');
		i++;

	}
	for(i=2,j=2;i<cl;i++,j++)
	{
		if(j>15)
		j=2;
		//(j);
		//(2,i);
		printf("\n\t\t\t\t%c",'*');
		//(rw-1,i);
		printf("\n\t\t\t\t%c",'*');

	}
	//(30,4);//(3);
	printf("\n\t\t\t\tModern Periodic Table");
	//(37,6);//(6);
	printf("\n\t\t\t\tDigital");
	//(35,7); //(15);
	printf("\n\t\t\t\t-----------");
}
void add()
{
	char ch;
	label1:
	system("cls"); 
	mainscreen();
		//(15,14);//(10);
	printf("\n\t\t\t\tEnter the Information of Elements:");
       //	printf(" %d",l);
	//(15,16);
	printf("\n\t\t\t\tName , ");
//scanf("\n\t\t\t\t%s\n",p.name);
	//(15,18);
	printf("\n\t\t\t\tSymbol , ");
//scanf("\n\t\t\t\t%s\n",p.sb);
	//(15,20);
	printf("\n\t\t\t\tAtomic No ,  ");
//scanf("\n\t\t\t\t%d\n",&p.atm);
	//(15,22);
	printf("\n\t\t\t\tAtomic Wt , ");
//scanf("\n\t\t\t\t%f\n",&p.atms);
	//(15,24);
	printf("\n\t\t\t\tAtomic Config , ");
   // scanf("\n\t\t\t\t%s\n",p.atc);
	fflush(stdin);
	//(15,26);
	printf("\n\t\t\t\tBlock ,");
//scanf("\n\t\t\t\t%c\n",p.block);
	//(15,28);
	printf("\n\t\t\t\tproperties ,\n ");
    //scanf("\n\t\t\t\t%s\n",p.prop);



	//(15);
	fflush(stdin);
	//(20,16);
	scanf("\n%[^\n]",p.name);
	p.name[0]=toupper(p.name[0]);

	fflush(stdin);
	//(23,18);
	scanf("%[^\n]",p.sb);
	p.sb[0]=toupper(p.sb[0]);

	fflush(stdin);
	//(25,20);
	scanf("%d",&p.atm);

	fflush(stdin);
	//(25,22);
	scanf("%f",&p.atms);

	fflush(stdin);
	//(29,24);
	scanf("%[^\n]",p.atc);

	fflush(stdin);
	//(21,26);
	scanf("%c",&p.block);
	p.block=toupper(p.block);
	if(p.block!='S'&&p.block!='P'&&p.block!='D'&&p.block!='F')
	p.block=' ';
	fflush(stdin);

	//(26,28);
	scanf("%[^\n]",p.prop);
	p.prop[0]=toupper(p.prop[0]);



	 /*	//(9,30);
	printf("(In Short)");

	//(5,33);
	printf("Reff. Specialist no:");      */
	if((fp=fopen("data","ab+"))==NULL)
	{
		printf("\n\t\t\t\tCannot open the file f1");
		getchar();
		exit(1);
	}
	fwrite(&p,sizeof(p),1,fp);
	fclose(fp);
	printf("\n\t\t\t\tEnter 'y' for next record(y/n):");
	ch=getchar();
	if(ch=='y')
	{
		goto label1;
	}

       //	getchar();
}
void explor()
{
	char d,c;
	FILE *f;
	int given_atomic_no,a,i,tsz,n;
	float given_atomic_mass;
	int flag;
	char string[20];
	startofexplore:
	system("cls"); 
	mainscreen();
	label6:
	//(22,15);//(12);
	printf("\n\t\t\t\tEnter the corresponding no");//(22,19);//(3);
	printf("\n\t\t\t\t1.Search by 'NAME'");//(22,21);
	printf("\n\t\t\t\t2.Search by SYMBOL");//(22,23);
	printf("\n\t\t\t\t3.Search by ATOMIC NUMBER");//(22,25);
	printf("\n\t\t\t\t4.Search by ATOMIC WEIGHT");//(22,27);
	printf("\n\t\t\t\t5.Elements of Diff. Blocks");//(22,29);
	printf("\n\t\t\t\t6.Return to main menu");
    printf("\n\n");
	//(25,32);
	fflush(stdin);
	d=getchar();
	switch(d)
       {
		case '1':
		{
			system("cls"); 
			mainscreen();
			//(15,25);
			//(12);
			printf("\n\t\t\t\tEnter the Name of Element:");
			//(3);
			fflush(stdin);
			scanf("%[^\n]",string);
			printf("\n\t\t\t\t%s",string);
			string[0]=toupper(string[0]);
			if((fp=fopen("data","rb+"))==NULL)
			{
			system("cls"); 

			printf("\n\t\t\t\t cannot open the record file 1");
			getchar();
			exit(1);
			}
			flag=1;
			while(fread(&p,sizeof(p),1,fp))
			{
				 if(strcmp(p.name,string)==0)
				{
					print();

					flag=0;

					break;
				 }

			}
			if(flag==1)
			{
				system("cls"); 
				mainscreen();
				//(25,25);
				//(12);
				printf("\n\t\t\t\t::No Element Available::");

			}

			fclose(fp);
			getchar();
			break;
		}
		case '2':
		{
			system("cls"); 
			mainscreen();
			//(22,15);
			//(12);
			printf("\n\t\t\t\tEnter the symbol:");
			//(3);
			fflush(stdin);
			scanf("%[^\n]",string);
			printf("\n\t\t\t\t%s",string);
			string[0]=toupper(string[0]);
			if((fp=fopen("data","rb+"))==NULL)
			{
			system("cls"); 

			printf("\n\t\t\t\t cannot open the record file 1");
			getchar();
			exit(1);
			}
			flag=1;
			while(fread(&p,sizeof(p),1,fp))
			{
				 if(strcmp(p.sb,string)==0)
				{
					print();
					flag=0;


					break;
				 }

			}
			if(flag==1)
			{
				system("cls"); 
				mainscreen();
				//(25,25);
				//(12);
				printf("\n\t\t\t\t::No Element Available::");

			}

			fclose(fp);
			getchar();
			break;
		}
		case '6':
		{
			return;
		}
		case '3':
		{
			system("cls"); 
			mainscreen();
			//(15,25);
			//(12);
			printf("\n\t\t\t\tEnter the Atomic No. Element:");
			//(3);
			fflush(stdin);
			scanf("%d",&given_atomic_no);
			if((fp=fopen("data","rb+"))==NULL)
			{
			system("cls"); 

			printf("\n\t\t\t\t cannot open the record file 1");
			getchar();
			exit(1);
			}
			flag=1;
			while(fread(&p,sizeof(p),1,fp))
			{
				 if(p.atm==given_atomic_no)
				{
					print();
					flag=0;

					break;
				 }

			}
			if(flag==1)
			{
				system("cls"); 
				mainscreen();
				//(25,25);
				//(12);
				printf("\n\t\t\t\t::No Element Available::");

			}

			fclose(fp);
			getchar();
			break;
		}
		case '4':
		{
			system("cls"); 
			mainscreen();
			//(15,22);
			//(12);
			printf("\n\t\t\t\tEnter the Atomic mass of Element:");
			//(3);
			fflush(stdin);
			scanf("%f",&given_atomic_mass);
			if((fp=fopen("data","rb+"))==NULL)
			{
			system("cls"); 

			printf("\n\n\t\t\t\t cannot open the record file 1");
			getchar();
			exit(1);
			}
			flag=1;
			while(fread(&p,sizeof(p),1,fp))
			{
				 if(p.atms==given_atomic_mass)
				{
					print();
					flag=0;

					break;
				 }

			}
			if(flag==1)
			{
				system("cls"); 
				mainscreen();
				//(25,25);
				//(12);
				printf("\n\t\t\t\t::No Element Available::");

			}

			fclose(fp);
			getchar();
			break;
		}
		case '5':
		{

			system("cls"); 
			mainscreen();
			//(15,25);
			//(12);
			printf("\n\t\t\t\tEnter the Block:");
			//(3);
			fflush(stdin);
			scanf("%c",&c);
			c=toupper(c);
			if((f=fopen("temp","wb+"))==NULL)
			{
			system("cls"); 

			printf("\n\t\t\t\t cannot open the temp file 1");
			getchar();
			exit(1);
			}


			if((fp=fopen("data","rb+"))==NULL)
			{
			system("cls"); 

			printf("\n\t\t\t\t cannot open the record file 1");
			getchar();
			exit(1);
			}
			flag=1;
			while(fread(&p,sizeof(p),1,fp))
			{
				 if(p.block==c)
				{
					fwrite(&p,sizeof(p),1,f);
				 }

			}
			fclose(f);
			fclose(fp);

					 if((f=fopen("temp","rb+"))==NULL)
					      {
						printf("\n\t\t\t\tCannot open the file");
						getchar();
						exit(1);
					      }
					 fseek(f,0,SEEK_END);
					 tsz=ftell(f);
					 n=(int)(tsz/sizeof(p));
					 for(i=0;i<(n-1);i++)
					 {
						for(a=i+1;a<n;a++)
						{
						fseek(f,i*sizeof(p),SEEK_SET);
						fread(&p,sizeof(p),1,f);
						fseek(f,a*sizeof(p),SEEK_SET);
						fread(&q,sizeof(p),1,f);
						if((p.atm-q.atm)>0)
							{
							fseek(f,i*sizeof(p),SEEK_SET);
							fwrite(&q,sizeof(p),1,f);
							fseek(f,a*sizeof(p),SEEK_SET); fflush(stdin);
							fwrite(&p,sizeof(p),1,fp);
							}
						}
					}
					rewind(f);
			while(fread(&p,sizeof(p),1,f))
			{

					print();
					getchar();


			}


				system("cls"); 
				mainscreen();
				//(25,25);
				//(12);
				printf("\n\t\t\t\t::No Element Available::");



			fclose(f);
			getchar();
			break;
		}


		default:
		{
				system("cls"); 
				mainscreen();
				//(12+128);//(22,11);
				printf("\n\t\t\t\tWrong choice");//(22,13);//(15);
				 printf("\n\t\t\t\tRetype choice");
				goto label6;
		}
	}
	goto startofexplore;

}
void print()
{
	system("cls"); 
	mainscreen();
	//(15,16);
	printf("\n\t\t\t\tName : ");
printf("\n\t\t\t\t%s\n",p.name);
	//(15,18);
	printf("\n\t\t\t\tSymbol : ");
printf("\n\t\t\t\t%s\n",p.sb);
	//(15,20);
	printf("\n\t\t\t\tAtomic No :  ");
printf("\n\t\t\t\t%d\n",p.atm);
	//(15,22);
	printf("\n\t\t\t\tAtomic Wt : ");
printf("\n\t\t\t\t%f\n",p.atms);
	//(15,24);
	printf("\n\t\t\t\tAtomic Config : ");
    printf("\n\t\t\t\t%s\n",p.atc);
	fflush(stdin);
	//(15,26);
	printf("\n\t\t\t\tBlock : ");
printf("\n\t\t\t\t%c\n",p.block);
	//(15,28);
	printf("\n\t\t\t\tproperties : ");
    printf("\n\t\t\t\t%s\n",p.prop);


	//(6);

	//(20,16);
	//printf("\n\t\t\t\t%s",p.name);

	//(23,18);
//	printf("\n\t\t\t\t%s",p.sb);

	fflush(stdin);
	//(25,20);
	//printf("\n\t\t\t\t%d",p.atm);

	fflush(stdin);

	//(25,22);
	//printf("\n\t\t\t\t%f",p.atms);

	fflush(stdin);
	//(29,24);
//	printf("\n\t\t\t\t%s",p.atc);

	//(21,26);
	//printf("\n\t\t\t\t%c",p.block);

	//(26,28);
	//printf("\n\t\t\t\t%s",p.prop);
}
