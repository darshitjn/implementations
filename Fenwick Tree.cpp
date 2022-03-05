template <typename T>
class FenwickTree {
 public:
  vector<T> fenw;
  int n;
 
  FenwickTree(int _n) : n(_n) {
    fenw.resize(n);
  }
 
  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
 
  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
 
 T get(int x, int y) {  // [x, y]
        return (get(y) - get(x - 1));
  }
};
