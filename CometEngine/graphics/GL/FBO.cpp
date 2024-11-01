#include "FBO.h"

FBO::FBO()
{
	glGenFramebuffers(1, &id);
	glBindFramebuffer(GL_FRAMEBUFFER, id);
}

void FBO::bind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, id);
}
