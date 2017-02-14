#include<iostream>
using namespace std;
int main()
{
    string str;
    cin >> str;

    bool c = false;
    string result = "No";
    for (int i = 0; i < (int)str.size(); i++) {
        if (str[i] == 'C') {
            c = true;
        } else if (str[i] == 'F' && c) {
            result = "Yes";
            break;
        }
    }
    cout << result << endl;
    return 0;
}