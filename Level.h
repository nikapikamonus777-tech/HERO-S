#pragma once
#include "raylib.h"
#include <vector>
#include <string>

class Level {
public:
    Level(const std::string& levelFile);

    bool IsSolid(int tx, int ty) const;
    bool Collides(Rectangle r) const;
    void Draw() const;
    void DestroyTile(int tx, int ty);

    Vector2 GetPlayerStart() const;
    float GetWidth() const;
    float GetHeight() const;

    static constexpr int TILE = 32;

private:
    void LoadLevel(const std::string& levelFile);

    std::vector<std::string> map;
    Vector2 playerStart{0, 0};
};