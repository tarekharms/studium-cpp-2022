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


### Wie unterscheiden sich die Werte "1234" und 1234 hinsichtlich der Darstellung im Speicher?


### Warum gibt es so viele verschieden Typen, die Werte ganzer Zahlen aufnehmen können?


### Welche Schritte sind notwendig, um zwei nullterminierte Zeichenketten an einander zu hängen? Geben Sie mindestens zwei der möglichen Antworten.


### Zeigen Sie auf, inwiefern das Piktogram auf der Titelseite dieses Materialpaketes den Inhalt zusammengefasst darstellt.
