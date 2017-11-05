
#ifndef FUSHU_H_
#define FUSHU_H_
class complex
{
private:
	int real;
	int imag;
public:
	complex(){real = 0.0; imag = 0.0;}
	complex(int r, int i){real = r; imag = i;}

	complex operator +(const complex & c)const
	{return complex(real + c.real, imag + c.imag);}
	complex operator -(const complex & c)const
	{return complex(real - c.real, imag - c.imag);}
	complex operator *(const complex & c)const 
	{return complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);}
	friend complex operator *(const int & x, const complex & c);
 	complex operator ~()const
	{return complex(real, -imag);}
	friend std::istream & operator>> (std::istream & is, complex & c);
	friend std::ostream & operator<< (std::ostream & os, const complex & c);
};
#endif
