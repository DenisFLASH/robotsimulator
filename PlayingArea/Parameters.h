#ifndef PARAMETERS_H
#define PARAMETERS_H

#define PI 3.14159265358979323846

namespace Parameters
{

    const unsigned int STEP_DURATION_MICROSECONDS = 1000000; // 1 sec
    // TO DO move it to SimulatorEngine project

    const int TABLE_WIDTH = 3000,
              TABLE_HEIGHT = 2000,
              TEAM_A_MAIN_ROBOT_INIT_X = 250,
              TEAM_A_MAIN_ROBOT_INIT_Y = 1000,
              TEAM_A_MAIN_ROBOT_RADIUS = 150;

    const double TEAM_A_MAIN_ROBOT_SPEED = 50.0 * (STEP_DURATION_MICROSECONDS / 1000000); // 50 mm per 1 sec



    enum Direction { LEFT, RIGHT };
    const double EAST = 0, // !!! CLOCKWISE trigonometric unit, according to screen pixel coordinate reference
                 WEST = PI,
                 SOUTH = 0.5*PI,
                 NORTH = -0.5*PI;
                 //RIGHTTURNFULLANGLE = 0.5*Math.PI, //value set according to screen pixel coordinate reference
                 //LEFTTURNFULLANGLE = -0.5*Math.PI;
}



#endif // PARAMETERS_H
