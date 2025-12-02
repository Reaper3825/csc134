#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Vec2 {
    int x;
    int y;
};

enum Direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3,
    NUM_DIRECTIONS = 4
};

const string DIRECTION_NAMES[NUM_DIRECTIONS] = {
    "north", "east", "south", "west"
};
// Define constants for rooms
enum RoomType {
    ENTRANCE_HALL = 0,
    LIBRARY = 1,
    KITCHEN = 2,
    GARDEN = 3,
    BASEMENT = 4,
    NUM_ROOMS = 5
};

struct passage {
    string from;
    string to;
    Direction dir;

};

struct RoomInfo {
    string name;
    string description;
    RoomType type;
    Vec2 location;
    Vec2 size;
    bool hasItem;
};


class Room { 
    public:
    
        RoomInfo info; 
        Room(RoomInfo info) {
        this->info = info;}
        ~Room(){}
        


};

class pawn {
    public:
        string name;
        Room currentRoom;
        vector<string> inventory;
        Vec2 location;

};


vector<Room> rooms;


void initializeGrid(Vec2 gridSize);
void initializePawn();
void initializeRooms();
void enterRoom();
void displayRoomInfo(const Room& room);
void moveToRoom(int& currentRoom, Direction dir);
Direction parseDirection(const Vec2& from, const Vec2& to);