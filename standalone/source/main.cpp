import bayou.board_position;
import bayou.move;
import bayou.piece;
import bayou.piece_state;
import bayou.game_state;
import bayou.abl_slide;
import std.core;

using namespace bayou;

int main()
{
	c_game_state game_state;
	c_board_position board_position(3, 6);
	uint8_t x = board_position.x();
	c_piece rook("rook");
	c_piece_state my_rook;
	c_abl_slide slide(0b00000001);
	std::vector<c_move> moves;
	slide.get_moves(my_rook, game_state, moves);
	return 0;
}
