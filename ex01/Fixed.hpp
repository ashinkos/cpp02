#ifndef FIXED_CLASS
#define FIXED_CLASS

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const int);
	Fixed(const float);
	~Fixed();
	Fixed(const Fixed &f);
	Fixed & operator =(const Fixed &f);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

private:
	int	_value;
	static const int _fraction = 8;
}; 

std::ostream& operator << (std::ostream& os ,const Fixed& f);

#endif
