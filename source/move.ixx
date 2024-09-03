export module bayou.move;
import bayou.board_position;
import stk.hash;
import stk.ds;

using namespace stk;
using namespace stk::ds;

namespace bayou
{
	export class c_move
	{
	public:
		c_move(c_board_position from, c_board_position to)
			: m_from(from)
			, m_to(to)
		{
		}

		[[nodiscard]] c_board_position from() const { return m_from; }
		[[nodiscard]] c_board_position to() const { return m_to; }

	private:
		const c_board_position m_from;
		const c_board_position m_to;
	};
}
