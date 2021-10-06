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

