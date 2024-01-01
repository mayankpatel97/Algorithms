
#include <stdio.h>
#include <stdlib.h>

#define MAXELEMENTS 1000


typedef struct Dict
{
    /*      void* array for  dictionary.    */
    void *elements[MAXELEMENTS];
    /* contains the number of elements in this dictionary */
    int number_of_elements;

} Dictionary;



/* constructor */
Dictionary *dict_create(void)
{
    Dictionary *p_dic = malloc(sizeof(Dictionary));
    if (p_dic)
    {
        p_dic->number_of_elements = 0;
        /* initializes the elemens of the array with NULL-pointer */
        for (int i = 0; i < MAXELEMENTS; i++)
        {
            p_dic->elements[i] = NULL;
        }
        return p_dic;
    }
    else
    {
        printf("unable to create a dictionary\n");
        return NULL;
    }
}

/*
    utility function
    sdbm hash algorithm
    returns a hashcode for the given string 's'
*/
int dict_get_hash(char s[])
{
    unsigned int hash_code = 0;

    /* iterates over string at each character */
    for (int counter = 0; s[counter] != '\0'; counter++)
    {
        /* actual computing of the hash code */
        hash_code =
            s[counter] + (hash_code << 6) + (hash_code << 16) - hash_code;
    }

    /* % modulo is for fitting the index in array. */
    return hash_code % MAXELEMENTS;
}

int dict_add_item_label(Dictionary *dic, char label[], void *item)
{
    unsigned int index = dict_get_hash(label);

    /* make sure index is fitting */
    if (index < MAXELEMENTS)
    {
        dic->elements[index] = item;
        return 0;
    }

    /* error case */
    return -1;
}

int dict_add_item_index(Dictionary *dic, int index, void *item)
{
    /* make sure whether this place is already given */
    if (!dic->elements[index])
    {
        dic->elements[index] = item;
        return 0;
    }

    /* error case */
    return -1;
}

void *dict_get_element_label(Dictionary *dict, char s[])
{
    int index = dict_get_hash(s);
    if (dict->elements[index])
    {
        return dict->elements[index];
    }

    printf("None entry at given label\n");
    return NULL;
}

void *dict_get_element_index(Dictionary *dict, int index)
{
    if (index >= 0 && index < MAXELEMENTS)
    {
        return dict->elements[index];
    }

    printf("index out of bounds!\n");
    return NULL;
}

void dict_deinit(Dictionary *dict) { free(dict); }


int main(void)
{
    Dictionary *testObj1;
    Dictionary *testObj2;

    int value = 26;
    testObj1 = dict_create();
    testObj2 = dict_create();

    dict_add_item_label(testObj1, "age", &value);
    dict_add_item_label(testObj2, "name", "Mayank");

    /*
        test for function disct_add_item_label
        attention:
        The void* pointer must be convert into an int* pointer.
        After that you can dereference it.
    */
    printf("My age is %d\n", *((int *)dict_get_element_label(testObj1, "age")));
    printf("My name is %s\n", dict_get_element_label(testObj2, "name"));

    /* test for function add_item_index */
    if (!dict_add_item_index(testObj1, 0, &value))
    {
        printf("My age at index %d is %d\n", 0,
               *((int *)dict_get_element_index(testObj1, 0)));
    }

    /* error scenario */
    /* dict_get_element_label(testObj,"none"); */

    /* de init */
    dict_deinit(testObj1);
    dict_deinit(testObj2);

    return 0;
}