#ifndef QUEUECONNECTION_H_
#define QUEUECONNECTION_H_

typedef struct command_list {
    char string[50];
    struct command_list *next;
} queue;

int put_element(FILE *input);
char *get_element(void);

#endif /* QUEUECONNECTION_H_ */
