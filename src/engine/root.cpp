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
}

void Root::render() {
  BeginDrawing();
}

void Root::postRender() {
  EndDrawing();
}
