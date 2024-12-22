
#  include <graphics.h>
#  include <conio.h>
#  include <stdlib.h>
#  include <bios.h>
//#  include "fileshow.c"
//#  include "utm.c"



      void *buffer,*buff3,*buff2;
      unsigned scan,w,q;
      int mov=0;
      int ncase;
      int image_size,image1,ima;
      int r=58,s=63,t=73,v=68,m=0,n;
      int  z,c,y=400,i=600,g,l,v1,button1;
      int  upper[] = {20,67,30,67,50,52,203,52,203,45,48,45,20,67};
      int upper1[] = {217,45,280,45,280,52,217,52,217,45};
      int screw[]={50,60,200,60,200,80,50,80,50,60};
      int lower[]={20,73,30,73,50,88,280,88,280,95,48,95,20,73};
      int funnel[]={193,45,193,35,150,0,270,0,227,35,227,45,193,45};
      int winding[] = {60,55,65,55,75,85,70,85,60,55};
      int plas[] = {20,73,30,73,40,80,50,80,50,60,40,60,30,67,20,67,20,73};

      int right_mold[] = {-7,33,15,33,15,3,45,3,45,133,15,133,15,103,-7,103,-7,33};
      int left_mold[] ={75,3,105,3,105,33,120,33,120,103,105,103,105,133,75,133,75,3};
      int eject[] = {40,43,55,43,55,58,120,58,120,63,55,63,55,73,120,73,120,78,55,78,55,93,40,93,40,43};


      int font , charsize,direction;
      int line_type,line_pattern,line_thickness;
      int horiz;
      int inc;

      /* FUNCTION DECLARATION'S  */

      void openscreen();
      void screwright();
      void screwleft();
      void moldmotion(void *buff,void *buf);
      void models();
      void no_act();
      void  modelshow(char *arg1[],char *arg2[],char *arg3[]);



	 main()
      {
	int graphdriver,graphmode;
	FILE *i;
	graphdriver = VGA;
	graphmode  = VGAHI;
	initgraph(&graphdriver,&graphmode,"");

	   while(1)
	 {
	   cleardevice();
	   openscreen();


	  while(!kbhit())
	{
	 screwright();
	 moldmotion(buff3,buff2);
	 screwleft();
	}
	  while(bioskey(1) != 0)
	  {
	  scan =  bioskey(0);
	  ncase = scan>>8;
	   }

	   switch(ncase)
	{
	  case 59:
	  models();
	  break;

	  case 60:
	  free(buffer);
	  free(buff3);
	  free(buff2);
	  system(" s ") ;
	  break;


	  case 1 :

	 cleardevice();
	   setviewport(0,0,639,479,0);
	   moveto(160,150);
	   settextstyle(SANS_SERIF_FONT,0,6);
	   outtext("Program by ");
	   moveto(30,200);

	   settextstyle(GOTHIC_FONT,0,8);
	   outtext("Thomas Fernando");
	   sleep(3);

	  closegraph();
	  exit(1);

	   default :
	      break;
	       }




	      }

	       }
       /* HI */
	   void openscreen()

      {
       setviewport(0,0,639,479,0);
       line(0,410,639,410);
       line(110,410,110,479);
       line(210,410,210,479);
       line(310,410,310,479);
       line(410,410,410,479);
       line(520,410,520,479);
       line(639,410,639,479);
       line(0,380,639,380);
       direction = HORIZ_DIR;
       font = SANS_SERIF_FONT;
       charsize = 1;
       moveto(40,420);
       settextstyle(font,direction,charsize);
       outtext( " F1          F2         F3        F4         F5          F6");
       moveto(15,450);
       outtext( " MODELS     DEMO    ADDRESSES  OPTIONS  REFERENCES  AUXILLIARY");
       direction = HORIZ_DIR;
       font = SANS_SERIF_FONT;
       charsize = 3;
       moveto(100,380);
       settextstyle(font,direction,charsize);
       outtext( " press ESC to quit program");
      direction = HORIZ_DIR;
      font = TRIPLEX_FONT;
      charsize = 4;
      line_type = 0;
      line_pattern = 0;
      line_thickness =3;
      moveto(225,50);
      settextstyle(font,direction,charsize);
      setcolor(3);
      rectangle(0,166,639,479);
      moveto(123,167);
      charsize = 4;
      settextstyle(font,direction,charsize);
      setcolor(2);
      outtext("Larsen & Toubro Limited");
      moveto(15,210);
      charsize = 4;
      settextstyle(font,direction,charsize);
      outtext("Mannesmann Demag Kunststofftechnik");

      nosound();

      setcolor(3);
      rectangle(0,0,639,479);


   /*     drawing of the mold     */

      rectangle(0,255,639,479);
      setviewport(325,10,395,200,0);
      setfillstyle(SOLID_FILL,DARKGRAY);
      fillpoly(sizeof(right_mold)/(2*sizeof(int)),right_mold);
      setviewport(197,10,320,200,0);
      fillpoly(sizeof(eject)/(2*sizeof(int)),eject);
      image1 = imagesize(40,43,120,93);
      buff3 = malloc(image1);
      getimage(40,43,120,93,buff3);
      fillpoly(sizeof(left_mold)/(2*sizeof(int)),left_mold);
      ima = imagesize(75,3,120,133);
      buff2 = malloc(ima);
      getimage(75,3,120,133,buff2);

    /*     drawing  of  the  machine    */

      setviewport(350,10,600,100,0);
      setlinestyle(0,0,NORM_WIDTH);
      line(203,52,217,52);
      setfillstyle(SOLID_FILL,LIGHTGRAY);
      fillpoly(sizeof(upper)/(2*sizeof(int)),upper);
      fillpoly(sizeof(upper1)/(2*sizeof(int)),upper1);
      fillpoly(sizeof(lower)/(2*sizeof(int)),lower);
      setfillstyle(SOLID_FILL,LIGHTGRAY);
      fillpoly(sizeof(screw)/(2*sizeof(int)),screw);
      line(280,50,280,90);
      fillpoly(sizeof(lower)/(2*sizeof(int)),lower);
      setfillstyle(SOLID_FILL,LIGHTGRAY);
      fillpoly(sizeof(funnel)/(2*sizeof(int)),funnel);
      setfillstyle(SOLID_FILL,WHITE);
      fillpoly(sizeof(plas)/(2*sizeof(int)),plas);

    /*  drawing  of  the  windings on screw  */


	 r=58,s=63,t=73,v=68,m=0;
      while (m < 7)
   {
       winding[0] = r;
       winding[1] = 55;
       winding[2] = s;
       winding[3] = 55;
       winding[4] = t;
       winding[5] = 85;
       winding[6] = v;
       winding[7] = 85;
       winding[8] = r;
       winding[9] = 55;
       setfillstyle(SOLID_FILL,WHITE);
       fillpoly(sizeof(winding)/(2*sizeof(int)),winding);
       m++;
       r=r+20;
       s=s+20;
       t=t+20;
       v=v+20;
      }

       }

      /*   process  for  motion  of  screw  */


	 void screwright()

      {
       image_size = imagesize(50,55,200,85);
      if (image_size == -1)
      {
	outtext("image > 64 kb ");
      }

      buffer = malloc(image_size);
      getimage(50,55,200,85,buffer);

	 sound(50);

	for ( inc = 50 ; inc <= 100 ; inc = inc++ )
	{
	   putimage(inc,55,buffer,COPY_PUT);
	   putimage(inc,55,buffer,XOR_PUT);
	   setfillstyle(SOLID_FILL,WHITE);
	   bar(inc,60,inc,80);
	   delay(20);
	}

	   putimage(inc,55,buffer,COPY_PUT);
	   nosound();

   }




   /*     viewport reset for  the  machine     */



	    void screwleft()

	  {

	   for (inc = 100 ; inc >= 50 ; inc = inc--)
	 {
	    putimage(inc,55,buffer,COPY_PUT);
	    setfillstyle(SOLID_FILL,BLACK);
	    bar(inc+151,60,inc+160,80);
	    delay(10);
	for(g=y;g<=i;g=g+5)
       {
	sound(g);
       }

	 nosound();

     }

	free(buffer);

		 }
/*

   scan =  bioskey(1);
  ncase = scan>>8;

  switch(ncase)
 {
  case 59:
  cleardevice();
  setviewport(0,0,639,478,0);
  file_show("model.cla");
  delay(1000);
  case 60:
  features();
  case 61:
  addresses();
  case 62:
  options();
  case 63:
  references();
  case 64:
  auxilliaries();
		 }


      }*/



/*  function for movement of  mold   */

void moldmotion(void *buff,void *buf)
      {
int h,j=0,i=0,g=40,c=135;
void *buff1;
int image;
setviewport(197,10,330,200,0);
image = imagesize(23,3,120,133);
buff1 = malloc(image);
getimage(23,3,120,133,buff1);
/*delay(50);
sound(100);
delay(100);
sound(100);
delay(100);
sound(100);
delay(100);
sound(100);
delay(100);
delay(50);
sound(100);
delay(100);
nosound();  */

		for(h=197;h>=160;h--)
	{
 setviewport(h,10,305,200,0);
 putimage(23,3,buff1,COPY_PUT);
 setfillstyle(EMPTY_FILL,BLACK);
 bar(108,3,109,32);
	  bar(121,33,122,103);
	  bar(106,104,107,134);
	 }

	 while(g<=55)
	{
	 putimage(g,43,buff,COPY_PUT);
	 putimage(75,3,buf,COPY_PUT);
	 g++;
	 bar(g-3,43, g-2,93);
	 }
	 while(g>=40)
	 {
	  putimage(g,43,buff,COPY_PUT);
	  putimage(75,3,buf,COPY_PUT);
	  g--;
	  bar(c+1,58,c+1,78);

	  delay(50);
	  c--;
	 }
	for(h=160;h<=197;h++)
	{
	 setviewport(h,10,305,200,0);
	 putimage(23,3,buff1,COPY_PUT);
	 setfillstyle(EMPTY_FILL,BLACK);
	 bar(73,3,74,133);
	}
	  free(buff1);
	  nosound();
	 setviewport(350,10,600,100,0);

		}





	    void models()
	 {
		 int modscan,modcase,modscan1;
	 int a=250,b=115,c,d;
	 char *arg1[10];
	 char *arg2[10];
	 char *arg3[10];
	 char *arg4[10];

	 c=a+13;
	 d=b+13;
	  cleardevice();
	  setviewport(0,0,639,478,0);

	//  file_show("model.cla");
	  setfillstyle(SOLID_FILL,LIGHTGRAY);
	  bar(a,b,c,d);
	  	 b=115;
	 modcase = 2;

	while ( modcase != 1)
     {

	// tuner();
	 modscan = bioskey(0);
	 modcase = modscan >> 8;

	 switch(modcase)
	 {
	   case 80 :
	 if(b < 386)
	{
	  setfillstyle(SOLID_FILL,BLACK);
	  bar(a,b,c,d);
	   b = b+40;
	   d = b+13;

	   setfillstyle(SOLID_FILL,LIGHTGRAY);
	   bar(a,b,c,d);
       }

	   break;

	   case 72 :

	 if (b>115)
	  {
	   setfillstyle(SOLID_FILL,BLACK);
	   bar(a,b,c,d);
	   b = b-40;
	   d = b+13;
	   setfillstyle(SOLID_FILL,LIGHTGRAY);
	   bar(a,b,c,d);
			  }
            	   break;



	     case 28 :


	    if ( b==115)
	     {

	     *arg1 = "d40.cla";
	     *arg2 = "d40.inj";
	     *arg3 = "d40.gen" ;
	     modelshow(arg1,arg2,arg3);

	      }
	       if ( b==155)
	     {

	     *arg1 = "d60.cla";
	     *arg2 = "d60.inj";
	     *arg3 = "d60.gen" ;
	     modelshow(arg1,arg2,arg3);

	      }

	       if ( b==195)
	     {

	     *arg1 = "d85.cla";
	     *arg2 = "d85.inj";
	     *arg3 = "d85.gen" ;
	     modelshow(arg1,arg2,arg3);

	      }
	      if ( b==235)
	     {
	       *arg1 = "d100.cla";
	       *arg2 = "d100.inj";
	       *arg3 = "d100.gen" ;
	       modelshow(arg1,arg2,arg3);

		      }
	       if ( b==275)
	     {

	      *arg1 = "d125.cla";
	      *arg2 = "d125.inj";
	      *arg3 = "d125.gen" ;
	      modelshow(arg1,arg2,arg3);

	      }
	       if ( b==315)
	     {

	     *arg1 = "d150.cla";
	     *arg2 = "d150.inj";
	     *arg3 = "d150.gen" ;
	     modelshow(arg1,arg2,arg3);

		   }

	       if ( b==355)
	     {

	     *arg1 = "d200.cla";
	     *arg2 = "d200.inj";
	     *arg3 = "d200.gen" ;
	     modelshow(arg1,arg2,arg3);

		    }

	       if ( b==395)
	     {
	      *arg1 = "d250.cla";
	     *arg2 = "d250.inj";
	     *arg3 = "d250.gen" ;
	     modelshow(arg1,arg2,arg3);

		    }

	 // file_show("model.cla");
          setfillstyle(SOLID_FILL,LIGHTGRAY);
	  bar(a,b,c,d);
	  break;



		   }
		   }
		  }


void  modelshow(char *arg1[],char *arg2[],char *arg3[])

	      {
		int modsca,modcas,cntr=1;
		cleardevice();
	      //	file_show(*arg1);
		nosound();

		modcas  =  2;

		while ( modcas !=  1)
		{

		modsca = bioskey(0);
		modcas  =  modsca >> 8;

		    switch(modcas)
		  {
		   case 81 :
		   cntr++;
		    while(cntr<=4)
		   {
		    if (cntr == 1)
		     {
		      cleardevice();
		     // file_show(*arg1);
		      break;
		     }

		      if (cntr == 2)
		      {
			cleardevice();
		       //	file_show(*arg2);
			 break;
					      }
		      if (cntr == 3)
		     {
		       cleardevice();
		      // file_show(*arg3);
		      break;
		      }

                      if (cntr >3)
		   {
		      cntr = 3;
		      break;

		   }





		    }
		       break;


		     case 73 :

		      cntr--;

			     while( cntr >=0)
		      {
			if (cntr == 1)
		       {
			cleardevice();
		       //	file_show(*arg1);
						break;
			}
			  if (cntr == 2)
			{
			cleardevice();
		       //	file_show(*arg2);
						break;
			}
		      if (cntr == 3)
			{
			cleardevice();
		       //	file_show(*arg3);

			break;
			}
				  if (cntr <1)
		   {
		      cntr = 1;
		      break;

		   }




			break;

			}
			 break;
				}


				  }
		  cleardevice();

				    }







































