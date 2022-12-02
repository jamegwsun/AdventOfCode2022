#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int curr_cal = 0;
    vector<int> all_cals;
    string line;
    ifstream file("input.txt");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line != "")
            {
                curr_cal += stoi(line);
            }
            else
            {
                all_cals.push_back(curr_cal);
                curr_cal = 0;
            }
        }
        file.close();
    }
    sort(all_cals.begin(), all_cals.end());
    auto it = all_cals.rbegin();
    cout << "part 1: " << *it << endl;     
    cout << "part 2: " << *it++ + *it++ + *it << endl;
}