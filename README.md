# The shwompEngine

The shwompEngine is a minimal game engine built off of raylib designed to let you program without worry*.

\*unless you're the problem.

# Getting started

Clone the repository with `git clone https://github.com/maningreen/shwompEngine`

The file structure is as follows
```
 .
├──  build
├──  external
│   └──  raylib-5.5
│       ├──  libraylib.a
│       ├──  raylib.h
│       └──  raymath.h
├──  flake.lock
├──  flake.nix
├──  LICENSE
├──  Makefile
├── 󰂺 README.md
└──  src
    ├──  engine
    │   ├──  core.cpp
    │   ├──  core.h
    │   ├──  entity.cpp
    │   ├──  entity.hpp
    │   ├──  main.cpp
    │   ├──  root.cpp
    │   └──  root.hpp
    ├──  example.cpp
    ├──  example.hpp
    ├──  include.h
    └──  init.cpp
```

It's suggested you take a gander at everything in src/ and if you want what's in src/engine/.<br>

## Initialisation

init.cpp (you don't have to name it that if you wish) must contain one function. 
`init(Entity* root)`
init is called right after the window is initialised.

### Deinitialisation

When you call `killDefered()` on root the window will close and your tree will be freed.

## Entity

The Entity superclass has four virtual functions, these are
* process(float delta)
* render()
* postRender()
* init()
* death()

When they are called is as follows.

* process is called on each child of root, it goes parent -> children, so a parent and it's children will always be processed before that parent's sibling
* render is called on each child of root, however it goes from the bottom up, it will render the children of a parent before the parent.
* postRender is called right after all of the children of the node are rendered, similar to `death()` it's niche but it has it's use cases. 
* init is called when children are added with the addChild(Entity* child) method, after the `Entity* parent` is set.
* death is called before the destructor of a given entity, this one is a little more niche but still useful. It's called before all the children of a given parent are killed. eg:
```
parent
|-child
 |-child2 the second one
```
death on parent will be called before any of the children are murdered, then child's death will be called then child2 the second one's death will be called. After the method is called child2 the second one will be destructed, following will be child and parent.

## Entity2D

Entity2D is a built in class that inherits from Entity, but with a Vector2 position field.

## How to actually build your game

Using make has a few options

| Commands | Effects |
|----------|---------|
| make     | builds all the .cpp files in src/ and src/engine |
| make clean | deletes everything in build/ |
| make run | everything `make` does and excecutes the output |

### Changing the output

normally the output is build/engine <br>
if you really don't like that you can change that by

1. going into the makefile, finding the line that says and change the variable
>  \# CHANGE THIS TO BE YOUR EXCECUTABLE NAME

2. going into the flake.nix, finding the line that says and change the variable
>  \# CHANGE THIS TO BE YOUR EXCECUTABLE NAME


## Using Nix

Using nix is sugguested for development due to it's powerful nature.<br>
to get started developing in nix you'd need nix flakes enabled, you can do this

### Nixos

To permanently enable flakes on nixos
`nix.settings.experimental-features = [ "nix-command" "flakes" ];`

### Other distros

Add the following to your nix.conf
`experimental-features = nix-command flakes`

### Starting development

`nix develop`
will pop you into a shell with all of the dependancies installed, if you need more packages add them in the flake.nix<br>
You can find nix packages [here](https://search.nixos.org/packages)<br>
And add them in the mkShell section and the buildInputs section

## Customising

### Root Entity

There is one more type of entity, that being root. Root (by default) manages the window initialisation and the window deinitilisation.
If you want you can change it from raylib to use another visual library, such as sdl, or if you want even a TUI library such as ncurses.

### Changing visual backend

In order to change the visual backend to something you prefer here is what you would do.

1. Install the library.
2. Update values, this means going into `entity.hpp` and adjusting the fields such as `position` to another type.
3. Edit `root.hpp` to account for your backend
4. (Optional, but suggested) edit flake.nix to account for your packages.

# How to contribute

If for some reason you think this project has any hopes of being useful, you can fork this repo and whence you add whatever you think is needed make a pull request.

#### About Me

I'm someone terminally bored. This is my first project that isn't crap.
