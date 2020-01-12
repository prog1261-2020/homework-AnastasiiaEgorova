#pragma once
#include <string>

class Vector2D
{
public:
	Vector2D(int x, int y);

	std::string toString() const;
	double length() const;

	bool operator==(const Vector2D& rhs) const;
	bool operator!=(const Vector2D& rhs) const;

	bool operator<(const Vector2D& rhs) const;
	bool operator<=(const Vector2D& rhs) const;
	bool operator>(const Vector2D& rhs) const;
	bool operator>=(const Vector2D& rhs) const;

private:
	int _x;
	int _y;
};

