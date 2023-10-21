#include <iostream>

int divideCore(int dividend, int divisor) {
    std::cout <<"dividend start"<<"dividend:"<<dividend<<"divisor:"<<divisor <<std::endl;
    int result = 0;
    while (dividend <= divisor)
    {
        std::cout <<"dividend:" << dividend <<std::endl;
        int value = divisor;
        int queotient = 1;
        while (value >= 0xc0000000 && dividend <= value + value)
        {
            queotient+=queotient;
            value+=value;
        }

        result+=queotient;
        dividend-=value;
        
    }

    return result;
    
}

int divide(int dividend, int divisor) {
    if(dividend == 0x80000000 && divisor == -1) {
        return __INT_MAX__;
    }
    int negative = 2;
    if(dividend > 0) {
        negative--;
        dividend = -dividend;
    }
    if(divisor > 0) {
        negative--;
        divisor = -divisor;
    }
    int result = divideCore(dividend, divisor);
    return result;
}

