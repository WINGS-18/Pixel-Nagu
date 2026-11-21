CXX = g++
CXXFLAGS = -std=c++20 -Wall -O3
COMMON_INCLUDES = -IEngine/include -IEngine/external/CTL/include

ENGINE_SOURCES = Engine/src/engine/core/SceneManager.cpp \
                 Engine/src/engine/assets/Utilities.cpp \
                 Engine/src/engine/math/direction-system/Direction.cpp \
                 Engine/src/engine/core/Time.cpp \
                 Engine/src/engine/core/bodies/Cell.cpp \
                 Engine/src/engine/core/bodies/RigidBody.cpp \
                 Engine/src/engine/core/bodies/SoftBody.cpp \
                 Engine/src/engine/systems/input/inputQueue.cpp \
                 Engine/src/engine/render/Window.cpp

SNAKE_SOURCES = SnakeGame/main.cpp \
                SnakeGame/src/game/entities/Snake.cpp \
                SnakeGame/src/game/entities/Wall.cpp \
                SnakeGame/src/game/Scenes/Menu.cpp \
                SnakeGame/src/game/Scenes/Gameplay.cpp \
                SnakeGame/src/game/Scenes/GameOver.cpp \
                $(ENGINE_SOURCES)

ICE_SOURCES = IceAndWater/main.cpp \
              IceAndWater/src/game/entities/Player.cpp \
              IceAndWater/src/game/scenes/Menu.cpp \
              IceAndWater/src/game/scenes/Gameplay.cpp \
              IceAndWater/src/game/scenes/GameOver.cpp \
              $(ENGINE_SOURCES)

.PHONY: all snake ice clean

debug: CXXFLAGS = -std=c++20 -Wall -g -O0
debug: snake

all: snake ice

snake:
	$(CXX) $(CXXFLAGS) $(COMMON_INCLUDES) -ISnakeGame/include $(SNAKE_SOURCES) -o snake_game.exe
	@echo "Snake Game build successful! Type ./snake_game.exe to run."

ice:
	$(CXX) $(CXXFLAGS) $(COMMON_INCLUDES) -IIceAndWater/include $(ICE_SOURCES) -o ice_and_water.exe
	@echo "Ice and Water build successful! Type ./ice_and_water.exe to run."

clean:
	-del /f /q snake_game.exe ice_and_water.exe 2>nul
