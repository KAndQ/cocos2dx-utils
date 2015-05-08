//
//  AEEffectSprite.cpp
//  cocos2d-x-tools
//
//  Created by Zhenyu Yao on 14/11/4.
//
//

#include "AEEffectSprite.h"
#include "AnimationHelper/Avatar/AvatarComponent.h"
#if CC_ENABLE_SCRIPT_BINDING
#include "CCLuaEngine.h"
#include "tolua_fix.h"
#endif // CC_ENABLE_SCRIPT_BINDING

USING_NS_CC;

bool AEEffectSprite::init(cocos2d::Vector<AvatarComponent *> components)
{
    bool result = Sprite::init();
    
    float sumTime = 0.0f;
    for (auto comp : components)
    {
        this->addChild(comp);
        
        float tmp = comp->getAnimatorData()->getAnimData()->getSumTime();
        if (sumTime < tmp)
            sumTime = tmp;
        
        DelayTime * delay = DelayTime::create(tmp);
        CallFunc * call = CallFunc::create([comp] { comp->removeFromParent(); });
        Sequence * seq = Sequence::create(delay, call, nullptr);
        comp->runAction(seq);
    }
    
    DelayTime * delay = DelayTime::create(sumTime);
    CallFunc * call = CallFunc::create([this]
    {
        if (this->m_callback != nullptr)
        {
            this->m_callback(this);
        }
        
#if CC_ENABLE_SCRIPT_BINDING
        if (m_handler != 0)
        {
            LuaStack * stack = LuaEngine::getInstance()->getLuaStack();
            stack->pushLuaValue(LuaValue::ccobjectValue(this, "AEEffectSprite"));
            stack->executeFunctionByHandler(m_handler, 1);
            stack->clean();
        }
#endif
        
        this->removeFromParent();
    });
    Sequence * seq = Sequence::create(delay, call, nullptr);
    this->runAction(seq);
    
    return result;
}












































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


