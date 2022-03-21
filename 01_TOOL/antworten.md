# Verständnisfragen

## 1. Schreibe Sie kurze Glossar-Enträge für alle an der Übersetzung/Erstellung eines Programms beteiligetn Komponenten bzw. Phasen

 - Präprozessor: Verarbeitung der Präprozessortanweisungen welche mit '#' gekennzeichnet werden. Entfernen der Kommentare `clang -o <output> -E <input>`
 - Compiler: Übersetzen des vom Präprozessor erstellten Quellcodes in Assemblersprache. `clang -S <input>`
 - Assembler: Übersetzen des Assembler Codes in Maschindencode (Objekt Datei) `clang -c <input>`
 - Linker: Zusammenfügen der einzelnen Objekt Dateien des Programms.


## 2. Ist es möglich, von einer Quelldatei aus eine Funktion aufzurufen, welche in einer anderen Quelldatei definiert ist? Begründung!

Ja, hierzu muss aber die Datei welche die Definition der Funktion enthält über die Präprozessoranweisung `#include` eingebunden werden.  


## 3. Welche aufgaben übernimmt der Compiler?  

Der Compiler übersetzt den Quelltext in Assembler Code. Hierbei werden unter anderem auch Syntaxfehler und Typfehler "geprüft" (Bei Fehlern schlägt das Kompilieren fehl).


## 4. Was ist der Unterschied zwischen einer ausführbaren Datei und einer Objektdatei?

Die ausführbare Datei beinhaltet die Funktionen welche beim Starten und Beenden des Programms benötigt werden. Die Objektdatei beinhaltet nur den kompilierten Quellcode.


## 5. Was ist der Unterschied zwischen einer Bibliotheksdatei (.a) und einer ausführbaren Datei (z.B a.out)?  

Die Bibliotheksdatei beinhaltet keine `main()` Funktion und somit keinen Programmeinstieg.


## 6. Welche Art von Fehler von welchem Wekzeug ergibt sich, wenn `#include "polynom1.h"` in `main.c` vorhanden ist und `int polynom1(int)` in `polynom1.h` deklariert ist, aber `polynom1.c` keine Defininition zu dieser Deklaration enthält?  

Der Linker stößt auf den Fehler `undefined reference`.


## 7. Nehmen Sie an, ein Programm `a.out` besteht aus den Dateien `main.c`, `f.h` und `f.c`. Geben Sie am, welche Werkzeuge vom Compiler Driver aufgerufen werden, wenn Sie die folgenden Optionen angeben: 

 - `clang main.c f.c` 
 - `clang main.o f.o` 

`clang main.c f.c` führt den Präprozessor, Compiler, Assembler und den Linker aus.
`clang main.o f.o` führt den Linker aus.


## 8. Welche Teiler der Toolchain sind beteiligt bei clang -c main.c und welche Datei entsteht?

`clang -c main.c` führt den Präprozessor, Compiler und Assembler aus. Erstellt wird eine Objekt Datei.


## 9. Zeigen Sie auf, inwiefern das Piktogram auf der Titelseite dieses Materialpaketes den Inhalt zusammengefasst darstellt.

Das Piktogramm zeigt einen Werkzeugkasten und Abbildungen von den darin enthaltenen Werkzeugen. Ebenso zeigt uns dieses Materialpaket den Gesamten Werkzeugkoffer, also den Compiler Driver Clang und die darin enthaltenen Werkzeuge: Präprozessor, Compiler, Assembler und Linker. 


## 10. Level C

 - Es gibt eine Warnung weil die nicht definierte Funktion `twice(double)` in der `main.c` verwendet wird. Der Compiler clang scheint dieses Problem durch die Angabe der benötigten Datei `twice.c` in der die Funktion definiert ist zu lösen und gibt nur eine Warnung anstatt eines Fehlers zurück. 

 - Durch die angabe der Deklaration direkt innerhalb der Main oder mithilfe einer Header Datei.

 - Durch die Erstellung einer Header Datei welche von der Quelltext Datei selbst inkludiert wird.

 - Ausgabe von diff:

```
< main.o:     file format elf64-x86-64
---
> main_.o:     file format elf64-x86-64
14,15c14
<   19: 8b 7d f8                mov    -0x8(%rbp),%edi
<   1c: b0 00                   mov    $0x0,%al
---
>   19: f2 0f 2a 45 f8          cvtsi2sdl -0x8(%rbp),%xmm0
18,29c17,28
<   26: 48 bf 00 00 00 00 00    movabs $0x0,%rdi
<   2d: 00 00 00
<   30: 8b 75 f4                mov    -0xc(%rbp),%esi
<   33: 89 c2                   mov    %eax,%edx
<   35: b0 00                   mov    $0x0,%al
<   37: e8 00 00 00 00          callq  3c <main+0x3c>
<   3c: 31 c9                   xor    %ecx,%ecx
<   3e: 89 45 f0                mov    %eax,-0x10(%rbp)
<   41: 89 c8                   mov    %ecx,%eax
<   43: 48 83 c4 10             add    $0x10,%rsp
<   47: 5d                      pop    %rbp
<   48: c3                      retq
---
>   26: f2 0f 2c d0             cvttsd2si %xmm0,%edx
>   2a: 48 bf 00 00 00 00 00    movabs $0x0,%rdi
>   31: 00 00 00
>   34: 8b 75 f4                mov    -0xc(%rbp),%esi
>   37: b0 00                   mov    $0x0,%al
>   39: e8 00 00 00 00          callq  3e <main+0x3e>
>   3e: 31 c9                   xor    %ecx,%ecx
>   40: 89 45 f0                mov    %eax,-0x10(%rbp)
>   43: 89 c8                   mov    %ecx,%eax
>   45: 48 83 c4 10             add    $0x10,%rsp
>   49: 5d                      pop    %rbp
>   4a: c3                      retq
```


# Fragen

# Anmerkungen

In der PDF Datei taucht noch ein `TODO` auf

# Gewonnene Erkenntnisse

Trotz bereits vorhandenen Wissen über Compiler und des grundlegenden Prinzips von Kompilierten Programmiersprachen waren beispielsweise die Arbeitsweise des Präprozessors sowie der Zwischenschritt in Assemblercode neu für mich.

Mit diesem Arbeitspaket habe ich auch eine tiefere Einsicht in die Arbeitsweise des Linkers und den Unterschied zwischen Objektdateien und ausführbaren Dateien gewonnen.
