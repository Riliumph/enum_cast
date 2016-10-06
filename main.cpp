#include <type_traits>
template<typename E>
constexpr auto e_cast( E e ) -> typename std::underlying_type<E>::type
{
	return static_cast<typename std::underlying_type<E>::type>( e );
}


#include<iostream>

enum struct COLOR
{
	RED, BLUE, GREEN, QTY
};

int main( void )
{
	COLOR colors[e_cast( COLOR::QTY )] = { COLOR::RED, COLOR::BLUE, COLOR::GREEN };

	for( auto color : colors ){
		switch( color ){
			case COLOR::RED: std::cout << "RED" << std::endl; break;
			case COLOR::BLUE: std::cout << "BLUE" << std::endl; break;
			case COLOR::GREEN: std::cout << "GREEN" << std::endl; break;
			default: std::cout << "UNDEFINED" << std::endl; break;
		}
	}

	return 0;
}