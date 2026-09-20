#include "game/entities/Wall.h"

namespace sg {

    namespace ec = Engine::Core;

    Wall::Wall(int head, int tail)
        : m_wallBody(head, tail) {}

    void Wall::init(char sym) {
        m_wallBody.init(sym);
    }

    using uint = std::size_t;

    void Wall::setTheWall() {
        int i = 0;
        setRight(i, 0, 30);
        setLeft(i, 50, 30);
        setTop(i, 50, 0);
        setDown(i, 50, 30);
    }

    void Wall::setRight(int& i, int xLimit, int yLimit) {
        for(uint lim = 0; lim < yLimit; lim++) {
            m_wallBody.setCoord(i++, xLimit, lim);
        }
    }

    void Wall::setLeft(int& i, int xLimit, int yLimit) {
        for(uint lim = 0; lim < yLimit; lim++) {
            m_wallBody.setCoord(i++, xLimit - 1, lim);
        }
    }

    void Wall::setTop(int& i, int xLimit, int yLimit) {
        for(uint lim = 0; lim < xLimit; lim++) {
            m_wallBody.setCoord(i++, lim, yLimit);
        }
    }

    void Wall::setDown(int& i, int xLimit, int yLimit) {
        for(uint lim = 0; lim < xLimit; lim++) {
            m_wallBody.setCoord(i++, lim, yLimit - 1);
        }
    }

    const ec::Cell& Wall::getCell(int index) const noexcept {
        return m_wallBody.getBody()[index];
    }

    int Wall::head() const noexcept {
        return m_wallBody.getHead();
    }

    int Wall::tail() const noexcept {
        return m_wallBody.getTail();
    }

}