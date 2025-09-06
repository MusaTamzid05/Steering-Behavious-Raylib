#ifndef MCAMERA_H
#define MCAMERA_H

#include <raylib.h>

class MCamera {

    public:
        virtual ~MCamera();

        static MCamera* get_instance();

        bool is_camera_init;
        void init(const Vector3& position);

        Camera camera;


    private:
        MCamera();
        static MCamera* m_instance;

};


#endif
