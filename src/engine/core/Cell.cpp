#include "engine/core/Cell.h"

namespace Engine::Core {

    Cell::Cell(char sym)
        : m_symbol(sym) {}

    int Cell::getX() const noexcept {return m_coord.x;}

    int Cell::getY() const noexcept {return m_coord.y;}

    void Cell::setX(int x) noexcept {m_coord.x = x;}

    void Cell::setY(int y) noexcept {m_coord.y = y;}

}