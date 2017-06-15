#pragma once
#include "CImg.h"
using namespace cimg_library;
#include <bitset>

ref class Transform
{
public:
	// liniowe przeksztalcenie obrazu 16 bitowego do obrazu 8 bitowego
	// input:  img - obraz 16 bitowy
	// output: nowy obraz 8 bitowy
	template<class T>
	static CImg<T> LinearTo8Bit(const CImg<T>& img);
	
	// przeniesienie bez kompresji 8-bitowej czesci informacji z obrazu 16-bitowego
	// input:  img - obraz 16 bitowy, [from, to) - zakres przenoszenia bitow
	// output: nowy obraz 8 bitowy
	template<class T>
	static CImg<T> BitPerBit(const CImg<T>& img, const int from, const int to);

	// kompresja z uwzglednieniem krzywej gamma
	// input:  img - obraz 16 bitowy, param - wartosci parametru gamma
	// output: nowy obraz 8 bitowy
	template<class T>
	static CImg<T> GammaCurve(const CImg<T>& img, const double param);
};


template<class T>
inline CImg<T> Transform::LinearTo8Bit(const CImg<T>& img)
{
	CImg<T> output(img.width(), img.height(), 1, 3);
	const float mySize = 65535.0;
	cimg_forXY(img, x, y)
	{
		T r = img(x, y, 0);
		T g = img(x, y, 1);
		T b = img(x, y, 2);
		output(x, y, 0) = (r / mySize) * 255;
		output(x, y, 1) = (g / mySize) * 255;
		output(x, y, 2) = (b / mySize) * 255;
	}
	return output;
}

template<class T>
inline CImg<T> Transform::BitPerBit(const CImg<T>& img, const int from, const int to)
{
	using namespace std;
	const int left = from;
	const int right = left + (16 - to);
	CImg<T> output(img.width(), img.height(), 1, 3);
	cimg_forXY(img, x, y)
	{
		int r = static_cast<int>(img(x, y, 0));
		int g = static_cast<int>(img(x, y, 1));
		int b = static_cast<int>(img(x, y, 2));

		bitset<16> binaryR_16Bit = r;
		bitset<16> binaryG_16Bit = g;
		bitset<16> binaryB_16Bit = b;

		binaryR_16Bit <<= left; binaryR_16Bit >>= right;
		binaryG_16Bit <<= left; binaryG_16Bit >>= right;
		binaryB_16Bit <<= left; binaryB_16Bit >>= right;

		int decimalR_8Bit = binaryR_16Bit.to_ulong();
		int decimalG_8Bit = binaryG_16Bit.to_ulong();
		int decimalB_8Bit = binaryB_16Bit.to_ulong();

		output(x, y, 0) = static_cast<T>(decimalR_8Bit);
		output(x, y, 1) = static_cast<T>(decimalG_8Bit);
		output(x, y, 2) = static_cast<T>(decimalB_8Bit);
	}
	return output;
}

template<class T>
inline CImg<T> Transform::GammaCurve(const CImg<T>& img, const double param)
{
	const float mySize = 65535.0;
	CImg<T>  output = (img / mySize).pow(param) *= 255;
	return output;
}
