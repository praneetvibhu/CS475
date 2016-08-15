#ifndef _MYDRAW_CLASS_HPP_
#define _MYDRAW_CLASS_HPP_

//Define all classes like the color class, adding appropriate methods and data members. 
//Implementation of the methods go into the corresponding cpp file

//------------------------
//color_t class

class color {
private:
  float r,g,b;
public:
  color();
  color(const float _r, const float _g, const float _b);

  void set(const float _r, const float _g, const float _b);
  float R(void);
  float G(void);
  float B(void);
};

//------------------------

//point_t class
class point {
private: int x,y;
	color pixfill;
public:
	int getx();
	int gety();
	void setx(int _x);
	void sety(int _y);
	color getc();
	point(x,y);
	void pdraw(color c);
		
};

class line {
private: point p,q;
	color linefill;
public: 
	line(point _p,point _q);
	point getp();
	point getq();
	color getc();
	void ldraw(color c);
};
//------------------------

#endif
