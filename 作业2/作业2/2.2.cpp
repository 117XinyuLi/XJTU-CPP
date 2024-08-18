#include <iostream>
using namespace std;
class Rectangle
{
public:
	
	Rectangle(int x1, int y1, int x2, int y2)
	{
		x1_ = x1;
		y1_ = y1;
		x2_ = x2;
		y2_ = y2;
	}
	int getPerimeter()
	{
		return 2 * (x2_ - x1_ + y2_ - y1_);
	}
	int getArea()
	{
		return (x2_ - x1_) * (y2_ - y1_);
	}
private:
	int x1_, y1_, x2_, y2_;
};

int main()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	Rectangle rect(x1, y1, x2, y2);
	cout << rect.getPerimeter() << endl;
	cout << rect.getArea() << endl;
	return 0;
}