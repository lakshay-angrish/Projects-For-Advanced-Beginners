## ASCII Art
You must have gcc and Magick++ to run this.
Run the following commands:
```
g++ -o art art.cpp \`Magick++-config --cppflags --cxxflags --ldflags --libs
./art /path/to/image
```

## Game of Life
Run the following commands:
```
g++ game.cpp main.cpp -o game
./game
```
For unit tests:
```
g++ tests.cpp main.cpp -o tests
./tests
```
