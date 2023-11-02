#include "methods.h"

int main() {
    std::vector<Curve*> curves; //Vector of curves
    int numberOfCurves; //Number of curves to generate
    
    std::cout << "Enter the number of curves to generate: ";
    std::cin >> numberOfCurves; 
    std::cout << "\n";
    addCurves(&curves, numberOfCurves);


    //Printing coordinates and derived curves
    std::cout << "==========================Vector of random curves==========================\n\n";
    printCurves(&curves); 

    std::cout << "==========================Vector of circles==========================\n\n";
    // Creating a second container to store circles
    std::vector<Circle*> circles;
    for (Curve* &curve : curves)
    {
        if (curve->curveType() == "Circle")
        {
            circles.push_back(static_cast<Circle*>(curve));
        }
    }
    printCircles(&circles);

    std::cout << "==========================Vector of SORTED circles==========================\n\n";
    //Sort the vector of circles by increasing radii
    sortCircles(&circles); 
    printCircles(&circles);


    std::cout << "Sum of circle radii = " << sumOfCircleRadii(&circles) << endl;

    

    return 0;
}