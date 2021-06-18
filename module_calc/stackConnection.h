#ifndef STACKCONNECTION_H_
#define STACKCONNECTION_H_

typedef struct result_stack {
    float result;
    struct result_stack *res_last;
} result_stack;

float pop_element(void);
void push_element(float element);


#endif /* STACKCONNECTION_H_ */
