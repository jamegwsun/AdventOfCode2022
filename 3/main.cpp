#include <stdio.h>
#include <string.h>

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int alphabet_to_score(char alpha) {
    if ((int)alpha <= 90) {
        return (int)alpha - 39;
    } else {
        return (int)alpha - 97;
    }
}

int main() {
    int priority = 0;
    int lsize, score;
    string line;
    ifstream file("./input.txt");

    // part 1
    if (file.is_open()) {
        while (getline(file, line)) {
            int low_comp[52] = {};
            int upp_comp[52] = {};
            lsize = line.size();
            for (int i = 0; i < lsize; i++) {
                score = alphabet_to_score(line[i]);
                if (i < lsize / 2) {
                    low_comp[score]++;
                } else {
                    upp_comp[score]++;
                }
            }
            for (int i = 0; i < 52; i++) {
                if (upp_comp[i] > 0 && low_comp[i] > 0) {
                    priority += i + 1;
                }
            }
        }
        cout << priority << endl;
    }

    // part 2
    file.clear();
    file.seekg(0);
    priority = 0;
    int j = 0;
    int grp_1[52] = {};
    int grp_2[52] = {};
    int grp_3[52] = {};

    if (file.is_open()) {
        while (getline(file, line)) {
            for (int i = 0; i < line.size(); i++) {
                score = alphabet_to_score(line[i]);
                // oof
                if (j % 3 == 0) {
                    grp_1[score]++;
                } else if (j % 3 == 1) {
                    grp_2[score]++;
                } else {
                    grp_3[score]++;
                }
            }

            if (j % 3 == 2) {
                for (int i = 0; i < 52; i++) {
                    if (grp_1[i] > 0 && grp_2[i] > 0 && grp_3[i] > 0) {
                        priority += i + 1;
                    }
                }
                memset(grp_1, 0, sizeof(grp_1));
                memset(grp_2, 0, sizeof(grp_2));
                memset(grp_3, 0, sizeof(grp_3));
            }

            j++;
        }
        cout << priority << endl;
    }
}