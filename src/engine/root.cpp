#include "root.hpp"
#include "entity.hpp"
#include <string>

const Vector2 Root::windowDimensions = {600, 800};
const std::string Root::windowName = "gameNameHere";

Root::Root() : Entity("root", nullptr) {
  InitWindow(windowDimensions.x, windowDimensions.y, windowName.c_str());
}

Root::~Root() {
  CloseWindow();
}
