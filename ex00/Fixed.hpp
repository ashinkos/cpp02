#ifndef FIXED_CLASS
#define FIXED_CLASS

#include <iostream>

class Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &f);
	Fixed & operator =(const Fixed &f);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
private:
	int	_value;
	static const int _fraction = 8;


}; 

#endif 
