# DRAGONFLY ENGINE

This is my currently inwork attempt to implement the [Dragonfly](https://dragonfly.wpi.edu/) game engine designed by Mark Claypool. [Dragonfly](https://dragonfly.wpi.edu/) is a tex-based game engine, primarily designed to teach about game engine development. I am doing my best to adhere to what is presented in the book, but I am making some small structural and sytle changes throughout.

I was having trouble using the precompiled binaries on the website on arch linux, so I am having to build it myself. I hope to improve upon the project and make it fully cross-platform later on.

## Building
Dependencies:
- SFML ^3.0.0
- gtest ^1.0

```
mkdir build
cd build
cmake ..
make
```

## Notes
When compiling a game with the library, only use the headers provided from this implementation of the dragonfly engine.
