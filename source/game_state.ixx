export module bayou.game_state;
import bayou.piece_state;
import stk.ds;
import std.core;
import <cassert>;
using namespace stk;
using namespace stk::ds;

namespace bayou
{
	export class c_game_state
	{
	public:
		static constexpr int num_players = 2;
		static constexpr int board_size = 8;
		static constexpr int hand_size = 4;
		static constexpr int max_deck_size = 20;

		c_game_state()
		{
			for (int i = 0; i < num_players; ++i)
			{
				m_steam[i] = 0;
				for (int j = 0; j < hand_size; ++j)
				{
					m_hands[i][j] = 0;
				}
			}
			// m_pieces and m_decks will default construct themselves
		}

		// Getters and setters for steam
		uint8_t get_steam(int player) const
		{
			assert(player >= 0 && player < num_players);
			return m_steam[player];
		}

		void set_steam(int player, uint8_t value)
		{
			assert(player >= 0 && player < num_players);
			m_steam[player] = value;
		}

		// Getter and setter for pieces
		const c_piece_state& get_piece(int x, int y) const
		{
			assert(x >= 0 && x < board_size && y >= 0 && y < board_size);
			return m_pieces[y][x];
		}

		void set_piece(int x, int y, const c_piece_state& piece)
		{
			assert(x >= 0 && x < board_size && y >= 0 && y < board_size);
			m_pieces[y][x] = piece;
		}

		// Getter and setter for hands
		uint16_t get_hand(int player, int index) const
		{
			assert(player >= 0 && player < num_players);
			assert(index >= 0 && index < hand_size);
			return m_hands[player][index];
		}

		void set_hand(int player, int index, uint16_t card)
		{
			assert(player >= 0 && player < num_players);
			assert(index >= 0 && index < hand_size);
			m_hands[player][index] = card;
		}

		// Getter and setter for decks
		const fixed_vector<uint16_t, max_deck_size>& get_deck(int player) const
		{
			assert(player >= 0 && player < num_players);
			return m_decks[player];
		}

		void set_deck(int player, const fixed_vector<uint16_t, max_deck_size>& deck)
		{
			assert(player >= 0 && player < num_players);
			m_decks[player] = deck;
		}

		// Deck manipulation methods
		void add_to_deck(int player, uint16_t card)
		{
			assert(player >= 0 && player < num_players);
			bool success = m_decks[player].append(card);
			assert(success && "Deck is full");
		}

		uint16_t draw(int player)
		{
			assert(player >= 0 && player < num_players);
			auto& deck = m_decks[player];
			assert(deck.count() > 0 && "Attempting to draw from an empty deck");

			uint16_t drawn_card = deck[deck.count() - 1];
			deck.remove_at_ordered(deck.count() - 1);
			return drawn_card;
		}

	private:
		uint8_t m_steam[num_players];
		c_piece_state m_pieces[board_size][board_size];
		uint16_t m_hands[num_players][hand_size];
		fixed_vector<uint16_t, max_deck_size> m_decks[num_players];
	};
}