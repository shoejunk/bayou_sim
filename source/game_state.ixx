export module bayou.game_state;
import bayou.piece_state;
import stk.ds;
import std.core;
using namespace stk;
using namespace stk::ds;

namespace bayou
{
	export class c_game_state
	{
	public:
		static constexpr int NUM_PLAYERS = 2;
		static constexpr int BOARD_SIZE = 8;
		static constexpr int HAND_SIZE = 4;
		static constexpr int MAX_DECK_SIZE = 20;

		c_game_state()
		{
			for (int i = 0; i < NUM_PLAYERS; ++i)
			{
				m_steam[i] = 0;
				for (int j = 0; j < HAND_SIZE; ++j)
				{
					m_hands[i][j] = 0;
				}
			}
			// m_pieces and m_decks will default construct themselves
		}

		// Getters and setters for steam
		uint8_t get_steam(int player) const
		{
			assert(player >= 0 && player < NUM_PLAYERS);
			return m_steam[player];
		}

		void set_steam(int player, uint8_t value)
		{
			assert(player >= 0 && player < NUM_PLAYERS);
			m_steam[player] = value;
		}

		// Getter and setter for pieces
		const c_piece_state& get_piece(int x, int y) const
		{
			assert(x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE);
			return m_pieces[y][x];
		}

		void set_piece(int x, int y, const c_piece_state& piece)
		{
			assert(x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE);
			m_pieces[y][x] = piece;
		}

		// Getter and setter for hands
		uint16_t get_hand(int player, int index) const
		{
			assert(player >= 0 && player < NUM_PLAYERS);
			assert(index >= 0 && index < HAND_SIZE);
			return m_hands[player][index];
		}

		void set_hand(int player, int index, uint16_t card)
		{
			assert(player >= 0 && player < NUM_PLAYERS);
			assert(index >= 0 && index < HAND_SIZE);
			m_hands[player][index] = card;
		}

		// Getter and setter for decks
		const fixed_vector<uint16_t, MAX_DECK_SIZE>& get_deck(int player) const
		{
			assert(player >= 0 && player < NUM_PLAYERS);
			return m_decks[player];
		}

		void set_deck(int player, const fixed_vector<uint16_t, MAX_DECK_SIZE>& deck)
		{
			assert(player >= 0 && player < NUM_PLAYERS);
			m_decks[player] = deck;
		}

		// Deck manipulation methods
		void add_to_deck(int player, uint16_t card)
		{
			assert(player >= 0 && player < NUM_PLAYERS);
			bool success = m_decks[player].append(card);
			assert(success && "Deck is full");
		}

		uint16_t draw(int player)
		{
			assert(player >= 0 && player < NUM_PLAYERS);
			auto& deck = m_decks[player];
			assert(deck.count() > 0 && "Attempting to draw from an empty deck");

			uint16_t drawn_card = deck[deck.count() - 1];
			deck.remove_at_ordered(deck.count() - 1);
			return drawn_card;
		}

	private:
		uint8_t m_steam[NUM_PLAYERS];
		c_piece_state m_pieces[BOARD_SIZE][BOARD_SIZE];
		uint16_t m_hands[NUM_PLAYERS][HAND_SIZE];
		fixed_vector<uint16_t, MAX_DECK_SIZE> m_decks[NUM_PLAYERS];
	};
}