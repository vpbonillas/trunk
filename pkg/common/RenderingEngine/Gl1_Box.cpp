/*************************************************************************
*  Copyright (C) 2004 by Olivier Galizzi                                 *
*  olivier.galizzi@imag.fr                                               *
*                                                                        *
*  This program is free software; it is licensed under the terms of the  *
*  GNU General Public License v2 or later. See file LICENSE for details. *
*************************************************************************/

#include "Gl1_Box.hpp"
#include<yade/pkg-common/InteractingBox.hpp>
#include<yade/lib-opengl/OpenGLWrapper.hpp>

void Gl1_Box::go(const shared_ptr<Shape>& cg, const shared_ptr<State>&,bool wire,const GLViewInfo&)
{
	// FIXME : check that : one of those 2 lines are useless
  	glMaterialv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, Vector3f(cg->diffuseColor[0],cg->diffuseColor[1],cg->diffuseColor[2]));
	glColor3v(cg->diffuseColor);
	
	Vector3r &extents = (static_cast<InteractingBox*>(cg.get()))->extents;
	
	glScalef(2*extents[0],2*extents[1],2*extents[2]);

 	if (wire) glutWireCube(1);
 	else glutSolidCube(1);
}

YADE_PLUGIN((Gl1_Box));
YADE_REQUIRE_FEATURE(OPENGL)