#include "mydraw_class.hpp"

//-------------------
//color_t methods

color::color():r(0.0),g(0.0),b(0.0) { }

color::color(const float _r, const float _g, const float _b)
		 :r(_r),g(_g),b(_b) { }

void color::set(const float _r, const float _g, const float _b)
{ 
  r=_r; g=_g; b=_b;
}

float color::R(void) { return r; }
float color::G(void) { return g; }
float color::B(void) { return b; }


//---------------------
//point_class
point::point(int _x,int _y) {
	x=_x;
	y=_y;
}
void point::setx(int _x){
	x=_x;
}
void point::sety(int _y){
	y=_y;
}

int point::getx()	{
	return x;
}
int point::gety()	{
	return y;
}
color point::getc()	{
	return pixfill;
}
void point::pdraw(color _c)	{
	this.pixfill=_c;
}

point line::getp(){
return p;
}

point line::getq(){
return q;
}
void swap (int &x, int &y)
{
  int temp = x;
  x = y; y = temp;
}
void line::ldraw(color _c)
{
	point p1=this.getp();
	point q1=this.getq();
	int x0=p1.getx();
	int y0=p1.gety();
	int x1=q1.getx();
	int y1=q1.gety();
	bool steep = abs(y1 - y0) > abs(x1 - x0);
  if (steep)
    {
      swap(x0, y0);
      swap(x1, y1);
    }
  if (x0 > x1)
    {
      swap(x0, x1);
      swap(y0, y1);
    }
  int deltax = x1 - x0;
  int deltay = abs(y1 - y0);

  float error = 0.0;
  float deltaerr = (float)deltay / (float)deltax;

  int ystep;
  int y = y0;

  if (y0 < y1) ystep = 1; else ystep = -1;

  p1.pdraw(_c);

  glBegin(GL_POINTS);
  for (int x=x0; x < x1; x++)
    {
      if (steep)
	  p1.setx(y);
	  p1.sety(x); 
      else 
	  p1.sety(y);
	  p1.setx(x); 
      error = error + deltaerr;
      if (error >= 0.5) 
	{
	  y = y + ystep;
	  error = error - 1.0;
	}
    }
  glEnd();
}


	
