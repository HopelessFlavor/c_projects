#include "stdlib.h"

#include "listConnection.h"
#include "math.h"

void add_element(input_data *current, FILE *input) {
    input_data *tmp = malloc(1 * sizeof(input_data));
    fscanf(input, " %c %c", &tmp->sign, &tmp->operation);
    if (tmp->operation == 'v') {
        fscanf(input, " %i", &tmp->size);
    } else {
        tmp->size = 1;
    }
    if (tmp->sign != '!') {
        tmp->firstNum = add_number(input, tmp->size);
        tmp->secondNum = add_number(input, tmp->size);
    } else {
        tmp->firstNum = add_number(input, tmp->size);
        tmp->secondNum = NULL;
    }
    tmp->next = NULL;
    current->next = tmp;
}


void add_element_result(output_data *current_res, input_data *current) {
    output_data *tmp_res = malloc(1 * sizeof(output_data));
    if (current->operation == 'v'){
        tmp_res->result = calculate_vectors(current->sign, current->size, current->firstNum, current->secondNum);
    }
    else{
        tmp_res->result = numbers_list(current->sign, current->firstNum, current->secondNum);
    }
    tmp_res->res_next = NULL;
    current_res->res_next = tmp_res;
}

float *add_number(FILE *input, int size) {
    float *number;
    number = malloc(size * sizeof(float));
    for(int i = 0;i < size;i++) {
        fscanf(input,"%f", &number[i]);
    }
    return number;
}

float *numbers_list(char sign, float *firstNum, float *secondNum){
    float *res_num;
    float var1, var2;
    res_num = malloc(1 * sizeof(float));
    switch (sign) {
        case '+':
            res_num[0] = firstNum[0] + secondNum[0];
            return res_num;
        case '-':
            res_num[0] = firstNum[0] - secondNum[0];
            return res_num;
        case '*':
            res_num[0] = firstNum[0] * secondNum[0];
            return res_num;
        case '/':
            if (secondNum[0] != 0) {
                res_num[0] = firstNum[0] / secondNum[0];
                return res_num;
            }
            else {
                return 0;
            }
        case '^':
            var2 = 1;
            var1 = 1;
            for (int ist1=1;ist1<=secondNum[0];ist1++){
                var1 = var2;
                var2 = var1 * firstNum[0];}
            res_num[0] = var2;
            return res_num;
        case '!':
            var1 = 1;
            for(int i = 1; i<=firstNum[0]; i++)
            {var1 = var1 * i;}
            res_num[0] = var1;
            return res_num;
    }
    return firstNum;
}
