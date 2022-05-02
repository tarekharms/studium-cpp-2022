# OO-ENTVAL

## Verständnisfragen

### 1.  

Temperatur: Werttyp, da keine Vererbung.  
Wissenschaftlicher Artikel: Objecttyp falls dieser von Artikel erben könnte.  
Farbton: Werttyp, da keine Vererbung, es sei denn Farbton wäre eine Elternklasse und würde beispielsweise an "RGB" oder "CMYK" erben.   
Elektronisches Bauteil: Objekttyp da es sehr generisch ist eine Elternklasse von "Diode", "Widerstand", "Transistor" usw. darstellen könnte.  

### 2.

Die Äquivalenz wird bei Werttypen mit dem Operator `==` geprüft, bei Objekttypen über die `.equals()` Methode.  

### 3.

Das prüfen der Identität ist bei Werttypen nebensächtlich, bei Objekttypen können die in den Zeigern gespeicherten Adressen mit `==` verglichen werden.  

### 4.

"is-a" bedeutet, dass ein bestimmtes Objekt auch vom Typ seiner Elternklasse ist. "Ein Auto ist ein Fahrzeug".  
"has-a" bedeutet, dass ein bestimmtes Objekt ein anderes Objekt besitzt. "Ein Auto bestitzt einen Motor".  
Der Unterschied wäre dementsprechend, dass ein Auto zwar ein Fahrzeug ist, aber ein Fahrzeug kein Auto besitzt. Ein Auto besitzt wiedderum einen Motor, aber ein Motor ist kein Objekt des Typs Auto.  

### 5.

`is-a` Auto erbt von Fahrzeug: `class Auto : Fahrzeug`.  
`has-a` und `consists of` Ein Auto besitzt einen Motor: `class Auto { protected: Motor _motor };` und Löschen des Motors bei Löschen des Autos: `Auto::~Auto() { delete _motor}`  
`knows` Ein Auto "besitzt" Passagiere, die Passagiere existieren aber unabhängig vom Auto: `class Auto { protected: Passagiere _passagiere };`. Die Passagiere werden nicht gelöscht wennd das Auto gelöscht wird.  

### 6.

Bei einer Aggregation kann das Teil auch unabhängig vom Ganzen existieren, bei einer Komposition widerrum nicht.  
Bei der Komposition wird beim Löschen des Ganzen auch der destruktor des Teils aufgerufen. Bei einer Aggregation nicht.  


## Fragen und Anmerkungen 

Keine


## Gewonnene Erkenntnisse

Genauere Unterschiede und Use-Cases von Werttypen und Objekttypen.   
