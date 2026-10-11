CXX = g++
CXXFLAGS = -std=c++20 -IEngine/include -ISnakeGame/include -Wall -O3

SOURCES = SnakeGame/main.cpp \
          SnakeGame/src/game/entities/Snake.cpp \
          SnakeGame/src/game/entities/Wall.cpp \
          SnakeGame/src/game/Scenes/Menu.cpp \
          SnakeGame/src/game/Scenes/Gameplay.cpp \
          SnakeGame/src/game/Scenes/GameOver.cpp \
          Engine/src/engine/core/SceneManger.cpp \
          Engine/src/engine/assets/Utilities.cpp \
          Engine/src/engine/math/rect.cpp \
          Engine/src/engine/math/vector2C.cpp \
          Engine/src/engine/math/vector4.cpp \
          Engine/src/engine/math/direction-system/Direction.cpp \
          Engine/src/engine/structures/Flatstring.cpp \
          Engine/src/engine/core/Time.cpp \
          Engine/src/engine/core/bodies/Cell.cpp \
          Engine/src/engine/core/bodies/RigidBody.cpp \
          Engine/src/engine/core/bodies/SoftBody.cpp \
          Engine/src/engine/systems/input/inputQueue.cpp

TARGET = snake_game.exe

all:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)
	@echo "Build successful! Type ./snake_game.exe to run."

clean:
	del $(TARGET)
