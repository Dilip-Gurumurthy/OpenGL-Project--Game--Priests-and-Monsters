
#include<stdio.h>
#include<math.h>
#include<glut.h>



float posX = 0.4, posY = 0.1, posZ = 0;
float ac=-.1,ab=.1,bb=0.0,cc=0;
int rig=1,lef=0;
int pa=3,ma=3,c1=0,c2=0;
int mb=0,pb=0,keyp=0,keym=0,keyp2=0,keym2=0;
int la=1,lb=0,rt=0,in=0;
int ctr1=0,ctr2=0;//11=p,22=m
float move_unit = 0.15f;
float kx=-.2,ky=.85;

void outtext(char *string,float x,float y,int a) 
{ 
	char *c;
	glRasterPos2f(x,y);
	switch(a)
	{
	case 1:
			for (c=string; *c != '\0'; c++) 
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
			}
			break;
	case 2:
			for (c=string; *c != '\0'; c++) 
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
			}
			break;
	case 3:
			for (c=string; *c != '\0'; c++) 
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
			}
			break;		
	}
	
}
void draw(float cx,float cy)
{
	glColor3f(1.0,1.0,0.0);
	glPointSize(8.0);
	glBegin(GL_POINTS);
	glVertex2f(cx,cy);
	glEnd();
}
void plot(float h,float k,float x,float y)
{
	draw(x+h,y+k);
	draw(-x+h,y+k);
	draw(x+h,-y+k);
	draw(-x+h,-y+k);
	draw(y+h,x+k);
	draw(-y+h,x+k);
	draw(y+h,-x+k);
	draw(-y+h,-x+k);
}
void circle(float h,float k,float r)
{
	float x=0,d=0.01-r,y=r;
	
	if(r>0)
	{
		
	while(y>x)
	{
		plot(h,k,x,y);
		if(d<0)
			d+=2*x+.03;
		else
		{
			d+=2*(x-y)+.05;
			y=y-.01;
		}
		x=x+.01;
	}
	plot(h,k,x,y);
	r=r-.01;
	circle(kx,ky,r);
	}

}

void gamewin()
{
	int k;
	if(pb==3)
	{
	
	for(k=0;k<2000;k++)
	{
		glColor3f(1.0,0.0,0.0);
		outtext("YOU WIN !!",-.2,.2,1);
	}
	exit(0);
	}

}
void gamelose()
{
	int k;
	rt=1;
	for(k=0;k<1000;k++)
	{
		glColor3f(1.0,0.0,0.0);
		outtext("GAME OVER!",.25,.3,1);
		//glColor3f(1.0,0.0,0.0);
		//outtext("THE MONSTERS ATTECKED THE PRIESTS !!",-.1,.2,1);
	}
	
}
void retry()
{
if(rt==1)
{
posX = 0.4, posY = 0.1, posZ = 0;
ac=-.1,ab=.1,bb=0.0,cc=0;
rig=1,lef=0;
pa=3,ma=3,c1=0,c2=0;
mb=0,pb=0,keyp=0,keym=0,keyp2=0,keym2=0;
la=1,lb=0;
ctr1=0,ctr2=0;//11=p,22=m
kx=-.2,ky=.85;
rt=0,in=0;
}
}


void testa()
{
	if(pa>0 && pa<ma)
		gamelose();
	if(pb>0 && pb==mb && ((ctr1==22 && ctr2!=11)||(ctr1!=11 && ctr2==22)))
		gamelose();
	
}
void testb()
{
	if(pb>0 && pb<mb)
		gamelose();
	if(pa>0 && pa==ma && ((ctr1==22 && ctr2!=11)||(ctr1!=11 && ctr2==22)))
		gamelose();
}
void rect(){
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-.15,.1);
    glVertex2f(.15, 0.1);
    glVertex2f(.05, -0.1);
    glVertex2f(-.25, -0.1);
    glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-.13,.08);
    glVertex2f(.13, 0.08);
    glVertex2f(.03, -0.08);
    glVertex2f(-.23, -0.08);
    glEnd();
}
void pla()
{
	 if(c1==0) 
					 {
						 if(pa==3)
						 {
							 keyp=3;
							 pa--;
							 ctr1=11;
							 c1=1;
						 }
						 else if(pa==2)
						 {
							 keyp=2;
							 pa--;
							 ctr1=11;
							 c1=1;
						 }
						 else if(pa==1)
						 {
							 keyp=1;
							 pa--;
							 ctr1=11;
							 c1=1;
						 }
					 }
					 else if(c1==1 && c2==0)
					 {
						 if(pa==3)
						 {
							 keyp2=3;
							 pa--;
							 ctr2=11;
							 c2=1;
						 }
						 else if(pa==2)
						 {
							 keyp2=2;
							 pa--;
							 ctr2=11;
							 c2=1;
						 }
						 else if(pa==1)
						 {
							 keyp2=1;
							 pa--;
							 ctr2=11;
							 c2=1;
						 }
					 }
}
void plb()
{
	 if(c1==0) 
					 {
						 if(pb==3)
						 {
							 keyp=3;
							 pb--;
							 ctr1=11;
							 c1=1;
						 }
						 else if(pb==2)
						 {
							 keyp=2;
							 pb--;
							 ctr1=11;
							 c1=1;
						 }
						 else if(pb==1)
						 {
							 keyp=1;
							 pb--;
							 ctr1=11;
							 c1=1;
						 }
					 }
					 else if(c1==1 && c2==0)
					 {
						 if(pb==3)
						 {
							 keyp2=3;
							 pb--;
							 ctr2=11;
							 c2=1;
						 }
						 else if(pb==2)
						 {
							 keyp2=2;
							 pb--;
							 ctr2=11;
							 c2=1;
						 }
						 else if(pb==1)
						 {
							 keyp2=1;
							 pb--;
							 ctr2=11;
							 c2=1;
						 }
					 }
}


void mla()
{
	 if(c1==0) 
					 {
						 if(ma==3)
						 {
							 keym=3;
							 ma--;
							 ctr1=22;
							 c1=1;
						 }
						 else if(ma==2)
						 {
							 keym=2;
							 ma--;
							 ctr1=22;
							 c1=1;
						 }
						 else if(ma==1)
						 {
							 keym=1;
							 ma--;
							 ctr1=22;
							 c1=1;
						 }
					 }
					 else if(c1==1 && c2==0) 
					 {
						 if(ma==3)
						 {
							 keym2=3;
							 ma--;
							 ctr2=22;
							 c2=1;
						 }
						 else if(ma==2)
						 {
							 keym2=2;
							 ma--;
							 ctr2=22;
							 c2=1;
						 }
						 else if(ma==1)
						 {
							 keym2=1;
							 ma--;
							 ctr2=22;
							 c2=1;
						 }
					 }
}
void mlb()
{
	 if(c1==0) 
					 {
						 if(mb==3)
						 {
							 keym=3;
							 mb--;
							 ctr1=22;
							 c1=1;
						 }
						 else if(mb==2)
						 {
							 keym=2;
							 mb--;
							 ctr1=22;
							 c1=1;
						 }
						 else if(mb==1)
						 {
							 keym=1;
							 mb--;
							 ctr1=22;
							 c1=1;
						 }
					 }
					 else if(c1==1 && c2==0) 
					 {
						 if(mb==3)
						 {
							 keym2=3;
							 mb--;
							 ctr2=22;
							 c2=1;
						 }
						 else if(mb==2)
						 {
							 keym2=2;
							 mb--;
							 ctr2=22;
							 c2=1;
						 }
						 else if(mb==1)
						 {
							 keym2=1;
							 mb--;
							 ctr2=22;
							 c2=1;
						 }
					 }
}
void keyboardown(unsigned char keys, int x, int y)
{
	
switch(keys)
{

		case 'p':if(rig==1 && ((c1+c2)<2))
				 {
					pla();
				 }
				 if(lef==1 && ((c1+c2)<2))
				 {
					plb();
				 }
				
				 break;
	
		case 'm':if(rig==1 && ((c1+c2)<2))
				 {
				    mla();	
				 }
				 if(lef==1 && ((c1+c2)<2))
				 {
				    mlb();	
				 }
				
				 break;
		
		case 'z': if(rig==1)
				  {
					  if(c1==1 && ctr1==11)
					  {
						  ctr1=0;
						  c1=0;
						  pa++;
					  }
					  if(c1==1 && ctr1==22)
					  {
						  ctr1=0;
						  c1=0;
						  ma++;
					  }
				  }
				  
				  if(lef==1)
				  {
					  if(c1==1 && ctr1==11)
					  {
						  ctr1=0;
						  c1=0;
						  pb++;
					  }
					  if(c1==1 && ctr1==22)
					  {
						  ctr1=0;
						  c1=0;
						  mb++;
					  }
				  }

				  break;
		case 'x':if(rig==1)
				  {
					  if(c2==1 && ctr2==11)
					  {
						  ctr2=0;
						  c2=0;
						  pa++;
					  }
					  if(c2==1 && ctr2==22)
					  {
						  ctr2=0;
						  c2=0;
						  ma++;
					  }
				  }

				 if(lef==1)
				  {
					  if(c2==1 && ctr2==11)
					  {
						  ctr2=0;
						  c2=0;
						  pb++;
					  }
					  if(c2==1 && ctr2==22)
					  {
						  ctr2=0;
						  c2=0;
						  mb++;
					  }
				  }
				
				  break;
		case 'i':if(in==0)
					 in=1;
				 else if(in==1)
					 in=0;
				 break;


		case 13:
			     retry();
				 break;
				
		case 27:exit(0);
				
		default: break;
			
}
  glutPostRedisplay();  
}

void keyboard(int key, int x, int y)
{
	double i;
	
    switch (key){
        case GLUT_KEY_RIGHT:
            if(rig==0 && lef==1 && (c1+c2)>0)
			{   rig=1;
				lef=0;
				for(i=0;i<=3;i++)
				{
					posX+=move_unit;
							
				}
			}
			
			testb();
			break;

        case GLUT_KEY_LEFT:
            if(rig=1 && lef==0 && (c1+c2)>0)
			{	
				rig=0;
				lef=1;
				for(i=0;i<=3;i++)
				{
					posX-=move_unit;
				
				}
			}
			testa();
			
			 break;
		
	}
	glutPostRedisplay();
}

void buildings()
{
	glColor3f(255.0,0.0,175.0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.95,0.2,0.0); 
	glVertex3f(-.85,.2,0.0); 
	glVertex3f(-.85,0.0,0.0); 
	glVertex3f(-.95,0.0,0.0); 
	glEnd();
	
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex3f(-0.95,0.2,0.0); 
	glVertex3f(-.85,.2,0.0); 
	glVertex3f(-.85,0.0,0.0); 
	glVertex3f(-.95,0.0,0.0); 
	glEnd();
    //1st win
	glColor3f(0.5,0.0,1.0);
	glBegin(GL_POLYGON);
	glVertex3f(-.93,.15,0.0); 
	glVertex3f(-.91,.15,0.0); 
	glVertex3f(-.91,.1,0.0); 
	glVertex3f(-.93,.1,0.0); 
	glEnd();
    //2nd win
	glColor3f(0.5,0.0,1.0);
	glBegin(GL_POLYGON);
	glVertex3f(-.89,.15,0.0); 
	glVertex3f(-.87,.15,0.0); 
	glVertex3f(-.87,.1,0.0); 
	glVertex3f(-.89,.1,0.0); 
	glEnd();
    //doors
	glColor3f(.81,.0,0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-.92,.05,0.0); 
	glVertex3f(-.88,.05,0.0); 
	glVertex3f(-.88,0.0,0.0); 
	glVertex3f(-.92,0.0,0.0); 
	glEnd();
	//3rd building
	glColor3f(0.0,0.0,211.0);
	glBegin(GL_POLYGON);
	glVertex3f(-.8,.3,0.0);
    glVertex3f(-.7,.3,0.0);
	glVertex3f(-.7,0.0,0.0);
	glVertex3f(-.8,0.0,0.0);
	glEnd();
	//2nd building
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-.84,.15,0.0);
    glVertex3f(-.79,.15,0.0);
	glVertex3f(-.79,0.0,0.0);
	glVertex3f(-.84,0.0,0.0);
	glEnd();
	//4th building
	glColor3f(255.0,215.0,0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-.7,.4,0.0);
    glVertex3f(-.5,.4,0.0);
	glVertex3f(-.5,0.0,0.0);
	glVertex3f(-.7,0.0,0.0);
	glEnd();
	//4th windows
	glColor3f(0.0,0.0,205.0);
	glBegin(GL_POLYGON);
	glVertex3f(-.66,.35,0.0);
    glVertex3f(-.64,.35,0.0);
	glVertex3f(-.64,.3,0.0);
	glVertex3f(-.66,.3,0.0);
	glEnd();

	glColor3f(0.0,0.0,205.0);
	glBegin(GL_POLYGON);
	glVertex3f(-.66,.25,0.0);
    glVertex3f(-.64,.25,0.0);
	glVertex3f(-.64,.2,0.0);
	glVertex3f(-.66,.2,0.0);
	glEnd();

	glColor3f(0.0,0.0,205.0);
	glBegin(GL_POLYGON);
	glVertex3f(-.66,.15,0.0);
    glVertex3f(-.64,.15,0.0);
	glVertex3f(-.64,.1,0.0);
	glVertex3f(-.66,.1,0.0);
	glEnd();

	glColor3f(0.0,0.0,205.0);
	glBegin(GL_POLYGON);
	glVertex3f(-.56,.35,0.0);
    glVertex3f(-.54,.35,0.0);
	glVertex3f(-.54,.3,0.0);
	glVertex3f(-.56,.3,0.0);
	glEnd();

	glColor3f(0.0,0.0,205.0);
	glBegin(GL_POLYGON);
	glVertex3f(-.56,.25,0.0);
    glVertex3f(-.54,.25,0.0);
	glVertex3f(-.54,.2,0.0);
	glVertex3f(-.56,.2,0.0);
	glEnd();

	glColor3f(0.0,0.0,205.0);
	glBegin(GL_POLYGON);
	glVertex3f(-.56,.15,0.0);
    glVertex3f(-.54,.15,0.0);
	glVertex3f(-.54,.1,0.0);
	glVertex3f(-.56,.1,0.0);
	glEnd();
//doors
	glColor3f(0.858824,0.439216,0.576471);
	glBegin(GL_POLYGON);
	glVertex3f(-.63,.05,0.0);
    glVertex3f(-.6,.07,0.0);
	glVertex3f(-.57,.05,0.0);
	glVertex3f(-.58,0.0,0.0);
	glVertex3f(-.62,0.0,0.0);
	glEnd();
	
	//stand city
	glColor3f(0.752941,0.658824,0.658824);
	glBegin(GL_POLYGON);
	glVertex3f(-1.0,0.0,0.0);
	glVertex3f(-0.5,0.0,0.0);
	glVertex3f(-0.5,-1.0,0.0);
	glVertex3f(-1.0,-1.0,0.0);
	glEnd();
//ledge
	glColor3f(.81,.71,.23);
	glBegin(GL_POLYGON);
	glVertex3f(-.55,-.15,0.0);
	glVertex3f(-0.25,-.15,0.0);
	glVertex3f(-0.25,-0.18,0.0);
	glVertex3f(-0.55,-.23,0.0);
	glEnd();
	//water
	glColor3f(0.0,0.0,255.0);
	glBegin(GL_POLYGON);
	glVertex3f(-.5,-.5,0.0);
	glVertex3f(1.0,-.5,0.0);
	glVertex3f(1.0,-1.0,0.0);
	glVertex3f(-.5,-1.0,0.0);
	glEnd();

}
void mountains()
{
	glColor3f(.0,205,.0);
	glBegin(GL_POLYGON);
	glVertex3f(.55,.03,0.0);
	glVertex3f(.60,.05,0.0);
	glVertex3f(.95,.05,0.0);
	glVertex3f(1.0,0.0,0.0);
	glVertex3f(1.0,-.3,0.0);
	glVertex3f(.95,-.33,0.0);
	glVertex3f(.8,-.3,0.0);
	glVertex3f(.83,-.27,0.0);
	glVertex3f(.7,-.28,0.0);
	glVertex3f(.6,-.3,0.0);
	glVertex3f(.48,-.25,0.0);
	glVertex3f(.40,-.18,0.0);
	glVertex3f(.46,-.13,0.0);
	glVertex3f(.45,-.08,0.0);
	glVertex3f(.6,-.03,0.0);
	glEnd();
	
//mount brown
	glColor3f(0.647059,0.164706,.164706);
	glBegin(GL_POLYGON);
	glVertex3f(1.0,-.3,0.0);
	glVertex3f(.95,-.33,0.0);
	glVertex3f(.8,-.3,0.0);
	glVertex3f(.83,-.27,0.0);
	glVertex3f(.7,-.28,0.0);
	glVertex3f(.6,-.3,0.0);
	glVertex3f(.48,-.25,0.0);
	glVertex3f(.40,-.18,0.0);
	glVertex3f(.43,-.5,0.0);
	glVertex3f(.48,-1.0,0.0);
	glVertex3f(1.0,-1.0,0.0);
	glEnd();
	//road
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-1.0,0.0,0.0);
	glVertex3f(-.5,0.0,0.0);
	glVertex3f(-.6,-.15,0.0);
	glVertex3f(-1.0,-.15,0.0);
	glEnd();
	//stripes
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex3f(-.95,-.07,0.0);
	glVertex3f(-.8,-.07,0.0);
	glVertex3f(-.8,-.09,0.0);
	glVertex3f(-.95,-.09,0.0);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex3f(-.7,-.07,0.0);
	glVertex3f(-.57,-.07,0.0);
	glVertex3f(-.59,-.09,0.0);
	glVertex3f(-.7,-.09,0.0);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(-.6,-.15);
	glVertex2f(-.6,-1.0);
	glEnd();
	
	

}
void a()
{ 
	
	if(c1==1 && ctr1==11)
	{
    glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-.01,.05);
    glVertex2f(.01,0.05);
    glVertex2f(.01,-0.05);
    glVertex2f(-.01,-0.05);
    glEnd();
	}
	
	if(c1==1 && ctr1==22)
	{
		glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-.01,.05);
    glVertex2f(.01,0.05);
    glVertex2f(.01,-0.05);
    glVertex2f(-.01,-0.05);
    glEnd();
	}
	
	if(c1==0 && c2==0)
	{
		glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-.01,.05);
    glVertex2f(.01,0.05);
    glVertex2f(.01,-0.05);
    glVertex2f(-.01,-0.05);
    glEnd();
	}
}

void b()
{ 
	if( c2==1 && ctr2==11)
	{
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);
    glVertex2f(-.01,.05);
    glVertex2f(.01,0.05);
    glVertex2f(.01,-0.05);
    glVertex2f(-.01,-0.05);
    glEnd();
	}
	
	if(c2==1 && ctr2==22)
	{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
    glVertex2f(-.01,.05);
    glVertex2f(.01,0.05);
    glVertex2f(.01,-0.05);
    glVertex2f(-.01,-0.05);
    glEnd();
	}
	
	if(c1==0 && c2==0)
	{
		glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
    glVertex2f(-.01,.05);
    glVertex2f(.01,0.05);
    glVertex2f(.01,-0.05);
    glVertex2f(-.01,-0.05);
    glEnd();
	}
	
}

void priests()
{
	if(pa==3)
	{
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);
    glVertex3f(.6,-.1,0.0); 
	glVertex3f(.62,-.1,0.0); 
	glVertex3f(.62,-.2,0.0); 
	glVertex3f(.6,-.2,0.0); 
	glEnd();
	}
	if(pa==3||pa==2)
	{
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);
    glVertex3f(.64,-.1,0.0); 
	glVertex3f(.66,-.1,0.0); 
	glVertex3f(.66,-.2,0.0); 
	glVertex3f(.64,-.2,0.0); 
	glEnd();
	}
	if(pa==3||pa==2||pa==1)
	{
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);
    glVertex3f(.68,-.1,0.0); 
	glVertex3f(.70,-.1,0.0); 
	glVertex3f(.70,-.2,0.0); 
	glVertex3f(.68,-.2,0.0); 
	glEnd();
	}
}
void monsters()
{
	//monsters
	if(ma==3)
	{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex3f(.75,-.1,0.0); 
	glVertex3f(.77,-.1,0.0); 
	glVertex3f(.77,-.2,0.0); 
	glVertex3f(.75,-.2,0.0); 
	glEnd();
	}
	if(ma==3||ma==2)
	{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
    glVertex3f(.79,-.1,0.0); 
	glVertex3f(.81,-.1,0.0); 
	glVertex3f(.81,-.2,0.0); 
	glVertex3f(.79,-.2,0.0); 
	glEnd();
	}
	if(ma==3||ma==2||ma==1)
	{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
    glVertex3f(.83,-.1,0.0); 
	glVertex3f(.85,-.1,0.0); 
	glVertex3f(.85,-.2,0.0); 
	glVertex3f(.83,-.2,0.0); 
	glEnd();
	}
}



void priests2()
{
	if(pb==1 || pb==2 || pb==3)
	{
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-.48,-.05,0.0); 
	glVertex3f(-.46,-.05,0.0); 
	glVertex3f(-.46,-.15,0.0); 
	glVertex3f(-.48,-.15,0.0); 
	glEnd();
	}

	if(pb==2 || pb==3)
	{
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-.44,-.05,0.0); 
	glVertex3f(-.42,-.05,0.0); 
	glVertex3f(-.42,-.15,0.0); 
	glVertex3f(-.44,-.15,0.0); 
	glEnd();
	}
	if(pb==3)
	{
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-.40,-.05,0.0); 
	glVertex3f(-.38,-.05,0.0); 
	glVertex3f(-.38,-.15,0.0); 
	glVertex3f(-.40,-.15,0.0); 
	glEnd();
	}
}
void monsters2()
{
	if(mb==1 || mb==2 || mb==3)
	{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-.36,-.05,0.0); 
	glVertex3f(-.34,-.05,0.0); 
	glVertex3f(-.34,-.15,0.0); 
	glVertex3f(-.36,-.15,0.0); 
	glEnd();
	}
	if(mb==2 || mb==3)
	{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-.32,-.05,0.0); 
	glVertex3f(-.30,-.05,0.0); 
	glVertex3f(-.30,-.15,0.0); 
	glVertex3f(-.32,-.15,0.0); 
	glEnd();
	}
	if(mb==3)
	{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-.28,-.05,0.0); 
	glVertex3f(-.26,-.05,0.0); 
	glVertex3f(-.26,-.15,0.0); 
	glVertex3f(-.28,-.15,0.0); 
	glEnd();
	}

}

void testc()
{
	if(mb>pb && ctr1==11 && ctr2==22 && lef==1)
	{
		gamelose();
	}
	if(mb>pb && ctr2==11 && ctr1==22 && lef==1)
	{
		gamelose();
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	buildings();
	mountains();
	//strings();
	glColor3f(1,0,0);
	outtext("press Z or X to move off the bridge",.1,.8,2);
	glColor3f(1,0,0);
	outtext("[Esc]=Exit",-.99,.93,2);
	glColor3f(1.0,0.0,1.0);
	outtext("[I]=Instructions",-.68,.93,2);
	glColor3f(1.0,0.0,0.0);
	outtext("press 'P' for priests in Yellow",.2,.7,1);
	glColor3f(1.0,0.0,0.0);
	outtext("press 'M' for monsters in Red",.2,.6,1);
	if(rt==1)
	{
		glColor3f(1.0,0.0,1.0);
	outtext("The Monsters attacked the priests!!",-.1,.5,1);
		glColor3f(1.0,0.0,1.0);
	outtext("press [ENTER] to play again",-.1,.4,1);
	}
	if(in==1)
	{
		glColor3f(1.0,0.0,0.0);
	outtext("Move the PRIESTS across the river,",-.9,.85,1);
	glColor3f(1.0,0.0,0.0);
	outtext("but the No. of priests should always ",-.9,.80,1);
	glColor3f(1.0,0.0,0.0);
	outtext("be greater than the number monsters",-.9,.75,1);
	glColor3f(1.0,0.0,0.0);
	outtext("on any side.",-.9,.70,1);
	}
		
	priests();
	monsters();
	priests2();
	monsters2();
	testc();
    circle(kx,ky,.1);
	glTranslatef(posX,posY,posZ);
    rect();
	glTranslatef(ac,bb,cc);
	a();
	glTranslatef(ab,bb,cc);
	b();
	
	gamewin();
	glFlush();
}
void main(int argc,char **argv)
{
	
	glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1024,768);
	glutCreateWindow("PROJECT");
	glutDisplayFunc(display);
	glClearColor(0.0,1.0,1.0,1.0);
	glutKeyboardFunc(keyboardown);
	glutSpecialFunc(keyboard);
	glutMainLoop();
}

