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
		static constexpr size_t max_name_length = 63; // 63 characters + null terminator
		static const c_piece nil;

		// Constructors
		c_piece()
		{
			// The piece with an empty name is piece 0, the nil piece.
			m_name[0] = '\0';
		}

		c_piece(const char* initialName)
		{
			set_name(initialName);
		}

		bool is_nil() const { return m_name[0] == '\0'; }

		// Getter for the name
		const char* get_name() const { return m_name; }

		// Setter for the name
		void set_name(const char* new_name)
		{
			strncpy(m_name, new_name, max_name_length);
			m_name[max_name_length] = '\0'; // Ensure null-termination
		}

		//void get_moves(std::vector<c_move>& out_moves) { return m_moves; }

	private:
		char m_name[max_name_length + 1]; // +1 for null terminator
		fixed_vector<c_hash, 8> m_tags;
		fixed_vector<std::pair<c_hash, uint32_t>, 8> m_attributes;
		std::vector<c_ability*> m_abilities;
	};

	const c_piece c_piece::nil{};
}
