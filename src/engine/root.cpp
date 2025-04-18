#include "root.hpp"
#include "entity.hpp"
#include <string>

const Vector2 Root::windowDimensions = {600, 800};
const std::string Root::windowName = "gameNameHere";

Root::Root() : Entity("root", nullptr) {
  InitWindow(windowDimensions.x, windowDimensions.y, windowName.c_str());
  SetTargetFPS(60);
}

Root::~Root() {
  CloseWindow();
}

void Root::process(float delta) {
  if(WindowShouldClose())
    killDefered();
  for(Entity* en : children)
    manageChildrenProcesses(en, GetFrameTime());
}

void Root::render() {
  BeginDrawing();
  for(Entity* child : children)
    manageChildrenRendering(child);
}

void Root::postRender() {
  EndDrawing();
}

void Root::manageChildrenRendering(Entity* en) {
  en->render();
  for(int i = 0; i < en->children.size(); i++)
    manageChildrenRendering(en->children[i]);
  en->postRender();
}

void Root::manageChildrenProcesses(Entity* en, float delta) {
  en->process(delta);
  for(int i = 0; i < en->children.size(); i++)
    manageChildrenProcesses(en->children[i], delta);
  if(!en->getValid())
    en->kill();
}
