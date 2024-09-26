export module bayou.piece_library;
import bayou.piece;
import stk.ds;
import std;
import <cassert>;

using namespace stk;

namespace bayou
{
	export class c_piece_library
	{
	public:
		c_piece_library()
		{
			// The first piece in the library must be the nil piece.
			m_library.append(c_piece::nil);
		}

		bool add(c_piece piece)
		{
			return m_library.append(piece);
		}

		c_piece const* operator[](std::uint16_t index) const
		{
			if (index >= m_library.count())
			{
				return nullptr;
			}
			return &m_library[index];
		}

		uint16_t count() const
		{
			return m_library.count();
		}

	private:
		c_fixed_vector<c_piece, std::numeric_limits<std::uint16_t>::max() + 1> m_library;
	};
}