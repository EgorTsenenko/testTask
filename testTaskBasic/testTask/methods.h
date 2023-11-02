#ifndef methods_h
#define methods_h
#include "curvesClass.cpp"

/// <summary>
/// The function adds n random curves to the vector
/// </summary>
/// <param name="curves"></param>
/// <param name="numberOfCurves"></param>
void addCurves(vector<Curve*>* curves, int numberOfCurves);

/// <summary>
/// The function prints the coordinates of curve points and their derivatives
/// </summary>
/// <param name="curves"></param>
void printCurves(vector<Curve*>* curves);

/// <summary>
/// The function sorts a vector of circles by increasing radii
/// </summary>
/// <param name="circles"></param>
void sortCircles(vector<Circle*>* circles);

/// <summary>
/// The function prints the coordinates of circle points and their derivatives
/// </summary>
/// <param name="curves"></param>
void printCircles(vector<Circle*>* circles);

/// <summary>
/// Function for calculating the sum of radii of a vector of circles
/// </summary>
/// <param name="circles"></param>
double sumOfCircleRadii(vector<Circle*>* circles);

#endif //methods
