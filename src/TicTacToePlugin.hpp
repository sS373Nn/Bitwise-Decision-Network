#ifndef TICTACTOEPLUGIN_H
#define TICTACTOEPLUGIN_H

#include "NodeSet.hpp"

class TicTacToePlugin{
public:
    TicTacToePlugin(uint8_t player);
    void initialize_nodes();
    NodeSet get_TicTacToeNodes();

private:
    NodeSet TicTacToeNodes;
    uint8_t player;
    uint8_t ORbitset;
    uint8_t input_size;
    uint8_t section_size;
};

#endif