
#include <iostream>
using namespace std;


class Shape {
public:
    virtual double getArea() const =0;

    friend std::ostream &operator<<(std::ostream &os, const Shape &shape) {
        os<<shape.getArea();
        return os;
    }
    bool operator<(const Shape &rhs) const;

    bool operator>(const Shape &rhs) const;

    bool operator<=(const Shape &rhs) const;

    bool operator>=(const Shape &rhs) const;
    bool operator==(const Shape &rhs) const;

    };

class Rectangle : public Shape{
    double base,altezza;
public:
    Rectangle(double b, double h):  altezza(h),base(b){};
    double getArea() const { return base*altezza;}

};

class Circle : public Shape{
    double raggio;
public:
    explicit Circle(double r): raggio(r){}
    double getArea() const { return raggio*raggio*3.14;}
};

class Triangle : public Shape{
    double base,altezza;
public:
    Triangle(double a, double b):  altezza(a),base(b){};
    double getArea() const {return (base*altezza)/2;}
};

bool Shape::operator<(const Shape &rhs) const {
    return this->getArea()<rhs.getArea();
}
bool Shape::operator>(const Shape &rhs) const {
    return this->getArea()>rhs.getArea();
}
bool Shape::operator<=(const Shape &rhs) const {
    return this->getArea()<=rhs.getArea();
}
bool Shape::operator>=(const Shape &rhs) const {
    return this->getArea() >= rhs.getArea();
}

bool Shape::operator==(const Shape &rhs) const {
    return this->getArea() == rhs.getArea();
}


int main()
{


}
