#include <iostream>
#include <array>
#include <algorithm>
#include <random>
#include <ctime>

// Перечисления для рангов карт
enum class Rank {
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
    JACK, QUEEN, KING, ACE
};

// Перечисления для мастей карт
enum class Suit {
    CLUBS, DIAMONDS, HEARTS, SPADES
};

// Структура для представления карты
struct Card {
    Rank rank;
    Suit suit;
};

// Функция для печати карты
void printCard(const Card& card) {
    const char* RANKS[] = { "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A" };
    const char* SUITS[] = { "C", "D", "H", "S" };

    std::cout << RANKS[static_cast<int>(card.rank)] << SUITS[static_cast<int>(card.suit)] << ' ';
}

// Функция для создания колоды карт
std::array<Card, 52> createDeck() {
    std::array<Card, 52> deck{};
    int card = 0;
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 0; rank < 13; ++rank) {
            deck[card].suit = static_cast<Suit>(suit);
            deck[card].rank = static_cast<Rank>(rank);
            ++card;
        }
    }
    return deck;
}

// Функция для печати колоды карт
void printDeck(const std::array<Card, 52>& deck) {
    for (const auto& card : deck) {
        printCard(card);
    }
    std::cout << '\n';
}

// Функция для перетасовки колоды карт
void shuffleDeck(std::array<Card, 52>& deck) {
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::shuffle(deck.begin(), deck.end(), mt);
}

// Функция для получения значения карты
int getCardValue(const Card& card) {
    switch (card.rank) {
    case Rank::TWO:   return 2;
    case Rank::THREE: return 3;
    case Rank::FOUR:  return 4;
    case Rank::FIVE:  return 5;
    case Rank::SIX:   return 6;
    case Rank::SEVEN: return 7;
    case Rank::EIGHT: return 8;
    case Rank::NINE:  return 9;
    case Rank::TEN:
    case Rank::JACK:
    case Rank::QUEEN:
    case Rank::KING:  return 10;
    case Rank::ACE:   return 11; // В этом примере туз всегда равен 11
    default:          return 0;
    }
}

// Функция для игры в блэкджек
bool playBlackjack(std::array<Card, 52>& deck) {
    shuffleDeck(deck); // Перетасовываем колоду перед началом игры

    int playerScore = 0;
    int dealerScore = 0;

    // Дилер получает одну карту
    dealerScore += getCardValue(deck.back());
    deck.pop_back();

    // Игрок получает две карты
    playerScore += getCardValue(deck.back());
    deck.pop_back();
    playerScore += getCardValue(deck.back());
    deck.pop_back();

    // Ход игрока
    char choice;
    do {
        std::cout << "У вас " << playerScore << " очков. Хотите взять еще карту? (y/n): ";
        std::cin >> choice;
        if (choice == 'y') {
            playerScore += getCardValue(deck.back());
            deck.pop_back();
            if (playerScore > 21) {
                std::cout << "У вас " << playerScore << " очков. Вы проиграли.\n";
                return false;
            }
        }
    } while (choice != 'n');

    // Ход дилера
    while (dealerScore < 17) {
        dealerScore += getCardValue(deck.back());
        deck.pop_back();
        if (dealerScore > 21) {
            std::cout << "У дилера " << dealerScore << " очков. Вы выиграли!\n";
            return true;
        }
    }

    // Определение победителя
    std::cout << "У дилера " << dealerScore << " очков. У вас " << playerScore << " очков. ";
    if (playerScore > dealerScore) {
        std::cout << "Вы выиграли!\n";
        return true;
    }
    else {
        std::cout << "Вы проиграли.\n";
        return false;
    }
}

int main() {
    // Создаем колоду и играем в блэкджек
    auto deck = createDeck();
    bool playerWon = playBlackjack(deck);

    // Выводим результат игры
    if (playerWon) {
        std::cout << "Поздравляем с победой!\n";
    }
    else {
        std::cout << "Удачи в следующий раз!\n";
    }

    return 0;
}