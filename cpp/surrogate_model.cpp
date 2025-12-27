#include "surrogate_model.h"
#include <cmath>

static const int NUM_COEFFS = 9;

static const double COEFFS[NUM_COEFFS] = {
    1.9999999999999778e+00,
    1.0000000000000002e-01,
    -3.0000000000001498e-01,
    1.0000000000001501e-02,
    -2.0000000000000236e-02,
    6.5768450064057837e-15,
    -4.9744241963811559e-16,
    6.6146802458660912e-16,
    -3.2119830520479829e-17
};

static const double INTERCEPT = 1.0000000000000025e+01;

double kmax_model(double mach, double alpha)
{
    double features[NUM_COEFFS];

    features[0] = mach;
    features[1] = alpha;
    features[2] = mach * mach;
    features[3] = mach * alpha;
    features[4] = alpha * alpha;
    features[5] = mach * mach * mach;
    features[6] = mach * mach * alpha;
    features[7] = mach * alpha * alpha;
    features[8] = alpha * alpha * alpha;

    double y = INTERCEPT;

    for (int i = 0; i < NUM_COEFFS; ++i)
        y += COEFFS[i] * features[i];

    return y;
}
