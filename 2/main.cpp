#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main()
{
    // part 1
    map<char, int> shape_map = {
        {'X', 1},
        {'Y', 2},
        {'Z', 3},
    };
    map<char, char> win_map = {
        {'X', 'C'},
        {'Y', 'A'},
        {'Z', 'B'},
    };
    map<char, char> draw_map = {
        {'X', 'A'},
        {'Y', 'B'},
        {'Z', 'C'},
    };

    int score = 0;
    string line;
    char player, opp;

    ifstream file("input.txt");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            opp = line[0];
            player = line[2];

            // shape score
            score += shape_map[player];

            if (win_map[player] == opp)
            {
                score += 6;
            }
            else if (draw_map[player] == opp)
            {
                score += 3;
            }
        }
    }
    cout << "part 1: " << score << endl;

    // part 2
    shape_map = {
        {'A', 1},
        {'B', 2},
        {'C', 3},
    };
    win_map = {
        {'A', 'B'},
        {'B', 'C'},
        {'C', 'A'},
    };
    map<char, char> lose_map = {
        {'A', 'C'},
        {'B', 'A'},
        {'C', 'B'},
    };

    score = 0;
    int goal;

    file.clear();
    file.seekg(0);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            opp = line[0];
            goal = line[2];

            if (goal == 'X')
            {
                player = lose_map[opp];
            }
            else if (goal == 'Y')
            {
                score += 3;
                player = opp;
            }
            else // win
            {
                score += 6;
                player = win_map[opp];
            }

            score += shape_map[player];
        }
    }
    cout << "part 2: " << score << endl;
    file.close();
 
}
