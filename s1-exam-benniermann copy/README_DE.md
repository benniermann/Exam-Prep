# STG-TES25: C Programmierprüfung

Willkommen zur C-Programmierprüfung. Diese Prüfung wurde
entworfen, um dein Verständnis und deine Fertigkeiten in grundlegenden
und fortgeschrittenen C-Programmierkonzepten zu bewerten, einschließlich
Speicherverwaltung, Datenstrukturen, Algorithmen und Dateiverarbeitung.

Diese deutsche Version wurde weitestgehend maschinell übersetzt.

----------------------------------------------------------

1. ***Du darfst das Internet nicht nutzen, außer um auf den Codespace zuzugreifen.***
2. ***Du darfst in keiner Form mit anderen kommunizieren.***
3. ***Du darfst keine LLMs in irgendeiner Weise verwenden.***

***Jeder Verstoß der oben genannten Regeln wird als Betrugsversuch gewertet und führt zum sofortigen Ausschluss von der Prüfung.***

----------------------------------------------------------

## Prüfungsaufbau

Du erhältst eine Reihe von vier unabhängigen Programmieraufgaben.
Diese Aufgaben können in beliebiger Reihenfolge gelöst werden.

Jede Aufgabe ist im Ordner `tasks/` als Paar aus Header- und Quelltextdateien enthalten.

Die Header-Dateien enthalten Dokumentationskommentare, die das beabsichtigte Verhalten der Funktionen,
Hinweise, zusätzliche Bedingungen/Einschränkungen sowie die Semantik von Parametern und Rückgabewerten beschreiben.

Dieses README enthält ebenfalls Aufgabenbeschreibungen und Beispiele, die von denen in den Header-Dateien abweichen können. Beide Quellen vermitteln denselben Kontext. Du kannst also frei wählen, welche Darstellung du hilfreicher findest.

Wir haben Testfälle für jede Aufgabe beigefügt, um dir bei der Verifikation deiner Implementierungen zu helfen.
Beachte jedoch, dass diese Tests nicht alle möglichen Fälle abdecken.
Du kannst die Tests erweitern, wenn du möchtest.

**Lies jede Aufgabe sorgfältig und implementiere genau das, was gefordert ist.**

## Abgabe

Um deine Prüfung erfolgreich einzureichen, befolge diese Schritte:

0. *(optional, aber sehr willkommen)* Stelle sicher, dass dein Code erfolgreich kompiliert.
1. Committe deine Änderungen wie bei den wöchentlichen Aufgaben (Dateien zum Staging hinzufügen, Commit erstellen und eine Commit-Nachricht angeben).
2. Das Commit erzeugt eine ZIP-Datei namens `submission_<repo name>.zip`.
3. Lade diese ZIP-Datei herunter.
4. Benenne die ZIP-Datei in `[deine matrikelnummer].zip` um (z.B. `081507.zip`).
5. Lade die ZIP-Datei auf Moodle hoch.
6. Informiere uns, dass du die Prüfung abgeschlossen hast.
7. Warte auf die Bestätigung, dass deine Abgabe erfolgreich hochgeladen wurde.
8. Fertig!

### Wir wünschen viel Erfolg!

## Inhaltsverzeichnis

- [Aufgabe 1 - Statistik](#aufgabe-1---statistik)
   * [Aufgabe 1.1 Zyklusanalyse](#aufgabe-11-zyklusanalyse)
   * [Aufgabe 1.2 Standardabweichung](#aufgabe-12-standardabweichung)
   * [Aufgabe 1.3 Zeitkonvertierung](#aufgabe-13-zeitkonvertierung)
- [Aufgabe 2 - Server](#aufgabe-2---server)
   * [Aufgabe 2.1 Finde den am staerksten ausgelasteten Server](#aufgabe-21-finde-den-am-staerksten-ausgelasteten-server)
   * [Aufgabe 2.2 Server an einem Ort finden](#aufgabe-22-server-an-einem-ort-finden)
   * [Aufgabe 2.3 Filtere Server nach Auslastung](#aufgabe-23-filtere-server-nach-auslastung)
- [Aufgabe 3 - Profiler](#aufgabe-3---profiler)
   * [Aufgabe 3.1 Profiler erstellen](#aufgabe-31-profiler-erstellen)
   * [Aufgabe 3.2 Funktionsaufruf hinzufuegen](#aufgabe-32-funktionsaufruf-hinzufuegen)
   * [Aufgabe 3.3 Eintraege sortieren](#aufgabe-33-eintraege-sortieren)
   * [Aufgabe 3.4 Zerstoeren](#aufgabe-34-zerstoeren)
   * [Aufgabe 3.5 BONUS: Groessenanpassung](#aufgabe-35-bonus-groessenanpassung)
- [Aufgabe 4 - Verschluesselung](#aufgabe-4---verschluesselung)
   * [Aufgabe 4.1 Verschluesseln](#aufgabe-41-verschluesseln)
   * [Aufgabe 4.2 BONUS: Entschluesseln](#aufgabe-42-bonus-entschluesseln)

---

## Aufgabe 1 - Statistik

Statistische Analysen sind grundlegend zur Auswertung von Benchmarks.
Diese Aufgabe umfasst die Implementierung von Funktionen zur Analyse von Messdaten, einschließlich Minimum, Maximum, Mittelwert, Standardabweichung und Zeitkonvertierung.

**Header-Datei:** `tasks/statistics.h`

### Aufgabe 1.1 Zyklusanalyse

Implementiere Funktionen, die minimale und maximale Zykluszahlen in Benchmark-Messungen finden:

```c
float min_cycles(const float* measurements, unsigned int count)
float max_cycles(const float* measurements, unsigned int count)
```

**Anforderungen:**
- `min_cycles`: Gibt den kleinsten Wert im Messungs-Array zurück
- `max_cycles`: Gibt den größten Wert im Messungs-Array zurück
- Beide Funktionen sollen 0 zurückgeben, wenn das Array leer ist

**Beispiel:**
```c
float data[] = { 10.5, 5.2, 8.7, 3.1 };
float minimum = min_cycles(data, 4);  // Gibt 3.1 zurück
float maximum = max_cycles(data, 4);  // Gibt 10.5 zurück
```

### Aufgabe 1.2 Standardabweichung

Implementiere Funktionen für die statistische Analyse:

```c
float average_cycles(const float* measurements, unsigned int count)
float standard_deviation(const float* measurements, unsigned int count)
```

**Anforderungen:**
- `average_cycles`: Berechnet und gibt das arithmetische Mittel der Messungen zurück
- `standard_deviation`: Berechnet und gibt die Standardabweichung zurück
- Gib jeweils 0 zurück, wenn das Array leer ist

**Formel für die Standardabweichung:**
$$\sigma = \sqrt{\frac{\sum_{i=0}^{n-1}(x_i - \mu)^2}{n}}$$

wobei $\mu$ der Mittelwert ist.

**Hinweis:**

Du kannst `sqrtf` aus `math.h` verwenden, um die Quadratwurzel einer `float`-Zahl zu berechnen.

**Beispiel:**
```c
float data[] = { 10.5, 5.2, 8.7, 3.1 };
float avg = average_cycles(data, 4);        // Gibt 6.875 zurück
float stddev = standard_deviation(data, 4); // Gibt ~2.895 zurück
```

### Aufgabe 1.3 Zeitkonvertierung

Implementiere eine Funktion, die Zyklusmessungen in Zeitwerte konvertiert:

```c
float* convert_to_time(const float* measurements, unsigned int count, float cycle_time)
```

**Anforderungen:**
- Wandle jede Zyklusmessung in Zeit um, indem du sie mit `cycle_time` multiplizierst
- Allokiere und gib ein neues Array mit den konvertierten Werten zurück
- Der Aufrufer ist verantwortlich für das Freigeben des zurückgegebenen Arrays
- Gib `NULL` zurück, wenn das übergebene Array leer ist oder die Allokation fehlschlägt

**Beispiel:**
```c
float cycles[] = { 100.0, 200.0, 300.0 };
float* times = convert_to_time(cycles, 3, 0.01);
// times[0] = 1.0, times[1] = 2.0, times[2] = 3.0
free(times);
```

---

## Aufgabe 2 - Server

Serververwaltung ist wichtig für den Betrieb verteilter Systeme. Diese Aufgabe umfasst die Implementierung von Funktionen, die Server anhand verschiedener Kriterien analysieren und filtern.

**Header-Datei:** `tasks/servers.h`

### Datenstruktur

#### `server`
```c
struct server {
    unsigned int req_per_sec;
    unsigned int utilization;
    const char* location;
};
```

Repräsentiert einen Server mit seiner Anfragefrequenz, der aktuellen Auslastung und dem geografischen Standort.

### Aufgabe 2.1 Finde den am stärksten ausgelasteten Server

Implementiere eine Funktion, die den Server identifiziert, der am meisten Anfragen bearbeitet:

```c
const struct server* get_busiest_server(const struct server* servers, unsigned int count)
```

**Anforderungen:**
- Finde den Server mit dem höchsten `req_per_sec`-Wert
- Gib einen Pointer auf diesen Server zurück
- Das Array hat mindestens ein Element garantiert

**Beispiel:**
```c
struct server servers[] = {
    { 100, 50, "US-East" },
    { 150, 75, "US-West" },
    { 120, 60, "EU-West" }
};
const struct server* busiest = get_busiest_server(servers, 3);
// Gibt Pointer auf Server mit req_per_sec = 150 (US-West) zurück
```

### Aufgabe 2.2 Server an einem Ort finden

Implementiere eine Funktion, die Server nach geografischem Standort filtert:

```c
struct server* get_servers_in_location(const struct server* servers, unsigned int count, const char* location)
```

**Anforderungen:**
- Filtere Server, die mit dem angegebenen Standort übereinstimmen
- Allokiere und gib ein neues Array mit den passenden Servern zurück
- Der Aufrufer ist für das Freigeben des zurückgegebenen Arrays verantwortlich
- Das zurückgegebene Array kann leer sein, wenn keine Übereinstimmungen gefunden werden

**Beispiel:**
```c
struct server* us_e_servers = get_servers_in_location(servers, 3, "US-East");
// Gibt neu allokiertes Array mit passenden Servern zurück
free(us_e_servers);
```

### Aufgabe 2.3 Filtere Server nach Auslastung

Implementiere eine Funktion, die Server anhand einer Auslastungsgrenze filtert:

```c
unsigned int filter_servers_by_utilization(struct server* servers, unsigned int count, unsigned int max_utilization)
```

**Anforderungen:**
- Filtere Server mit `utilization` kleiner oder gleich der angegebenen Grenze
- Modifiziere das Array in-place und verschiebe passende Server an den Anfang
- Erhalte die Reihenfolge der passenden Elemente bei
- Gib die neue Anzahl der gefilterten Server zurück
- Nicht passende Server können verschoben oder entfernt werden (deren Reihenfolge oder Existenz ist unerheblich)

**Beispiel:**
```c
struct server servers[] = {
    { 100, 50, "US-East" },
    { 150, 75, "US-West" },
    { 120, 60, "EU-West" }
};
unsigned int count = filter_servers_by_utilization(servers, 3, 60);
// count = 2, der Anfang des Arrays enthält { 100, 50, "US-East" } und { 120, 60, "EU-West" }
```

---

## Aufgabe 3 - Profiler

Ein Profiler misst, wie ein Programm ausgeführt wird – er verfolgt z.B. Funktionsaufrufhäufigkeiten, Ausführungszeit, Speicherverbrauch und CPU-Nutzung. Profiling ist der Prozess, ein solches Werkzeug zu verwenden, um Performance-Engpässe zu identifizieren und die Effizienz des Codes zu optimieren.
In dieser Aufgabe erstellst du eine Profiler-Datenstruktur, die Funktionsaufrufe und deren CPU-Zeit speichert.

**Header-Datei:** `tasks/profiler.h`

### Datenstrukturen

#### `function_entry`
```c
typedef struct {
    const char* func_name;
    unsigned int call_count;
    unsigned int total_cpu_time;
} function_entry;
```

Speichert Informationen über eine profilierte Funktion, einschließlich Name, Aufrufanzahl und kumulierter CPU-Zeit.

#### `function_profiler`
```c
typedef struct {
    function_entry* entries;
    unsigned int count;
    unsigned int capacity;
} function_profiler;
```

Verwaltet eine Sammlung profilierter Funktionen mit dynamischer Allokation.

### Aufgabe 3.1 Profiler erstellen

Implementiere eine Funktion, die einen neuen Profiler mit gegebener Kapazität initialisiert:

```c
function_profiler create_profiler(unsigned int capacity)
```

**Anforderungen:**
- Allokiere Speicher für ein Array von `function_entry`-Strukturen
- Initialisiere den Profiler mit der angegebenen Kapazität, nur wenn die Allokation erfolgreich war
- Setze `count` auf 0 (anfangs keine Einträge)
- Gib die initialisierte `function_profiler`-Struktur zurück

**Beispiel:**
```c
function_profiler prof = create_profiler(10);
// prof.capacity = 10, prof.count = 0, prof.entries zeigt auf allokierten Speicher
```

### Aufgabe 3.2 Funktionsaufruf hinzufuegen

Implementiere eine Funktion, die einzelne Funktionsaufrufe und deren CPU-Zeit protokolliert:

```c
void add_function_call(function_profiler* profiler, const char* func_name, unsigned int cpu_time)
```

**Anforderungen:**
- Prüfe, ob der Funktionsname bereits in den Einträgen des Profilers existiert
- Falls ja, erhöhe `call_count` und addiere zu `total_cpu_time`
- Falls nein, erstelle einen neuen Eintrag mit `call_count` = 1 und der gegebenen CPU-Zeit
- Du kannst annehmen, dass der Profiler genügend Kapazität hat

**Beispiel:**
```c
add_function_call(&prof, "process_data", 150);  // Erstellt neuen Eintrag
add_function_call(&prof, "process_data", 200);  // Aktualisiert bestehenden Eintrag
add_function_call(&prof, "render", 300);        // Erstellt neuen Eintrag
```

### Aufgabe 3.3 Eintraege sortieren

Implementiere eine Funktion, die Profiler-Einträge nach CPU-Zeit sortiert:

```c
void sort_entries(function_profiler* profiler)
```

**Anforderungen:**
- Sortiere Einträge in absteigender Reihenfolge von `total_cpu_time`
- Funktionen mit der höchsten kumulierten CPU-Zeit sollten zuerst erscheinen
- Verwende beliebigen Sortieralgorithmus (Bubble Sort, Quicksort, etc.)

### Aufgabe 3.4 Zerstoeren

Implementiere eine Funktion, die den allokierten Speicher freigibt und alle Mitglieder auf 0 oder NULL setzt.

```c
void destroy_profiler(function_profiler* profiler);
```

**Anforderungen:**
- Allokierter Speicher wird freigegeben
- Mitglieder werden auf 0 oder NULL gesetzt

### Aufgabe 3.5 BONUS: Groessenanpassung

Dies ist eine Bonusaufgabe. Wenn du genügend Zeit hast, kannst du diese Aufgabe zur zusätzlichen Punktzahl bearbeiten.
**Hinweis:** Wenn du funktionierenden Code für Aufgabe 3.2 hast, erstelle bitte eine Sicherungskopie (z.B. kopieren und auskommentieren). So stellst du sicher, dass du weiterhin Punkte für diese Aufgabe bekommst, selbst wenn die Bonus-Implementierung Fehler verursacht. Du kannst den Code dieser Bonusaufgabe auch auskommentieren, wenn du unsicher bist.

Erweitere die `add_function_call`-Funktion so, dass dynamische Größenanpassung unterstützt wird. Wenn das Hinzufügen eines neuen Eintrags die Kapazität überschreiten würde, vergrößere das Array entsprechend (die Kapazität soll sich verdoppeln). Falls die Vergrößerung fehlschlägt (keine Allokation möglich), behandle das entsprechend.

Beispiel:
```
function_profiler prof = create_profiler(3);
add_function_call(&prof, "process_data", 150);
add_function_call(&prof, "process_data", 200);
add_function_call(&prof, "render", 400);       // -> size: 3, capacity: 3
add_function_call(&prof, "clear", 100);        // dieser Aufruf würde die Kapazität überschreiten, daher verdoppeln -> new size: 4, new capacity: 6
```

---

## Aufgabe 4 - Verschluesselung

Verschlüsselung ist wichtig, um sensible Informationen zu schützen. In dieser Aufgabe implementierst du Funktionen zum Verschlüsseln und Entschlüsseln von Nachrichten mithilfe einer Zeichenoffset-Chiffre.

**Header-Datei:** `tasks/encryption.h`

### Aufgabe 4.1 Verschluesseln

Implementiere eine Funktion, die eine Nachricht verschlüsselt und in eine Datei schreibt:

```c
void encrypt(const char* message, char offset, FILE* output)
```

**Anforderungen:**
- Schreibe zuerst die Nachrichtenlänge gefolgt von einem Semikolon: `<length>;`
- Wende den Offset auf jedes Zeichen der Nachricht an
- Räume (Leerzeichen) unverändert lassen (nicht verschlüsseln)
- Verwende modulo-26-Arithmetik zum Umschlagen innerhalb des Alphabets
- Schreibe die verschlüsselte Nachricht in die Ausgabedatei

**Verschlüsselungsalgorithmus:**
- Jedes Zeichen wird um den Offset verschoben
- Beim Umschlagen verwende modulo 26, um Werte im Bereich der Kleinbuchstaben zu halten

**Beispiel:**
```c
FILE* out = fopen("encrypted.txt", "w");
encrypt("hello", 3, out);
// h+3=k, e+3=h, l+3=o, l+3=o, o+3=r
fclose(out);
// Datei enthält: 5;khoor
```

### Aufgabe 4.2 BONUS: Entschluesseln

Dies ist eine Bonusaufgabe. Wenn du genügend Zeit hast, kannst du diese Aufgabe zur zusätzlichen Punktzahl bearbeiten.

Implementiere eine Funktion, die eine Nachricht mit einem gegebenen Offset aus einer Datei entschlüsselt und als dynamisch allokierten, null-terminierten String zurückgibt:

```c
char* decrypt(char offset, FILE* input);
```

**Anforderungen:**
- Die Eingabedatei enthält genau eine Nachricht im Format: `<length>;<encrypted message>`
- Diese Funktion soll zuerst die Länge lesen, um ausreichend Speicher für die entschlüsselte Nachricht zu allokieren
- Der zurückgegebene String muss immer null-terminiert sein
- Die Entschlüsselung arbeitet ähnlich zur Verschlüsselung; der Offset wird jedoch in die entgegengesetzte Richtung angewendet (z.B. wird aus 'b' mit Offset 1 'a', aus 'a' mit Offset 1 'z')
- Gib einen dynamisch allokierten null-terminierten String mit der entschlüsselten Nachricht zurück oder `NULL`, falls ein Fehler auftritt

**Hinweis:**
- Der Offset ist derselbe Wert, der beim Verschlüsseln verwendet wurde.
- Lies zuerst die angegebene Länge, allokiere (Länge + 1) Bytes für das Ergebnis, führe die Umkehr-Transformation für jeden Buchstaben durch (Leerzeichen unverändert) und setze abschließend das Nullterminator-Byte.
