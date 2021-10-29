#include <iostream>
using namespace std;
int main()
{
    int largest = 0;
    int input = 0;
    largest = input;
    while (1)
    {
        cout << "please input a number" << endl;
        cin >> input;

        if (input > largest)
        {
            largest = input;
        }

        cout << "the biggest value so far is " << largest << '\n';
        cout << endl;
    }
    return 0;
}