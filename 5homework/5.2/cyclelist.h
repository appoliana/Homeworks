#pragma once

struct cycleList;

cycleList* createList();

void createCircle(cycleList *first, int amount);

int stayAlive(cycleList *first, int amount, int period);

cycleList* last(cycleList *first);