data {
  int<lower=0> N; 
  vector[N] exposure2;
  int y[N];
  vector[N] roach1;
  vector[N] treatment;
  vector[N] senior;
}
transformed data {
  vector[N] log_expo;
  log_expo <- log(exposure2);
}
parameters {
  vector[4] beta;
} 
model {
  y ~ poisson_log(log_expo + beta[1] + beta[2] * roach1 + beta[3] * treatment
                      + beta[4] * senior);
}