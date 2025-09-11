#ifndef FIXED_HPP
#define FIXED_HPP

#include <iosfwd>

class Fixed{
private:
	int	value;
	static const int FractionalBits = 8;
public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed &operator =(const Fixed &other);
	~Fixed();

	Fixed(const int value);
	Fixed(const float value);
	int		getRawBits()const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;

	bool	operator>(const Fixed &other) const;
	bool	operator<(const Fixed &other) const;
	bool	operator>=(const Fixed &other) const;
	bool	operator<=(const Fixed &other) const;
	bool	operator==(const Fixed &other) const;
	bool	operator!=(const Fixed &other) const;
	Fixed	operator+(const Fixed &other) const;
	Fixed	operator-(const Fixed &other) const;
	Fixed	operator*(const Fixed &other) const;
	Fixed	operator/(const Fixed &other) const;
	Fixed	operator++(int);
	Fixed	&operator++();
	Fixed	operator--(int);
	Fixed	&operator--();

	static Fixed& min(Fixed &one, Fixed &two);
	static Fixed& max(Fixed &one, Fixed &two);
	static const Fixed& min(const Fixed &one, const Fixed &two);
	static const Fixed& max(const Fixed &one, const Fixed &two);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
