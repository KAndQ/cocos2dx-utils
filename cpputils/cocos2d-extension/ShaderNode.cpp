//
//  ShaderNode.cpp
//  mgbx-client
//
//  Created by Coder-1-Mac on 15-3-11.
//
//

#include "ShaderNode.h"
#include "cocos2d.h"
#include "base/ccTypes.h"

void ShaderNode::loadShaderVertex(const char * vert,const char * frag)
{
    cocos2d::GLProgram * shader = new  cocos2d::GLProgram();
    shader->initWithFilenames(vert, frag);
    //绑定attribute变量
    shader->bindAttribLocation("a_position",0);
    shader->bindAttribLocation("a_color", 1);
    shader->link();
    //获取attribute变量标识
    m_attributeColor = glGetAttribLocation(shader->getProgram(), "a_color");
    m_attributePosition = glGetAttribLocation(shader->getProgram(), "a_position");
    shader->updateUniforms();
    
    m_uniformCenter = glGetUniformLocation(shader->getProgram(), "center");
    m_uniformResolution = glGetUniformLocation(shader->getProgram(), "resolution");
    m_uniformTime = glGetUniformLocation(shader->getProgram(), "time");
    m_uniformTex0 = glGetUniformLocation(shader->getProgram(), "tex0");
    
    //使用着色器程序
    this->setGLProgram(shader);
    shader->release();
}

bool ShaderNode::initWithVertex(const char *vert, const char *frag)
{
    loadShaderVertex(vert, frag);
    m_texture = cocos2d::TextureCache::sharedTextureCache()->addImage("transparent.png")->getName();
    setContentSize(cocos2d::CCSizeMake(1024,768));
    setColor(cocos2d::Color3B(125, 125, 255));
    m_time = 0;
    scheduleUpdate();
    return true;
}

void ShaderNode::update(float dt)
{
    m_time += dt;
}

void ShaderNode::setContentSize(const cocos2d::Size &var)
{
    Node::setContentSize(var);
    m_resolution = cocos2d::Vec2(getContentSize().width,getContentSize().height);
}

void ShaderNode::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags)
{
    CC_NODE_DRAW_SETUP();
    //传递uniform变量
    cocos2d::GLProgram * shader = getGLProgram();
    shader->setUniformLocationWith2f(m_uniformCenter, 480.0,320.0);
    shader->setUniformLocationWith2f(m_uniformResolution, m_resolution.x, m_resolution.y);
    shader->setUniformLocationWith1i(m_uniformTex0,0);
    glUniform1f(m_uniformTime, m_time);
    
    //获取attribute变量
    cocos2d::Size size = this->getContentSize();
    float w = size.width;
    float h = size.height;
    
    cocos2d::ccGLBindTexture2D(m_texture); //绑定文理
    glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 0, 0, w, h, 0); //复制文理数据
    glEnableVertexAttribArray(m_attributePosition);
    glDisableVertexAttribArray(m_attributeColor);
    
    //传递attribute变量
    GLfloat vertices[12] = {
        0,0,w,0,
        w,h,0,0,
        0,h,w,h,
    };
    glVertexAttribPointer(m_attributePosition, 2, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttrib4fv(m_attributeColor, color);
    
    //绘制
    glDrawArrays(GL_TRIANGLES, 0, 6);
}