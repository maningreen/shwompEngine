#include "entity.hpp"
#include "root.hpp"
#include <vector>

void manageProcess(Entity* en, float delta) {
  en->process(delta);
  for(int i = 0; i < en->children.size(); i++) {
    manageProcess(en->children[i], delta);
    if(en->children[i]->getValid() == false)
      en->children.erase(en->children.begin() + i);
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

    manageProcess(root, delta);

    BeginDrawing();

    preRendering(root);

    manageChildrenRendering(&root->children);

    postRendering(root);

    EndDrawing();
  }

  root->kill();
}
