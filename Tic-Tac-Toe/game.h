#ifndef GAME_HEADER
#define GAME_HEADER

#include <vector>
#include <string>

static std::string super_tab(60, ' ');

std::vector<std::string> new_board();
void render(std::vector<std::string>&);
std::pair<int, int> get_move(std::vector<std::string>&);
std::vector<std::string> make_move(std::pair<int, int>, std::vector<std::string>&, char);
char check_winner(std::vector<std::string>&);
bool is_draw(std::vector<std::string>&);
char get_opponent(char);

#endif