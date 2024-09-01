export module bayou.piece_state;
import bayou.board_position;
import stk.ds;
import stk.hash;
import std.core;

using namespace stk;
using namespace stk::ds;

namespace bayou
{
	export class c_piece_state
	{
	public:
		c_piece_state()
			: m_piece_type(0)
			, m_position(0, 0)
		{
		}

		c_board_position position() const { return m_position; }

	private:
		uint16_t m_piece_type;
		fixed_vector<c_hash, 8> m_tags;
		fixed_vector<std::pair<c_hash, uint32_t>, 8> m_attributes;
		c_board_position m_position;
	};
}
