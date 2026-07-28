#include "Bomb.h"
#include <iostream>

using namespace std;

Bomb::Bomb(int x, int y, int dmg) : BoardObject(x, y), damage(dmg) {}

Bomb::~Bomb() {}

void Bomb::paint() {
    cout << "B";
}

int Bomb::getDamage() const {
    return damage;
}
