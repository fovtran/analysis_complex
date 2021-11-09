#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unordered_set>

using namespace std;

long generate1()
{
    static const int p6 = 1e6;
    static const int p5 = 1e5;
    static const int p4 = 1e4;
    static const int p3 = 1e3;
    static const int p2 = 1e2;
    static const int p1 = 1e1;
//  static const int p0 = 1e0;

    static int digit[7];
    
    digit[6] = rand() % 30 + 1;
        
    for (int i=5; i>=0; i--) 
        digit[i] = rand() % 10 + 1;
       
    return digit[6] * p6 
         + digit[5] * p5
         + digit[4] * p4 
         + digit[3] * p3 
         + digit[2] * p2 
         + digit[1] * p1 
         + digit[0];    
}

int main()
{    
    srand(time(NULL));
       
//    const int size = 100000;
    const int size = 10;

    std::unordered_set<long> randoms;    
    
    while (randoms.size() < size)
        randoms.insert(generate1());
     
    for (auto & num : randoms)
        cout << num << '\n';
}