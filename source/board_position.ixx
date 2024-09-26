export module bayou.board_position;
import std;

namespace bayou
{
	export class c_board_position
	{
	public:
		c_board_position(std::uint8_t x, std::uint8_t y) : m_x(x), m_y(y) {}

		std::uint8_t x() const
		{
			return m_x;
		}

		void x(std::uint8_t x)
		{
			m_x = x;
		}

		std::uint8_t y() const
		{
			return m_y;
		}

		void y(std::uint8_t y)
		{
			m_y = y;
		}

	private:
		std::uint8_t m_x : 3;
		std::uint8_t m_y : 3;
	};
}