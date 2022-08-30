#include <iostream>

struct Vector2
{
	float x, y;
	
	Vector2(float x, float y)
		: x(x), y(y) {}
		
	Vector2 add(const Vector2& other) const // const is not going to modify this class, 
	//it just going to create a new Vector2
	{
		return Vector2(x + other.x, y + other.y);
	}
	
	Vector2 multiply(const Vector2& other) const // is not going to modify this class, 
	//it just going to create a new Vector2
	{
		return Vector2(x * other.x, y * other.y);
	}	
	
	// here is how we overload the + operator
	Vector2 operator+(const Vector2& other) const
	{
		// and we just return the already defined add function
		return add(other);
	}
	
	Vector2 operator*(const Vector2& other) const
	{
		return multiply(other);
	}
};

// another example: overloading of the << operator
std::ostream& operator<<(std::ostream& stream, const Vector2& vector)
{
	stream << vector.x << ", " << vector.y;
	return stream;
}

int main()
{
	Vector2 position(4.0f, 4.0f);
	Vector2 speed(0.5f, 1.5f);
	Vector2 powerup(1.1f, 1.1f); // 10% faster	
	
	// the result is position + (speed times powerup)
	Vector2 result1 = position.add(speed.multiply(powerup));
	// this is a little bit hard to read
	
	// it could be more readable like this
	Vector2 result2 = position + speed * powerup;
	
	std::cout << result2 << std::endl;
}
