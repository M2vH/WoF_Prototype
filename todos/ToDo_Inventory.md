# ToDo List

## Inventar

### In der Engine

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

GInventory erbt von CUIObject;

TexturedObject ist Hintergrundgrafik

Hat 3 Member vom Typ CUIObject;

Hat eine Liste InventarList\<CUIObject>;

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
