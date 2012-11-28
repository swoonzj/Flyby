//Camera Class Header

#include "Angel.h"



#ifndef _CAMERA_H
#define _CAMERA_H


class Camera{

public:

	Camera() ;
	Camera(vec4 p, GLfloat h, GLfloat v) ;
	Camera(vec4 p, vec4 t, vec4 u) ;
	Camera(GLuint px,GLuint py,GLuint pz,GLuint tx,GLuint ty,GLuint tz,GLuint ux,GLuint uy,GLuint uz) ;
	
	void SetCamera(vec4 cPosition, GLfloat h, GLfloat v) ;
	void RotateCamera(GLfloat h, GLfloat v) ;
	void SlideCamera(GLfloat h, GLfloat v) ;
	void MoveCamera(int d) ;

	vec4 position ;
	vec4 target ;
	vec4 up ;

	GLfloat hTheta ;
	GLfloat vTheta ;

	GLuint radius ;
	GLfloat distance ;


} ;

#endif
