export module bayou.piece_state;
import bayou.board_position;
import stk.ds;
import stk.hash;
import std;

using namespace stk;

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

		c_piece_state(std::uint16_t piece_type, std::uint8_t owner, c_board_position pos)
			: m_piece_type(piece_type)
			, m_owner(owner)
			, m_position(pos)
		{
		}

		c_board_position position() const { return m_position; }
		void move(c_board_position to) { m_position = to; }
		bool is_nil() const { return m_piece_type == 0; }
		uint16_t piece_type() const { return m_piece_type; }

	private:
		std::uint16_t m_piece_type;
		std::uint8_t m_owner : 1;
		c_fixed_vector<c_hash, 8> m_tags;
		c_fixed_vector<std::pair<c_hash, std::uint32_t>, 8> m_attributes;
		c_board_position m_position;
	};

	const c_piece_state c_piece_state::nil{};
}
