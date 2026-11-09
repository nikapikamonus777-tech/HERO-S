#include "Level.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

Level::Level(const std::string& levelFile) {
    LoadLevel(levelFile);
}
bool Level::IsSolid(int tx, int ty) const {
    if (ty < 0|| ty >= map.size() || tx < 0 || tx >= map[ty].size()) {
        return true;
    }
    return map[ty][tx] == '#';
}

bool Level::Collides(Rectangle r)const{
    int left = (r.x + 0.01f) / TILE;
    int right  = (r.x + r.width  - 0.01f) / TILE;
    int top= r.y/TILE;
    int bottom = (r.y + r.height - 0.01f) / TILE;
      for (int y = top; y <= bottom; ++y) {
      for (int x = left; x <= right; ++x) {
          if (IsSolid(x, y)) return true;
      }
  }
  return false;
  }
void Level::Draw() const {
    for( int y= 0; y<map.size(); ++y)
    for (int x=0; x<map[y].size(); ++x){
        if (map[y][x] == '#'){
            DrawRectangle(x*TILE, y*TILE, TILE, TILE, GRAY);
        }
    }
}
 void Level::DestroyTile(int tx, int ty) {
    if (ty >= 0 && ty < map.size() && tx >= 0 && tx < map[ty].size()) {
        map[ty][tx] = ' ';
    }
}
Vector2 Level::GetPlayerStart() const {
    return playerStart;
}
float Level::GetWidth() const {
    if (map.empty()) {
        return 0;
    }
    return map[0].size() * TILE;
}
float Level::GetHeight() const {
    return map.size() * TILE;
}
void Level::LoadLevel(const std::string& levelFile){
    std::ifstream file(levelFile);
    std::string line;
    if (!file.is_open()) {
         TraceLog(LOG_ERROR, "Cannot open level file");
        return;
    }
    std::string getLine;
    while (std::getline(file, line)){
        size_t playerPos = line.find('P');
        if (playerPos != string::npos) {
            playerStart = { (float)(playerPos * TILE), (float)(map.size() * TILE) };
            line[playerPos] = '.';
        }
        map.push_back(line);
    }
}
