#include "Fixed.hpp"
#include <iostream>
int main( void ) {
Fixed a;
Fixed d(5);

Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << "5 * 5 = " <<(d * d) << std::endl;
std::cout << "5 / 5 = " <<(d / d) << std::endl;
std::cout << d << std::endl;
std::cout << d << std::endl;
std::cout << ++d << std::endl;
std::cout << d << std::endl;
std::cout << d++ << std::endl;
std::cout << d << std::endl;
std::cout << b << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}
