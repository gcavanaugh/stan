data {
  int<lower=0> N;
  vector[N] kid_score;
  vector[N] mom_pred;        // may be mom_iq or mom_hs
}
parameters {
  vector[2] beta;
  real<lower=0> sigma;
}
model {
  kid_score ~ normal(beta[1] + beta[2] * mom_pred, sigma);
}
generated quantities {
  real b1_twiddle;
  real b2_twiddle;
  b1_twiddle <- normal_rng(beta[1],sigma);
  b2_twiddle <- normal_rng(beta[2],sigma);
}