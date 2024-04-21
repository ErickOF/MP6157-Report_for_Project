function [Pk1, xk1] = compute_pk1(Pk, Tk, Tk1, xk, uk, W)
H = [Tk uk];
Ht = transpose(H);
I = eye(2);

K = Pk * Ht * inv(H * Pk * Ht + inv(W));
xk1 = xk + K * (Tk1 - H * xk);
Pk1 = (I - K * H) * Pk;
