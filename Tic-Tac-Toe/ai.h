#ifndef AI_HEADER
#define AI_HEADER

#include <vector>
#include <string>
#include <map>

static std::map<std::string, int> cache;
static std::map<std::string, std::pair<int, int> > coords;

std::pair<int, int> random_ai(std::vector<std::string>&, char);
std::pair<int, int> find_winning_move_ai(std::vector<std::string>&, char);
std::pair<int, int> find_winning_and_losing_move_ai(std::vector<std::string>&, char);
int minimax_score(std::vector<std::string>&, char);
std::vector<std::pair<int, int> > legal_moves(std::vector<std::string>&);
std::pair<int, int> minimax_ai(std::vector<std::string>&, char);
std::pair<int, int> minimax_ai_with_cache(std::vector<std::string>&, char);
void load_cache();

#endif