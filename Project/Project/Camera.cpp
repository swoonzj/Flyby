//Camera Class

#include "Camera.h"


Camera::Camera(){

	position = vec4(0.0, 0.0, 0.0, 1.0) ;
	//up = vec4(0.0, 1.0, 0.0, 1.0) ;
	//target = vec4(0.0, 0.0, 1.0, 1.0) ;

	radius =  1 ;
	distance = 0.01 ;
	hTheta = M_PI/2 ;
	vTheta = 0.0 ;

	SetCamera(position, hTheta, vTheta) ;
}

Camera::Camera(vec4 p, GLfloat h, GLfloat v){

	position = p ;
	hTheta = h ;
	vTheta = v ;

	radius = 1 ;
	distance = 0.01 ;

	SetCamera(position, h, v) ;

}

Camera::Camera( vec4 p, vec4 t, vec4 u){

	position = p ;
	target = t ;
	up = u ;
	hTheta = vTheta = 0 ;
	radius = 1 ;
	distance = 0.1 ;
}

Camera::Camera(GLuint px,GLuint py,GLuint pz,GLuint tx,GLuint ty,GLuint tz,GLuint ux,GLuint uy,GLuint uz){

	position = vec4(px, py, pz, 1) ;
	target = vec4(tx,ty,tz,1) ;
	up = vec4(ux,uy,uz,1) ;
	hTheta = vTheta = 0 ;
	radius = 1 ;
	distance = 0.1 ;
}


//sets the target and up vectors based on the camera position and angles h and v
void Camera::SetCamera(vec4 cPosition, GLfloat h, GLfloat v){

	target.y = position.y + radius * sin(v) ;
	target.x = position.x + radius * cos(v) * cos(h) ;
	target.z = position.z + radius * cos(v) * sin(h) ;

	up.x = position.x - target.x ;
	up.z = position.z - target.z ;
	up.y = position.y + radius * sin(v + M_PI/2) ;



}

//rotates camera h radians horizontally and v radians vertically
void Camera::RotateCamera(GLfloat h, GLfloat v){

	hTheta += h ;
	vTheta += v ;
	

	SetCamera(position, hTheta, vTheta) ;

}

// h and v are 1 or 0 indicating whether it slides in that direction or not
void Camera::SlideCamera(GLfloat h, GLfloat v){

	position.y += v*distance ;
	position.x += h*distance * cos(hTheta + M_PI/2) ;
	position.z += h*distance * sin(hTheta + M_PI/2) ;

	SetCamera(position, hTheta, vTheta) ;
}

//moves camera forward or backward depending if d is +/- 1
void Camera::MoveCamera(int d){

	position.y += d*distance * sin(vTheta) ;
	position.x += d*distance * cos(vTheta) * cos(hTheta) ;
	position.z += d*distance * cos(vTheta) * sin(hTheta) ;

	SetCamera(position, hTheta, vTheta) ;

}
