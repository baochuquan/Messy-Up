
#ifndef classic_H
#define classic_H

//base class
class Cd
{
private:
	char * performers;
	char * label;
	int selections;
	double playtime;
public:
	Cd(const char * s1, const char * s2, const int n, const double x);
	Cd(const Cd & d);
	Cd();
	virtual ~Cd();
	virtual void Report()const;
	virtual Cd & operator =(const Cd & d);
};

class Classic : public Cd
{
private:
	char * Main;
public:
	Classic(const char * s1, const char * s2, const char * s3, const int n, const double x);
	Classic(const Cd & cd, char *s3);
	Classic();
	virtual ~Classic();
	virtual void Report()const;
	virtual Classic & operator =(const Classic & d);
};
#endif
