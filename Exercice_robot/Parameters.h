#ifndef PARAMETERS_H
#define PARAMETERS_H

#define PI 3.14159265358979323846
#define MILLION 1000000

namespace Parameters
{
    const unsigned int STEP_DURATION_MILLISECONDS = 100; // deltaT
    // TO DO move it to SimulatorEngine project

    const int TABLE_WIDTH = 3000,
              TABLE_HEIGHT = 2000,
              TEAM_A_MAIN_ROBOT_INIT_X = 250,
              TEAM_A_MAIN_ROBOT_INIT_Y = 1000,
              TEAM_A_MAIN_ROBOT_LENGTH = 250,
              TEAM_A_MAIN_ROBOT_WIDTH = 200;

    const int SIMULATOR_SCREEN_WIDTH = 900,
              SIMULATOR_SCREEN_HEIGHT = 600;

    const double ROBOT_MAX_SPEED = 100.0 * STEP_DURATION_MILLISECONDS / 1000 ; // 100 mm per 1 sec


    enum Direction { LEFT, RIGHT };
    const double EAST = 0,
                 WEST = PI,
                 SOUTH = -0.5*PI,
                 NORTH = 0.5*PI;
                 //RIGHTTURNFULLANGLE = 0.5*Math.PI, //value set according to screen pixel coordinate reference
                 //LEFTTURNFULLANGLE = -0.5*Math.PI;
    const double STEP_TURN_ANGLE = PI / 4 *  STEP_DURATION_MILLISECONDS / 1000; // 10 degre

}



#endif // PARAMETERS_H
