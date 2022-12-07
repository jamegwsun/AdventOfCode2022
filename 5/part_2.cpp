#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int char_to_int(char c) { return (int)c - 48; }

bool check_input(std::string l, int p_cnt) {
    for (int i = 0; i < p_cnt; i++) {
        if (l[i * 4] == '[') {
            return true;
        }
    }
    return false;
}

int main() {
    std::string l, ins;
    int p_cnt = 9;
    int _to, _from, move;
    std::map<int, std::string> p;
    for (int i = 1; i <= p_cnt; i++) {
        p[i] = "";
    }

    std::ifstream file("./input.txt");
    while (std::getline(file, l)) {
        if (check_input(l, p_cnt)) {
            for (int i = 0; i < p_cnt; i++) {
                if (l[1 + 4 * i] != ' ') {
                    p[i + 1].append(1, l[1 + 4 * i]);
                }
            }
        }

        if (l.substr(0, 4) == "move") {
            _to = char_to_int(l.back());

            l.erase(0, 5);
            move = std::stoi(l.substr(0, l.find(' ') + 1));

            l.erase(0, l.find('m') + 2);
            _from = char_to_int(l[0]);
            std::cout << move << ' ' << _from << ' ' << _to << std::endl;

            if (p[_from].size() <= move) {
                ins = p[_from];
                p[_from] = "";
                std::cout << ins;
            } else {
                ins = p[_from].substr(0, move);
                p[_from].erase(0, move);
            }
            p[_to].insert(0, ins);
        }
    }
    for (int i = 0; i < p_cnt; i++) {
        std::cout << p[i + 1][0];
    }
    std::cout << std::endl;
}
