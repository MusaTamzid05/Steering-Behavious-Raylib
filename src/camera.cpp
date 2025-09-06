#include "camera.h"

MCamera *MCamera::m_instance = nullptr;

MCamera::MCamera():is_camera_init(false) {

}


MCamera::~MCamera() {

}


MCamera* MCamera::get_instance() {
    if(m_instance == nullptr)
        m_instance = new MCamera();

    return m_instance;

}

void MCamera::init(const Vector3& position) {
    camera = { 0 };
    camera.position = position;
    camera.target = { 0 } ;
    camera.fovy = 45.0f;
    camera.up = { 0.0f, 1.0f, 0.0f};
    camera.projection = CAMERA_PERSPECTIVE;

    is_camera_init = true;



}
