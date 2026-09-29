#include "game/entities/Wall.h"

namespace sg {

    namespace ec = Engine::Core;

    Wall::Wall(bool isActive, int rows, int cols)
        : m_wallBody(isActive, rows, cols) {}

    void Wall::init(const std::vector<char>& sym) {
        m_wallBody.setSprites(sym);
    }

    void Wall::initAll(char sym) {
        m_wallBody.initAllSprites(sym);
    }

    const ec::RigidBody& Wall::getBody() const noexcept {
        return m_wallBody;
    }

    void Wall::setWallPosition(int x, int y) {
        m_wallBody.setPosition(x, y);
    }

}