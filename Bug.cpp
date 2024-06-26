#include "Bug.h"

Bug::Bug(int id, int x, int y, int direction, int size) // constructor
{
    this->id = id;
    this->position.first = x;
    this->position.second = y;
    this->direction = direction;
    this->size = size;
    this->alive = true;
    this->path.push_back(position);
    this->eatenBy = 0;
}

bool Bug::isWayBlocked(){ // check if they are facing the edge they are on
    if(direction == 1 && position.second == 0){
        return true;
    }
    else if(direction == 2 && position.first == 9){
        return true;
    }
    else if(direction == 3 && position.second == 9){
        return true;
    }
    else if(direction == 4 && position.first == 0){
        return true;
    }
    else{
        return false;
    }
}

string Bug::getType() const{
    return type;
}
void Bug::setType(string type){
    Bug::type = type;
}

int Bug::getId() const{
    return id;
}
void Bug::setId(int id){
    Bug::id = id;
}

pair<int, int> Bug::getPosition() const{
    return position;
}
void Bug::setPosition(pair<int, int> position){
    Bug::position = position;
}

int Bug::getDirection() const{
    return direction;
}
void Bug::setDirection(int direction){
    Bug::direction = direction;
}

int Bug::getSize() const{
    return size;
}
void Bug::setSize(int size){
    Bug::size = size;
}

bool Bug::getAlive() const{
    return alive;
}
void Bug::setAlive(bool alive){
    Bug::alive = alive;
}

list<pair<int,int>> Bug::getPath() const{
    return path;
}
void Bug::setPath(list<pair<int,int>> path){
    Bug::path = path;
}

int Bug::getEatenBy() const{
    return eatenBy;
}
void Bug::setEatenBy(int eatenBy){
    Bug::eatenBy = eatenBy;
}

string Bug::toString(){ // print all the details about the bug
    string dir;
    switch(direction) {
        case 1: dir = "North"; break;
        case 2: dir = "East"; break;
        case 3: dir = "South"; break;
        case 4: dir = "West"; break;
        default: break; // default
    }
    string live = "Alive!";
    if(!alive){live = "Dead!";}

    string str = type + to_string(id) + "\t<" + to_string(position.first) + "," + to_string(position.second)
                 + ">\t\t" + dir + "\t\t" + to_string(size) + "\t\t" + live + "\t\tN/A";
    return str;
}

string Bug::historyToString(){ // print the bugs history and current status, (alive, or who it was eaten by)
    string live = "Alive!";
    if(!alive){live = "Eaten by " + to_string(eatenBy);}

    string str = type + to_string(id) + "\t[";
    for(pair<int, int> pos : path){
        str += "<" + to_string(pos.first) + "," + to_string(pos.second) + ">,";
    }
    str += live + "]";
    return str;
}

Bug::~Bug() { cout << "~Bug() destructor called.\n"; }