#include "function2.hpp"
#include <fstream>
#include <iostream>

struct Image {
  double quality;   // 10
  double freshness; // 2
  double rating;    // 6
};

// 10 * 4 - 2 * 2 + 6 * 6 = 40 - 4 + 36 = 72
// 5 * 4 + 2 * 2 - 6 * 6 = 13 + 4 - 36  = 52


struct Params {
  double a; // 4
  double b; // 2
  double c; // 6
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
  Function function;
  function.AddPart('*', params.a);
  function.AddPart('-', image.freshness * params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}

using namespace std;

int main() {
  Image image = {10, 2, 6};
  Params params = {4, 2, 6};
  // cout << ComputeImageWeight(params, image) << endl;
  // cout << ComputeQualityByWeight(params, image, 52) << endl;
  Function f;
  std::ifstream inp("function2.txt");
  char op;
  double val;
  double res;
  while (true) {
    inp >> op;
    if (op == '_')
      break;
    inp >> val;
    f.AddPart(op, val);
  }
  // direct
  std::vector<double> vals;
  while (true) {
    inp >> val;
    if (!inp)
      break;
    res = f.Apply(val);
    vals.push_back(res);
    std::cout << val << ": " << res << '\n';
  }
  // inverted
  std::cout << "--------" << '\n';
  f.Invert();
  std::cout << f.ToStr() << '\n';
  for(double val: vals) {
    std::cout << val << ": " /* << f.ToStr() */ << f.Apply(val) << '\n';
  }
  return 0;
}
