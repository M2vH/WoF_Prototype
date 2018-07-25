# ToDo Inventory

Wir brauchen ein Inventar.  

Wir erstellen im Game eine Inventarklasse, die die Funktionalität des Invenatrs abbildet, und fügen sie der UI-Liste hinzu.

Frage: Werden Objecte in der UI-Liste im Screenspace angezeigt?

Wenn nein, dann erstellen wir in der Engine ein eigene UI-Klasse, die die Position errechnet.
Die Inventarklasse erbt dann von unserer UI-Klasse.

Wenn ja, dann wird die Position relativ zur Kamera berechnet. Wir erben von MoveObject/TexturedObject.

## In der Engine eine eigene UI-Klasse anlegen.

Wir erstellen eine CUIObject Klasse;  
Erbt von TexturedObject;

primitive variable:  
SVector2 m_offset;

#### override function

##### Überschreibt Update()

    Testen, ob Eltern
    ja:     Position Eltern - offset
    nein:   Position Kamera - offset

##### Überschreibt Render()

#### inline function

Berechnet Position relativ  
!! Wir brauchen GetCameraPosition in CRenderer

### Im Game

Wir erstellen eine GInventory Klasse

GInventory erbt von MoveObject || CUIObject;

TexturedObject ist Hintergrundgrafik

Hat 3 Member vom Typ TexturedObject || CUIObject;

Hat eine Liste InventarList;

Inventar hat Position relativ zum Parent object;

#### Überschreibt Update()

Update() der Elternklasse

Abfragen der Zifferntasten:

    Löschen von Object an Position aus Liste

#### Überschreiben der Render()

Rendert den Hintergrund;

Rendert die Objecte der Liste auf den Hintergrund;

```cpp
// CInventory.h

list <CObject*> Icons;

```
