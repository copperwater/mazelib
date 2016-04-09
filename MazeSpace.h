#ifndef MAZESPACE_H
#define MAZESPACE_H

/* MazeSpace.h - defines MazeSpace, a class which should be customized by the
   programmer for the behavior they want in their maze. */

#include "MazeDefs.h"

namespace Maze {

  class Space {
  private:

    // Represents whether this space is part of a structure.
    bool structure;

    // Actual representation of the maze data. Everything has to be regarded
    // either as a path or as a wall by the maze generator. Structures
    // must therefore always define one of the two.
    maze_type path_type;

    // If the space is part of a structure, this will represent what kind of
    // custom space it is. If the type is a normal wall or path, this will
    // not be used.
    ushort structure_id;
  

  public:
    Space(): structure(false), data(M_WALL) {}
    Space(bool is_st, ushort m_type, ushort st_type):
      structure(is_st, path_type(m_type), structure_id(st_type) {}
  
  };
 
}

#endif
