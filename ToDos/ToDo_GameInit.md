# the New Game.Init()

Changes in the `game.cpp`  
Find the file quickly [here](https://github.com/M2vH/WoF_Prototype/blob/3a8835680c307ec0be500228d7593f5e1e9e993d/Project/WorldOfFacades/Game.cpp).  
To jump directly to the changed section of the file, use [this link](https://github.com/M2vH/WoF_Prototype/blob/3a8835680c307ec0be500228d7593f5e1e9e993d/Project/WorldOfFacades/Game.cpp#L26-L27).

```cpp
game.init()
{
/*
 *   hier steht alles aus MainScene.Init
 *   Scene und persistant objekte in WorldStatus
 *   MainSceneObjectList und
 *   MainPersistantList
 *
 *   hier steht alles aus HouseScene init;
 *   Scene und persistant objekte in WorldStatus
 *   HouseSceneObjectList und
 *   HousePersistantList
 *
 *   UI in ContentmanagerList;
 *   Player in Contentmanager Player List;
 *
 *   GMainScene* aMainScene = new GMainScene();
 *   init houseScene
 *  
 *   create player;
 *   put into PlayerList in contentmanager
 *
 *   finally
 *    -> call Engine->changeScene(new MainScene())
*/

}
```

changes in `mainscene.cpp`

```cpp
init(){
/*
    clear contentmanager
        scene List
        persistant List

    copy mainscene worldstatus
        into contentmanager scene

    copy worldstatus persistant
        into contentmanager persistant

    get pointer to player with dynamic cast on front layer list;
        set value isNotInHouse;
*/
}

clean(){
    /*
    copy contentmanager list 
    into worldstatus list;
        - scene objects
        - persistant objects
    */
}

```

changes in `housescene.cpp`

```cpp
init(){
/*
    clear contentmanager
        scene List
        persistant List
    copy worldstatus scene
        into contentmanager scene
    copy worldstatus persistant
        into contentmanager persistant
    get pointer to player with dynamic cast on front layer list;
        set value isNotInHouse;
*/
}

clean(){
    // copy contentmanager into worldstatus;
}
```

changes in `engine.cpp`

```cpp
changeScene(CScene _scene){
    // clear old
}

clean(){
    game.clean()
    delete game;
}
```

changes in `game.cpp`

```cpp
clean(){
    // clean up WorldStatus;
}
``

