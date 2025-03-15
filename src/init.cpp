#include "engine/entity.hpp"
#include "engine/core.h"
#include "example.hpp"

void init(Entity* root) {
  root->addChild(new Example());
}

void preRendering(Entity* root) {
}

void postRendering(Entity* root) {
  DrawFPS(0, 0);
}
