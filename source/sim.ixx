export module bayou.sim;
import bayou.ability;
import bayou.abl_slide;
import bayou.board_position;
import bayou.game_state;
import bayou.move;
import bayou.piece;
import bayou.piece_library;
import bayou.piece_state;
import std;
import stk.math;

using namespace stk;

namespace bayou
{
	export class c_sim
	{
	public:
		c_sim()
		{
			std::bitset<static_cast<size_t>(e_compass_direction::count)> rook_directions{ 0b01010101 };
			c_abl_slide* rook_ability = new c_abl_slide(rook_directions);
			m_abilities.push_back(rook_ability);
			c_piece rook{ "Rook" };
			rook.add_ability(rook_ability);
			m_library.add(rook);
		}

		~c_sim()
		{
			for (c_ability* ability : m_abilities)
			{
				delete ability;
			}
		}

		bool place_piece(std::uint16_t piece_type, std::uint8_t owner, c_board_position pos)
		{
			if (!m_game_state[pos].is_nil())
			{
				return false;
			}

			if (piece_type >= m_library.count())
			{
				return false;
			}

			if (!m_game_state.is_valid_position(pos))
			{
				return false;
			}

			if (owner >= 2)
			{
				return false;
			}

			m_game_state[pos] = c_piece_state(piece_type, owner, pos);
			return true;
		}

		bool try_move(c_move const& move)
		{
			c_piece_state& piece_to_move = m_game_state[move.from()];
			if (piece_to_move.is_nil())
			{
				return false;
			}

			uint16_t piece_type = piece_to_move.piece_type();
			c_piece const* piece = m_library[piece_type];
			if (piece == nullptr)
			{
				return false;
			}

			return piece->try_move(move, m_game_state);
		}

	private:
		c_piece_library m_library;
		std::vector<c_ability*> m_abilities;
		c_game_state m_game_state;
	};
}
