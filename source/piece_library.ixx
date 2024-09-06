export module bayou.piece_library;
import bayou.piece;
import stk.ds;
import std.core;
import <cassert>;

using namespace stk;
using namespace stk::ds;

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

		c_piece const& operator[](uint16_t index) const
		{
			if (index >= m_library.count())
			{
				return c_piece::nil;
			}
			return m_library[index];
		}

		c_piece& operator[](uint16_t index)
		{
			assert(index < m_library.count());
			return m_library[index];
		}

	private:
		fixed_vector<c_piece, std::numeric_limits<uint16_t>::max() + 1> m_library;
	};
}