#include "entity.hpp"
#include "core.h"
#include "../include.h"
#include <vector>
#include <iostream>

#define baseScreenScalar 1000
#define initialScreenDimensions (Vector2){baseScreenScalar * 16/9, baseScreenScalar / (16 / 9)}

void manageChildrenProcess(std::vector<Entity*>* children, float delta) {
  for(int i = 0; i < children->size(); i++) {
    (*children)[i]->process(delta);
    manageChildrenProcess(&(*children)[i]->children, delta);
    if(!(*children)[i]->getValid()) {
      (*children)[i]->kill();
      children->erase(children->begin() + i);
      i--;
      continue;
    }
  }
}

void manageChildrenRendering(std::vector<Entity*>* children) {
  for(Entity* child : *children) {
    manageChildrenRendering(&child->children);
    child->render();
  }
}

void init(Entity* root);

void preRendering(Entity* root);

void postRendering(Entity* root);

int main() {
  Entity* Root = new Entity("Root", 0);

  Entity::setRoot(Root);

  SetTargetFPS(60);

  InitWindow(initialScreenDimensions.x, initialScreenDimensions.y, "Game :)");

  init(Root);

  float delta = 1.0f / 60.0f;
  while(!WindowShouldClose()) {

    manageChildrenProcess(&Root->children, delta);

    BeginDrawing();

    preRendering(Root);

    manageChildrenRendering(&Root->children);

    postRendering(Root);

    EndDrawing();
  }

  Root->kill();

  CloseWindow();
}
