#ifndef USEFULL_THINGS_H_INCLUDED
#define USEFULL_THINGS_H_INCLUDED

#include <cstdlib>
#include <ctime>
#include <string>

enum GameState
{
    LOADER=1,
    PRESENTATION,
    MAINMENUE,
    PREPARING,
    MULTIPREPARE,
    MULTIPLAYER,
    OPTIONING,
    EXITING,
};
enum LaserType
{

};

struct MultiParamValues
{
    unsigned int VSO;
    unsigned int ESO;
};
typedef MultiParamValues MpValues;

#endif // USEFULL_THINGS_H_INCLUDED
