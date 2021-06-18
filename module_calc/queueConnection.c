#include <stdio.h>

#include "queueConnection.h"

queue *queue_head = NULL;
queue *queue_tail = NULL;

int put_element(FILE *input) {
    queue *tmp = malloc(1 * sizeof(queue));
    fgets(tmp->string, sizeof(tmp->string), input);
    tmp->next = NULL;
    if (queue_tail != NULL) {
        queue_tail->next = tmp;
        queue_tail = tmp;
    } else {
        queue_head = tmp;
        queue_tail = tmp;
    } return 1;
}

char *get_element(void) {
    if(queue_head != NULL) {
        char *data;
        data = queue_head->string;
        queue_head = queue_head->next;
        return data;
    } else {
        return NULL;
    }
}
