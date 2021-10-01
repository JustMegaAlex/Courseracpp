#include <string>
#include <vector>
#include <iostream>

class FunctionPart {
    public:
        FunctionPart(char _op, double _val) {
            operation = _op;
            value = _val;
        }

        double Apply(double src_val) {
            if (operation == '-') return src_val - value;
            else return src_val + value;
        }

        void Invert() {
            operation = (operation == '+' ? '-' : '+');
        }

        std::string to_str() {
            std::string res;
            res.push_back(operation);
            return res + " " + std::to_string(value);
        }
    
    private:
        char operation;
        double value;
};

class Function {
    public:
        void AddPart(char _op, double _val) {
            parts.push_back(FunctionPart(_op, _val));
        };
        void Invert() {
            for(auto& p : parts) {
                p.Invert();
            }
        };
        double Apply(double value) {
            for(auto p: parts) {
                value = p.Apply(value);
            }
            return value;
        }
    private:
        std::vector<FunctionPart> parts;
};
struct Image {
    double quality;
    double freshness;
    double rating;
};

struct Params {
    double a;
    double b;
    double c;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
    Function function;
    function.AddPart('-', image.freshness * params.a + params.b);
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

// using namespace std;

// int main() {
//     Image image = {10, 2, 6};
//     Params params = {4, 2, 6};
//     cout << ComputeImageWeight(params, image) << endl;
//     cout << ComputeQualityByWeight(params, image, 46) << endl;
//     return 0;
// }
