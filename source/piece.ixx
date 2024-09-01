export module bayou.piece;
import bayou.move;
import bayou.ability;
import stk.hash;
import stk.ds;
import std.core;

using namespace stk;
using namespace stk::ds;

namespace bayou
{
	export class c_piece
	{
	public:
		static constexpr size_t MAX_NAME_LENGTH = 63; // 63 characters + null terminator

		// Constructor
		c_piece(const char* initialName)
		{
			setName(initialName);
		}

		// Getter for the name
		const char* getName() const { return m_name; }

		// Setter for the name
		void setName(const char* newName)
		{
			strncpy(m_name, newName, MAX_NAME_LENGTH);
			m_name[MAX_NAME_LENGTH] = '\0'; // Ensure null-termination
		}

		//void get_moves(std::vector<c_move>& out_moves) { return m_moves; }

	private:
		char m_name[MAX_NAME_LENGTH + 1]; // +1 for null terminator
		fixed_vector<c_hash, 8> m_tags;
		fixed_vector<std::pair<c_hash, uint32_t>, 8> m_attributes;
		std::vector<c_ability*> m_abilities;
	};
}
