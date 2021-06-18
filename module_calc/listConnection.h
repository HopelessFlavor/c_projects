#ifndef LISTCONNECTION_H_
#define LISTCONNECTION_H_
#include <stdio.h>

typedef struct list {
    char operation;
    char sign;
    int size;
    float *firstNum;
    float *secondNum;
    struct list *next;
} input_data;

//announce work structure (list for saving results after counting operations).
typedef struct result_list {
    float *result;
    struct rez_list *res_next;
} output_data;

void add_element(input_data *current, FILE *input);
void add_element_result(output_data *current_res, input_data *current);
float *add_number(FILE *input, int size);
float *numbers_list(char sign, float *firstNum, float *secondNum);


#endif /* LISTCONNECTION_H_ */
