#include "BTT.h"

bool BTTNodeComp::operator()(const BTTNode* a, const BTTNode* b) {
    return a->priority < b->priority;
}