#include"deck.h"

int main() {
    Deck intDeck;
    intDeck.push_front(3);
    intDeck.push_front(2);
    intDeck.push_front(1);
    intDeck.push_back(4);

    std::cout<<intDeck.toString();
    intDeck.pop();

    std::cout << intDeck.toString();
    return 0;
}