#include "tbm.h"

using std::cout;

double sum(double *array) {
    double SUM { 0 };
    for(int i = 0; i <= sizeof(array); i++) {
        SUM += array[i];
    }
    
    return SUM;
}

tbm930::tbm930() {
    units = "US";
}

void tbm930::setUnits(char* unit) {
    units = unit;
}

char* tbm930::getUnits() {
    return units;
}

void tbm930::inputParams() {
    cout << "How much weight is loaded in FWD Baggage? ";
    std::cin >> weights[0];
    
    cout << "How much weight is in the front seats? ";
    std::cin >> weights[1];
    
    cout << "How much weight is in the Intermediate Seats? ";
    std::cin >> weights[2];
    
    cout << "How much weight is in the Rear/Bench seats? ";
    std::cin >> weights[3];
    
    cout << "How much weight is in AFT baggage? ";
    std::cin >> weights[4];
    
    cout << "How much fuel is there? ";
    std::cin >> fuel[0];
    
    cout << "How much taxi fuel is onboard? ";
    std::cin >> fuel[1];
    
    cout << "How much trip fuel is onboard? ";
    std::cin >> fuel[2];
}

double tbm930::calcMomentsUS() {
    double moments[sizeof(armsUS)];
    for(int i = 0; i <= sizeof(armsUS); i++) {
        if(i <= sizeof(weights))
            moments[i] = weights[i] * armsUS[i];
        else
            moments[i] = fuel[0] * armsUS[i];
    }
    
    return *moments;
}

double tbm930::calcMomentsSI() {
    double moments[sizeof(armsSI)];
    for(int i = 0; i <= sizeof(armsSI); i++) {
        if(i <= sizeof(weights))
            moments[i] = weights[i] * armsSI[i];
        else
            moments[i] = fuel[0] * armsSI[i];
    }
    
    return *moments;
}

double tbm930::calcCGUS(double arm) {
    double cg = ((arm - 172.93) / 59.45) * 100;
    return cg;
}

double tbm930::calcCGSI(double arm) {
    double cg = ((arm - 4.392) / 1.51) * 100;
    return cg;
}

double tbm930::calcArm(double M, double W) {
    double arm = M / W;
    return arm;
}

bool tbm930::cgLimitsUS(double weight, double cg) {
    // TODO: Add limit evaluations.
}

bool tbm930::cgLimitsSI(double weight, double cg) {
    // TODO: Add limit evaluations.
}

void tbm930::outputDataUS() {
    double emptyWeight = tbmEmptyWeightUS;
    double emptyCG = tbmCGEmpty;
    double zfw = sum(weights);
    double rampWeight = zfw + fuel[0];
    double toWeight = rampWeight - fuel[1];
    double landWeight = toWeight - fuel[2];
    double totalFuel = fuel[0];
    double taxiFuel = fuel[1];
    double tripFuel = fuel[2];
    double moments = calcMomentsUS();
    
    double armZFW = moments[5] / zfw;
    double cgZFW = calcCGUS(armZFW);
}

void tbm930::outputDataSI() {
    double emptyWeight = tbmEmptyWeightSI;
    double emptyCG = tbmCGEmpty;
    double zfw = sum(weights);
    double rampWeight = zfw + fuel[0];
    double toWeight = rampWeight - fuel[1];
    double landWeight = toWeight - fuel[2];
    double totalFuel = fuel[0];
    double taxiFuel = fuel[1];
    double tripFuel = fuel[2];
}
//    std::cout << std::fixed << std::endl;
//    std::cout << std::setprecision(2) << std::endl;
//    std::cout << "Empty Weight (lbs.):\t\t\t" << weights[0] << std::endl;
//    std::cout << "Empty CG (%% MAC):\t\t\t\t" %(cgMAC_empty))
//    print('')
//    print("ZFW (lbs.):\t\t\t\t%.2f" %(ZFW))
//    print("CG of ZFW (%% MAC):\t\t\t\t%.2f" %(cg_ZFW))
//    print('')
//    print("Ramp Gross Weight (lbs.):\t\t%.2f" %(rampWeight))
//    print("CG of Ramp Gross Weight (%% MAC):\t\t%.2f" %(cg_Ramp))
//    print('')
//    print("Takeoff Weight (lbs.):\t\t\t%.2f" %(takeoffWeight))
//    print("CG of Takeoff Weight (%% MAC):\t\t\t%.2f" %(cg_Takeoff))
//    print('')
//    print("Landing Weight (lbs.):\t\t\t%.2f" %(landingWeight))
//    print("CG of Landing Weight (%% MAC):\t\t\t%.2f" %(cg_Landing))
//    print('')
//    print('')
//    print("Total Fuel Load (lbs.):\t\t\t%.2f" %(fuel))
//    print("Taxi Fuel (lbs.):\t\t\t%.2f" %(taxiFuel))
//    print("Trip Fuel (lbs.):\t\t\t%.2f" %(tripFuel))
//    print('')
//    print('')

tbm930::~tbm930() {
    
}
