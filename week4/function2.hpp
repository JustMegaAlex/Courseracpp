#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>

void print(std::string s);
void print(char s);
std::string tostr(char c);

class FunctionPart {
    public:
        FunctionPart(char _op, double _val) {
            operation = _op;
            value = _val;
            print("Ctor " + tostr(operation));
        }

        double Apply(double src_val) const {
            const char& op = operation;
            if (op == '-') return src_val - value;
            else if (op == '+') return src_val + value;
            else if (op == '*') return src_val * value;
            else if (op == '/') return src_val / value;
            throw std::runtime_error("no such operation");
        }

        char Invert() {
            char& op = operation;
            if (op == '-') op = '+';
            else if (op == '+') op = '-';
            else if (op == '*') op = '/';
            else if (op == '/') op = '*';
            return op;
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
            double gain = 1;
            for(auto& p : parts) {
                std::reverse(parts.begin(), parts.end());
                print("Invert " + tostr(p.Invert()));
            }
        };
        double Apply(double value) const {
            for(auto& p: parts) {
                value = p.Apply(value);
            }
            return value;
        }
    private:
        std::vector<FunctionPart> parts;
};

void print(std::string s) {
    std::cout << s << '\n';
};

void print(char s) {
    std::cout << s << '\n';
};

std::string tostr(char c) {
    std::string s;
    s.push_back(c);
    return s;
}
