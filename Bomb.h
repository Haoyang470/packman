/**
 * @file Bomb.h
 * @brief Represents a Bomb entity on the game board.
 */

#ifndef BOMB_H
#define BOMB_H

#include "BoardObjectH.h"

/**
 * @class Bomb
 * @brief Derived class from BoardObject representing an explosive item.
 */
class Bomb : public BoardObject {
private:
    int damage; ///< Damage value of the bomb.

public:
    /**
     * @brief Constructs a Bomb object at specified board coordinates.
     * @param x Initial row index.
     * @param y Initial column index.
     * @param dmg Damage value dealt by the bomb (defaults to 10).
     * @pre x >= 0 && y >= 0 && dmg > 0.
     * @post A Bomb object is created at (x, y) with specified damage.
     */
    Bomb(int x, int y, int dmg = 10);

    /**
     * @brief Destructor for Bomb.
     * @pre None.
     * @post Bomb object is safely destroyed.
     */
    ~Bomb();

    /**
     * @brief Renders the ASCII representation of the Bomb.
     * @pre None.
     * @post Prints 'B' to stdout representing the bomb.
     */
    void paint();

    /**
     * @brief Gets the damage value of the bomb.
     * @pre None.
     * @post Returns damage value without modifying object state.
     * @return Integer representing damage.
     */
    int getDamage() const;
};

#endif // BOMB_H
