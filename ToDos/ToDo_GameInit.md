# the New Game.Init()

Changes in the `game.cpp`

```cpp
game.init()
{
/*
 *   hier steht alles aus MainScene.Init
 *   Scene und persistant objekte in WorldStatus
 *   MainSceneObjectList und
 *   MainPersistantList

 *   hier steht alles aus HouseScene init;
 *   Scene und persistant objekte in WorldStatus
 *   HouseSceneObjectList und
 *   HousePersistantList
 *   UI in ContentmanagerList;
 *   Player in Contrenmanager Player List;
 *   GMainScene* aMainScene = new GMainScene();
 *   init houseScene
 
 *   create player;
 *   put into PlayerList in contenmanager
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

        get pointer to player with dynamic cast on front of player list;
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

