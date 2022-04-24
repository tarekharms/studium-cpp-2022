# Flow basic

## Verständnisfragen

### 1.  

Eine Iteration spart Zeit, da hier weniger Zeilen geschrieben werden müssen. Zusätzlich lässt eine Iteration eine variable Länge an Anweisungen zu,


### 2.

Eine in einer Funktion gebündelte Anweisungssequenz kann an anderer stelle im Code benutzt werden. Ebenso können Anweisungssequenzen so benannt werden (Name der Funktion) was bei richtiger benennung zu einem besser lesbaren Coe führt.  


### 3.

Für einige Problemstellungen ist eine rekursive Implementierung besser geeignet, da für eine iterative Implementierung das Problem abstrahiert werden muss.


### 4.

Rekursive Implementierungen benötigen mehr speicher und können ggf. sogar den Stack zum überlauf bringen.  


### 5.

Keine mir bekannte. Hatten wir bereits in der Berufsschule. (Prüfung ob durch 3 und 5 teilbar zuerst)


### 6.

Style Guides ermöglichen ein leichteres lesen des Codes. -> Code wird öfter gelesen als er geschrieben wird.


### 7.

Der Programmfluss wird durch Kontrollstrukturen bestimmt und lässt so die "CPU durch das Programm laufen". 


### 8.

#### a. 

 - a: 16, b: 24 -> (a < b) == wahr;loopnum: 1, a: 24, b: 16; r: 24%16=8
 - a = 16
 - b = 8

 - a: 16, b: 8 -> (a < b) == falsch; loopnum: 2, a: 16, b: 8; r: 16%8 = 0;
 - Ausgabe: "exec state 2 : a=16 b=8 r=0"


#### b.

 - a: 23, b: 13 -> (a < b) == falsch; loopnum: 1, a: 23, b: 13; r: 23%13=10
 - a = 13
 - b = 10
 
 - a: 13, b: 10 -> (a < b) == falsch; loopnum: 2, a: 13, b: 10; r: 13%10=3
 - a = 10
 - b = 3

 - a: 10, b: 3 -> (a < b) == falsch; loopnum: 3, a: 10, b: 3; r: 10%3=1
 - a = 3 
 - b = 1

 - Ausgabe: "exec state 3 : a=10 b=3 r=1"



## Fragen und Anmerkungen 

Keine


## Gewonnene Erkenntnisse

Die Tatsache, dass GOTO in C/C++ noch verwendet werden kann.
