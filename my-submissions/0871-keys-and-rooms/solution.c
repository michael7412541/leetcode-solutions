bool checkroom(int** rooms, int room, int *roomsSize, int* map) {
    if(map[room] == 0)
        return false;
    for(int k = 0; k < roomsSize[room]; k++) {
        if( map[rooms[room][k]] == 0){ //沒有去過才需要去
            map[rooms[room][k]] = 1;
            checkroom(rooms, rooms[room][k], roomsSize, map);
        }
    }
    return true;
    
}
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int *map = (int*)calloc(roomsSize, sizeof(int));
    map[0] = 1;
    int i = 0, j = 0;
    bool answer;
    checkroom(rooms, 0, roomsColSize, map);
    for(i = 0; i < roomsSize; i++) {
        if(map[i] == 0)
            return false;
    }
    /*for(i = 0; i < roomsSize; i++) {
        answer = checkroom(rooms, i, roomsColSize, map);
        if(answer == false)
            return false;
    }*/
    
    return true;
}
