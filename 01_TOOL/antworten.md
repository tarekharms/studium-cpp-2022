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

 
