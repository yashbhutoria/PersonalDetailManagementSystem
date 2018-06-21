
#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h>

struct p //structure definition
{
char name[30];
char fname[30];
char dob[20];
char adr[50];
char uid[14];
char pno[12];
int wno;
int crec;
char psno[9];
char dis[10];
int flg;
};

int reg();				//declaration of functions
int acc();
int sloc();
int sname();
int spno();
int edit();
int options();


void main()
{
	int j,i,n,gd=DETECT,gm;//initialize graphics

initgraph(&gd,&gm,"c:\\turboc3\\bgi");                 /*To start the graphics system, we first call initgraph which initializes the graphics system by loading a graphics driver from disk then putting the system into graphics mode*/
setcolor(RED);
settextstyle(1,0,4);
outtextxy(67,20,"Poornima College of Engineering");
arc(0,0,270,0,50);
setfillstyle(1,RED);
for(i=60;i<=getmaxx()-50;i+=20)
{
arc(i,0,180,0,10);
floodfill(i,1,RED);
delay(50);
}
arc(getmaxx(),0,180,270,50);
floodfill(1,1,RED);
floodfill(637,1,RED);
setcolor(2);
rectangle(0,0,getmaxx(),getmaxy());
rectangle(1,1,getmaxx()-1,getmaxy()-1);
rectangle(2,2,getmaxx()-2,getmaxy()-2);
setcolor(1);
line(248,100,298,100);line(298,100,319,115);
line(319,115,340,100);line(340,100,390,100);
line(390,100,390,230);line(248,100,248,230);
arc(319,230,180,255,71);arc(319,230,285,360,71);
line(298,298,319,315);line(319,315,340,298);
setfillstyle(1,RED);
floodfill(250,102,1);
setcolor(YELLOW);
settextstyle(1,0,3);
outtextxy(261,115,"POORNIMA");
settextstyle(0,0,1);
outtextxy(259,141,"GROUP");
settextstyle(0,0,1);
outtextxy(299,141,"OF");
settextstyle(0,0,1);
outtextxy(315,141,"COLLEGES");
for(i=1;i<=5;i++)
circle(319,220,55+i);
setfillstyle(1,YELLOW);
for(i=30;i<=360;i++)
{
if(i%30==0)
{
pieslice(319,220,i-30,i-5,50);
sound(500);
delay(100);
nosound();
delay(100);
}

}

randomize();
setcolor(random(15));
settextstyle(9,0,1);
outtextxy(110,290,"AADHAR DATABASE");
outtextxy(430,290,"SYSTEM");
setcolor(BLUE);
settextstyle(1,0,2);
outtextxy(190,350,"Press any key to continue...");
setcolor(GREEN);
line(0,52,getmaxx(),52);
settextstyle(1,0,1);
outtextxy(50,400,"Guided By:");
outtextxy(30,425,"Mr. Sanjay Gupta");
outtextxy(450,400,"Developed By:");
outtextxy(430,425,"-> Yash Bhutoria");
outtextxy(430,445,"-> Shantanu Raje");
getch();
cleardevice();
options();
}

int options()
{
int n,i=0;
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\turboc3\\bgi");
while(1)
{
setbkcolor(WHITE);							//design of page in graphics
setcolor(GREEN);
setfillstyle(1,GREEN);
rectangle(10,10,630,450);
rectangle(15,15,625,445);
floodfill(12,12,GREEN);

setcolor(1);
settextstyle(1,0,4);
outtextxy(20,20,"      Aadhar Database System      ");
setcolor(9);
settextstyle(1,0,2);
outtextxy(40,70,"1.Register");
outtextxy(40,100,"2.Access Database");
outtextxy(40,130,"3.Search By Locality");
outtextxy(40,160,"4.Search By Phone Number");
outtextxy(40,190,"5.Search By Name");
outtextxy(40,220,"6.Edit Details");
outtextxy(40,250,"7.Exit");
outtextxy(40,360,"Enter Your Choice : ");
setcolor(GREEN);
gotoxy(32,24);
flushall();
scanf("%d",&n);

switch(n)     //calling of function in switch
{
case 1:
	reg();
	getch();
	break;
case 2:
	acc();
	getch();
	break;
case 3:
	sloc();
	getch();
	break;
case 4:
	spno();
	getch();
	break;
case 5:
	sname();
	getch();
	break;
case 6:
	edit();
	getch();
	break;
case 7:  closegraph();
	 exit(1);				//exit statement
default :
outtextxy(200,200,"Input Error!!!Enter Correct Choice");
options();
}
closegraph();					//closing of graphics
}
}

int reg() 						//definition of register function
{
FILE *fp;
struct p A;

int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\turboc3\\bgi");			//initialize graphics


setbkcolor(WHITE);
setcolor(GREEN);
setfillstyle(1,GREEN);
rectangle(10,10,630,450);
rectangle(15,15,625,445);
floodfill(12,12,GREEN);


fp=fopen("nsp.txt","ab");					//opening of file
if(fp==NULL)
{
outtextxy(165,200,"Fatal Error,Database Missing !");
exit(1);						//error in case of missing file or pointer error
}

setcolor(9);
settextstyle(1,0,2);
outtextxy(170,10,"Register Yourself");
flushall();
outtextxy(40,70,"Enter Name : ");		//form for inputs
gotoxy(25,6);
gets(A.name);
flushall();
sound(1000);
delay(100);
nosound();
outtextxy(40,102,"Enter Father's Name : ");
gotoxy(36,8);
gets(A.fname);
flushall();
sound(1000);
delay(100);
nosound();
outtextxy(40,135,"Enter Date of Birth : ");
gotoxy(35,10);
gets(A.dob);
flushall();
sound(1000);
delay(100);
nosound();
outtextxy(40,168,"Enter Address : ");
gotoxy(27,12);
gets(A.adr);
flushall();
sound(1000);
delay(100);
nosound();
outtextxy(40,200,"Enter Aadhar Number : ");
gotoxy(37,14);
gets(A.uid);
flushall();
sound(1000);
delay(100);
nosound();
outtextxy(40,233,"Enter Phone Number : ");
gotoxy(36,16);
gets(A.pno);
flushall();
sound(1000);
delay(100);
nosound();
outtextxy(40,265,"Enter Ward Number : ");
gotoxy(34,18);
scanf("%d",&A.wno);
flushall();
sound(1000);
delay(100);
nosound();
outtextxy(40,298,"Enter Number Of Criminal Records : ");
gotoxy(53,20);
scanf("%d",&A.crec);
flushall();
sound(1000);
delay(100);
nosound();
outtextxy(40,330,"Enter Passport Number : ");
gotoxy(39,22);
gets(A.psno);
flushall();
sound(1000);
delay(100);
nosound();
outtextxy(40,363,"Enter Disability Status : ");
gotoxy(38,24);
gets(A.dis);
flushall();
sound(1000);
delay(100);
nosound();
A.flg=0;

cleardevice();

setbkcolor(WHITE);
setcolor(GREEN);
setfillstyle(1,GREEN);
rectangle(10,10,630,450);
rectangle(15,15,625,445);
floodfill(12,12,GREEN);
setcolor(GREEN);
outtextxy(190,200,"Entries Successfully Recoded!!!!");			//prompt for success
getch();
fwrite(&A,sizeof(A),1,fp);			//writing of file
fclose(fp);									//closing of file
closegraph();
options();								//return to options function
}

int acc()							//definition of access function
{
FILE *fp;
struct p A;

int i=0;
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\turboc3\\bgi");


setbkcolor(LIGHTGRAY);
setcolor(GREEN);
setfillstyle(1,GREEN);
rectangle(10,10,630,450);
rectangle(15,15,625,445);
floodfill(12,12,GREEN);

fp=fopen("nsp.txt","rb");
if(fp==NULL)
{
	setcolor(RED);
outtextxy(165,200,"Fatal Error Database Missing !");
exit(1);
}
while(fread(&A,sizeof(struct p),1,fp)==1)         //loop for reading of file
{
setcolor(BLUE);
settextstyle(1,0,2);
outtextxy(170,10,"Database");
setcolor(9);
outtextxy(40,70,"Name : ");
gotoxy(6,8+i);
puts(A.name);
flushall();
outtextxy(200,70,"Aadhar Number : ");
gotoxy(30,8+i);
puts(A.uid);
flushall();
i+=1;
}
getch();
fclose(fp);
closegraph();
options();
}


int sloc()									//definition of search by location function
{
FILE *fp;
struct p A;

int f=0,n;
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\turboc3\\bgi");


setbkcolor(WHITE);
setcolor(GREEN);
setfillstyle(1,GREEN);
rectangle(10,10,630,450);
rectangle(15,15,625,445);
floodfill(12,12,GREEN);


fp=fopen("nsp.txt","rb");
if(fp==NULL)
{
	setcolor(RED);
outtextxy(165,200,"Fatal Error Database Missing !");
exit(1);
}
setcolor(BLUE);
settextstyle(1,0,2);
outtextxy(170,10,"Search by Location");
settextstyle(1,0,3);
setcolor(9);
outtextxy(60,100,"Enter Ward Number : ");
gotoxy(45,8);
scanf("%d",&n);
flushall();
while(fread(&A,sizeof(struct p),1,fp)==1)
{
if(A.wno==n)
{
cleardevice();
f=1;
setbkcolor(LIGHTGRAY);
setcolor(GREEN);
setfillstyle(1,GREEN);
rectangle(10,10,630,450);
rectangle(15,15,625,445);
floodfill(12,12,GREEN);
setcolor(BLUE);
settextstyle(1,0,2);
outtextxy(170,10,"Search by Location");
setcolor(9);
outtextxy(40,70,"Name : ");
gotoxy(15,6);
puts(A.name);
flushall();
outtextxy(40,102,"Father's Name : ");
gotoxy(26,8);
puts(A.fname);
flushall();
outtextxy(40,135,"Date of Birth : ");
gotoxy(25,10);
puts(A.dob);
flushall();
outtextxy(40,168,"Address : ");
gotoxy(17,12);
puts(A.adr);
flushall();
outtextxy(40,200,"Aadhar Number : ");
gotoxy(29,14);
puts(A.uid);
flushall();
outtextxy(40,233,"Phone Number : ");
gotoxy(28,16);
puts(A.pno);
flushall();
outtextxy(40,265,"Ward Number : ");
gotoxy(26,18);
printf("%d",A.wno);
flushall();
outtextxy(40,298,"Number Of Criminal Records : ");
gotoxy(45,20);
printf("%d",A.crec);
flushall();
outtextxy(40,330,"Passport Number : ");
gotoxy(30,22);
puts(A.psno);
flushall();
outtextxy(40,363,"Disability Status : ");
gotoxy(32,24);
puts(A.dis);
flushall();
outtextxy(300,363,"Flag Status (0 or 1) : ");
gotoxy(68,24);
printf("%d",A.flg);
flushall();
getch();
}
}
if(f==0)
{
cleardevice();
setbkcolor(WHITE);
setcolor(GREEN);
setfillstyle(1,GREEN);
rectangle(10,10,630,450);
rectangle(15,15,625,445);
floodfill(12,12,GREEN);
setcolor(RED);
settextstyle(1,0,2);
outtextxy(250,210,"No Such Person!");
}


getch();
fclose(fp);
closegraph();
options();
}

int spno()							//definition of search by phone number function
{
FILE *fp;
struct p A;
char n[12];

int gd=DETECT,gm,f=0;
initgraph(&gd,&gm,"C:\\turboc3\bgi");

setbkcolor(WHITE);
setcolor(GREEN);
setfillstyle(1,GREEN);
rectangle(10,10,630,450);
rectangle(15,15,625,445);
floodfill(12,12,GREEN);


fp=fopen("nsp.txt","rb");
if(fp==NULL)
{
	setcolor(RED);
outtextxy(165,200,"Fatal Error Database Missing !");
exit(1);
}
setcolor(BLUE);
settextstyle(1,0,2);
outtextxy(170,10,"Search by Phone Number");
settextstyle(1,0,3);
setcolor(9);
outtextxy(60,100,"Enter Phone Number : ");
gotoxy(45,8);
flushall();
gets(n);
flushall();
while(fread(&A,sizeof(struct p),1,fp)==1)
{
if(strcmp(A.pno,n)==0)
{
cleardevice();
f=1;
setbkcolor(LIGHTGRAY);
setcolor(GREEN);
setfillstyle(1,GREEN);
rectangle(10,10,630,450);
rectangle(15,15,625,445);
floodfill(12,12,GREEN);
setcolor(BLUE);
settextstyle(1,0,2);
outtextxy(170,10,"Search by Phone Number");
setcolor(9);
outtextxy(40,70,"Name : ");
gotoxy(15,6);
puts(A.name);
flushall();
outtextxy(40,102,"Father's Name : ");
gotoxy(26,8);
puts(A.fname);
flushall();
outtextxy(40,135,"Date of Birth : ");
gotoxy(25,10);
puts(A.dob);
flushall();
outtextxy(40,168,"Address : ");
gotoxy(17,12);
puts(A.adr);
flushall();
outtextxy(40,200,"Aadhar Number : ");
gotoxy(27,14);
puts(A.uid);
flushall();
outtextxy(40,233,"Phone Number : ");
gotoxy(26,16);
puts(A.pno);
flushall();
outtextxy(40,265,"Ward Number : ");
gotoxy(26,18);
printf("%d",A.wno);
flushall();
outtextxy(40,298,"Number Of Criminal Records : ");
gotoxy(45,20);
printf("%d",A.crec);
flushall();
outtextxy(40,330,"Passport Number : ");
gotoxy(30,22);
puts(A.psno);
flushall();
outtextxy(40,363,"Disability Status : ");
gotoxy(30,24);
puts(A.dis);
flushall();
outtextxy(40,385,"Flag Status (0 or 1) : ");
gotoxy(30,28);
printf("%d",A.flg);
flushall();
getch();
}
if(f==0)
{
cleardevice();
setbkcolor(WHITE);
setcolor(GREEN);
setfillstyle(1,GREEN);
rectangle(10,10,630,450);
rectangle(15,15,625,445);
floodfill(12,12,GREEN);
setcolor(RED);
settextstyle(1,0,2);
outtextxy(250,210,"No Such Person!");
}
}


getch();
fclose(fp);
closegraph();
options();
}

int sname()								//definition of search by name function
{
FILE *fp;
struct p A;
char n[20];

int gd=DETECT,gm,f=0;
initgraph(&gd,&gm,"C:\\turboc3\\bgi");


setbkcolor(WHITE);
setcolor(GREEN);
setfillstyle(1,GREEN);
rectangle(10,10,630,450);
rectangle(15,15,625,445);
floodfill(12,12,GREEN);


fp=fopen("nsp.txt","rb");
if(fp==NULL)
{
	setcolor(RED);
outtextxy(165,200,"Fatal Error Database Missing !");
exit(1);
}
setcolor(BLUE);
settextstyle(1,0,2);
outtextxy(170,10,"Search by Name");
settextstyle(1,0,3);
setcolor(9);
outtextxy(60,100,"Enter Name : ");
gotoxy(29,8);
flushall();
gets(n);
flushall();
while(fread(&A,sizeof(struct p),1,fp)==1)
{
if(strcmp(n,A.name)==0)
{
cleardevice();
f=1;
setbkcolor(LIGHTGRAY);
setcolor(GREEN);
setfillstyle(1,GREEN);
rectangle(10,10,630,450);
rectangle(15,15,625,445);
floodfill(12,12,GREEN);
setcolor(BLUE);
settextstyle(1,0,2);
outtextxy(80,10,"Search by Name");
setcolor(9);
outtextxy(40,70,"Name : ");
gotoxy(15,6);
puts(A.name);
flushall();
outtextxy(40,102,"Father's Name : ");
gotoxy(26,8);
puts(A.fname);
flushall();
outtextxy(40,135,"Date of Birth : ");
gotoxy(25,10);
puts(A.dob);
flushall();
outtextxy(40,168,"Address : ");
gotoxy(17,12);
puts(A.adr);
flushall();
outtextxy(40,200,"Aadhar Number : ");
gotoxy(27,14);
puts(A.uid);
flushall();
outtextxy(40,233,"Phone Number : ");
gotoxy(26,16);
puts(A.pno);
flushall();
outtextxy(40,265,"Ward Number : ");
gotoxy(26,18);
printf("%d",A.wno);
flushall();
outtextxy(40,298,"Number Of Criminal Records : ");
gotoxy(45,20);
printf("%d",A.crec);
flushall();
outtextxy(40,330,"Passport Number : ");
gotoxy(30,22);
puts(A.psno);
flushall();
outtextxy(40,363,"Disability Status : ");
gotoxy(30,24);
puts(A.dis);
flushall();
outtextxy(40,385,"Flag Status (0 or 1) : ");
gotoxy(26,28);
printf("%d",A.flg);
flushall();
}
if(f==0)
{
cleardevice();
setbkcolor(WHITE);
setcolor(GREEN);
setfillstyle(1,GREEN);
rectangle(10,10,630,450);
rectangle(15,15,625,445);
floodfill(12,12,GREEN);
setcolor(RED);
settextstyle(1,0,2);
outtextxy(250,210,"No Such Person");
}
}


getch();
fclose(fp);
closegraph();
options();
}



int edit()						//definition of edit function
{
FILE *fp1,*fp2;
struct p A;

char n[14];
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\turboc3\\bgi");


setbkcolor(LIGHTGRAY);
setcolor(GREEN);
setfillstyle(1,GREEN);
rectangle(10,10,630,450);
rectangle(15,15,625,445);
floodfill(12,12,GREEN);


fp1=fopen("nsp.txt","rb");
fp2=fopen("temp.txt","ab");
if(fp1==NULL||fp2==NULL)
{
setcolor(RED);
outtextxy(165,200,"Fatal Error Database Missing !");
exit(1);
}
setbkcolor(WHITE);
setcolor(BLUE);
settextstyle(1,0,2);
outtextxy(80,10,"Edit Details");
setcolor(9);
outtextxy(40,70,"Enter Aadhar Number : ");
gotoxy(25,10);
flushall();
gets(n);
flushall();
while(fread(&A,sizeof(struct p),1,fp1)==1) //this copies the records to  a temp file as it is
{										   //if they don't match the arguments
if(strcmp(A.uid,n)==1)					   //but edit them if they match
{
fwrite(&A,sizeof(struct p),1,fp2);
}
else
{
cleardevice();
setbkcolor(WHITE);
setcolor(GREEN);
setfillstyle(1,GREEN);
rectangle(10,10,630,450);
rectangle(15,15,625,445);
floodfill(12,12,GREEN);
setcolor(BLUE);
settextstyle(1,0,2);
outtextxy(80,10,"Edit Details");
setcolor(9);
outtextxy(40,70,"Name : ");
gotoxy(15,6);
gets(A.name);
sound(1000);
delay(100);
nosound();
flushall();
outtextxy(40,102,"Father's Name : ");
gotoxy(26,8);
gets(A.fname);
sound(1000);
delay(100);
nosound();
flushall();
outtextxy(40,135,"Date of Birth : ");
gotoxy(25,10);
gets(A.dob);
sound(1000);
delay(100);
nosound();
flushall();
outtextxy(40,168,"Address : ");
gotoxy(17,12);
gets(A.adr);
sound(1000);
delay(100);
nosound();
flushall();
outtextxy(40,233,"Phone Number : ");
gotoxy(26,16);
gets(A.pno);
sound(1000);
delay(100);
nosound();
flushall();
outtextxy(40,265,"Ward Number : ");
gotoxy(26,18);
scanf("%d",&A.wno);
sound(1000);
delay(100);
nosound();
flushall();
outtextxy(40,298,"Number Of Criminal Records : ");
gotoxy(45,20);
scanf("%d",&A.crec);
sound(1000);
delay(100);
nosound();
flushall();
outtextxy(40,330,"Passport Number : ");
gotoxy(30,22);
gets(A.psno);
sound(1000);
delay(100);
nosound();
flushall();
outtextxy(40,363,"Disability Status : ");
gotoxy(30,24);
gets(A.dis);
sound(1000);
delay(100);
nosound();
flushall();

fwrite(&A,sizeof(struct p),1,fp2);
}
}


getch();
fcloseall();
remove("nsp.txt");						//delete original file
rename("temp.txt","nsp.txt");			//rename the temp file as original
closegraph();
options();
}