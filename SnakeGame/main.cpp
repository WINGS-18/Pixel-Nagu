#include "engine/core/SceneManager.h"
#include "game/Scenes/Menu.h"
#include "game/Scenes/Gameplay.h"
#include "game/Scenes/GameOver.h"
#include "game/Scenes/SceneTypes.h"

int main() {
    auto menu = std::make_unique<sg::MenuScene> ("menu");
    auto gameplay = std::make_unique<sg::GameplayScene> ("gameplay");
    auto gameover = std::make_unique<sg::GameOver> ("gameover");

    Engine::Core::SceneManager sm;

    sm.registerScene(sg::SceneEnum::MenuScene, std::move(menu));
    sm.registerScene(sg::SceneEnum::GameplayScene, std::move(gameplay));
    sm.registerScene(sg::SceneEnum::GameOver, std::move(gameover));

    sm.startGame();

    return 0;

}