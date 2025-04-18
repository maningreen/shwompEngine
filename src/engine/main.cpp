#include "entity.hpp"
#include "root.hpp"
#include <vector>

void manageProcess(Entity* en, float delta) {
  en->process(delta);
  for(int i = 0; i < en->children.size(); i++)
    manageProcess(en->children[i], delta);
  if(!en->getValid())
    en->kill();
}

void init(Entity* root);

void preRendering(Entity* root);

void postRendering(Entity* root);

int main() {
  Root* root = new Root();

  Entity::setRoot(root);

  init(root);

  float delta = 1.0f / 60.0f;
  while(root->getValid()) {

    manageProcess(root, delta);

    preRendering(root);

    root->render();

    postRendering(root);

    root->postRender();
  }
}
