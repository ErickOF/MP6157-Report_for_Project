function x0 = compute_x0(alpha, beta, P0, T, u, W)
H = [T u];
Ht = transpose(H);

x0 = P0 * (1 / alpha * beta + Ht * W * T);
