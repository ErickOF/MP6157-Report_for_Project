function P0 = compute_p0(alpha, T, u, W)
I = eye(2);
H = [T u];
Ht = transpose(H);

P0 = inv([1/alpha^2 * I + Ht * W * H]);
