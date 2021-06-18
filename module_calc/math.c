#include "math.h"

float calculate_factorial(float number) {
    int variable1 = 1;
    for (int i=1;i<=number;i++) {
        variable1 = variable1 * i;
    } return variable1;
}

float calculate_numbers(char sign, float x, float y) {
    float result;
    float variable1, variable2;
    switch(sign) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            if (y == 0) {
                return 0;
            } else {
                return x / y;
            }
        case '^':
            if (y == 0) {
                return 1;
            } else {
                variable1 = 1;
                variable2 = 1;
                for (int i=1;i<=y;i++) {
                    variable1 = variable2;
                    variable2 = variable1 * x;
                } return variable2;
            }
    }
}

float *calculate_vectors(char sign, int size, float *vector1, float *vector2) {
    float *vector_result;
        switch (sign){
            case '+':
                vector_result = malloc(size * sizeof(float));
                for (int i = 0; i < size; i++)
                {
                    vector_result[i] = vector1[i] + vector2[i];
                }
                return vector_result;
            case '-':
                vector_result = malloc(size * sizeof(float));
                for (int i = 0; i < size; i++)
                {
                    vector_result[i] = vector1[i] - vector2[i];
                }
                return vector_result;
            }
        return vector1;

}
