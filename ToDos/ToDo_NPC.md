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