/*
A weather balloon is drifting in the atmosphere. You want to track its x-position along a straight line using radar, but the radar measurements are noisy. The balloon moves with a nearly constant velocity.

Write a C++ program that:

1. Simulates the true motion of the balloon (starting at x=0, moving at 1m/s).

2. Simulates radar measurements by adding Gaussian noise (mean 0, std. deviation 2) to the true position.

3. Implements a 1D Kalman filter to estimate the balloon’s true position.

4. Prints the results for 20 time steps:
-True position
-Noisy measurement
-Kalman filter estimate

*/
#include <iostream>
#include <vector>
#include <Eigen/Dense>
#include <random>

using namespace Eigen;

class kalman_1D {
    public:
        Vector2d X; // State vector;
        Matrix2d P; // Measurement cov matrix
        Matrix2d A; // State transition matrix
        RowVector2d H; // Observation matrix
        double R; // Measurement noise var
        Matrix2d Q; // Process noise cov
        Matrix2d I; // Identity matrix
        Matrix2d y; // Intermediate estimate

kalman_1D(double dt, double process_noise, double measurement_noise) {
    X << 0,1;
    P = Matrix2d::Identity() * 1000;

    A << 1,dt,
         0,1;

    H << 1,0;

    R = measurement_noise;
    Q = Matrix2d::Identity() * process_noise;
    I = Matrix2d::Identity();
}

void predict() {
    X = A * X;
    P = A*P*A.transpose() + Q;
}

void update(double Z) {
    double Y = Z - H*X;
    double S = H * P * H.transpose() + R;
    Matrix<double,2,1> K = P*H.transpose() * (1.0/S);

    X = X + K*Y;
    P = (I-K*H)*P;
}

};

int main(int argc, char const *argv[])
{
    int steps = 20;
    double dt = 1.0;

    double process_noise = 0.01;
    double measurement_noise = 4.0;

    kalman_1D kf(dt, process_noise, measurement_noise);

    std::default_random_engine gen;
    std::normal_distribution<double> noise(0,2.0);

    double true_x = 0.0;
    double true_v = 1.0;


    std::cout << "Time step | True Position | Noisy Measurement | Estimated Position (x)\n";
    std::cout << "----------------------------------------------------------------------\n";

    for (size_t i = 0; i < steps; i++)
    {
        true_x += true_v*dt;
        double z = true_x + noise(gen);

        kf.predict();
        kf.update(z);

        std::cout << i << true_x << " | " << z << " | " << kf.X(0) << std::endl;
    }
    

    return 0;
}
