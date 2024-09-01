export module bayou.abl_slide;
import bayou.piece_state;
import bayou.game_state;
import bayou.board_position;
import bayou.ability;
import stk.math;
import std.core;

using namespace stk;

namespace bayou
{
	export class c_abl_slide : public c_ability
	{
	public:
		c_abl_slide(std::bitset<static_cast<size_t>(e_compass_direction::count)> move_directions)
			: m_move_directions(move_directions)
		{
		}

		bool can_move_in_direction(e_compass_direction dir) const
		{
			return m_move_directions.test(static_cast<size_t>(dir));
		}

		void get_moves(c_piece_state const& piece_state, c_game_state const& game_state, std::vector<c_move>& out_moves) const override
		{
			c_board_position from = piece_state.position();
			uint8_t piece_x = from.x();
			uint8_t piece_y = from.y();
			if (can_move_in_direction(e_compass_direction::n))
			{
				for (uint8_t y = piece_y + 1; y < c_game_state::board_size; ++y)
				{
					out_moves.push_back({ from, { piece_x, y } });
				}
			}
		}

	private:
		std::bitset<static_cast<size_t>(e_compass_direction::count)> m_move_directions;
	};
}
