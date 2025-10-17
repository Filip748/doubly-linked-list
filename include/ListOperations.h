#ifndef LIST_OPERATIONS_H
#define LIST_OPERATIONS_H

#include "ListElement.h"

/**
 * @brief Wyświetla zawartość listy.
 *
 * Wyświetla wartości całkowite elementów listy w kolejności od głowy do ogona (reverse=false)
 * lub od ogona do głowy (reverse=true), oddzielone przecinkami.
 * @param head Wskaźnik na głowę listy.
 * @param reverse Flaga określająca kierunek wyświetlania (domyślnie false).
 */
void show(ListElement_type* head, bool reverse = false);

/**
 * @brief Zwraca liczbę elementów w liście.
 *
 * Zlicza elementy w liście, przechodząc od głowy do ogona.
 * @param head Wskaźnik na głowę listy.
 * @return Liczba elementów w liście.
 */
int list_size(ListElement_type* head);

/**
 * @brief Dodaje element na początek listy.
 *
 * Tworzy nowy element z podaną wartością i wstawia go na początek listy.
 * @param head Wskaźnik na wskaźnik na głowę listy.
 * @param number Wartość całkowita do dodania.
 */
void push_front(ListElement_type** head, int number);

/**
 * @brief Dodaje element na koniec listy.
 *
 * Tworzy nowy element z podaną wartością i wstawia go na koniec listy.
 * @param head Wskaźnik na wskaźnik na głowę listy.
 * @param number Wartość całkowita do dodania.
 */
void push_back(ListElement_type** head, int number);

/**
 * @brief Dodaje element na określonej pozycji w liście.
 *
 * Wstawia nowy element z podaną wartością na wskazanej pozycji (liczonej od 0).
 * @param head Wskaźnik na wskaźnik na głowę listy.
 * @param number Wartość całkowita do dodania.
 * @param position Pozycja, na której ma być wstawiony element.
 */
void push_by_index(ListElement_type** head, int number, int position);

/**
 * @brief Usuwa element z początku listy.
 *
 * Usuwa pierwszy element listy i zwalnia jego pamięć.
 * @param head Wskaźnik na wskaźnik na głowę listy.
 */
void pop_front(ListElement_type** head);

/**
 * @brief Usuwa element z końca listy.
 *
 * Usuwa ostatni element listy i zwalnia jego pamięć.
 * @param head Wskaźnik na wskaźnik na głowę listy.
 */
void pop_back(ListElement_type** head);

/**
 * @brief Usuwa element z określonej pozycji w liście.
 *
 * Usuwa element na wskazanej pozycji (liczonej od 0) i zwalnia jego pamięć.
 * @param head Wskaźnik na wskaźnik na głowę listy.
 * @param position Pozycja elementu do usunięcia.
 */
void pop_by_index(ListElement_type** head, int position);

/**
 * @brief Sprawdza, czy lista jest pusta.
 *
 * Zwraca wartość logiczną wskazującą, czy lista nie zawiera elementów.
 * @param head Wskaźnik na głowę listy.
 * @return true, jeśli lista jest pusta, false w przeciwnym razie.
 */
bool empty(ListElement_type* head);

/**
 * @brief Zwraca wartość pierwszego elementu listy bez jego usuwania.
 *
 * Pozwala odczytać wartość z głowy listy bez modyfikacji struktury.
 * @param head Wskaźnik na głowę listy.
 * @return Wartość pierwszego elementu lub 0, jeśli lista jest pusta.
 */
int value(ListElement_type* head);

#endif // LIST_OPERATIONS_H