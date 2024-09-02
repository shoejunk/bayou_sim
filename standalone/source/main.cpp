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
	game_state[{0, 0}] = { 1, 0, {0, 0} };
	c_abl_slide slide(0b11111111);
	c_game_state new_game_state;
	slide.try_move({ {0, 0}, {2, 2} }, game_state, new_game_state);
	return 0;
}
