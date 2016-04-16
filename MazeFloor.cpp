#include "MazeFloor.h"

Floor::Floor(ushort width, ushort height) {
  //MazeSpace def;
  floor = vector<vector<MazeSpace> >(height, vector<MazeSpace>(width, MazeSpace()));
}

Floor::RenderAsText(uchar spacing, std::map<ushort,char> structviews) {
  // For now, spacing will be ignored and there will be no spacing.
  for(int i=0; i<floor.size(); ++i) {
    for(int j=0; j<floor[i].size(); ++j) {
      ushort sid = floor[i][j].struct_id();
      if(sid) {
        // structure, use its preferred character if possible
        map<ushort,char>::iterator itr = structviews.find(sid);
        if(itr != structviews.end()) {
          std::cout << itr->second;
        }
        else {
          // else give up and print the id
          std::cout << sid;
        }
      }
      else {
        // normal wall or path
        if(floor[i][j].type() == M_WALL) {
          std::cout << '#';
        }
        else {
          std::cout << '.';
        }
      }
    }
    std::cout << std::endl;
  }
}
