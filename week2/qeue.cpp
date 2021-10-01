#include<iostream>
#include<string>
#include<vector>
#include<map>

enum Commands {
    in,
    out,
    worry,
    quiet,
    worry_count
};

struct Human {
    public:
        bool is_worried;
    Human(){
        is_worried = false;
    }
};

std::map<std::string, int> command_types = {
    {"COME", in},
    {"WORRY", worry},
    {"QUIET", quiet},
    {"WORRY_COUNT", worry_count}
};

int get_command_type(std::string type) {
    return command_types[type];
}

void qeue_add(std::vector<Human>& qeue, int num) {
    for (int i = 0; i < num; i++) {
        Human hum;
        qeue.push_back(hum);   
    }
}
void qeue_pop(std::vector<Human>& qeue, int num) {
    for (int i = 0; i < num; i++) {
        qeue.pop_back();
    }
}
void qeue_worry(std::vector<Human>& qeue, int i) {
    qeue[i].is_worried = true;
}
void qeue_quiet(std::vector<Human>& qeue, int i) {
    qeue[i].is_worried = false;
}
int qeue_worry_count(std::vector<Human>& qeue) {
    int res = 0;
    for(Human h: qeue) res += h.is_worried;
    return res;
}
void print_worry_count(std::vector<Human>& qeue) {
    std::cout << qeue_worry_count(qeue) << "\n";
}

void process(std::vector<Human>& qeue) {
    std::string comstr;
    std::cin >> comstr;
    int com = get_command_type(comstr);
    int num = -1;

    if (com != worry_count) {
        std::cin >> num;
        if (num < 0 && com == in) {
            com = out;
            num = -num;
        }
    }   

    switch (com) {
        case Commands::in:
            qeue_add(qeue, num);
            break;
        case Commands::out:
            qeue_pop(qeue, num);
            break;
        case Commands::worry:
            qeue_worry(qeue, num);
            break;
        case Commands::quiet:
            qeue_quiet(qeue, num);
            break;
        case Commands::worry_count:
            print_worry_count(qeue);
            break;
    }
}

/* 
8
COME 5
WORRY 1
WORRY 4
COME -2
WORRY_COUNT
COME 3
WORRY 3
WORRY_COUNT
*/
int main() {
    int num = 0;
    std::cin >> num;
    std::vector<Human> qeue;
    for (int i = 0; i < num; ++i) {
        process(qeue);
    }
    return 0;
}
