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
		static const c_piece_state nil;

		c_piece_state()
			: m_piece_type(0)
			, m_owner(0)
			, m_position(0, 0)
		{
		}

		c_piece_state(uint16_t piece_type, uint8_t owner, c_board_position pos)
			: m_piece_type(piece_type)
			, m_owner(owner)
			, m_position(pos)
		{
		}

		c_board_position position() const { return m_position; }
		void move(c_board_position to) { m_position = to; }
		bool is_nil() const { return m_piece_type == 0; }

	private:
		uint16_t m_piece_type;
		uint8_t m_owner : 1;
		fixed_vector<c_hash, 8> m_tags;
		fixed_vector<std::pair<c_hash, uint32_t>, 8> m_attributes;
		c_board_position m_position;
	};

	const c_piece_state c_piece_state::nil{};
}
