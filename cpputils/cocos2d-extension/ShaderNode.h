//
//  ShaderNode.h
//  mgbx-client
//
//  Created by Coder-1-Mac on 15-3-11.
//
//

#ifndef __mgbx_client__ShaderNode__
#define __mgbx_client__ShaderNode__

#include <stdio.h>
#include "2d/CCNode.h"

class ShaderNode: public cocos2d::Node
{
public:
    ShaderNode() {}
    bool initWithVertex(const char *vert,const char * frag);
    void loadShaderVertex(const char * vert,const char * frag);
    virtual void update(float dt);
    virtual void setContentSize(const cocos2d::Size & var);
//    virtual void setColor(cocos2d::Color4F newColor);
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags);
//    static ShaderNode * shaderNodeWithVertex(const char * vert,const char * frag);
    CREATE_FUNC(ShaderNode);
private:

	GLuint m_uniformResolution = 0;
	GLuint m_uniformTime = 0;
	GLuint m_uniformTex0 = 0;
	GLuint m_uniformCenter = 0;
	GLuint m_attributeColor = 0;
	GLuint m_attributePosition = 0;

	float m_time = 0.0f;
    cocos2d::Vec2 m_resolution;
	GLuint m_texture = 0;
    GLfloat color[4];
};
#endif /* defined(__mgbx_client__ShaderNode__) */
