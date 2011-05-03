#include "math/vector2.h"

float FastInverseSqrt( float Number );

template <class T>
Vector2<T>::Vector2( void )
	: X(0), Y(0)
{
}

template <class T>
Vector2<T>::Vector2( T X, T Y )
	: X(X), Y(Y)
{
}

// Arithmetic
template <class T>
Vector2<T> Vector2<T>::operator+( Vector2<T> V )
{
	Vector2<T> Result = Vector2<T>( X + V.X, Y + V.Y );
	return Result;
}

template <class T>
Vector2<T> Vector2<T>::operator-( Vector2<T> V )
{
	Vector2<T> Result = Vector2<T>( X - V.X, Y - V.Y );
	return Result;
}

template <class T>
void Vector2<T>::operator+=( Vector2<T> V )
{
	//Vector2<T> Result = Vector2<T>( X + V.X, Y + V.Y );
	*this = *this + V;
}

// Multiplication
template <class T>
Vector2<T> Vector2<T>::operator*( T S )
{
	Vector2<T> Result = Vector2<T>( S * X, S * Y );
	return Result;
}

template <class T>
Vector2<T> Vector2<T>::operator*(  Vector2<T> V )
{
	Vector2<T> Result = Vector2<T>( V.X * X, V.Y * Y );
	return Result;
}

// Division
template <class T>
Vector2<T> Vector2<T>::operator/( T S )
{
	Vector2<T> Result = Vector2<T>( X / S, Y / S );
	return Result;
}

template <class T>
Vector2<T> Vector2<T>::operator/(  Vector2<T> V )
{
	Vector2<T> Result = Vector2<T>( X / V.X, Y / V.Y );
	return Result;
}

// Magnitude
template <class T>
T Vector2<T>::Length( void )
{
	return 1 / (T)FastInverseSqrt((float)X*X + Y*Y);
}

template <class T>
T Vector2<T>::Length2( void )
{
	return X*X + Y*Y;
}

// Normalization
template <class T>
void Vector2<T>::Normalize( void )
{
	T Mag = (T)FastInverseSqrt((float)X*X + Y*Y);
	X *= Mag;
	Y *= Mag;
}

template <class T>
Vector2<T> Vector2<T>::Normalized( void )
{
	Vector2<T> Copy = Vector2<T>(X, Y);
	Copy.Normalize();
	return Copy;
}

// Other
template <class T>
T Vector2<T>::DotProduct( Vector2<T> V )
{
	return X * V.X + Y * V.Y;
}

// Aprox. 4x as fast
// http://betterexplained.com/articles/understanding-quakes-fast-inverse-square-root/
// http://en.wikipedia.org/wiki/Fast_inverse_square_root
float FastInverseSqrt( float Number )
{
        long i;
        float x2, y;

        x2 = Number * 0.5F;
        y  = Number;
        i  = * ( long * ) &y;
        i  = 0x5f375a86 - ( i >> 1 );
        y  = * ( float* ) &i;
        y  = y * ( 1.5F - ( x2 * y * y ) );
        
        return y;
}


template class Vector2<float>;
template class Vector2<double>;