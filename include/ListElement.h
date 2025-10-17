#ifndef LIST_ELEMENT_H
#define LIST_ELEMENT_H

typedef struct ListElement {
    int data; 
    struct ListElement* previous;
    struct ListElement* next; 
} ListElement_type;

#endif // LIST_ELEMENT_H