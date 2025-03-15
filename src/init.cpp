#include "engine/entity.hpp"
#include "engine/core.h"
#include "example.hpp"

void init(Entity* root) {
  root->addChild(new Example());
}

void preRendering(std::vector<Entity*>* entities) {
}

void postRendering(std::vector<Entity*>* entities) {
  DrawFPS(0, 0);
}
