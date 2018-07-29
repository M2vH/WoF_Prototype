# The NPC flow chart

What happens when and the result

## A quick draft

Collision detection is player based, so if Player hits NPC the following will happen.

```txt

Collision Player/NPC == TRUE:
    switch NPC.state
        case: NONE  
            -> display string hello;
            -> setNPCState(VISITED)

        case: VISITED  
            -> display string again;
            -> if (ITEM dropped)
                -> setNPCState(DONE);
                -> setWorldState(STATE << 1)

        case: DONE
            -> break;  

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