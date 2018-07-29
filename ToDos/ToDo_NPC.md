# The NPC flow chart

What happens when and the result

## A quick draft

Collision detection is player based, so if Player hits NPC the following will happen.

```txt
// Collision Detection
// Player meets NPC

Collision Player/NPC == TRUE
    -> PlayerState = AT_NPC


// Input Control
Key "W" is pressed && PlayerState == AT_NPC
    -> PlayerState = VISIT_NPC


Collision Player/NPC == TRUE && PlayerState == VISIT_NPC:
    switch NPC.state
        case: NONE  
            -> display string hello;
            -> setNPCState(VISITED);
            -> break;

        case: VISITED  
            -> display string again;
            -> if (ITEM dropped)
                -> setNPCState(DONE);
                -> setWorldState(STATE << 1)
            -> break;

        case: DONE
            -> set state of corresponding Item to CONSUMED
            -> break;  

// Collision Detection
// Player verweigert Mission
PlayerState == AT_NPC &&
NPCState == VISITED && 
// passendes Item wurde gefunden
Inventory::List->contains(NPC.EmotionType)::ItemState == FOUND
    // world is getting darker
    // and barriers are spawned
    -> SpawnBarriers(EmotionType)
    -> WorldState << 1
```

## The NPC class

We use a Enum for the NPC states

```cpp
// ENpcState Enumeration

enum ENpcState {
    NONE        = 0,
    VISITED     = 1 << 0,
    DONE        = 1 << 1
};

```

```cpp
// GNpcObject class

class GNPCObject : public CMoveObject
{

public:

GNpcObject(_pos, _size, _pRenderer, _pFileName) : CMoveObject(_pos, _size, _pRenderer, _pFileName) ;

void GNpcObject::IncreaseState()
{
    if( (m_pState & DONE) != DONE)  // State != DONE
        {
            m_pState << 1;
        }
};

void GNpcObject::SetNPCState(ENpcState* _state){m_pstate = _state;}

ENpcState* GNpcObject::GetNPCState(){return m_pstate;}

private:

ENpcState* m_pstate = NONE;
// string or const char*
const char* hello, again, goodbye;
}

```