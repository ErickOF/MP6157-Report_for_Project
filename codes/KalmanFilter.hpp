#ifndef KALMAN_FILTER_HPP
#define KALMAN_FILTER_HPP

#include "MathMatrix.hpp"

template <size_t S>
class KalmanFilter
{
protected:
    double h[1][S];
    double ht[S][1];
    double r;
    double phi[S][S];
    double phit[S][S];
    double gamma[S][S];
    double q[S][S];
    double I[S][S];
public:
    KalmanFilter();
    void predict(double xk[S][1], double pk[S][S], double y[S][1], double uk[S][1], double xk1[S][1], double pk1[S][S]);
    void set_params(double h[1][S], double r, double phi[S][S], double gamma[S][S], double q[S][S]);
};

#endif // KALMAN_FILTER_HPP
