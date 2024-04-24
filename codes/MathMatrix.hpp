#ifndef MATH_MATRIX_HPP
#define MATH_MATRIX_HPP

template <typename T, size_t M, size_t N>
void matadd(T A[M][N], T B[M][N], T C[M][N]);

template <typename T, size_t M, size_t N>
void add(T A[M][N], T b);

template <typename T, size_t N>
int inv(T A[N][N], T C[N][N]);

template <typename T, size_t M, size_t N, size_t P>
void matmult(T A[M][N], T B[N][P], T C[M][P]);

template <typename T, size_t M, size_t N>
void scale(T A[M][N], T a);

template <typename T, size_t M, size_t N>
void scale(T A[M][N], T a, T C[M][N]);

template <typename T, size_t M, size_t N>
void sub(T A[M][N], T B[M][N], T C[M][N]);

template <typename T, size_t M, size_t N>
void sub(T A[M][N], T b, T C[M][N]);

template <typename T, size_t M, size_t N>
void transpose(T A[M][N], T C[N][M]);

template <typename T, size_t N>
void vecmult(T A[N][1], T B[N][1], T C[N][1]);

template <typename T, size_t N>
void vecmult(T A[1][N], T B[1][N], T C[1][N]);
#endif // MATH_MATRIX_HPP
