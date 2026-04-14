# Informatik I - Extended Retake Preparation 

Willkommen zur Vorbereitung auf die Nachklausur. Diese Übung ist modular aufgebaut. Du kannst in der `main.c` einzelne Aufgaben durch das Setzen der Makros (`#define TEST_TASK_1 1`) an- und ausschalten, um strukturiert zu debuggen.

## Aufgabe 1: String-Manipulation & Pointer-Arithmetik
In C sind Strings lediglich nullterminierte Char-Arrays. 
Deine Aufgabe ist es, eine einfache Run-Length-Encoding (RLE) Kompression zu schreiben. 
Ein String wie "AAAABBBCCDAA" soll zu "A4B3C2D1A2" konvertiert werden. 
*Hinweis: Du darfst davon ausgehen, dass der Ziel-String groß genug alloziert ist.*

## Aufgabe 2: Structs & Arrays
Wir verwalten ein einfaches Lager. Du bekommst ein Array von `Item`-Structs.
Schreibe eine Funktion, die das Array durchsucht und einen Pointer auf das Item mit dem geringsten Lagerbestand (Quantity) zurückgibt. 
Schreibe eine zweite Funktion, die den Preis aller Items einer bestimmten Kategorie um einen Prozentwert reduziert (In-Place Manipulation über Pointer).

## Aufgabe 3: Dynamische Speicherverwaltung (Matrizen)
Das Arbeiten mit 2D-Arrays, die zur Laufzeit erstellt werden, ist ein Klausurklassiker.
1. Schreibe eine Funktion, die eine `n x m` Matrix dynamisch alloziert (als Array von Pointern oder flaches 1D-Array – siehe Header für die genaue Signatur).
2. Schreibe eine Funktion, die diese Matrix transponiert (Zeilen und Spalten vertauscht) und eine NEUE dynamisch allozierte Matrix zurückgibt.
3. Schreibe eine Funktion, die den Speicher einer Matrix sauber wieder freigibt.

## Aufgabe 4: Verkettete Listen (Linked Lists)
Die Königsdisziplin der C-Klausuren. Gegeben ist eine einfach verkettete Liste von Integern.
1. `list_append`: Füge ein neues Element am Ende der Liste ein. Beachte den Fall einer leeren Liste (Head = NULL).
2. `list_filter_even`: Entferne alle Knoten mit geraden Zahlen aus der Liste. Gib den freigewordenen Speicher der gelöschten Knoten mit `free()` frei!
3. `list_free`: Gib die komplette Liste frei, um Memory Leaks zu vermeiden.
