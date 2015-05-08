//
//  ScissorNode.cpp
//  mgbx-client
//
//  Created by Coder-1-Mac on 15-3-1.
//
//

#include "ScissorNode.h"
#include "cocos2d.h"

void ScissorNode::visit(cocos2d::Renderer *renderer, const cocos2d::Mat4& parentTransform, uint32_t parentFlags)
{
    //启动遮罩效果
    _beforeVisitCmdScissor.init(_globalZOrder);
    _beforeVisitCmdScissor.func = CC_CALLBACK_0(ScissorNode::setBefore, this);
    renderer->addCommand(&_beforeVisitCmdScissor);
    Node::visit(renderer,parentTransform,parentFlags);
    //关闭遮罩效果

    _afterVisitCmdScissor.init(_globalZOrder);
    _afterVisitCmdScissor.func = CC_CALLBACK_0(ScissorNode::setAfter, this);
    renderer->addCommand(&_afterVisitCmdScissor);
}

void ScissorNode::setArgs(int x, int y, int width, int height)
{
    this->m_rect_x = x ;
    this->m_rect_y = y ;
    this->m_rect_width = width;
    this->m_rect_height = height;
}

void ScissorNode::setBefore()
{
    glEnable(GL_SCISSOR_TEST);
    cocos2d::CCPoint pos= cocos2d::Point::ZERO;
    pos= this->convertToWorldSpace(pos);//获取屏幕绝对位置
    
//    CCLOG("屏幕坐标%f - %f",pos.x,pos.y);
    //框架使用方法
    if (m_model == 1) {
        auto glview = cocos2d::Director::getInstance()->getOpenGLView();
        glview->setScissorInPoints(pos.x,pos.y,m_rect_width,m_rect_height);
    }else {
        if (m_model == 2) {
            auto glview = cocos2d::Director::getInstance()->getOpenGLView();
            glview->setScissorInPoints(pos.x - m_rect_width / 2,pos.y - m_rect_height / 2,m_rect_width,m_rect_height);
        }
        //其他模式之后扩展
    }
    
    //简单粗暴方法,不考虑缩放
//    glScissor(pos.x,pos.y ,m_rect_width,m_rect_height);
}

void ScissorNode::setAfter()
{
    glDisable(GL_SCISSOR_TEST);
}
void ScissorNode::setModel(int model)
{
    m_model = model;
}
ScissorNode::ScissorNode()
{
    m_model = 1;
}