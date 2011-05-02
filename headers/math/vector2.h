#ifndef INCLUDES_MATH_VECTOR2_H
#define INCLUDES_MATH_VECTOR2_H

#include "common.h"

// A 2D Vector helper class
template <class T>
class Vector2
{
	public:
		Vector2( void );
		Vector2( T X, T Y );
		
		// Arithmetic
		Vector2<T> operator+( Vector2<T> V );
		Vector2<T> operator-( Vector2<T> V );
	
		// Multiplication
		Vector2<T> operator*( T S );
		Vector2<T> operator*( Vector2<T> V );
		
		// Division
		Vector2<T> operator/( T S );
		Vector2<T> operator/( Vector2<T> V );
		
		// Magnitude
		T Length( void );
		T Length2( void );
		
		// Normalization
		void Normalize( void );
		Vector2<T> Normalized( void );
		
		// Other
		T DotProduct( Vector2<T> V );
	
		T X, Y;
};

template class Vector2<float>;
template class Vector2<double>;

#endif /* INCLUDES_MATH_VECTOR2_H */

