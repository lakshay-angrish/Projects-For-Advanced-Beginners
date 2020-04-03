#ifndef AI_HEADER
#define AI_HEADER

#include <vector>
#include <string>

std::pair<int, int> random_ai(std::vector<std::string>&, char);
std::pair<int, int> find_winning_move_ai(std::vector<std::string>&, char);
std::pair<int, int> find_winning_and_losing_move_ai(std::vector<std::string>&, char);

#endif