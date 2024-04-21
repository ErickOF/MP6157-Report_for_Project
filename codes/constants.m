% Contants
tau = 20;
Kp = 0.5;
sigma = 0.08;
alpha = 1E3;
beta = [1E-2; 1E-2];
delta_t = 0.1;

% Variables
a = -1 / tau;
b = Kp / tau;
W = 1 / sigma^2;
