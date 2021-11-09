#include "stdafx.h"
#include "Generator.hxx"
#include "BagObject.hxx"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

Generator::Generator(void)
{
    srand(time(NULL));
}

Generator::~Generator(void)
{
    data.clear();
}

void Generator::generator(int ld)
{
    for (int i = 0; i<ld; i++)
{
    object = new BagObject(rand(),rand(),i);
    data.push_back(object);
    }
}

int main()
{
    Generator *g = new Generator;
    g->generator(10);
    return 0;
}