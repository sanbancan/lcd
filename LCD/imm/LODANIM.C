# include<graphics.h>
# include<stdlib.h>
# include <stdio.h>

main()
{
FILE *fopen(),*fp;
   int d,f,i,inc,loop=0,
   size1,size2,check;
   int xpixe[22] = { 201,206,206,215,207,214,204,212,203,207,200,200,193,196,187,190,181,
		     179,175,162,164,153 };
   int ypixe[22] = { 422,416,404,393,387,374,362,350,342,332,320,307,297,287,283,273,265,
		    255,244,237,229,231 };
   int xpixe1[21] = { 70,78,85,90,95,102,73,77,80,83,87,90,94,93,
		    95,90,80,84,83,86,86 } ;
   int ypixe1[21] = { 417,417,417,417,417,417,410,408,410,408,410,
		     410,410,408,410,400,400,401,395,394};


int graphmode,graphdriver;
void *buff1,*buff2;
graphdriver = VGA;
graphmode = VGAHI;

initgraph(&graphdriver,&graphmode,"");
if(( fp = fopen("loader.dis","rb")) ==NULL)
  {
   printf("\n sorry file not opened successfully");
   exit(1);
   }


    while(!feof(fp))
  {
    d = getw(fp);
    f = getw(fp);
    putpixel(d,f,15);
    }
   fclose(fp);
   setfillstyle(SOLID_FILL,WHITE);
   fillellipse(203,428,2,2);
   fillellipse(211,418,2,1);
   size1=imagesize(201,422,208,432);
   buff1=malloc(size1);
   getimage(201,422,208,432,buff1);

   size2=imagesize(0,362,168,435);
   buff2=malloc(size2);
   getimage(0,362,168,435,buff2);

while(!kbhit())
{
loop = 0;
while(loop<8)
   {
   for(inc=0;inc<22;inc++)
   {
   check=random(3);
    putimage(xpixe[inc],ypixe[inc],buff1,COPY_PUT);
    if (check==1)
    putimage(xpixe[inc],ypixe[inc],buff1,XOR_PUT);
    delay(100);
    sound(50);
}
    loop++;
      }



  nosound();
  setfillstyle(SOLID_FILL,BLACK);
  bar(71,369,104,378);
  line(104,378,90,393);

     for(inc=0;inc<20;inc++)
   {

    putimage(xpixe1[inc],ypixe1[inc],buff1,COPY_PUT);

    delay(400);
}
    sleep(1);
    putimage(0,362,buff2,COPY_PUT);
    sleep(1);
  }

  closegraph();

   }
