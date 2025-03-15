#include "engine/entity.hpp"
#include "engine/core.h"
#include "example.hpp"

void Init(Entity* root) {
  root->addChild(new Example());
}

void PreRendering(std::vector<Entity*>* entities) {
}

void PostRendering(std::vector<Entity*>* entities) {
  DrawFPS(0, 0);
}
