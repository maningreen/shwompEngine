#include "entity.hpp"
#include "root.hpp"
#include <vector>

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
  Root* root = new Root();

  Entity::setRoot(root);

  SetTargetFPS(60);

  init(root);

  float delta = 1.0f / 60.0f;
  while(!WindowShouldClose()) {

    manageChildrenProcess(&root->children, delta);

    BeginDrawing();

    preRendering(root);

    manageChildrenRendering(&root->children);

    postRendering(root);

    EndDrawing();
  }

  root->kill();
}
