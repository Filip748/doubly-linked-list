#include "ListOperations.h"
#include "ListElement.h"
#include <iostream>

void show(ListElement_type* head, bool reverse) {
    std::cout << "Moja lista" << (reverse ? " (odwrotna): <" : ": <");
    ListElement_type* current = head;

    if (reverse) {
        while (current && current->next) {
            current = current->next;
        }
        while (current) {
            std::cout << current->data;
            if (current->previous) {
                std::cout << ",";
            }
            current = current->previous;
        }
    } else {
        while (current) {
            std::cout << current->data;
            if (current->next) {
                std::cout << ",";
            }
            current = current->next;
        }
    }
    std::cout << ">" << std::endl;
}

int list_size(ListElement_type* head)
{
    ListElement_type* current = head;
    int count = 0;
    while(current)
    {
        count++;
        current = current->next;  
    }
    return count;
}

void push_front(ListElement_type** head, int number)
{
    ListElement_type* newEl = new ListElement_type;
    newEl->data = number;
    newEl->next = *head;
    newEl->previous = nullptr;

    (*head)->previous = newEl;
    *head = newEl;
}

void push_back(ListElement_type** head, int number)
{
    ListElement_type* newEl = new ListElement_type;
    newEl->data = number;
    newEl->next = nullptr;
    newEl->previous = nullptr;
    if(*head == nullptr)
    {
        *head = newEl;
    }
    else
    {
        ListElement_type* current = *head;
        while(current->next)
        {
            current = current->next;
        }
        current->next = newEl;
        newEl->previous = current;
    }
}

void push_by_index(ListElement_type** head, int number, int position)
{
    if(position == 0)
    {
        push_front(head, number);
        return;
    }
    if(position > list_size(*head) - 1)
    {
        push_back(head, number);
        return;
    }
    if(*head)
    {
        int count = 0;
        ListElement_type* newEl = new ListElement_type;
        newEl->data = number;
        ListElement_type* current = *head;
        while(current && count != position - 1)
        {
            current = current->next;
            count++;
        }
        newEl->previous = current;
        newEl->next = current->next;
        current->next->previous = newEl;
        //current->previous->next = newEl;
        current->next = newEl;
    }
    
}

void pop_by_index(ListElement_type** head, int position)
{
    int count = 0;
    if(position == 0)
    {
        pop_front(head);
        return;
    }
    if(position == list_size(*head) - 1)
    {
        pop_back(head);
        return;
    }
    if(*head == nullptr) return;
    ListElement_type* current = *head;
    while(current->next && count != position)
    {
        count++;
        current = current->next;
    }
    current->previous->next = current->next;
    current->next->previous = current->previous;
    delete current;
}

bool empty(ListElement_type* head) // true - pusta
{
    if(head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int value(ListElement_type* head)
{
    if(head) return head->data;
    return 0;
}

void pop_front(ListElement_type** head)
{
    if(*head)
    {
        ListElement_type* temp = *head;
        *head = (*head)->next;        
        (*head)->previous = nullptr;
        delete temp;

    }
}

void pop_back(ListElement_type** head)
{
    ListElement_type* current = *head;
    while(current->next)
    {
        current = current->next;
    }
    ListElement_type* temp = *head;
    temp = current;
    current = current->previous;
    current->next = nullptr;
    delete temp;
}
