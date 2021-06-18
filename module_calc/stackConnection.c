#include <stdio.h>
#include <stdlib.h>

#include "stackConnection.h"

result_stack *head_stack = NULL;

void push_element(float element){
    result_stack *tmp_stack = malloc(1* sizeof(result_stack));
    tmp_stack->result = element;
    if (head_stack == NULL) {
        tmp_stack->res_last = NULL;
        head_stack = tmp_stack;
    } else {
        tmp_stack->res_last = head_stack;
        head_stack = tmp_stack;
    }
}

float pop_element(void){
    result_stack *tmp;
    float data;
    tmp = head_stack;
    head_stack = head_stack->res_last;
    data = tmp->result;
    free(tmp);
    return data;
}
