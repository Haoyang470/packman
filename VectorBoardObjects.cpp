#include <iostream>
#include "BoardObjectH.h"
#include "CookieH.h"
#include "VectorBoardObjects.h"

VectorBoardObjects::VectorBoardObjects() {
    count = 0;
    internalCursor = 0;
    for (int i = 0; i < MAX_OBJECTS; i++) {
        collection[i] = NULL;
    }
}

VectorBoardObjects::VectorBoardObjects(p_BoardObject newOne) {
    count = 0;
    internalCursor = 0;
    for (int i = 0; i < MAX_OBJECTS; i++) {
        collection[i] = NULL;
    }
    addOne(newOne);
}

VectorBoardObjects::~VectorBoardObjects() {}

p_BoardObject VectorBoardObjects::theFirst() {
    if (count > 0) {
        internalCursor = 0;
        return collection[0];
    }
    return NULL;
}

p_BoardObject VectorBoardObjects::theNext() {
    internalCursor++;
    if (internalCursor < count) {
        return collection[internalCursor];
    }
    return NULL;
}

void VectorBoardObjects::addOne(p_BoardObject newOne) {
    if (count < MAX_OBJECTS) {
        for (int i = count; i > 0; i--) {
            collection[i] = collection[i - 1];
        }
        collection[0] = newOne;
        count++;
    }
}

void VectorBoardObjects::removeOnePlayer() {
    for (int i = 0; i < count; i++) {
        if (collection[i] != NULL && collection[i]->get_Type() == A_PLAYER) {
            for (int j = i; j < count - 1; j++) {
                collection[j] = collection[j + 1];
            }
            collection[count - 1] = NULL;
            count--;
            return;
        }
    }
}

bool VectorBoardObjects::isThereAWall() {
    for (int i = 0; i < count; i++) {
        if (collection[i] != NULL && collection[i]->get_Type() == A_WALL) {
            return true;
        }
    }
    return false;
}

int VectorBoardObjects::isCookieValue() {
    int temp = 0;
    for (int i = 0; i < count; i++) {
        if (collection[i] != NULL && collection[i]->get_Type() == A_COOKIE) {
            temp = ((Cookie *)collection[i])->get_value();
            for (int j = i; j < count - 1; j++) {
                collection[j] = collection[j + 1];
            }
            collection[count - 1] = NULL;
            count--;
            return temp;
        }
    }
    return temp;
}
