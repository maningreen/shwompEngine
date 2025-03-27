#ifndef entity_hpp
#define entity_hpp

#include "../include.h"
#include <string>
#include <vector>

class Entity {
private:
  Entity *parent;

  static Entity* root;

  bool valid;

public:
  std::string name;
  std::vector<Entity*> children;
  std::vector<std::string> tags;

  Entity(const std::string& name, Entity* parent);
  Entity(const std::string& name);
  virtual ~Entity();

  void addChild(Entity *child);

  void addTag(std::string tag);
  bool removeTag(std::string tag);
  bool hasTag(std::string tag);

  void printAllChildren();

  void kill();
  void killDefered();

  Entity* getParent();

  bool getValid();

  static Entity* getRoot();
  //returns false if failed, true if succeeded
  static bool setRoot(Entity* root);

  virtual void process(float delta) {};
  virtual void render() {};
  virtual void postRender() {};
  virtual void init() {};
  virtual void death() {};
};

class Entity2D : public Entity {
public:
  Vector2 position;

  Entity2D(const std::string& name, Entity* Parent, Vector2 position);
  Entity2D(const std::string& name, Vector2 position);
};

#endif
