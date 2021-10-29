#include <iostream>
#include <math.h>
using namespace std;
int main()
{

    double total = 0;
    double input = 0;
    double average = 0;
    int count = 0;
    while (true)
    {
        cin >> input;
        if (input == 0)
            break;
        count++;
        total += input;
    }
    cout << "the average of the above numbers is " << total / count << endl;

    return 0;
}