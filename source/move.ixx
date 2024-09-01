export module bayou.move;
import bayou.board_position;
import bayou.game_state;
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

		//virtual void get_resulting_game_state(c_game_state& out_game_state) = 0;

	private:
		const c_board_position m_from;
		const c_board_position m_to;
	};
}
