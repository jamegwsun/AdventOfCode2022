#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    size_t pos;
    int secs[4];
    int answer = 0;
    int answer2 = 0;
    string line;
    ifstream file("./input.txt");

    // part 1
    if (file.is_open()) {
        while (getline(file, line)) {
            pos = line.find(',');
            line[pos] = '-';

            for (int i = 0; i < 4; i++) {
                pos = line.find('-');
                secs[i] = stoi(line.substr(0, pos));
                line.erase(0, pos + 1);
            }

            if ((secs[0] >= secs[2] && secs[1] <= secs[3]) ||
                (secs[0] <= secs[2] && secs[1] >= secs[3])) {
                answer++;
            }

            if ((secs[1] >= secs[2] && secs[0] <= secs[3]) ||
                (secs[3] >= secs[0] && secs[2] <= secs[1])) {
                answer2++;
            }
        }
        file.close();
        cout << answer << endl;
        cout << answer2 << endl;
    }
}