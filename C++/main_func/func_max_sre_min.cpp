#include "main_max_sre_min.h"

void max(float number1, float number2, float number3){
    float max = number1;

    if (number2 > max){
        max = number2;
    }
    if (number3 > max){
        max = number3;
    }
}
void min(float number1, float number2, float number3){
    float min = number1;

    if (number2 < min){
        min = number2;
    }
    if (number3 < min){
        min = number3;
    }
} 
void sre(float number1, float number2, float number3){
    float max = number1;
    float min = number1;
    float sre = number1;

    if (number2 > max){
        max = number2;
    }
    if (number3 > max){
        max = number3;
    }

    if (number2 < min){
        min = number2;
    }
    if (number3 < min){
        min = number3;
    }

    if (number2 < max and number2 > min){
        sre = number2;
    }
    if (number3 < max and number3 > min){
        sre = number3;
    }
} 