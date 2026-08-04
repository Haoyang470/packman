/**
 * @file Monster.h
 * @brief Represents a Monster entity on the game board.
 */

#ifndef MONSTER_H
#define MONSTER_H

#include "BoardObjectH.h"

/**
 * @class Monster
 * @brief Derived class from BoardObject representing an active hazard/enemy.
 */
class Monster : public BoardObject {
private:
    bool active; ///< Indicates if the monster is active.

public:
    /**
     * @brief Constructs a Monster object at specified board coordinates.
     * @param x Initial row index.
     * @param y Initial column index.
     * @pre x >= 0 && y >= 0.
     * @post A Monster object is created at (x, y) with active set to true.
     */
    Monster(int x, int y);

    /**
     * @brief Destructor for Monster.
     * @pre None.
     * @post Monster object is safely destroyed.
     */
    ~Monster();

    /**
     * @brief Renders the ASCII representation of the Monster.
     * @pre None.
     * @post Prints 'M' to stdout representing the monster.
     */
    void paint();

    /**
     * @brief Checks if the monster is currently active.
     * @pre None.
     * @post Returns the active state without modifying it.
     * @return true if active, false otherwise.
     */
    bool isActive() const;
};

#endif // MONSTER_H
