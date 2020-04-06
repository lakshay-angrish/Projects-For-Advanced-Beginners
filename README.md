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
g++ tests.cpp game.cpp -o tests
./tests
```

## Tic Tac Toe
![](Tic-Tac-Toe/tic.gif)

To play PvP:
```
g++ -o game game.cpp main.cpp
./game
```
To play against Computer:
```
g++ -o game game.cpp main.cpp ai.cpp -DAI
./game
```
To see two AIs fight:
```
g++ -o game game.cpp main.cpp ai.cpp -DAI2
./game <ai1> <ai2>
```
where ai1, ai2 ∈ {random_ai, find_winning_move_ai, find_winning_and_losing_move_ai, minimax_ai}

For unit tests:
```
g++ tests.cpp ai.cpp game.cpp -o tests
./tests
```
