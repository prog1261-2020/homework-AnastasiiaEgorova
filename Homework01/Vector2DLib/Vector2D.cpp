#include "Vector2D.h"
#include <sstream>
#include <cmath>

Vector2D::Vector2D(int x, int y) : _x(x), _y(y)
{}

std::string Vector2D::toString() const
{
	std::stringstream ss;
	ss << "(" << _x << ", " << _y << ")";
	return ss.str();
}

double Vector2D::length() const {
	return sqrt(_x^2 + _y^2);
}

bool AlmostEqualRelative(double A, double B, double maxRelDiff = std::numeric_limits<double>::epsilon()) {
	double diff = fabs(A - B);
	A = fabs(A);
	B = fabs(B);

	double largest = (B > A) ? B : A;

	if (diff <= largest * maxRelDiff)
		return true;
	else
		return false;
}

bool Vector2D::operator==(const Vector2D& rhs) const {
	double epsilon = 1E-5;
	return (AlmostEqualRelative(length(), rhs.length()));
}

bool Vector2D::operator!=(const Vector2D& rhs) const {
	return !((*this) == rhs);
}

bool Vector2D::operator<(const Vector2D& rhs) const {
	return (length() < rhs.length());
}

bool Vector2D::operator<=(const Vector2D& rhs) const {
	return (*this < rhs) || (*this == rhs);
}

bool Vector2D::operator>(const Vector2D& rhs) const {
	return !(*this < rhs) && !(*this == rhs);
}

bool Vector2D::operator>=(const Vector2D& rhs) const {
	return !(*this < rhs) || (*this == rhs);
}

