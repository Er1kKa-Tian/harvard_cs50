#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    // start from a linked list of size 0
    node *list = NULL;

    // add nodes
    for (int i = 1; i < argc; i++) // loop over all command line arguments
    {
        int number = atoi(argv[i]); // convert to int
        // add node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
            // indeed, there's still possibility for valgrind here
        }
        n->number = number;
        n->next = NULL;
        n->next = list;
        list = n;
    }

    // loop to print all values
    for (node *temp = list; temp != NULL; temp = temp->next)
    {
        printf("%i\n", temp->number);
    }

    // loop to free all allocated memory
    node *ptr = list;
    while (ptr != NULL)
    {
        node *ptr_nxt = ptr->next;
        free(ptr);
        ptr = ptr_nxt;
    }
}
