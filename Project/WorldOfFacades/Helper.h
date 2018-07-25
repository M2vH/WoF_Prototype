#pragma once

#pragma region system include
#include <string>
#pragma endregion

#pragma region using
using namespace std;
#pragma endregion

/// <summary>
/// get parent directory of given path
/// </summary>
string GetParentDirectory(string _path, int _depth = 1);

/// <summary>
/// get directory from asset
/// </summary>
string GetAssetPath(const char* _pPath, int _depth);