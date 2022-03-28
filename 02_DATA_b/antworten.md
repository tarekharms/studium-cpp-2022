# Data Vars B

## Verständnisfragen

### Vergleichen Sie die beiden Arten, Zeichenketten zu speichern, wie sie von Pascal und C verwendet werden. Welche Vor- und Nachteile existieren jeweils?

Die Nullterminierten C Strings benötigen keine weitere Variable für die Länge des Strings, dafür aber ein zusätzliches Zeichen, die 0, am Ende.  
Nullterminierte Strings sind ebenso anfälliger für Fehler da hier mit Zeigern gearbeitet wird. Um die Länge eines C Strings herauszufinden, muss dieser komplett durchiteriert werden, was ebenso mehr Zeit in anspruch nimmt.  

Bei Pascal Strings wird die Länge zusätzlich abgespeichert und direkt die maximale Länge des Strings im Speicher reserviert. Dadurch verbrauchen Pascal Strings mehr speicher, jedoch lassen sich Operationen effizienter umsetzen.  


### Welches Bitmuster (Zahlendarstellung im 2er-System) ergibt sich am Ende des folgenden Codes?

```
    0000 0000 1000 0000 //128
OR  0000 0000 0110 0000 //64 + 32
  = 0000 0000 1110 0000
XOR 0000 0000 0001 0000 //16
  = 0000 0000 1111 0000
AND 0000 0000 1100 0000 //128+64
  = 0000 0000 1100 0000
<<= 1
  = 0000 0001 1000 0000
```


### Welchen Typ haben die unten angegebenen Ausdrücke?

 - `1` = `int`
 - `1.0` = `double`
 - `"1.0"` = `string`
 - `1 + 1.0` = `double` 
 - `'1'` = `char`  


### Die Funktionen `intToHex(int n)` und `intToDual(int n)` haben im Rumpf viele Gemeinsamkeiten. Zeigen Sie Verbesserungsmöglichkeiten auf. 

Den wert der Basis als Argument der Funktion übergeben:  

```
PascalString intToBaseXString(int n, int base)
{
    PascalString string = {0,{0,}};

    do
    {
        string.characters[string.length] = intToBaseXDigit(zahl % base, base);
        string.length++;
        zahl /= base;
    }
    while(zahl > 0)

    return reversed(string);
}
```


### Wie unterscheiden sich die Werte "1234" und 1234 hinsichtlich der Darstellung im Speicher?

Der Integer Wert 1234 wird als `00 00 04 d2` im Speicher abgelegt, während beim String "1234" die einzelnen Zeichen mit einer Null am Ende aufeinanderfolgend abgelegt werden `31 32 33 34 00 00 00 00`. 


### Warum gibt es so viele verschieden Typen, die Werte ganzer Zahlen aufnehmen können?

Weil die Werte dieser Typen als ganzzahlen im Speicher abgelegt werden. Die Typen unterscheiden sich dann in der Interpretierung.  


### Welche Schritte sind notwendig, um zwei nullterminierte Zeichenketten an einander zu hängen? Geben Sie mindestens zwei der möglichen Antworten.

Die Länge der Zeichenketten bis zur 0 muss bei beiden gezählt und aufaddiert werden. Daraufhin erfolgt die erzeugung eines neuen Strings mit einem einzelnen Nullterminator am Ende.


### Zeigen Sie auf, inwiefern das Piktogram auf der Titelseite dieses Materialpaketes den Inhalt zusammengefasst darstellt.

Das Piktogramm zeigt Daten in unterschiedlichen Darstellungsweisen. Beispielsweise wird die Zahl 9 einmal als `9` und als `IX` gezeigt. Obwohl der Wert hinter diesen beiden Darstellungen gleich ist unterscheiden sich diese je nach Interpretation. Deshalb sind Datentypen wichtig, da das Programm sonst nicht weiß worum es sich bei den Daten handelt. So kann der Wert `85` im Speicher sowohl die Zahl 85 als auch den Buchstaben 'U' darstellen. 


## Fragen und Anmerkungen 

Keine


## Gewonnene Erkenntnisse

Wissen über die genauere Handhabung von Strings und zur Verwendung von Bitweisen Operationen in C/++.
