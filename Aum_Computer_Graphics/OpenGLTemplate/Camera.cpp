#include "camera.h"
#include "CatmullRom.h"
#include "gamewindow.h"

// Constructor for camera -- initialise with some default values
CCamera::CCamera() {
    m_position = glm::vec3(0.0f, 10.0f, 100.0f);
    m_view = glm::vec3(0.0f, 0.0f, 0.0f);
    m_upVector = glm::vec3(0.0f, 1.0f, 0.0f);
    m_speed = 0.025f;

    // set current distance to 0
    // m_currentDistance = 0.0f;
    m_currentDistance = 20.f;

    m_cameraRotation = 0.f;
    m_cameraSpeed = 0.1f;
    m_freeRoamSpeed = 2.f;
    // m_cameraSpeed = 0.1f;
}

CCamera::~CCamera() {}

// Set the camera at a specific position, looking at the view point, with a given up vector
void CCamera::Set(const glm::vec3& position, const glm::vec3& viewpoint, const glm::vec3& upVector) {
    m_position = position;
    m_view = viewpoint;
    m_upVector = upVector;

}

// Respond to mouse movement
void CCamera::SetViewByMouse() {
    int middle_x = GameWindow::SCREEN_WIDTH >> 1;
    int middle_y = GameWindow::SCREEN_HEIGHT >> 1;

    float angle_y = 0.0f;
    float angle_z = 0.0f;
    static float rotation_x = 0.0f;

    POINT mouse;
    GetCursorPos(&mouse);

    if (mouse.x == middle_x && mouse.y == middle_y) {
        return;
    }

    SetCursorPos(middle_x, middle_y);

    angle_y = (float)(middle_x - mouse.x) / 100000.0f;
    angle_z = (float)(middle_y - mouse.y) / 100000.0f;

    rotation_x -= angle_z;

    float maxAngle = 1.56f; // Just a little bit below PI / 2

    if (rotation_x > maxAngle) {
        rotation_x = maxAngle;
    }
    else if (rotation_x < -maxAngle) {
        rotation_x = -maxAngle;
    }
    else {
        glm::vec3 cross = glm::cross(m_view - m_position, m_upVector);
        glm::vec3 axis = glm::normalize(cross);

        RotateViewPoint(angle_z, axis);
    }

    RotateViewPoint(angle_y, glm::vec3(0, 1, 0));
}

void CCamera::SetViewBySpline(double dt, CCatmullRom* catmullRom) {

    // on track
    // makes camera spin around the spline

    // // camera rotation changes based on key presses
    // if (GetKeyState(VK_LEFT) & 0x80) {
    //     m_cameraRotation -= dt * 0.001f;
    // }
    // else if (GetKeyState(VK_RIGHT) & 0x80) {
    //     m_cameraRotation += dt * 0.001f;
    // }


    m_currentDistance += dt * m_cameraSpeed; // increment by 0.1

    glm::vec3 p;
    glm::vec3 pNext;

    catmullRom->Sample(m_currentDistance, p);
    catmullRom->Sample(m_currentDistance +  0.1f, pNext);

    glm::vec3 tangent = pNext - p;
    tangent = glm::normalize(tangent);
    glm::vec3 normal = glm::normalize(glm::cross(tangent, glm::vec3(0, 1, 0)));
    glm::vec3 binormal = glm::normalize(glm::cross(normal, tangent));
    glm::vec3 up = glm::rotate(glm::vec3(0, 1, 0), m_cameraRotation, tangent);

    // First Person Camera
    if (cameraType == FIRST_PERSON) {
        catmullRom->Sample(m_currentDistance, p);
        catmullRom->Sample(m_currentDistance +  0.1f, pNext);
        glm::vec3 tangent = pNext - p;
        tangent = glm::normalize(tangent);
        glm::vec3 normal = glm::normalize(glm::cross(tangent, glm::vec3(0, 1, 0)));
        glm::vec3 binormal = glm::normalize(glm::cross(normal, tangent));

        p = p + normal * mPositionOffset;
        p += 1.0f * binormal;
        glm::vec3 up = glm::rotate(glm::vec3(0, 1, 0), m_cameraRotation, tangent);
        Set(p, p + 10.0f * tangent, up);

    }
        // Third Person Camera
    else if (cameraType == THIRD_PERSON) {
        catmullRom->Sample(m_currentDistance - firstPersonCameraOffsetFromCar, p);
        catmullRom->Sample(m_currentDistance - firstPersonCameraOffsetFromCar +  0.1f, pNext);
        glm::vec3 tangent = pNext - p;
        tangent = glm::normalize(tangent);
        glm::vec3 normal = glm::normalize(glm::cross(tangent, glm::vec3(0, 1, 0)));
        glm::vec3 binormal = glm::normalize(glm::cross(normal, tangent));

        p += 3.0f * binormal;
        glm::vec3 up = glm::rotate(glm::vec3(0, 1, 0), m_cameraRotation, tangent);
        Set(p, p + 10.0f * tangent, up);
    }
        // Side View Camera
    else if (cameraType == SIDE_VIEW) {
        catmullRom->Sample(m_currentDistance, p);
        catmullRom->Sample(m_currentDistance +  0.1f, pNext);
        glm::vec3 tangent = pNext - p;
        tangent = glm::normalize(tangent);
        glm::vec3 normal = glm::normalize(glm::cross(tangent, glm::vec3(0, 1, 0)));
        glm::vec3 binormal = glm::normalize(glm::cross(normal, tangent));

        p += 10.0f * normal;
        glm::vec3 up = glm::rotate(glm::vec3(0, 1, 0), m_cameraRotation, tangent);
        Set(p, pNext + tangent , up);
    }
    // Other Side View Camera
    else if (cameraType == OTHER_SIDE_VIEW) {
        catmullRom->Sample(m_currentDistance, p);
        catmullRom->Sample(m_currentDistance +  0.1f, pNext);
        glm::vec3 tangent = pNext - p;
        tangent = glm::normalize(tangent);
        glm::vec3 normal = glm::normalize(glm::cross(tangent, glm::vec3(0, 1, 0)));
        glm::vec3 binormal = glm::normalize(glm::cross(normal, tangent));

        p += -10.0f * normal;
        glm::vec3 up = glm::rotate(glm::vec3(0, 1, 0), m_cameraRotation, tangent);
        Set(p, pNext + tangent , up);
    }
        // Top View Camera
    else if (cameraType == TOP_VIEW) {
        catmullRom->Sample(m_currentDistance, p);
        catmullRom->Sample(m_currentDistance +  0.1f, pNext);
        glm::vec3 tangent = pNext - p;
        tangent = glm::normalize(tangent);
        glm::vec3 normal = glm::normalize(glm::cross(tangent, glm::vec3(0, 1, 0)));
        glm::vec3 binormal = glm::normalize(glm::cross(normal, tangent));

        p += 15.0f * binormal;
        glm::vec3 up = glm::rotate(glm::vec3(0, 1, 0), m_cameraRotation, tangent);
        Set(p, pNext + tangent , up);
    }
        // Free View Camera
    else if (cameraType == FREE_VIEW) { }
 
}

// Rotate the camera view point -- this effectively rotates the camera since it is looking at the view point
void CCamera::RotateViewPoint(float fAngle, const glm::vec3& vPoint) {
    glm::vec3 vView = m_view - m_position;

    glm::mat4 R = glm::rotate(glm::mat4(1), fAngle * 180.0f / (float)M_PI, vPoint);
    glm::vec4 newView = R * glm::vec4(vView, 1);

    m_view = m_position + glm::vec3(newView);
}

// Strafe the camera (side to side motion)
void CCamera::Strafe(double direction) {
    float speed = (float)(m_speed * direction);

    m_position.x = m_position.x + m_strafeVector.x * speed;
    m_position.z = m_position.z + m_strafeVector.z * speed;

    m_view.x = m_view.x + m_strafeVector.x * speed;
    m_view.z = m_view.z + m_strafeVector.z * speed;
}

// Advance the camera (forward / backward motion)
void CCamera::Advance(double direction) {
    float speed = (float)(m_speed * direction);

    glm::vec3 view = glm::normalize(m_view - m_position);
    m_position = m_position + view * speed;
    m_view = m_view + view * speed;

}

// Update the camera to respond to mouse motion for rotations and keyboard for translation
void CCamera::Update(double dt, CCatmullRom* catmullRom) {


    // by mouse and keyboard
    glm::vec3 vector = glm::cross(m_view - m_position, m_upVector);
    m_strafeVector = glm::normalize(vector);

    SetViewByMouse();
    TranslateByKeyboard(dt);

    SetViewBySpline(dt, catmullRom);

}


// Update the camera to respond to key presses for translation
void CCamera::TranslateByKeyboard(double dt) {
    if (GetKeyState('W') & 0x80) {
        Advance(m_freeRoamSpeed * dt);
    }

    if (GetKeyState('S') & 0x80) {
        Advance(-m_freeRoamSpeed * dt);
    }

    if (GetKeyState('A') & 0x80) {
        Strafe(-m_freeRoamSpeed * dt);
    }

    if (GetKeyState('D') & 0x80) {
        Strafe(m_freeRoamSpeed * dt);
    }
}

// Return the camera position
glm::vec3 CCamera::GetPosition() const {
    return m_position;
}

// Return the camera view point
glm::vec3 CCamera::GetView() const {
    return m_view;
}

// Return the camera up vector
glm::vec3 CCamera::GetUpVector() const {
    return m_upVector;
}

// Return the camera strafe vector
glm::vec3 CCamera::GetStrafeVector() const {
    return m_strafeVector;
}

// Return the camera perspective projection matrix
glm::mat4* CCamera::GetPerspectiveProjectionMatrix() {
    return &m_perspectiveProjectionMatrix;
}

// Return the camera orthographic projection matrix
glm::mat4* CCamera::GetOrthographicProjectionMatrix() {
    return &m_orthographicProjectionMatrix;
}

// Set the camera perspective projection matrix to produce a view frustum with a specific field of view, aspect ratio, 
// and near / far clipping planes
void CCamera::SetPerspectiveProjectionMatrix(float fov, float aspectRatio, float nearClippingPlane, float farClippingPlane) {
    m_perspectiveProjectionMatrix = glm::perspective(fov, aspectRatio, nearClippingPlane, farClippingPlane);
}

// The the camera orthographic projection matrix to match the width and height passed in
void CCamera::SetOrthographicProjectionMatrix(int width, int height) {
    m_orthographicProjectionMatrix = glm::ortho(0.0f, float(width), 0.0f, float(height));
}

// Get the camera view matrix
glm::mat4 CCamera::GetViewMatrix() {
    return glm::lookAt(m_position, m_view, m_upVector);
}

// The normal matrix is used to transform normals to eye coordinates -- part of lighting calculations
glm::mat3 CCamera::ComputeNormalMatrix(const glm::mat4& modelViewMatrix) {
    return glm::transpose(glm::inverse(glm::mat3(modelViewMatrix)));
}
