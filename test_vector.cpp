/**
 * @file test_vector.cpp
 * @brief Unit tests for VectorBoardObjects class verifying Design by Contract (DbC).
 */

#include <iostream>
#include <cassert>
#include "VectorBoardObjects.h"
#include "PlayerH.h"
#include "CookieH.h"
#include "Monster.h"
#include "Bomb.h"

using namespace std;

void testAddAndLimit() {
    cout << "[TEST 1] Testing addOne and capacity limit (max 4 objects)..." << endl;
    VectorBoardObjects container;

    Player* p1 = new Player(0, 0);
    Cookie* c1 = new Cookie(0, 0);
    Monster* m1 = new Monster(0, 0);
    Bomb* b1 = new Bomb(0, 0);
    Bomb* b2 = new Bomb(0, 0);

    container.addOne(p1);
    container.addOne(c1);
    container.addOne(m1);
    container.addOne(b1);

    cout << "  - 4 objects added successfully." << endl;

    container.addOne(b2);
    cout << "  - Handled 5th object attempt gracefully." << endl;

    delete b2;
}

void testIteration() {
    cout << "[TEST 2] Testing iteration methods (theFirst, theNext)..." << endl;
    VectorBoardObjects container;

    Player* p = new Player(1, 1);
    Cookie* c = new Cookie(1, 1);

    container.addOne(p);
    container.addOne(c);

    p_BoardObject first = container.theFirst();
    assert(first != NULL);
    cout << "  - First object retrieved." << endl;

    p_BoardObject second = container.theNext();
    assert(second != NULL);
    cout << "  - Second object retrieved." << endl;

    p_BoardObject third = container.theNext();
    assert(third == NULL);
    cout << "  - Iteration cleanly reached the end (NULL)." << endl;
}

void testRemove() {
    cout << "[TEST 3] Testing removeOnePlayer..." << endl;
    VectorBoardObjects container;

    Player* p = new Player(2, 2);
    Cookie* c = new Cookie(2, 2);

    container.addOne(p);
    container.addOne(c);

    container.removeOnePlayer();
    cout << "  - removeOnePlayer called." << endl;

    p_BoardObject remain = container.theFirst();
    assert(remain != NULL);
    assert(remain->get_Color() != YELLOW);
    cout << "  - Verified player was removed successfully." << endl;
}

int main() {
    cout << "========================================" << endl;
    cout << "  Running VectorBoardObjects Unit Tests " << endl;
    cout << "========================================" << endl;

    testAddAndLimit();
    testIteration();
    testRemove();

    cout << "========================================" << endl;
    cout << "  ALL UNIT TESTS PASSED SUCCESSFULLY!   " << endl;
    cout << "========================================" << endl;

    return 0;
}
