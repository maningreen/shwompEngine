#ifndef root_h
#define root_h

#include "entity.hpp"

class Root : public Entity {
  public:
    Root();
    ~Root();

    static const Vector2 windowDimensions;
    static const std::string windowName;
};

#endif
