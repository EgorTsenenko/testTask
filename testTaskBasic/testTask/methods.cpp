#include "curvesClass.cpp"
#include <ctime>
#include <cstdlib>

void addCurves(vector<Curve*> *curves, int numberOfCurves)
{
    srand(time(NULL));
    for (int i = 0; i < numberOfCurves; ++i) 
    {
        double randomrad = rand();
        double randomStep = rand();
        
        int variable = rand() % 100 + 1;
        if (variable < 30) {
            (*curves).push_back(new Circle(randomrad));
        }
        else if (variable >= 30 && variable < 70) {
            (*curves).push_back(new Ellipse(randomrad, randomrad * 0.5));
        }
        else {
            (*curves).push_back(new Helix(randomrad, randomStep));
        }
    }
}

void printCurves(vector<Curve*>* curves) 
{
    int sizeOfCurvesVector = 0;
    for (Curve* curve : (*curves)) 
    {

        double x, y, z;
        double dx, dy, dz;
        double t = PI / 4;
        curve->Point(t, x, y, z);
        curve->Derivative(t, dx, dy, dz);
        std::cout << sizeOfCurvesVector <<"." << curve->curveType() << "\nPoint: (" << x << ", " << y << ", " << z << ") \nDerivative: (" << dx << ", " << dy << ", " << dz << ")\n\n";
        sizeOfCurvesVector++;
    }
}

void sortCircles(vector<Circle*> *circles)
{
    std::sort(circles->begin(), circles->end(), [](Circle* first, Circle* second)
    {
        return first->circleRadius() < second->circleRadius();
    });
}

void printCircles(vector<Circle*>* circles)
{
    int sizeOfCircleVector = 0;
    for (Circle* circle : (*circles))
    {

        double x, y, z;
        double dx, dy, dz;
        double t = PI / 4;
        circle->Point(t, x, y, z);
        circle->Derivative(t, dx, dy, dz);
        std::cout << sizeOfCircleVector << "." << circle->curveType() << "\nPoint: (" << x << ", " << y << ", " << z << ") \nDerivative: (" << dx << ", " << dy << ", " << dz << ")\n" << "Radius: " << circle->circleRadius() << "\n\n";
        sizeOfCircleVector++;
    }
}

double sumOfCircleRadii(vector<Circle*>* circles)
{
    double radSum = 0.0;
    for (Circle* &circle : (*circles)) 
    {
        radSum += circle->circleRadius();
    }
    return radSum;
}



