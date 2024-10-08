export module bayou.ability;
import bayou.game_state;
import bayou.move;
import bayou.piece_state;
import std;

namespace bayou
{
	export class c_ability
	{
	public:
		virtual void get_moves(c_piece_state const& piece_state, c_game_state const& game_state, std::vector<c_move>& out_moves) const = 0;
		virtual bool validate_move(c_move move, c_game_state const& game_state) const = 0;
		virtual bool try_move(c_move move, c_game_state& game_state) const = 0;
	};
}
