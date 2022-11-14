

#include "includes/cub3d.h"

int main(){
  
  mlx_t *mlx;

  mlx = mlx_init(640, 640, "MLX$", true);
  if (!mlx)
    return (0);

  double posX = 22, posY = 12;  //x and y start position
  double rayDirX = -1, rayDirY = 0; //initial direction vector
  double planeX = 0, planeY = 1; //the 2d raycaster version of camera plan
    //which box of the map we're in
  int mapX = (int)posX;
  int mapY = (int)posY;

  //length of ray from current position to next x or y-side
  double sideDistX;
  double sideDistY;

    //length of ray from one x or y-side to next x or y-side
  double deltaDistX;
  if (rayDirX == 0)
    deltaDistX = DBL_MAX;
  else
    deltaDistX = abs(1/ rayDirX);
  double deltaDistY;
  if (rayDirY == 0)
    deltaDistY = DBL_MAX;
  else
    deltaDistY = abs(1/rayDirY);
  double perpWallDist;

  //what direction to step in x or y-direction (either +1 or -1)
  int stepX;
  int stepY;

  int hit = 0; //was there a wall hit?
  int side; //was a NS or a EW wall hit?
}
