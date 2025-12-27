#include <iostream>
#include "surrogate_model.h"

int main()
{
    double mach;
    double alpha;

    std::cout << "Enter Mach number: ";
    std::cin >> mach;

    std::cout << "Enter angle of attack (deg): ";
    std::cin >> alpha;

    double kmax = kmax_model(mach, alpha);

    std::cout << "Predicted Kmax = " << kmax << std::endl;

    return 0;
}
