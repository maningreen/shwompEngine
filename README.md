# The shwompEngine

The shwompEngine is a minimal game engine built off of raylib designed to let you program without worry*.

\* unless you're the problem.

# Getting started

Clone the repository with either `git clone https://github.com/maningreen/shwompEngine` or get started with nix flakes TODO: figure out this remotely...

The file structure is as follows
```
├── external
│   └── raylib-5.5
│       ├── libraylib.a
│       ├── raylib.h
│       └── raymath.h
├── flake.lock
├── flake.nix
├── LICENSE
├── Makefile
├── README.md
└── src
    ├── engine
    │   ├── core.cpp
    │   ├── core.h
    │   ├── entity.cpp
    │   ├── entity.hpp
    │   └── main.cpp
    ├── example.cpp
    ├── example.hpp
    ├── include.h
    └── init.cpp
```

It's suggested you take a gander at everything in src/ and if you want what's in src/engine/. init.cpp (you don't have to name it that if you wish) must contain three functions. 
* init(Entity* root)
* preRendering(Entity* root)
* postRendering(Entity* root)
Here is when they are called
* init is called right after the window is initialised.
* preRendering is called right before we begin rendering all of the entities
* postRendering is called right before we stop drawing, draw post processing and others here

# Entity

The Entity superclass has four virtual functions, these are
* process(float delta)
* render()
* init()
* death()
When they are called:
* process is called on each child of root, it goes parent -> children, so a parent and it's children will always be processed before that parent's sibling
* render is called on each child of root, however it goes from the bottom up, it will render the children of a parent before the parent.
* init is called when children are added with the addChild(Entity* child) method, after the `Entity* parent` is set.
* death is called before the destructor of a given entity, this one is a little more niche but still usefull. It's called before all the children of a given parent are killed. eg:
```
parent
| child
|| child2 the second one

```
death on parent will be called before any of the children are murdered, then child's death will be called then child2 the second one's death will be called. After the method is called child2 the second one will be destructed, following will be child and parent.

# Entity2D

This is a built in class, not much to explain here, it inherits from Entity but has a Position field (public).

# How to contribute

If for some reason you think this project has any hopes of being useful, you can fork this repo and whence you add whatever you think is needed make a pull request.
