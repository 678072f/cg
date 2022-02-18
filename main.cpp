#include "tbm.h"
#include <iostream>
#include <stdexcept>


int main() {
    char* UNITS;
    
    std::cout << "Which units do you want to use? (Options: US, SI): ";
    std::cin >> UNITS;
    
    if(UNITS != "US" || UNITS != "SI")
        std::invalid_argument("Error! Invalid input. Please try again.");
    
    tbm930 TBM;
    TBM.setUnits(UNITS);
    std::cout << TBM.getUnits() << std::endl;
    TBM.inputParams();
    
    if(TBM.getUnits() == "US")
        TBM.outputDataUS();
    else if(TBM.getUnits() == "SI")
        TBM.outputDataSI();
    else
        std::cout << "ERROR: Units not recognized. Please try again.";
    
    
    return 0;
}
