#include "../common/common.h"

class quaternion {
public:
    float x, y, z, w;     
    quaternion();
    quaternion(float x, float y, float z);
    ~quaternion();

    void set_rotation(float x, float y, float z);
    void rotate(float x, float y, float z, float theta);
};
