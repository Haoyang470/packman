/**
 * @file VectorBoardObjects.h
 * @brief Class managing a fixed-capacity collection of BoardObjects for a single board cell.
 * 
 * Provides an array-based or vector-like storage mechanism for board entities (e.g., Players,
 * Walls, Cookies), replacing the previous linked-list implementation while maintaining identical API contracts.
 */

#ifndef VECTORBOARDOBJECTSH_H
#define VECTORBOARDOBJECTSH_H

#include "BoardObjectH.h"

typedef BoardObject* p_BoardObject;
const int MAX_OBJECTS = 4;

/**
 * @class VectorBoardObjects
 * @brief Manages up to MAX_OBJECTS BoardObject pointers.
 */
class VectorBoardObjects {
private:
    p_BoardObject collection[MAX_OBJECTS]; ///< Array storing pointers to board objects.
    int count;                             ///< Current number of stored objects.
    int internalCursor;                    ///< Traversal cursor for internal iteration.

public:
    /**
     * @brief Constructs a VectorBoardObjects container pre-populated with a initial object.
     * @param newOne Pointer to the initial BoardObject to add.
     * @pre newOne != nullptr (The provided object pointer must be valid).
     * @post count == 1, collection[0] == newOne, and internalCursor is set to 0.
     */
    VectorBoardObjects(p_BoardObject newOne);

    /**
     * @brief Default constructor for an empty container.
     * @pre None.
     * @post count == 0 and internalCursor is set to 0.
     */
    VectorBoardObjects();

    /**
     * @brief Destructor. Cleans up dynamically allocated memory if owned.
     * @pre None.
     * @post All object slots cleared and container memory released.
     */
    ~VectorBoardObjects();

    /**
     * @brief Retrieves the first object in the collection and resets the internal cursor.
     * @pre None.
     * @post If count > 0, returns collection[0] and sets internalCursor to 1. Otherwise returns nullptr.
     * @return Pointer to the first BoardObject, or nullptr if the collection is empty.
     */
    p_BoardObject theFirst();

    /**
     * @brief Retrieves the next object in the collection based on the internal cursor.
     * @pre theFirst() should be called prior to iterating, or internalCursor must be within [0, count].
     * @post If internalCursor < count, returns collection[internalCursor] and increments internalCursor by 1. Otherwise returns nullptr.
     * @return Pointer to the next BoardObject, or nullptr if no more objects exist.
     */
    p_BoardObject theNext();

    /**
     * @brief Adds a new BoardObject to the top/front of the collection.
     * @param newOne Pointer to the BoardObject to add.
     * @pre count < MAX_OBJECTS and newOne != nullptr.
     * @post Objects are shifted right; newOne is placed at collection[0], and count is incremented by 1.
     */
    void addOne(p_BoardObject newOne);

    /**
     * @brief Removes the Player object from the container if present.
     * @pre None.
     * @post If a Player object existed in collection, it is removed, remaining objects are shifted, and count is decremented by 1.
     */
    void removeOnePlayer();

    /**
     * @brief Checks if any object in the collection is a wall.
     * @pre None.
     * @post The state of the collection remains unchanged.
     * @return true if a Wall object exists in collection, false otherwise.
     */
    bool isThereAWall();

    /**
     * @brief Checks for a Cookie object and returns its point value.
     * @pre None.
     * @post The state of the collection remains unchanged.
     * @return Integer value of the Cookie if present; 0 otherwise.
     */
    int isCookieValue();
};

#endif // VECTORBOARDOBJECTSH_H
