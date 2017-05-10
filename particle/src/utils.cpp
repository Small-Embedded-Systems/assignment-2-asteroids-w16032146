/* utility functions */
#include <stdint.h>
#include <stdlib.h>
#include <math.h>


/* some numerical helper functions */
float norm(float value, float min, float max) 
{
    return (value-min)/(max-min); 
}
float lerp(float min, float max, float value) 
{
    return max*value+(1.0f-value)*min; 
}
float map(float value, float lower, float upper, float min, float max) 
{
    return lerp(min,max, norm(value,lower,upper)); 
}
/*------*/

/* random number between values, not including last
    randrange(0,360) produces numbers 0..359
*/
int randrangeUtils(int fromUtils, int toUtils)
{
    int range = toUtils-fromUtils;
    return fromUtils + rand()%range;
}

/* Convery degrees to radians */
const float piUtils = 3.1415926f;
float radiansUtils(float degreesUtils) { return degreesUtils/180*piUtils; }

