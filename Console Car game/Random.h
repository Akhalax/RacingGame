#ifndef RANDOM_H    
#define RANDOM_H  
class Random
{
public:
	Random();
	~Random();
	int getValue() const;
	void setValue(int value);

	void random();

private:
	int value;

};

#endif RANDOM_H
