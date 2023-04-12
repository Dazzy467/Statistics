#include <iostream>
#include "cstatistic.h"

float mySqrt(float num)
{
    float guess = num / 2;
    float temp = 0;
    float sqrt = guess;
    while(sqrt != temp)
    {
        temp = sqrt;
        sqrt = (temp + num/ temp)/2;
    }

    return sqrt;
}

float myPow(float num,int pow)
{
    if (pow % 2 == 0 && pow != 0)
        return myPow(num*num,(pow/2));
    else if (pow % 2 != 0)
        return num * myPow(num*num,(pow-1)/2);
    else if (pow < 0)
        return myPow(1/num,-pow);
    else if (pow == 0)
        return 1;
    
    return float{};
}

int main()
{
    std::cout << "mypow: " << myPow(5,2) << std::endl;
    std::cout << "Mysqrt: " << mySqrt(25.3) << std::endl;
    int a[] {50,50,30,20,10,20,30,50,30,10,30,50,30};
    // int a[] {29, 19, 21, 52, 91, 50, 82, 65, 53, 84, 51, 90, 93};
    // int a[] {39, 35, 35, 36, 37, 38, 42, 40, 38, 41, 37, 35, 38, 40, 41, 40};
    int b[13];

    cstatistic<int> c(a);

    std::copy(a,(a+13),b);
    std::cout << "Data A: \n";
    printData(a);
    std::cout << std::endl;

    std::cout << "Data B: \n";
    printData(b);

    std::sort(b,(b+13));
    printData(b);

    std::cout << "Data C: \n";
    c.printData();

    printFreq(a);
    printMean(a);
    printMedian(a);

    std::cout << "\n\nIni statistik C:\n";
    std::cout << "Mean: " << c.getMean() << std::endl;
    std::cout << "Median: " << c.getMedian() << std::endl;
    std::cout << "Mode: " << c.getMode() << std::endl;
    std::cout << "Std.Deviation: " << c.getStdDeviation() << std::endl;
    auto freqMap = c.getFrequencyMap();

    std::cout << "Freq:\n";
    for (auto i = freqMap.begin(); i != freqMap.end(); ++i)
        std::cout << i->first << " : " << i->second << std::endl;

    
    return 0;
}