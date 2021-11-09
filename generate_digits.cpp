#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
int digit[7];
long int id=0;
int main()
{
    srand(100000);
    for (int n=1; n<100; n++)
    {
        digit[6]=rand()%29+1; //1,XXX,XXX to 30,XXX,XXX
        for (int i=5; i>=0; i--) {digit[i]=rand()%10+1;} //Other digits
        id=digit[6]*pow(10,6)+digit[5]*pow(10,5)+digit[4]*pow(10,4)+digit[3]*pow(10,3)+digit[2]*pow(10,2)+digit[1]*10+digit[0]; //Summation
        cout << id << "\n";
    }
    return 0;
}
