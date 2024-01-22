#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int));

    if (list == NULL)
    {
        return 1;
    }

    list[0] = 114;
    list[1] = 514;
    list[2] = 1919;

    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }

    // bad design
    /*
    int *temp = malloc(4 * sizeof(int));
    if (temp == NULL)
    {
        free(list);
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        temp[i] = list[i];
    }
    temp[3] = 810;

    free(list);

    list = temp;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);
    return 0;
    */

    //using realloc
    int *temp = realloc(list, 4 * sizeof(int)); // this automatic copy existing values and free the original memory
    // the temporary pointer temp is made to enable the loop below. If we just use list = realloc(...), then if this fails, list will be NULL and the original memory allocated is leaked
    if (temp == NULL)
    {
        free(list);
        return 1;
    }

    list = temp;

    temp[3] = 810;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);
    return 0;
}
