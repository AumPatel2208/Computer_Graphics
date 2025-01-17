#include "CatmullRom.h"
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>


CCatmullRom::CCatmullRom() {
    m_vertexCount = 0;
}

CCatmullRom::~CCatmullRom() {}

// Perform Catmull Rom spline interpolation between four points, interpolating the space between p1 and p2
glm::vec3 CCatmullRom::Interpolate(glm::vec3& p0, glm::vec3& p1, glm::vec3& p2, glm::vec3& p3, float t) {
    float t2 = t * t;
    float t3 = t2 * t;

    glm::vec3 a = p1;
    glm::vec3 b = 0.5f * (-p0 + p2);
    glm::vec3 c = 0.5f * (2.0f * p0 - 5.0f * p1 + 4.0f * p2 - p3);
    glm::vec3 d = 0.5f * (-p0 + 3.0f * p1 - 3.0f * p2 + p3);

    return a + b * t + c * t2 + d * t3;

}


void CCatmullRom::SetControlPoints() {
    // Set control points (m_controlPoints) here, or load from disk
    // m_controlPoints.push_back(glm::vec3(100, 5, 0));
    // m_controlPoints.push_back(glm::vec3(71, 5, 71));
    // m_controlPoints.push_back(glm::vec3(0, 5, 100));
    // m_controlPoints.push_back(glm::vec3(-71, 5, 71));
    // m_controlPoints.push_back(glm::vec3(-100, 5, 0));
    // m_controlPoints.push_back(glm::vec3(-71, 5, -71));
    // m_controlPoints.push_back(glm::vec3(0, 5, -100));
    // m_controlPoints.push_back(glm::vec3(71, 5, -71));


    const float xScale = 10.f;
    const float zScale = 10.f;
    const float yScale = 10.f;
    const float xOffset = 0 * xScale;
    const float zOffset = 0 * zScale;
    const float yOffset = 10 * yScale;
    ///// PATH A  ////////
    /*
    m_controlPoints.push_back(glm::vec3(xOffset + 0, yOffset + 0, zOffset + -80));
    m_controlPoints.push_back(glm::vec3(xOffset + 30, yOffset + 0, zOffset + -60));
    m_controlPoints.push_back(glm::vec3(xOffset + 90, yOffset + -30, zOffset + -30));
    m_controlPoints.push_back(glm::vec3(xOffset + 140, yOffset + 0, zOffset + 30));
    // changed
    // m_controlPoints.push_back(glm::vec3(xOffset + 0, yOffset + 0, zOffset + 60));
    m_controlPoints.push_back(glm::vec3(xOffset + 0, yOffset + 0, zOffset + 100));

    m_controlPoints.push_back(glm::vec3(xOffset + -60, yOffset + 20, zOffset + 40));
    m_controlPoints.push_back(glm::vec3(xOffset + -100, yOffset + 40, zOffset + 20));
    m_controlPoints.push_back(glm::vec3(xOffset + -100, yOffset + 0, zOffset + -20));
    // changed
    // m_controlPoints.push_back(glm::vec3(xOffset + -30, yOffset + 0, zOffset + -40));
    // m_controlPoints.push_back(glm::vec3(xOffset + -30, yOffset + -20, zOffset + -40));
    // changed due to crimp
    m_controlPoints.push_back(glm::vec3(xOffset + -70, yOffset + 0, zOffset + -60));
    // m_controlPoints.push_back(glm::vec3(xOffset + -50, yOffset + 0, zOffset + -80));
    // changed due to crimp
    m_controlPoints.push_back(glm::vec3(xOffset + -40, yOffset + 0, zOffset + -90));
    // m_controlPoints.push_back(glm::vec3(xOffset + -30, yOffset + 0, zOffset + -80));
    */

    ///// PATH B  ////////


    m_controlPoints.emplace_back(xOffset + xScale * 59.0, yOffset + yScale * 5.0, zOffset + zScale * 7.0);
    m_controlPoints.emplace_back(xOffset + xScale * 62.0, yOffset + yScale * 7.0, zOffset + zScale * 10.0);
    m_controlPoints.emplace_back(xOffset + xScale * 65.0, yOffset + yScale * 9.0, zOffset + zScale * 12.0);
    m_controlPoints.emplace_back(xOffset + xScale * 69.0, yOffset + yScale * 10.0, zOffset + zScale * 12.0);
    m_controlPoints.emplace_back(xOffset + xScale * 72.0, yOffset + yScale * 10.0, zOffset + zScale * 12.0);
    m_controlPoints.emplace_back(xOffset + xScale * 77.0, yOffset + yScale * 10.0, zOffset + zScale * 11.0);
    m_controlPoints.emplace_back(xOffset + xScale * 79.0, yOffset + yScale * 10.0, zOffset + zScale * 7.0);
    m_controlPoints.emplace_back(xOffset + xScale * 80.0, yOffset + yScale * 10.0, zOffset + zScale * 2.0);
    m_controlPoints.emplace_back(xOffset + xScale * 79.0, yOffset + yScale * 10.0, zOffset + zScale * -3.0);
    m_controlPoints.emplace_back(xOffset + xScale * 73.0, yOffset + yScale * 10.0, zOffset + zScale * -7.0);
    m_controlPoints.emplace_back(xOffset + xScale * 64.0, yOffset + yScale * 10.0, zOffset + zScale * -7.0);
    m_controlPoints.emplace_back(xOffset + xScale * 57.0, yOffset + yScale * 9.0, zOffset + zScale * -7.0);
    m_controlPoints.emplace_back(xOffset + xScale * 51.0, yOffset + yScale * 7.0, zOffset + zScale * -5.0);
    m_controlPoints.emplace_back(xOffset + xScale * 43.0, yOffset + yScale * 4.0, zOffset + zScale * -3.0);
    m_controlPoints.emplace_back(xOffset + xScale * 36.0, yOffset + yScale * 1.0, zOffset + zScale * 0.0);
    m_controlPoints.emplace_back(xOffset + xScale * 31.0, yOffset + yScale * 0.0, zOffset + zScale * 6.0);
    m_controlPoints.emplace_back(xOffset + xScale * 25.0, yOffset + yScale * 0.0, zOffset + zScale * 10.0);
    m_controlPoints.emplace_back(xOffset + xScale * 17.0, yOffset + yScale * 0.0, zOffset + zScale * 10.0);
    m_controlPoints.emplace_back(xOffset + xScale * 11.0, yOffset + yScale * 0.0, zOffset + zScale * 7.0);
    m_controlPoints.emplace_back(xOffset + xScale * 10.0, yOffset + yScale * 0.0, zOffset + zScale * 0.0);
    m_controlPoints.emplace_back(xOffset + xScale * 10.0, yOffset + yScale * 2.0, zOffset + zScale * -6.0);
    m_controlPoints.emplace_back(xOffset + xScale * 10.0, yOffset + yScale * 7.0, zOffset + zScale * -13.0);
    m_controlPoints.emplace_back(xOffset + xScale * 10.0, yOffset + yScale * 15.0, zOffset + zScale * -19.0);
    m_controlPoints.emplace_back(xOffset + xScale * 10.0, yOffset + yScale * 27.0, zOffset + zScale * -26.0);
    m_controlPoints.emplace_back(xOffset + xScale * 10.0, yOffset + yScale * 30.0, zOffset + zScale * -31.0);
    m_controlPoints.emplace_back(xOffset + xScale * 10.0, yOffset + yScale * 30.0, zOffset + zScale * -37.0);
    m_controlPoints.emplace_back(xOffset + xScale * 10.0, yOffset + yScale * 26.0, zOffset + zScale * -42.0);
    m_controlPoints.emplace_back(xOffset + xScale * 10.0, yOffset + yScale * 20.0, zOffset + zScale * -47.0);
    m_controlPoints.emplace_back(xOffset + xScale * 10.0, yOffset + yScale * 11.0, zOffset + zScale * -52.0);
    m_controlPoints.emplace_back(xOffset + xScale * 10.0, yOffset + yScale * 2.0, zOffset + zScale * -58.0);
    m_controlPoints.emplace_back(xOffset + xScale * 10.0, yOffset + yScale * -5.0, zOffset + zScale * -65.0);
    m_controlPoints.emplace_back(xOffset + xScale * 10.0, yOffset + yScale * -9.0, zOffset + zScale * -74.0);
    m_controlPoints.emplace_back(xOffset + xScale * 10.0, yOffset + yScale * -9.0, zOffset + zScale * -84.0);
    m_controlPoints.emplace_back(xOffset + xScale * 7.0, yOffset + yScale * -9.0, zOffset + zScale * -95.0);
    m_controlPoints.emplace_back(xOffset + xScale * -4.0, yOffset + yScale * -9.0, zOffset + zScale * -100.0);
    m_controlPoints.emplace_back(xOffset + xScale * -20.0, yOffset + yScale * -9.0, zOffset + zScale * -100.0);
    m_controlPoints.emplace_back(xOffset + xScale * -28.0, yOffset + yScale * -9.0, zOffset + zScale * -105.0);
    m_controlPoints.emplace_back(xOffset + xScale * -44.0, yOffset + yScale * -6.0, zOffset + zScale * -108.0);
    m_controlPoints.emplace_back(xOffset + xScale * -55.0, yOffset + yScale * -3.0, zOffset + zScale * -106.0);
    m_controlPoints.emplace_back(xOffset + xScale * -67.0, yOffset + yScale * -2.0, zOffset + zScale * -100.0);
    m_controlPoints.emplace_back(xOffset + xScale * -73.0, yOffset + yScale * -1.0, zOffset + zScale * -93.0);
    m_controlPoints.emplace_back(xOffset + xScale * -71.0, yOffset + yScale * -1.0, zOffset + zScale * -83.0);
    m_controlPoints.emplace_back(xOffset + xScale * -67.0, yOffset + yScale * -1.0, zOffset + zScale * -77.0);
    m_controlPoints.emplace_back(xOffset + xScale * -58.0, yOffset + yScale * -1.0, zOffset + zScale * -74.0);
    m_controlPoints.emplace_back(xOffset + xScale * -55.0, yOffset + yScale * -1.0, zOffset + zScale * -71.0);
    m_controlPoints.emplace_back(xOffset + xScale * -53.0, yOffset + yScale * -1.0, zOffset + zScale * -65.0);
    m_controlPoints.emplace_back(xOffset + xScale * -53.0, yOffset + yScale * -1.0, zOffset + zScale * -60.0);
    m_controlPoints.emplace_back(xOffset + xScale * -56.0, yOffset + yScale * -1.0, zOffset + zScale * -54.0);
    m_controlPoints.emplace_back(xOffset + xScale * -56.0, yOffset + yScale * -1.0, zOffset + zScale * -47.0);
    m_controlPoints.emplace_back(xOffset + xScale * -52.0, yOffset + yScale * -2.0, zOffset + zScale * -42.0);
    m_controlPoints.emplace_back(xOffset + xScale * -45.0, yOffset + yScale * -3.0, zOffset + zScale * -37.0);
    m_controlPoints.emplace_back(xOffset + xScale * -37.0, yOffset + yScale * -5.0, zOffset + zScale * -34.0);
    m_controlPoints.emplace_back(xOffset + xScale * -27.0, yOffset + yScale * -5.0, zOffset + zScale * -35.0);
    m_controlPoints.emplace_back(xOffset + xScale * -17.0, yOffset + yScale * -3.0, zOffset + zScale * -34.0);
    m_controlPoints.emplace_back(xOffset + xScale * -10.0, yOffset + yScale * 0.0, zOffset + zScale * -34.0);
    m_controlPoints.emplace_back(xOffset + xScale * -2.0, yOffset + yScale * 3.0, zOffset + zScale * -34.0);
    m_controlPoints.emplace_back(xOffset + xScale * 7.0, yOffset + yScale * 5.0, zOffset + zScale * -34.0);
    m_controlPoints.emplace_back(xOffset + xScale * 14.0, yOffset + yScale * 5.0, zOffset + zScale * -34.0);
    m_controlPoints.emplace_back(xOffset + xScale * 19.0, yOffset + yScale * 7.0, zOffset + zScale * -34.0);
    m_controlPoints.emplace_back(xOffset + xScale * 23.0, yOffset + yScale * 10.0, zOffset + zScale * -34.0);
    m_controlPoints.emplace_back(xOffset + xScale * 28.0, yOffset + yScale * 15.0, zOffset + zScale * -34.0);
    m_controlPoints.emplace_back(xOffset + xScale * 32.0, yOffset + yScale * 21.0, zOffset + zScale * -34.0);
    m_controlPoints.emplace_back(xOffset + xScale * 42.0, yOffset + yScale * 28.0, zOffset + zScale * -34.0);
    m_controlPoints.emplace_back(xOffset + xScale * 50.0, yOffset + yScale * 28.0, zOffset + zScale * -34.0);
    m_controlPoints.emplace_back(xOffset + xScale * 59.0, yOffset + yScale * 22.0, zOffset + zScale * -34.0);
    m_controlPoints.emplace_back(xOffset + xScale * 62.0, yOffset + yScale * 17.0, zOffset + zScale * -30.0);
    m_controlPoints.emplace_back(xOffset + xScale * 62.0, yOffset + yScale * 10.0, zOffset + zScale * -24.0);
    m_controlPoints.emplace_back(xOffset + xScale * 60.0, yOffset + yScale * 5.0, zOffset + zScale * -14.0);
    m_controlPoints.emplace_back(xOffset + xScale * 58.0, yOffset + yScale * 3.0, zOffset + zScale * -7.0);
    m_controlPoints.emplace_back(xOffset + xScale * 57.0, yOffset + yScale * 3.0, zOffset + zScale * -4.0);
    m_controlPoints.emplace_back(xOffset + xScale * 57.0, yOffset + yScale * 3.0, zOffset + zScale * 0.0);
    // m_controlPoints.emplace_back(xOffset + xScale * 59.0, yOffset + yScale * 5.0, zOffset + zScale * 7.0);


    // Optionally, set upvectors (m_controlUpVectors, one for each control point as well)
}


// Determine lengths along the control points, which is the set of control points forming the closed curve
void CCatmullRom::ComputeLengthsAlongControlPoints() {
    int M = (int)m_controlPoints.size();

    float fAccumulatedLength = 0.0f;
    m_distances.push_back(fAccumulatedLength);
    for (int i = 1; i < M; i++) {
        fAccumulatedLength += glm::distance(m_controlPoints[i - 1], m_controlPoints[i]);
        m_distances.push_back(fAccumulatedLength);
    }

    // Get the distance from the last point to the first
    fAccumulatedLength += glm::distance(m_controlPoints[M - 1], m_controlPoints[0]);
    m_distances.push_back(fAccumulatedLength);
}


// Return the point (and upvector, if control upvectors provided) based on a distance d along the control polygon
bool CCatmullRom::Sample(float d, glm::vec3& p, glm::vec3& up) {
    if (d < 0)
        return false;

    int M = (int)m_controlPoints.size();
    if (M == 0)
        return false;


    float fTotalLength = m_distances[m_distances.size() - 1];

    // The the current length along the control polygon; handle the case where we've looped around the track
    float fLength = d - (int)(d / fTotalLength) * fTotalLength;

    // Find the current segment
    int j = -1;
    for (int i = 0; i < (int)m_distances.size() - 1; i++) {
        if (fLength >= m_distances[i] && fLength < m_distances[i + 1]) {
            j = i; // found it!
            break;
        }
    }

    if (j == -1)
        return false;

    // Interpolate on current segment -- get t
    float fSegmentLength = m_distances[j + 1] - m_distances[j];
    float t = (fLength - m_distances[j]) / fSegmentLength;

    // Get the indices of the four points along the control polygon for the current segment
    int iPrev = ((j - 1) + M) % M;
    int iCur = j;
    int iNext = (j + 1) % M;
    int iNextNext = (j + 2) % M;

    // Interpolate to get the point (and upvector)
    p = Interpolate(m_controlPoints[iPrev], m_controlPoints[iCur], m_controlPoints[iNext], m_controlPoints[iNextNext], t);
    if (m_controlUpVectors.size() == m_controlPoints.size())
        up = glm::normalize(Interpolate(m_controlUpVectors[iPrev], m_controlUpVectors[iCur], m_controlUpVectors[iNext], m_controlUpVectors[iNextNext], t));

    return true;
}

glm::vec3 CCatmullRom::GeneratePositionOnPath() {
    // srand (time(NULL));
    float distance = rand() % 100000;

    glm::vec3 position;
    glm::vec3 up;


    int offset = rand() % (int)width - width / 2;

    Sample(distance, position, up);

    glm::vec3 pNext;
    Sample(distance + 0.1, pNext);


    glm::vec3 tangent = glm::normalize(position - pNext);
    glm::vec3 normal = glm::normalize(glm::cross(tangent, glm::vec3(0, 1, 0)));

    // offset them
    position = position + (float)offset * normal;
    return position;
}


// Sample a set of control points using an open Catmull-Rom spline, to produce a set of iNumSamples that are (roughly) equally spaced
void CCatmullRom::UniformlySampleControlPoints(int numSamples) {
    glm::vec3 p, up;

    // Compute the lengths of each segment along the control polygon, and the total length
    ComputeLengthsAlongControlPoints();
    float fTotalLength = m_distances[m_distances.size() - 1];

    // The spacing will be based on the control polygon
    float fSpacing = fTotalLength / numSamples;

    // Call PointAt to sample the spline, to generate the points
    for (int i = 0; i < numSamples; i++) {
        Sample(i * fSpacing, p, up);
        m_centrelinePoints.push_back(p);
        if (m_controlUpVectors.size() > 0)
            m_centrelineUpVectors.push_back(up);

    }


    // Repeat once more for truly equidistant points
    m_controlPoints = m_centrelinePoints;
    m_controlUpVectors = m_centrelineUpVectors;
    m_centrelinePoints.clear();
    m_centrelineUpVectors.clear();
    m_distances.clear();
    ComputeLengthsAlongControlPoints();
    fTotalLength = m_distances[m_distances.size() - 1];
    fSpacing = fTotalLength / numSamples;
    for (int i = 0; i < numSamples; i++) {
        Sample(i * fSpacing, p, up);
        m_centrelinePoints.push_back(p);
        if (m_controlUpVectors.size() > 0)
            m_centrelineUpVectors.push_back(up);
    }

}


void CCatmullRom::CreateCentreline() {
    // Call Set Control Points
    // adds the control points to m_controlPoints
    SetControlPoints();

    // Call UniformlySampleControlPoints with the number of samples required
    // This will generate points along the centreline, and store them in m_centrelinePoints.
    UniformlySampleControlPoints(1000);

    // Create a VAO called m_vaoCentreline and a VBO to get the points onto the graphics card
    // Use VAO to store state associated with vertices
    glGenVertexArrays(1, &m_vaoCentreline);
    glBindVertexArray(m_vaoCentreline);
    // Create a VBO
    CVertexBufferObject vbo;
    vbo.Create();
    vbo.Bind();
    glm::vec2 texCoord(0.0f, 0.0f);
    glm::vec3 normal(0.0f, 1.0f, 0.0f);

    for (auto& centrelinePoint : m_centrelinePoints) {
        vbo.AddData(&centrelinePoint, sizeof(glm::vec3));
        vbo.AddData(&texCoord, sizeof(glm::vec2));
        vbo.AddData(&normal, sizeof(glm::vec3));
    }

    // Upload the VBO to the GPU
    vbo.UploadDataToGPU(GL_STATIC_DRAW);
    // Set the vertex attribute locations
    GLsizei stride = 2 * sizeof(glm::vec3) + sizeof(glm::vec2);
    // Vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, 0);
    // Texture coordinates
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, (void*)sizeof(glm::vec3));
    // Normal vectors
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(glm::vec3) + sizeof(glm::vec2)));
}


void CCatmullRom::CreateOffsetCurves() {

    for (int i = 0; i < m_centrelinePoints.size() - 1; ++i) {
        // w = path width
        glm::vec3 tangent = glm::normalize(m_centrelinePoints[i + 1] - m_centrelinePoints[i]);
        glm::vec3 normal = glm::normalize(glm::cross(tangent, glm::vec3(0, 1, 0)));
        glm::vec3 binormal = glm::normalize(glm::cross(normal, tangent));

        m_leftOffsetPoints.push_back(m_centrelinePoints[i] - (width / 2) * normal);
        m_rightOffsetPoints.push_back(m_centrelinePoints[i] + (width / 2) * normal);

    }

    // Generate two VAOs called m_vaoLeftOffsetCurve and m_vaoRightOffsetCurve, each with a VBO, and get the offset curve points on the graphics card
    // Note it is possible to only use one VAO / VBO with all the points instead.

    // Use VAO to store state associated with vertices
    glGenVertexArrays(1, &m_vaoLeftOffsetCurve);
    glBindVertexArray(m_vaoLeftOffsetCurve);
    // Create a VBO
    CVertexBufferObject vbo;
    vbo.Create();
    vbo.Bind();
    glm::vec2 texCoord(0.0f, 0.0f);
    glm::vec3 normal(0.0f, 1.0f, 0.0f);

    for (auto& leftOffsetPoint : m_leftOffsetPoints) {
        vbo.AddData(&leftOffsetPoint, sizeof(glm::vec3));
        vbo.AddData(&texCoord, sizeof(glm::vec2));
        vbo.AddData(&normal, sizeof(glm::vec3));
    }

    // Upload the VBO to the GPU
    vbo.UploadDataToGPU(GL_STATIC_DRAW);
    // Set the vertex attribute locations
    GLsizei stride = 2 * sizeof(glm::vec3) + sizeof(glm::vec2);
    // Vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, 0);
    // Texture coordinates
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, (void*)sizeof(glm::vec3));
    // Normal vectors
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(glm::vec3) + sizeof(glm::vec2)));


    // Use VAO to store state associated with vertices
    glGenVertexArrays(1, &m_vaoRightOffsetCurve);
    glBindVertexArray(m_vaoRightOffsetCurve);
    // Create a VBO
    CVertexBufferObject vbo2;
    vbo2.Create();
    vbo2.Bind();


    for (auto& rightOffsetPoint : m_rightOffsetPoints) {
        vbo2.AddData(&rightOffsetPoint, sizeof(glm::vec3));
        vbo2.AddData(&texCoord, sizeof(glm::vec2));
        vbo2.AddData(&normal, sizeof(glm::vec3));
    }

    // Upload the VBO to the GPU
    vbo2.UploadDataToGPU(GL_STATIC_DRAW);
    // Set the vertex attribute locations
    // Vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, 0);
    // Texture coordinates
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, (void*)sizeof(glm::vec3));
    // Normal vectors
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(glm::vec3) + sizeof(glm::vec2)));


}

void CCatmullRom::CreateTrack() {

    // Load texture
    m_texture.Load("resources\\textures\\track\\Glass Seamless Texture #3524.jpg");


    // Generate a VAO called m_vaoTrack and a VBO to get the offset curve points and indices on the graphics card
    // Use VAO to store state associated with vertices
    glGenVertexArrays(1, &m_vaoTrack);
    glBindVertexArray(m_vaoTrack);

    GLsizei stride = sizeof(glm::vec3) + sizeof(glm::vec2) + sizeof(glm::vec3);

    CVertexBufferObject vboTrack;
    vboTrack.Create();
    vboTrack.Bind();
    glm::vec2 texCoord(0.0f, 0.0f);
    glm::vec3 normal(0.0f, 1.0f, 0.0f);


    // put the points in
    for (int i = 0; i < m_leftOffsetPoints.size() - 1; ++i) {
        m_trackTrianglePoints.push_back(m_leftOffsetPoints[i]);
        m_trackTrianglePoints.push_back(m_rightOffsetPoints[i]);
    }
    m_trackTrianglePoints.push_back(m_leftOffsetPoints[0]);
    m_trackTrianglePoints.push_back(m_rightOffsetPoints[0]);
    m_trackTrianglePoints.push_back(m_leftOffsetPoints[1]);
    m_trackTrianglePoints.push_back(m_rightOffsetPoints[1]);


    // one set of triangles
    for (int i = 0; i < m_trackTrianglePoints.size(); ++i) {
        vboTrack.AddData(&m_trackTrianglePoints[i], sizeof(glm::vec3));
        vboTrack.AddData(&texCoord, sizeof(glm::vec2));
        vboTrack.AddData(&normal, sizeof(glm::vec3));
    }


    // janky fix for not having a triangle have a point at 0,0,0
    // vboTrack.AddData(&m_trackTrianglePoints[0], sizeof(glm::vec3));
    // vboTrack.AddData(&m_trackTrianglePoints[m_trackTrianglePoints.size() - 2], sizeof(glm::vec3));
    // vboTrack.AddData(&m_trackTrianglePoints[m_trackTrianglePoints.size() - 1], sizeof(glm::vec3));
    // vboTrack.AddData(&texCoord, sizeof(glm::vec2));
    // vboTrack.AddData(&normal, sizeof(glm::vec3));
    //
    // vboTrack.AddData(&m_trackTrianglePoints[0], sizeof(glm::vec3));
    // vboTrack.AddData(&m_trackTrianglePoints[m_trackTrianglePoints.size() - 1], sizeof(glm::vec3));
    // vboTrack.AddData(&m_trackTrianglePoints[1], sizeof(glm::vec3));
    // vboTrack.AddData(&texCoord, sizeof(glm::vec2));
    // vboTrack.AddData(&normal, sizeof(glm::vec3));


    // Upload the VBO to the GPU
    vboTrack.UploadDataToGPU(GL_STATIC_DRAW);
    // Set the vertex attribute locations
    // Vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, 0);

    // Texture coordinates
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(glm::vec3) * 3));

    // Normal vectors
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, stride, (void*)((sizeof(glm::vec3) * 3) + sizeof(glm::vec2)));

}

//
// void CCatmullRom::CreateTrack() {
//
//     // Load texture
//     m_texture.Load("resources\\textures\\track\\Glass Seamless Texture #3524.jpg");
//
//     
//     // Generate a VAO called m_vaoTrack and a VBO to get the offset curve points and indices on the graphics card
//     // Use VAO to store state associated with vertices
//     glGenVertexArrays(1, &m_vaoTrack);
//     glBindVertexArray(m_vaoTrack);
//
//     GLsizei stride = sizeof(glm::vec3) * 3 + sizeof(glm::vec2) + sizeof(glm::vec3);
//
//     CVertexBufferObject vboTrack;
//     vboTrack.Create();
//     vboTrack.Bind();
//     glm::vec2 texCoord(0.0f, 0.0f);
//     glm::vec3 normal(0.0f, 1.0f, 0.0f);
//
//
//     // put the points in
//     for (int i = 0; i < m_leftOffsetPoints.size() - 1; ++i) {
//         m_trackTrianglePoints.push_back(m_leftOffsetPoints[i]);
//         m_trackTrianglePoints.push_back(m_rightOffsetPoints[i]);
//     }
//     m_trackTrianglePoints.push_back(m_leftOffsetPoints[0]);
//     m_trackTrianglePoints.push_back(m_rightOffsetPoints[0]);
//     m_trackTrianglePoints.push_back(m_leftOffsetPoints[1]);
//     m_trackTrianglePoints.push_back(m_rightOffsetPoints[1]);
//
//
//     // one set of triangles
//     for (int i = 0; i < m_trackTrianglePoints.size() - 2; ++i) {
//         vboTrack.AddData(&m_trackTrianglePoints[i], sizeof(glm::vec3));
//         vboTrack.AddData(&m_trackTrianglePoints[i + 1], sizeof(glm::vec3));
//         vboTrack.AddData(&m_trackTrianglePoints[i + 2], sizeof(glm::vec3));
//         vboTrack.AddData(&texCoord, sizeof(glm::vec2));
//         vboTrack.AddData(&normal, sizeof(glm::vec3));
//     }
//
//
//     // janky fix for not having a triangle have a point at 0,0,0
//     vboTrack.AddData(&m_trackTrianglePoints[0], sizeof(glm::vec3));
//     vboTrack.AddData(&m_trackTrianglePoints[m_trackTrianglePoints.size() - 2], sizeof(glm::vec3));
//     vboTrack.AddData(&m_trackTrianglePoints[m_trackTrianglePoints.size() - 1], sizeof(glm::vec3));
//     vboTrack.AddData(&texCoord, sizeof(glm::vec2));
//     vboTrack.AddData(&normal, sizeof(glm::vec3));
//
//     vboTrack.AddData(&m_trackTrianglePoints[0], sizeof(glm::vec3));
//     vboTrack.AddData(&m_trackTrianglePoints[m_trackTrianglePoints.size() - 1], sizeof(glm::vec3));
//     vboTrack.AddData(&m_trackTrianglePoints[1], sizeof(glm::vec3));
//     vboTrack.AddData(&texCoord, sizeof(glm::vec2));
//     vboTrack.AddData(&normal, sizeof(glm::vec3));
//
//
//     // Upload the VBO to the GPU
//     vboTrack.UploadDataToGPU(GL_STATIC_DRAW);
//     // Set the vertex attribute locations
//     // Vertex positions
//     glEnableVertexAttribArray(0);
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, 0);
//
//     // Texture coordinates
//     glEnableVertexAttribArray(1);
//     glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(glm::vec3) * 3));
//
//     // Normal vectors
//     glEnableVertexAttribArray(2);
//     glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, stride, (void*)((sizeof(glm::vec3) * 3) + sizeof(glm::vec2)));
//
// }


void CCatmullRom::RenderCentreline() {
    // Bind the VAO m_vaoCentreline and render it
    glBindVertexArray(m_vaoCentreline);
    // m_texture.Bind();
    // Draw points and then a line loop
    // glDrawElements(GL_POINTS, m_centrelinePoints.size(), GL_UNSIGNED_INT, 0);
    // glDrawElements(GL_LINE_LOOP, m_centrelinePoints.size(), GL_UNSIGNED_INT, 0);
    glPointSize(5);
    glDrawArrays(GL_POINTS, 0, m_centrelinePoints.size());
    glDrawArrays(GL_LINE_LOOP, 0, m_centrelinePoints.size());
}

void CCatmullRom::RenderOffsetCurves() {
    // Bind the VAO m_vaoLeftOffsetCurve and render it
    glBindVertexArray(m_vaoLeftOffsetCurve);
    // m_texture.Bind();
    glPointSize(5);
    glDrawArrays(GL_POINTS, 0, m_leftOffsetPoints.size());
    glDrawArrays(GL_LINE_STRIP, 0, m_leftOffsetPoints.size());

    // Bind the VAO m_vaoRightOffsetCurve and render it
    glBindVertexArray(m_vaoRightOffsetCurve);
    // m_texture.Bind();
    glPointSize(5);
    glDrawArrays(GL_POINTS, 0, m_rightOffsetPoints.size());
    glDrawArrays(GL_LINE_STRIP, 0, m_rightOffsetPoints.size());
}


void CCatmullRom::RenderTrack() {
    // Bind the VAO m_vaoTrack and render it
    glBindVertexArray(m_vaoTrack);
    m_texture.Bind();
    // glPointSize(5);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, m_trackTrianglePoints.size());

}

int CCatmullRom::CurrentLap(float d) {

    return (int)(d / m_distances.back());

}

glm::vec3 CCatmullRom::_dummy_vector(0.0f, 0.0f, 0.0f);
