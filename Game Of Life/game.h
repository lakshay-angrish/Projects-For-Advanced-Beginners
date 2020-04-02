#ifndef GAME_HEADER
#define GAME_HEADER

#include <vector>
#include <string>

void render(std::vector<std::vector<int> >&);
std::vector<std::vector<int> > random_state(int, int);
std::vector<std::vector<int> > load_state(std::string&);
void next_cell_state(int, std::vector<std::vector<int> >&, int, int, int);
void corner_cases(std::vector<std::vector<int> >&, std::vector<std::vector<int> >&);
void edge_cases(std::vector<std::vector<int> >&, std::vector<std::vector<int> >&);
void next_state(std::vector<std::vector<int> >&);

#endif