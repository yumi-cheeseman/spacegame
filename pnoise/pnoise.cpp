#include "pnoise/pnoise.h"

// Reference implementation by MMavipc

inline double Noise( double X, double Y, int Seed = 57 )
{
	int n = (int)X + (int)Y * Seed;
	n = ( n << 13 ) ^ n;
	int nn = (n * (n * n * 60493 + 19990303) + 1376312589);
	nn = nn & 0x7fffffff;
	return 1.0 - ( (double)nn / 1073741824.0 );
}

inline double Interpolate( double A, double B, double X )
{
	double ft = X * 3.1415927;
	double f = (1.0 - cos(ft)) * 0.5;
	return A * (1.0 - f) + B * f;
}

double CalculatePerlinNoise( double X, double Y, int Seed = 57 )
{
	const double floorx = floor(X);
	const double floory = floor(Y);
	double s, t, u, v;
	s = Noise(floorx, floory, Seed); 
	t = Noise(floorx + 1, floory, Seed);
	u = Noise(floorx, floory + 1, Seed);
	v = Noise(floorx + 1, floory + 1, Seed);
	double int1 = Interpolate(s, t, X - floorx);
	double int2 = Interpolate(u, v, Y - floorx);
	return Interpolate(int1, int2, Y - floory);
}

double LinearInterpolate(double A, double B, double X)
{
	return A * (1 - X) + (B * X);
}

void PerlinNoise::Generate( sf::Image &Image, const int Octaves, const double Zoom, const double Persistence, const int Seed )
{
	for( int y = 0; y<int(Image.GetHeight()); ++y )
	{
		for( int x = 0; x < int(Image.GetWidth()); ++x )
		{
			double noise = 0;
			for(double i = 0; i<Octaves; i++)
			{
				double freq = pow(2, i);
				double amp = pow(Persistence, i);
				noise += CalculatePerlinNoise(double(x) * freq / Zoom, double(y) / Zoom * freq, Seed);
			}
			if(noise > 1.0)
			{
				noise = 1.0;
			}
			else if(noise < -1.0)
			{
				noise = -1.0;
			}
			unsigned char max255 = (noise + 1.0)/2.0 * 255;
			max255 = 255 - max255;
			noise = (noise + 1.0) / 2.0;
			noise = 1.0 - noise;

			sf::Color clr(max255, max255, max255);

			if(max255 <= 50)
			{
				clr.r = 0;
				clr.g = 0;
				//max255 += 205;
				clr.b = 255;

				unsigned char a = (double(50.0 - max255) / 50.0) * 255;

				clr.r = LinearInterpolate(107, clr.r, double(a) / 255.0);
				clr.g = LinearInterpolate(88, clr.g, double(a) / 255.0);
				clr.b = LinearInterpolate(10, clr.b, double(a) / 255.0);
			}
			else if(max255 <= 100)
			{
				clr.r = (double(max255) / 100.0) * 210;
				clr.g = (double(max255) / 100.0) * 172;
				clr.b = (double(max255) / 100.0) * 19;
			}
			else
			{
				clr.r = 0;
				clr.g = (double(max255) / 255) * 255;
				clr.b = 0;
			}

			Image.SetPixel(x, y, clr);
		}
	}
}
