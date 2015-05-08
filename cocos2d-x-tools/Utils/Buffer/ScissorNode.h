//
//  ScissorNode.h
//  mgbx-client
//
//  Created by Coder-1-Mac on 15-3-1.
//
//

#ifndef __mgbx_client__ScissorNode__
#define __mgbx_client__ScissorNode__

#include <stdio.h>

#include "2d/CCNode.h"
#include "math/Mat4.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCCustomCommand.h"
class ScissorNode : public cocos2d::Node
{
public:
    virtual void visit(cocos2d::Renderer *renderer, const cocos2d::Mat4& parentTransform, uint32_t parentFlags);
    virtual void setArgs(int x, int y, int width, int height);
    CREATE_FUNC(ScissorNode);
    void setModel(int model);
    ScissorNode();
private:
    float m_rect_x;
    float m_rect_y;
    float m_rect_width;
    float m_rect_height;
    int m_model;
    cocos2d::CustomCommand _beforeVisitCmdScissor;
    cocos2d::CustomCommand _afterVisitCmdScissor;
    void setBefore();
    void setAfter();
    
};

#endif /* defined(__mgbx_client__ScissorNode__) */
