#include "surrogate_model.h"
#include <cmath>

static const int NUM_COEFFS = 9;

static const double COEFFS[NUM_COEFFS] = {
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0
};

static const double INTERCEPT = 0.0;

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
