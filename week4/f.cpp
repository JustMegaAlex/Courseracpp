
#include <iostream>
#include <string>
#include <vector>

void print(std::string s = "") {
    std::cout << s << '\n';
}

void print(char c) {
    std::string s;
    s.push_back(c);
    print(s);
}

void print(double d) {
    std::cout << d << '\n';
}

class FunctionPart {
    public:
        FunctionPart(char op, double v) { operation = op; value = v;};
        void Invert() {
            operation= operation == '+' ? '-' : '+';
        };

        double Apply(double src_val) {
            // std::cout << "apply: " << operation << '\n';
            if (get_op() == '-') return src_val - value;
            else return src_val + value;
        };

        char get_op() { return operation; };
    
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
                std::cout << "get_op: " << p.get_op() << " ";
            }
            print();
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

int main() {
    Function f;
    // f.AddPart('+', 2);
    // print(f.Apply(3));
    // f.Invert();
    // print(f.Apply(3));
    // f.Invert();
    FunctionPart fp('-', 3);
    print(fp.Apply(3));
    fp.Invert();
    print(fp.get_op());
    print(fp.Apply(3));
    return 0;
};