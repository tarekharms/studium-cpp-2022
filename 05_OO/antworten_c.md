# OO-CYCL

## Verständnisfragen

### 1.  

Erst die Basis und danach die erbenden Klassen.  


### 2.

Erst die erbende Klasse und dann hoch zur Basis.  


### 3.

In der Member initializer List werden die Member direkt initialisiert.  


### 4.

In der Base initializer List werden die Basis Konstruktoren aufgerufen.  


### 5.

Ja, da sonst nur der Destruktor des bekannten Typs aufgerufen wird.  


### 6.

Ja, wenn diese in der Initializer List angegeben sind.  


### 7.

Der Speicher für das Objekt wirt alloziiert.  


### 8.

Weil der Heap Speicher zur Laufzeit fragmentiert und somit die freien Speicherbereiche nicht bekannt sind.  


### 9.

```
class Derived {
    int b;

public:  
    Derived(int aa, int bb) : Base (aa)
    {
        b = bb;
    }
};
```


## Fragen und Anmerkungen 

Keine


## Gewonnene Erkenntnisse

Reihenfolge des Aufrufs der Konstruktoren und Destruktoren.  
Vergeben von initialen Werten für Member (In keiner anderen mir bekannten Programmiersprache so gehandhabt).  

