#include "Monster.h"
#include <iostream>

using namespace std;

Monster::Monster(int x, int y) : BoardObject(x, y), active(true) {}

Monster::~Monster() {}

void Monster::paint() {
    cout << "M";
}

bool Monster::isActive() const {
    return active;
}
