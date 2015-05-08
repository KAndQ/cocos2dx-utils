//
//  AEEffectSprite.h
//  cocos2d-x-tools
//
//  Created by Zhenyu Yao on 14/11/4.
//
//

#ifndef __cocos2d_x_tools__AEEffectSprite__
#define __cocos2d_x_tools__AEEffectSprite__

#include "cocos2d-extension/CCSpecialSprite.h"

class AvatarComponent;

/**
 * 根据 Animation 对象和动作脚本生成一次性动画, 动画播放结束后，将自动从场景中移除.
 * @author Zhenyu Yao
 */
class AEEffectSprite : public CCSpecialSprite
{
public:
    
    /**
     * 创建 AEEffectSprite 对象
     * @param components AvatarComponent 对象的集合
     */
    static AEEffectSprite * create(cocos2d::Vector<AvatarComponent *> components)
    {
        AEEffectSprite * sp = new AEEffectSprite();
        if (sp != nullptr && sp->init(components))
        {
            sp->autorelease();
            return sp;
        }
        
        CC_SAFE_DELETE(sp);
        return sp;
    }
    
    /// 动画结束后的回调
    void setFinishCallback(const std::function<void (AEEffectSprite * es)> & callback)
    {
        m_callback = callback;
    }
    
#if CC_ENABLE_SCRIPT_BINDING
    void setHandler(int handler) { m_handler = handler; }
#endif
    
protected:
    
    /**
     * 初始化
     * @param components AvatarComponent 对象的集合
     */
    virtual bool init(cocos2d::Vector<AvatarComponent *> components);
    
    int m_handler = 0;
    std::function<void (AEEffectSprite * es)> m_callback = nullptr;
};

#endif /* defined(__cocos2d_x_tools__AEEffectSprite__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


