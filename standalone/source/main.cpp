import bayou.abl_slide;
import bayou.board_position;
import bayou.game_state;
import bayou.move;
import bayou.piece;
import bayou.piece_library;
import bayou.piece_state;
import std.core;

using namespace bayou;

int main()
{
	c_piece_library library;
	c_piece rook{ "rook" };
	library.add(rook);
	c_game_state game_state{ library };
	c_board_position board_position{ 3, 6 };
	uint8_t x = board_position.x();
	game_state[{0, 0}] = { 1, 0, {0, 0} };
	c_abl_slide slide(0b11111111);
	c_game_state new_game_state;
	slide.try_move({ {0, 0}, {2, 2} }, game_state, new_game_state);
	return 0;
}
