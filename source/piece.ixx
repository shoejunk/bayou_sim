export module bayou.piece;
import stk.hash;

using namespace stk;
using namespace stk::ds;

namespace bayou
{
	export class c_piece
	{
	public:

	private:
		char name[64];
		fixed_vector<std::pair<c_hash, uint32_t>> attributes;
	};
}
