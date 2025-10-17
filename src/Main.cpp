#include <iostream>
#include "List.h"
#include "ListOperations.h"

using namespace std;
// 15.10.2025
// CWL 3
// Laboratorium Język C++ - Zajęcia 3
//
//Polecenie
// Prosze napisać kod, który będzie implementował Liste dwukierunkowa
// W dostarczonym kodzie mogą państwo natrafić na: błędy - we wszystkich dostarczonych plikach - napraw/dopisz/usuń niepotrzebne rzeczy.
// Pliku Main.cpp, nie wolno modyfikowac. Plik Main.cpp zawiera wszystkie funkcje które trzeba zaimplementować.
// Kod niekompilujący sie nie będzie oceniany, kod nie przesłąny przez UPEL a oceniony na zajeciach zostaje oceniony na 0.
//
// Ostateczny program powinien byc przyjazny dla programisty
// (miec czytelny i dobrze napisany kod)
// KISS - Keep It Simple Stupid - Kod powinien być tak prosty, jak to tylko możliwe. Co prawda likwidacja muchy za pomocą armaty może być widowiskowa, ale później i tak trzeba będzie posprzątać.
// YANGI - You Aren’t Gonna Need It. - Co należy robić z kodem, którego nie potrzebujesz ? Bezwzględnie go usuwać. Nie przekształcać w komentarz, bo „może się potem przyda”.
// DRY - Don’t Repeat Yourself. - Nie rób powtórzeń w kodzie źródłowym. Każdy programista i programistka powinien zauważać takie sytuacje niemal natychmiast – i sprawnie sobie z nimi radzić.
//
//
// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani żadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz makefile, chyba że polecenie stanowi inaczej)
//
//
// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli dodane pliki i Main.cpp należy wgrać do UPEL
// jako archiwum tar.gz o strukturze takiej jak w zadaniu na UPeL.
//
//
// UWAGA:
// * archiwum powinno zawierać katalog z zadaniem lab02/
// * katalog z zadaniem powinien zawierać podkatalog include/
//   w którym muszą znajdować się wszystkie niezbędne pliki nagłówkowe
// * katalog z zadaniem powinien zawierać podkatalog src/
//   w którym muszą znajdować się wszystkie niezbędne pliki z kodem źródłowym
// * katalog z zadaniem powinien zawierać podkatalog build/
//   w którym powinien znajdować się tylko i wyłącznie plik Makefile
// * tworzenie archiwum: tar -czvf nazwa.tar.gz zad/
//   np. tar -czvf lab01.tar.gz lab01/
// * rozpakowanie archiwum: tar -xvf nazwa.tar.gz
//
//
// * wszystkie funkcje w plikach *.h powinny być okomentowane (patrz przyklad w pliku StackOperations.h (format pod Doxygena))
// * do alokacji i dealokacji pamięci używaj operatorów: new i delete
//
// Powodzenia



int main(int argc, char** argv) 
{
    ListElement_type* List = nullptr;
	
    init(&List);
	
    std::cout << "Czy lista pusta (przed push): " << (empty(List) ? "tak" : "nie") << endl;

    push_back(&List, 43);  // '+'
    push_back(&List, 43);  // '+'
    push_back(&List, 67);  // 'C'
    push_back(&List, 32);  // ' '
    push_back(&List, 107); // 'k'
    push_back(&List, 121); // 'y'
    push_back(&List, 122); // 'z'
    push_back(&List, 101); // 'e'
    push_back(&List, 74);  // 'J'

    std::cout << "Rozmiar listy: " << list_size(List) << endl;

    std::cout << "Wartość na początku: " << value(List) << endl;

    show(List);

    show(List, true);

    pop_front(&List);
    std::cout << "Po pop_front, rozmiar: " << list_size(List) << endl;
    show(List);
    show(List, true);

    push_front(&List, 43);
    std::cout << "Po push_front(43), rozmiar: " << list_size(List) << endl;
    show(List);

    push_by_index(&List, 100, 2); 
    std::cout << "Po push_by_index(100, 2), rozmiar: " << list_size(List) << endl;
    show(List);

    pop_back(&List);
    std::cout << "Po pop_back, rozmiar: " << list_size(List) << endl;
    show(List);

    pop_by_index(&List, 2);
    std::cout << "Po pop_by_index(2), rozmiar: " << list_size(List) << endl;
    show(List);

    std::cout << "Czy lista pusta (po operacjach): " << (empty(List) ? "tak" : "nie") << endl;

    ListElement_type* current = List;
    ListElement_type* next;
    while (current != nullptr) {
        next = current->next; // Save next pointer
        delete current;       // Use delete, not free
        current = next;       // Move to next
    }
    List = nullptr; // Avoid dangling pointer


    return 0;
}

// Wynik kodu
// Czy lista pusta (przed push): tak
// Rozmiar listy: 9
// Wartość na początku: 43
// Moja lista: <43,43,67,32,107,121,122,101,74>
// Moja lista (odwrotna): <74,101,122,121,107,32,67,43,43>
// Po pop_front, rozmiar: 8
// Moja lista: <43,67,32,107,121,122,101,74>
// Moja lista (odwrotna): <74,101,122,121,107,32,67,43>
// Po push_front(43), rozmiar: 9
// Moja lista: <43,43,67,32,107,121,122,101,74>
// Po push_by_index(100, 2), rozmiar: 10
// Moja lista: <43,43,100,67,32,107,121,122,101,74>
// Po pop_back, rozmiar: 9
// Moja lista: <43,43,100,67,32,107,121,122,101>
// Po pop_by_index(2), rozmiar: 8
// Moja lista: <43,43,67,32,107,121,122,101>
// Czy lista pusta (po operacjach): nie