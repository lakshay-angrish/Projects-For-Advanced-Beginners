## ASCII Art
You must have gcc and Magick++ to run this.
Run the following commands:
```
g++ -o art art.cpp `Magick++-config --cppflags --cxxflags --ldflags --libs`
./art /path/to/image
```
Original             |  ASCII
:-------------------------:|:-------------------------:
![](Ascii%20Art/tiger.jpg)  |  ![](Ascii%20Art/tiger-ASCII.png)

## Game of Life
Run the following commands:
```
g++ game.cpp main.cpp -o game
./game
```
![](Game%20Of%20Life/gun.gif)

For unit tests:
```
g++ tests.cpp main.cpp -o tests
./tests
```
