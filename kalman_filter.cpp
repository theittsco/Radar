#include "algorithm"
#include <iostream>
#include <vector>
#include <Eigen/Dense>

using namespace Eigen;

class KalmanFilter {
    public:
        Vector4d X; // State vector
        Matrix4d P; // Measurement cov matrix
        Matrix4d A; // State transition matrix
        Matrix<double,2,4> H; // Observation matrix
        Matrix2d R; // Measurement noise cov 
        Matrix4d Q; // Process noise cov
        Matrix4d I; // Identity matrix

KalmanFilter(double dt, double process_noise, double measurement_noise) {
    X << 0,0,0,0;

    P = Matrix4d::Identity() * 1000;

    A << 1,0,dt,0,
         0,1,0,dt,
         0,0,1,0,
         0,0,0,1;

    H << 1,0,0,0,
         0,1,0,0;

    R = Matrix2d::Identity() * measurement_noise;

    Q = Matrix4d::Identity() * process_noise;

    I = Matrix4d::Identity();
}

void predict() {
    X = A * X;
    P = A * P * A.transpose() + Q;
}

void update(Vector2d Z) {
    Vector2d Y = Z - H*X;
    Matrix2d S = H*P*H.transpose() + R;
    Matrix<double, 4, 2> K = P*H.transpose() * S.inverse();

    X = X + K*Y;
    P = (I-K*H)*P;
}

};

int main(int argc, char const *argv[])
{
    double dt = 1.0;
    double process_noise = 0.1;
    double measurement_noise = 2.0;

    KalmanFilter kf(dt, process_noise, measurement_noise);

    std::vector<Vector2d> measurements = {
        {100,200}, {105,208}, {110,217}, {120,230}, {130,245}
    };

    std::cout << "Time Step | Estimated Position (x, y) | Estimated Velocity (vx, vy)\n";
    std::cout << "-------------------------------------------------------------------\n";

    for (size_t i = 0; i < measurements.size(); i++) {
        kf.predict();
        kf.update(measurements[i]);

        std::cout << i+1 << "        | (" 
             << kf.X(0) << ", " << kf.X(1) << ") | (" 
             << kf.X(2) << ", " << kf.X(3) << ")\n";
    }

    return 0;
}
