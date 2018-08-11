#pragma once

#pragma region value macro
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define PLAYER_SPEED 499.0f
#define PLAYER_JUMP_FORCE 500.0f
#define PLAYER_JUMP_TIME 0.5f
#define PLAYER_WIDTH 126
#define PLAYER_HEIGHT 172
#define PLAYER_MIRROR SVector2(1.0f, 0.0f)
#define WORLD_BLOCK_ATLAS_WIDTH 26
#define WORLD_BLOCK_ATLAS_HEIGHT 26
#define WORLD_BLOCK_WIDTH 48
#define WORLD_BLOCK_HEIGHT 48
#define GRAVITY_VALUE 9.81f
#define WORLD_WIDTH 3840
#define WORLD_HEIGHT 720
#define WORLD_PLAYER_BORDER_LEFT 700
#define WORLD_PLAYER_BORDER_RIGHT 3000
#pragma endregion

#pragma region m2vh
#define FOREGROUND_DISTFACTOR 1.2f
#define FOREGROUND_MARGIN 5
#define FOREGROUND_POSITION_Y 600
#define GROUND_POSITION 580	// Y-Position of top border
#define WAY_HEIGHT 20
#define NPC_HEIGHT 302
#define NPC_WIDTH 174
#define ITEM_WIDTH 55
#define ITEM_HEIGHT 55
#define INVENTORY_ITEM_OFFSET_X 22
#define INVENTORY_ITEM_OFFSET_Y 17
#define INVENTORY_WIDTH 97
#define INVENTORY_HEIGHT 244
#define MOON_POSITION_Y -50
#define MOON_POSITION_X 850
#define HOUSE_POS_X 640 // outer left
#define HOUSE_POS_Y 200 + 68
#define HOUSE_WIDTH 373
#define HOUSE_HEIGHT 296
#define DOOR_WIDTH 57
#define DOOR_HEIGHT 123
#define DOOR_POS_X (HOUSE_POS_X + 226)
#define DOOR_POS_Y (HOUSE_POS_Y + 158)
#pragma endregion
#define CAMERA_OFFSET_X (HOUSE_WIDTH +10 )
#define CAMERA_OFFSET_Y 200

#pragma region Color
#define YELLOW SColor(255, 255, 0)
#pragma endregion



#pragma region function macro
#define LOG_ERROR(TEXT, ERROR)		\
	std::cout << TEXT;				\
	std::cout << " Error: ";		\
	std::cout << ERROR;				\
	std::cout << std::endl;

#define LOG_MESSAGE(TEXT, VALUE)	\
	std::cout << ">> ";		\
	std::cout << TEXT;		\
	std::cout << ": ";		\
	std::cout << VALUE;		\
	std::cout << std::endl;

#pragma endregion