# aero-surrogate-ml-cpp

Surrogate model for an aerodynamic coefficient Kmax(M, alpha) with training in Python
and fast evaluation in C++.

## Project idea

The project demonstrates a typical workflow used in digital twins and engineering applications:

- generate or load aerodynamic data Kmax = f(Mach, alpha)
- train a regression model in Python (polynomial regression via scikit-learn)
- export learned coefficients to C++
- use a lightweight C++ function kmax_model(M, alpha) inside a simulation or control system

This allows to replace heavy lookup tables with a compact analytical surrogate model.

## Repository structure

- `train_model.py` – trains polynomial regression model in Python and prints C++ coefficients  
- `cpp/`  
  - `surrogate_model.h` – C++ interface for kmax_model  
  - `surrogate_model.cpp` – implementation of the surrogate model with exported coefficients  
  - `main.cpp` – simple console demo (reads Mach, alpha and prints predicted Kmax)  
  - `CMakeLists.txt` – minimal build configuration for the C++ part

## Technologies

- Python 3  
- NumPy  
- scikit-learn (PolynomialFeatures, LinearRegression)  
- C++17  
- basic regression / surrogate modelling ideas

## How to run (Python part)

1. Install dependencies:

    pip3 install numpy scikit-learn

2. Run training script:

    python3 train_model.py

The script will:

- generate synthetic aerodynamic data (Mach, alpha → Kmax)  
- train a polynomial regression model  
- print training RMSE  
- print a C++ snippet with:

    static const int NUM_COEFFS = ...;
    static const double COEFFS[NUM_COEFFS] = { ... };
    static const double INTERCEPT = ...;

These values are used in `cpp/surrogate_model.cpp`.

## How to run (C++ part)

1. Build the demo (from the `cpp` directory):

    g++ -std=c++17 main.cpp surrogate_model.cpp -o aero_surrogate

2. Run the executable:

    ./aero_surrogate

3. Enter Mach number and angle of attack (deg).  
   The program will print the predicted value of Kmax.

## Example use case

This project can be used as:

- a simple example of data-driven surrogate modelling for aerodynamic coefficients  
- a prototype of a module for a digital twin of an aircraft  
- a small ML + C++ project for technical interviews (regression + integration into C++ code)

## Disclaimer

This project is intended for educational and research purposes only.
The author is not responsible for any possible misuse of the code.
