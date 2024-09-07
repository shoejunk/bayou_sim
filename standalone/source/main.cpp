import bayou.abl_slide;
import bayou.board_position;
import bayou.game_state;
import bayou.move;
import bayou.piece;
import bayou.piece_library;
import bayou.piece_state;
import bayou.sim;
import std.core;

using namespace bayou;

int main()
{
	c_sim* sim = new c_sim;
	if (sim == nullptr)
	{
		return 1;
	}

	sim->place_piece(1, 0, { 0, 0 });
	sim->try_move({ { 0, 0 }, { 0, 1 } });
	return 0;
}
