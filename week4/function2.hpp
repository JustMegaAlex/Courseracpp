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
            // print("Ctor " + tostr(operation));
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
        char get_op() { return operation; }
        double get_val() { return value; }

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
            std::reverse(parts.begin(), parts.end());
            for(auto& p : parts) {
                char _op = p.Invert();
                // print("Invert " + tostr(_op));
            }
        };
        double Apply(double value) const {
            for(auto& p: parts) {
                value = p.Apply(value);
            }
            return value;
        }
        std::string ToStr() {
            std::string s;
            for (auto op: parts) {
                s.push_back(op.get_op());
                s += "";
                s += std::to_string(op.get_val()) + " ";
            }
            return s;
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
