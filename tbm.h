#ifndef _TBM_H
#define _TBM_H

#include <iostream>
#include <iomanip>

double sum(double *array);

class tbm930 {
public:
    // Program setup
    tbm930();
    void setUnits(char* unit);
    char* getUnits();
    void inputParams();
    
    // Final data output
    void outputDataUS();
    void outputDataSI();
    
    // End of program
    ~tbm930();
private:
    // Input parameters
    double weights[5];
    double fuel[3];
    
    // Output parameters
    double moments[5];
    double cg[5];
    
    // Fuel density for fuel input options
    double fuelDensityUS = 6.7;
    double fuelDensitySI = 0.8;
    
    // Units to be used
    char* units;
    
    // Constants
    double tbmCGEmpty = 22.9;
    double tbmEmptyWeightUS = 4583.0;
    double tbmEmptyWeightSI = 2126;
    double tbmEmptyMomentUS = 854882.51;
    double tbmEmptyMomentSI = 10073;
    double armsUS[6] = {128.0, 178.5, 224.8, 267.1, 303.0, 189.8};
    double armsSI[6] = {3.250, 4.534, 5.710, 6.785, 7.695, 4.820};
    
    // Functions for calculations
    double calcMomentsUS();
    double calcMomentsSI();
    double calcCGUS(double arm);
    double calcCGSI(double arm);
    double calcArm(double M, double W);
    bool cgLimitsUS(double weight, double cg);
    bool cgLimitsSI(double weight, double cg);
};

#endif
