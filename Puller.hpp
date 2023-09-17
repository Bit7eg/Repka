#pragma once

#include "Repka.hpp"

class Puller: public sf::RectangleShape {
private:
    Puller* chain = nullptr;
    int getChainStrenght() {
        if (this->chain == nullptr) return 0;
        return this->strength + this->chain->getChainStrenght();
    }
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        sf::RectangleShape shape = (sf::RectangleShape)*this;
        target.draw(shape, states);
        if (this->chain != nullptr) target.draw(*(this->chain), states);
    }
public:
    int strength = 1;
    Puller(const sf::Vector2f &size = sf::Vector2f(0, 0)): sf::RectangleShape(size) {}
    ~Puller() {
        delete this->chain;
    }
    void addToChain(Puller *chain) {
        if (this->chain != nullptr) return;
        
        this->chain = chain;
    }
    Puller *removeFromChain() {
        Puller *prevChain = this->chain;
        this->chain = nullptr;
        return prevChain;
    }
    bool pull(Repka repka) {
        return (repka.need_strength <= this->getChainStrenght());
    }
};