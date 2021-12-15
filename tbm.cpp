#include "tbm.h"

using std::cout;

tbm930::tbm930() {
    units = "US";
}

void tbm930::setUnits(char* unit) {
    units = unit;
}

char* tbm930::getUnits() {
    return units;
}

double tbm930::calcMoments(double W, double arm) {
    double moment = W * arm;
    return moment;
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

void tbm930::outputData() {
    std::cout << std::fixed << std::endl;
    std::cout << std::setprecision(2) << std::endl;
    std::cout << "Empty Weight (lbs.):\t\t\t" << weights[0] << std::endl;
    std::cout << "Empty CG (%% MAC):\t\t\t\t" %(cgMAC_empty))
    print('')
    print("ZFW (lbs.):\t\t\t\t%.2f" %(ZFW))
    print("CG of ZFW (%% MAC):\t\t\t\t%.2f" %(cg_ZFW))
    print('')
    print("Ramp Gross Weight (lbs.):\t\t%.2f" %(rampWeight))
    print("CG of Ramp Gross Weight (%% MAC):\t\t%.2f" %(cg_Ramp))
    print('')
    print("Takeoff Weight (lbs.):\t\t\t%.2f" %(takeoffWeight))
    print("CG of Takeoff Weight (%% MAC):\t\t\t%.2f" %(cg_Takeoff))
    print('')
    print("Landing Weight (lbs.):\t\t\t%.2f" %(landingWeight))
    print("CG of Landing Weight (%% MAC):\t\t\t%.2f" %(cg_Landing))
    print('')
    print('')
    print("Total Fuel Load (lbs.):\t\t\t%.2f" %(fuel))
    print("Taxi Fuel (lbs.):\t\t\t%.2f" %(taxiFuel))
    print("Trip Fuel (lbs.):\t\t\t%.2f" %(tripFuel))
    print('')
    print('')
}

tbm930::~tbm930() {
    
}
