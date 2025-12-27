import numpy as np
from sklearn.preprocessing import PolynomialFeatures
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error


def generate_data():
    mach = np.linspace(0.2, 2.0, 20)
    alpha = np.linspace(-2.0, 12.0, 15)

    M, A = np.meshgrid(mach, alpha)

    K = (
        10.0
        + 2.0 * M
        - 0.30 * M**2
        + 0.10 * A
        - 0.02 * A**2
        + 0.01 * M * A
    )

    X = np.column_stack([M.ravel(), A.ravel()])
    y = K.ravel()
    return X, y


def train_surrogate(degree: int = 3):
    X, y = generate_data()

    poly = PolynomialFeatures(degree=degree, include_bias=False)
    X_poly = poly.fit_transform(X)

    model = LinearRegression()
    model.fit(X_poly, y)

    y_pred = model.predict(X_poly)
    rmse = mean_squared_error(y, y_pred, squared=False)

    print(f"Polynomial degree: {degree}")
    print(f"Training samples: {X.shape[0]}")
    print(f"Training RMSE: {rmse:.6f}")

    return poly, model


def export_cpp(poly: PolynomialFeatures, model: LinearRegression):
    coeffs = model.coef__
    intercept = model.intercept_

    print("\n=== C++ snippet ===\n")

    print(f"static const int NUM_COEFFS = {len(coeffs)};\n")

    print("static const double COEFFS[NUM_COEFFS] = {")
    for c in coeffs:
        print(f"    {c:.16e},")
    print("};\n")

    print(f"static const double INTERCEPT = {intercept:.16e};")


def main():
    poly, model = train_surrogate(degree=3)
    export_cpp(poly, model)


if __name__ == "__main__":
    main()
