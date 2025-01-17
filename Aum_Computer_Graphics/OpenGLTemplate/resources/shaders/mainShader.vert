#version 400 core

// Structure for matrices
uniform struct Matrices
{
	mat4 projMatrix;
	mat4 modelViewMatrix; 
	mat3 normalMatrix;
} matrices;

// Structure holding light information:  its position as well as ambient, diffuse, and specular colours
struct LightInfo
{
	vec4 position;
	vec3 La;
	vec3 Ld;
	vec3 Ls;
};

// Structure holding material information:  its ambient, diffuse, and specular colours, and shininess
struct MaterialInfo
{
	vec3 Ma;
	vec3 Md;
	vec3 Ms;
	float shininess;
};



// Lights and materials passed in as uniform variables from client programme
uniform LightInfo light1; 
uniform MaterialInfo material1; 
uniform bool isFloor;

// Layout of vertex attributes in VBO
layout (location = 0) in vec3 inPosition;
layout (location = 1) in vec2 inCoord;
layout (location = 2) in vec3 inNormal;

// Vertex colour output to fragment shader -- using Gouraud (interpolated) shading
out vec3 vColour;	// Colour computed using reflectance model
out vec2 vTexCoord;	// Texture coordinate

out vec3 worldPosition;	// used for skybox
//
// FOG: Open GL Game Tutorial 16: fog https://www.youtube.com/watch?v=qslBNLeSPUc
out float visibility;
///
out MaterialInfo materialOut;
out vec4 eyePosition;
out vec3 eyeNormal;
float density = 0.005;
float gradient = 1.5;

//const float density = 0.0005;
//const float gradient = 1;

// This function implements the Phong shading model
// The code is based on the OpenGL 4.0 Shading Language Cookbook, Chapter 2, pp. 62 - 63, with a few tweaks. 
// Please see Chapter 2 of the book for a detailed discussion.
vec3 PhongModel(vec4 eyePosition, vec3 eyeNorm)
{
	vec3 s = normalize(vec3(light1.position - eyePosition));
	vec3 v = normalize(-eyePosition.xyz);
	vec3 r = reflect(-s, eyeNorm);
	vec3 n = eyeNorm;
	vec3 ambient = light1.La * material1.Ma;
	float sDotN = max(dot(s, n), 0.0f);
	vec3 diffuse = light1.Ld * material1.Md * sDotN;
	vec3 specular = vec3(0.0f);
	float eps = 0.000001f; // add eps to shininess below -- pow not defined if second argument is 0 (as described in GLSL documentation)
	if (sDotN > 0.0f) 
		specular = light1.Ls * material1.Ms * pow(max(dot(r, v), 0.0f), material1.shininess + eps);
	
	
	// toon shader
//	float intensity;
//	vec4 color;
//	intensity = dot(light1.Ld, normalize(inNormal));
//	if(intensity > 0.95)
//		color = vec4(1.0,0.5,0.5,1.0);
//	else if (intensity > 0.5)
//		color = vec4(0.6,0.3,0.3,1.0);
//	else if (intensity > 0.25)
//		color = vec4(0.4,0.2,0.2,1.0);
//	else
//		color = vec4(0.2,0.1,0.1,1.0);
	
//	return ambient + vec3(color.x,color.y,color.z) + diffuse + specular;

	return ambient + diffuse + specular;

}

// This is the entry point into the vertex shader
void main()
{	
	// have a weaker fog for the floor
	if(isFloor){
		density = 0.0005;
		gradient = 1;
	}else{
		density = 0.005;
		gradient = 1.5;	
	}
	// Save the world position for rendering the skybox
	worldPosition = inPosition;
	// fog code
	vec4 positionRelativeToCam = matrices.modelViewMatrix * vec4(worldPosition, 1);

	// Transform the vertex spatial position using 
	gl_Position = matrices.projMatrix * matrices.modelViewMatrix * vec4(inPosition, 1.0f);
	
	// Get the vertex normal and vertex position in eye coordinates
	vec3 vEyeNorm = normalize(matrices.normalMatrix * inNormal);
	vec4 vEyePosition = matrices.modelViewMatrix * vec4(inPosition, 1.0f);
	
	// fog
	float distance = length(positionRelativeToCam.xyz );
	visibility = exp(-pow((distance*density), gradient));
	visibility = clamp(visibility, 0.0, 1.0);
	
	
	// Apply the Phong model to compute the vertex colour
	vColour = PhongModel(vEyePosition, vEyeNorm);
	
	// Pass through the texture coordinate
	vTexCoord = inCoord;
	
	eyePosition = vEyePosition;
	eyeNormal = vEyeNorm;
	materialOut = material1;
} 
	