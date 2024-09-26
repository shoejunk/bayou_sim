export module bayou.abl_slide;
import bayou.game_state;
import bayou.ability;
import bayou.piece_state;
import bayou.board_position;
import bayou.move;
import stk.math;
import std;

using namespace stk;

namespace bayou
{
	export class c_abl_slide : public c_ability
	{
	public:
		c_abl_slide(std::bitset<static_cast<size_t>(e_compass_direction::count)> move_directions)
			: m_move_directions(move_directions)
		{
		}

		bool can_move_in_direction(e_compass_direction dir) const
		{
			return m_move_directions.test(static_cast<size_t>(dir));
		}

		void get_moves(c_piece_state const& piece_state, c_game_state const& game_state, std::vector<c_move>& out_moves) const override
		{
			c_board_position from = piece_state.position();
			uint8_t piece_x = from.x();
			uint8_t piece_y = from.y();

			if (can_move_in_direction(e_compass_direction::n))
			{
				for (uint8_t y = piece_y + 1; y < c_game_state::board_size; ++y)
				{
					out_moves.push_back({ from, { piece_x, y } });
				}
			}
			if (can_move_in_direction(e_compass_direction::ne))
			{
				for (uint8_t y = piece_y + 1, x = piece_x + 1; y < c_game_state::board_size && x < c_game_state::board_size; ++y, ++x)
				{
					out_moves.push_back({ from, { x, y } });
				}
			}
			if (can_move_in_direction(e_compass_direction::e))
			{
				for (uint8_t x = piece_x + 1; x < c_game_state::board_size; ++x)
				{
					out_moves.push_back({ from, { x, piece_y } });
				}
			}
			if (can_move_in_direction(e_compass_direction::se))
			{
				for (uint8_t y = piece_y - 1, x = piece_x + 1; y < c_game_state::board_size && x < c_game_state::board_size; --y, ++x)
				{
					out_moves.push_back({ from, { x, y } });
				}
			}
			if (can_move_in_direction(e_compass_direction::s))
			{
				for (uint8_t y = piece_y - 1; y < c_game_state::board_size; --y) // Using underflow for the unsigned int
				{
					out_moves.push_back({ from, { piece_x, y } });
				}
			}
			if (can_move_in_direction(e_compass_direction::sw))
			{
				for (uint8_t y = piece_y - 1, x = piece_x - 1; y < c_game_state::board_size && x < c_game_state::board_size; --y, --x)
				{
					out_moves.push_back({ from, { x, y } });
				}
			}
			if (can_move_in_direction(e_compass_direction::w))
			{
				for (uint8_t x = piece_x - 1; x < c_game_state::board_size; --x) // Using underflow for the unsigned int
				{
					out_moves.push_back({ from, { x, piece_y } });
				}
			}
			if (can_move_in_direction(e_compass_direction::nw))
			{
				for (uint8_t y = piece_y + 1, x = piece_x - 1; y < c_game_state::board_size && x < c_game_state::board_size; ++y, --x)
				{
					out_moves.push_back({ from, { x, y } });
				}
			}
		}

		[[nodiscard]] bool validate_move(c_move move, c_game_state const& game_state) const override
		{
			c_board_position from = move.from();
			c_board_position to = move.to();

			// Check if the move is within the board
			if (to.x() >= c_game_state::board_size || to.y() >= c_game_state::board_size)
				return false;

			// Check if the move is in a straight line
			int dx = to.x() - from.x();
			int dy = to.y() - from.y();

			// Determine the direction of the move
			e_compass_direction direction;
			int steps, step_x, step_y;
			if (dx == 0 && dy > 0)
			{
				direction = e_compass_direction::n;
				steps = dy;
				step_x = 0;
				step_y = 1;
			}
			else if (dx > 0 && dy > 0 && dx == dy)
			{
				direction = e_compass_direction::ne;
				steps = dx;
				step_x = 1;
				step_y = 1;
			}
			else if (dx > 0 && dy == 0)
			{
				direction = e_compass_direction::e;
				steps = dx;
				step_x = 1;
				step_y = 0;
			}
			else if (dx > 0 && dy < 0 && dx == -dy)
			{
				direction = e_compass_direction::se;
				steps = dx;
				step_x = 1;
				step_y = -1;
			}
			else if (dx == 0 && dy < 0)
			{
				direction = e_compass_direction::s;
				steps = -dy;
				step_x = 0;
				step_y = -1;
			}
			else if (dx < 0 && dy < 0 && dx == dy)
			{
				direction = e_compass_direction::sw;
				steps = -dx;
				step_x = -1;
				step_y = -1;
			}
			else if (dx < 0 && dy == 0)
			{
				direction = e_compass_direction::w;
				steps = -dx;
				step_x = -1;
				step_y = 0;
			}
			else if (dx < 0 && dy > 0 && -dx == dy)
			{
				direction = e_compass_direction::nw;
				steps = dy;
				step_x = -1;
				step_y = 1;
			}
			else return false; // Not a straight line move

			// Check if the move is in an allowed direction
			if (!can_move_in_direction(direction))
				return false;

			// Check if the path is clear
			for (int i = 1; i < steps; ++i)
			{
				int x = (int)from.x() + i * step_x;
				int y = (int)from.y() + i * step_y;
				c_board_position pos = { (uint8_t)x, (uint8_t)y };
				if (!game_state[pos].is_nil())
					return false; // Path is blocked
			}

			return true;
		}

		bool try_move(c_move move, c_game_state& game_state) const override
		{
			c_board_position from = move.from();
			c_board_position to = move.to();
			c_piece_state& moved_piece = game_state[from];
			if (moved_piece.is_nil())
			{
				return false;
			}

			if (!validate_move(move, game_state))
				return false;

			// Move the piece
			game_state.move_piece(from, to);

			return true;
		}

	private:
		std::bitset<static_cast<size_t>(e_compass_direction::count)> m_move_directions;
	};
}
