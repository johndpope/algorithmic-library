#include "basic.hpp"

// 返回[0, n]每个数关于m的逆元
// x * i = 1 mod m
// let m = i * k + r, where k = m / i, r = m % i
// i = (m - r) * k^-1
// x = -k * r^-1
// time complexity: O(n)
std::vector<LL> linear_inversion(int n, LL m) {
  std::vector<LL> inv(n + 1, 0);
  inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = (m - m / i) * inv[m % i] % m;
  }
  return inv;
}
