#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "math.h"
#include "queueConnection.h"
#include "stackConnection.h"
#include "listConnection.h"


int main(void) {
    double reversed_stroke[30];
    int k = 0, len = 0, m = -1, counting = 0, stroke_count = 0;
    float elem1, elem2, elem3, res;

    char inFile[254+1], outFile[254+1], *element_now, *cut, space[10] = " ", version;
    FILE *input, *output;

    input_data *head, *current;
    output_data *head_result, *current_result;

    printf("I realized two modes in this calculator:\n1. Working by list.\n2. Working by stack and queue.\nChose one from this one: [q/l]");
    scanf(" %c", &version);
    printf("\nEnter the input filename: ");
    scanf(" %s", inFile);
    printf("\nEnter the output filename: ");
    scanf(" %s", outFile);
    input = fopen(inFile , "r");
    switch(version) {
        case 'q': // if queue
            while(!feof(input)) { // cycle of file reading
                put_element(input);
                counting++; // lines count
            }
            stroke_count = counting - 1;
            while(counting != 0) {
                element_now = get_element(); // get element from memory
                len = strlen(element_now);
                counting--;

                while (counting != 0){
                        counting--;
                        cut = strtok(element_now,space); // python split analog
                        while (cut != NULL) {
                            int i = 0;
                            elem1 = strtof(cut, NULL);

                            if (elem1 != 0){
                                push_element(elem1); // add new element to stack
                                i++;
                            } else {
                                while(k <= len-1) {
                                if (element_now[k] == '+' ||
                                        element_now[k] == '-' ||
                                        element_now[k] == '*' ||
                                        element_now[k] == '/' ||
                                        element_now[k] == '^' ||
                                        element_now[k] == '!'||
                                        element_now[k] == '@') {

                                    if (element_now[k] == '@') {
                                        k++;
                                    } else {
                                        if(element_now[k] != '!') {
                                            elem2 = pop_element(); // get elements from stack
                                            elem1 = pop_element();
                                            res = calculate_numbers(element_now[k], elem1, elem2); // calculate
                                            push_element(res); // add result to stack
                                            k++;
                                        } else {
                                            elem1 = pop_element(); // for factorial needs only one number
                                            res = calculate_factorial(elem1);
                                            push_element(res);
                                            k++;
                                        }
                                    }
                                } else {
                                    k++;
                                }
                                }
                            }
                            cut = strtok(NULL, space);
                        }
                        k = 0;
                        element_now = get_element();
                        len = strlen(element_now);
                }
            }
                output = fopen(outFile, "w");
                while (stroke_count != 0) { // get results from stack
                    m++;
                    elem3 = pop_element();
                    reversed_stroke[m] = elem3;
                    stroke_count--;
                }
                for(k=m; k >= 0; k--) { // and reverse the line
                    fprintf(output, "Answer is: %.4f\n", reversed_stroke[k]);
                }
                fclose(output);
                fclose(input);
                break;

        case 'l': // if list
            if(!feof(input)) {
                head = malloc(1 * sizeof(input_data));  // get memory for element
                fscanf(input, " %c %c", &head->sign, &head->operation);
                if (head->operation == 'v') {
                    fscanf(input, " %i", &head->size);
                } else {
                    head->size = 1;
                }
                if (head->sign != '!') {
                    head->firstNum = add_number(input, head->size);
                    head->secondNum = add_number(input, head->size);
                } else {
                    head->firstNum = add_number(input, head->size);
                    head->secondNum = NULL;
                }

                current = head; // start again
                int n;

                while (!feof(input)) {
                    add_element(current, input);
                    current = current->next;
                    n += 1;
                }
                head_result = malloc(sizeof(output_data));

                current = head;
                if (current->operation == 'v') {
                    head_result->result = calculate_vectors(current->sign, current->size, current->firstNum, current->secondNum);
                } else {
                    head_result->result = numbers_list(current->sign, current->firstNum, current->secondNum);
                }
                head_result->res_next = NULL;
                current = current->next;
                current_result = head_result;

                while (current != NULL) {
                    add_element_result(current_result, current);
                    current = current->next;
                    current_result = current_result->res_next;
                    counting++;
                }
                current = head;
                current_result = head_result;
                fclose(input);
                output = fopen(outFile, "w");

                while (counting != 0) {
                    if (current->operation == 'v') {
                        fprintf(output, "(");
                        for (int i = 0; i < current->size; i++) { // data output cycle
                            fprintf(output, " %.4f ", current->firstNum[i]);
                        }
                        fprintf(output, ") %c (", current->sign);
                        for (int i = 0; i < current->size; i++) {
                            fprintf(output, " %.4f ", current->secondNum[i]);
                        }
                        fprintf(output, ") = ");
                        if (current->sign != '*') {
                            fprintf(output, "(");
                            for (int i = 0; i < current->size; i++) { fprintf(output, " %.4f ", current_result->result[i]); }
                            fprintf(output, ")\n");
                        } else {
                            fprintf(output, " %.2f\n", current_result->result[0]);
                        }
                    } else if (current->operation == 's') {
                        fprintf(output, "%.2f\n", current_result->result[0]);
                    }
                    current = current->next;
                    current_result = current_result->res_next;
                    counting--;
                }
                fclose(output);
                }
            break;

        default://if not queue, stack or list
            printf("I don't understand you. Could you try again?");
            break;
    }
}
