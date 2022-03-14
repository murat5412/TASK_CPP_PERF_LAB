#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int calc_median(vector <int> nums) {
    if ((nums.size() / 2) == 1) {
        return (nums.size() / 2) + 1;
    }
    else {
        return round(((nums.size() / 2) + (nums.size() / 2 + 1)) / 2);
    }
}

int main()
{
    string name_file = "";
    cin >> name_file;

    vector <int> nums;
    int abstract_var,
        sum = 0;

    ifstream fin(name_file);
    if (fin.is_open()) {
        while (!fin.eof()) {
            fin >> abstract_var;
            nums.push_back(abstract_var);
        }
    }
    else {
        cout << "Error with the file!" << endl;
    }
    fin.close();

    int mediana = calc_median(nums);

    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        sum = sum + abs(nums[i] - mediana);
    }
    
    cout << sum;

    return 0;
}