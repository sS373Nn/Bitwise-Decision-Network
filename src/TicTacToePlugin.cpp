#include "TicTacToePlugin.hpp"

TicTacToePlugin::TicTacToePlugin(uint8_t player) : player(player) {
    uint8_t ORbitset = 0b00000010;
    uint8_t input_size = 18;
    uint8_t section_size = 2;
    initialize_nodes();
};

void TicTacToePlugin::initialize_nodes(){ //if player == 1 mask == 0b01, elif player == 2 mask == 0b10
    TicTacToeNodes = NodeSet(ORbitset, input_size, section_size);
    TicTacToeNodes.set_node_mask(1, player);
};

NodeSet TicTacToePlugin::get_TicTacToeNodes(){
    return TicTacToeNodes;
};
