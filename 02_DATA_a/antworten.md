# Data Vars A

## Verständnisfragen

### Was sind die Unterschiede und Gemeinsamkeiten zwischen den beiden Variablen `int i`, wovon eine in `main()` und eine in `polynom1()` enthalten ist?

Beides sind lokale Variablen welche im jeweiligen Geltungsbereich verwendet werden können. Der Unterschied zwischen den beiden ist der Gültigkeitsbereich.


### Welche Ausgabe erzeugt dieser Code?

0


### Welches `i` wird geändert?

Die lokale Variable `i` innerhalb der Funktion `foo()`.


### (Level C) Wie können Sie obigen Code ändern, so dass das andere `i` geändert wird?

Der Code folgenderweise verändert werden:  

```
#include "println.hpp"


void foo(int* i)
{
    *i = *i + 1;
}

int main()
{
    int i = 7;
    int* iPointer = &i;

    foo(iPointer);

    return 0;
}
```

Verwendung eines Pointers welcher auf die Speicheradresse der Variable `i` zeigt.

### Zeigen Sie auf, inwiefern das Piktogram auf der Titelseite dieses Materialpaketes den Inhalt zusammengefasst darstellt.

Das Schild stellt eine Variable dar, da der hier angezeigte Wert durch Austauschen der Karten geändert werden kann.


## Fragen

Die Level C Verständnisfrage wurde nun direkt mit Pointern gelöst. Wäre dies auch mit der einfachen verwendung der Referenz mit `&` möglich gewesen?


## Anmerkungen

Keine

## Wesentliche gewonnene Erkenntnisse

Variablen und Datentypen waren bereits aus Java bekannt.
Unterschied zwischen "Call By Value" und "Call By Reference" war ebenso aufgrund von vorwissen bekannt.
