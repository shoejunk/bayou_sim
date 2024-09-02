export module bayou.board_position;
import std.core;

namespace bayou
{
	export class c_board_position
	{
	public:
		c_board_position(uint8_t x, uint8_t y) : m_x(x), m_y(y) {}

		uint8_t x() const
		{
			return m_x;
		}

		void x(uint8_t x)
		{
			m_x = x;
		}

		uint8_t y() const
		{
			return m_y;
		}

		void y(uint8_t y)
		{
			m_y = y;
		}

	private:
		uint8_t m_x : 3;
		uint8_t m_y : 3;
	};
}