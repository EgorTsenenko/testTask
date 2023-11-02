#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define PI 3.14159265

//Main class
class Curve {
public:
    virtual ~Curve() {}

    virtual void Point(double t, double& x, double& y, double& z) const = 0; // Function for calculating a point by t
    virtual void Derivative(double t, double& dx, double& dy, double& dz) const = 0; // Function for calculating the first derivative by t
    virtual string curveType() const = 0; //Curve type detection function
};


class Circle : public Curve {
private:
    double rad;

public:
    Circle(double r) : rad(r) {}

    void Point(double t, double& x, double& y, double& z) const override //Overriding the method for calculating a point on a curve
    { 
        x = rad * cos(t); // The formula for finding the coordinates of a point on a circle: x = x0 + r * cos(t), where x0,y0 are the coordinates of the center of the circle (0 by default), r is the radius of the circle, t is the angle of rotation
        y = rad * sin(t); //                                                                 y = y0 + r * sin(t)
        z = 0.0;
    }

    void Derivative(double t, double& dx, double& dy, double& dz) const override //Overriding the method for calculating the derivative of a curve
    { 
        dx = rad * -(sin(t));
        dy = rad * cos(t);
        dz = 0.0;
    }

    double circleRadius() const // Method to get the radius of a circle
    { 
        return rad;
    }

    string curveType() const override
    {
        return "Circle";
    }

};


class Ellipse : public Curve {
private:
    double radX;
    double radY;

public:
    Ellipse(double rx, double ry) : radX(rx), radY(ry) {}

    void Point(double t, double& x, double& y, double& z) const override 
    {
        x = radX * cos(t); // Formula for finding the coordinates of an ellipse point: x = rX * cos(t), rX,rY - minor and major semi-axes, t - angle of rotation
        y = radY * sin(t); //                                                          y = rY * cos(t)
        z = 0.0;
    }

    void Derivative(double t, double& dx, double& dy, double& dz) const override 
    {
        dx = radX * -(sin(t));
        dy = radY * cos(t);
        dz = 0.0;
    }

    string curveType() const override
    {
        return "Ellipse";
    }
};


class Helix : public Curve {
private:
    double rad;
    double step;

public:
    Helix(double r, double s) : rad(r), step(s) {}

    void Point(double t, double& x, double& y, double& z) const override 
    {
        x = rad * cos(t);
        y = rad * sin(t);
        z = step * t / (2 * PI);                                 
    }

    void Derivative(double t, double& dx, double& dy, double& dz) const override 
    {
        dx = rad * -(sin(t));
        dy = rad * cos(t);
        dz = step / (2 * PI); 
    }

    string curveType() const override
    {
        return "Helix";
    }
};