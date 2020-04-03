#ifndef GAME_HEADER
#define GAME_HEADER

#include <vector>
#include <string>

std::vector<std::string> new_board();
void render(std::vector<std::string>&);
std::pair<int, int> get_move(std::vector<std::string>&);
std::vector<std::string> make_move(std::pair<int, int>, std::vector<std::string>&, char);
char check_winner(std::vector<std::string>&);

#endif