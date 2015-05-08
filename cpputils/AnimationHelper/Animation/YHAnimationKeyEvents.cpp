//
//  YHAnimationKeyEvents.cpp
//  Demo
//
//  Created by Zhenyu Yao on 14-1-2.
//
//

#include "YHAnimationKeyEvents.h"
#if CC_ENABLE_SCRIPT_BINDING
#include "CCLuaEngine.h"
#include "tolua_fix.h"
#endif // CC_ENABLE_SCRIPT_BINDING

USING_NS_CC;

////////////////////////////////////////////////////////////////////////////////////////////////////
// YHAnimationKeyEventsInternalObject
////////////////////////////////////////////////////////////////////////////////////////////////////

YHAnimationKeyEventsInternalObject::YHAnimationKeyEventsInternalObject() : m_keyEvents(NULL)
{
}

YHAnimationKeyEventsInternalObject::~YHAnimationKeyEventsInternalObject()
{
}

void YHAnimationKeyEventsInternalObject::onCallFuncOHandle(cocos2d::CCObject * object)
{
	m_keyEvents->onCallFuncOHandle(object);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// YHAnimationKeyEvents
////////////////////////////////////////////////////////////////////////////////////////////////////

YHAnimationKeyEvents::YHAnimationKeyEvents() : m_node(NULL), m_delegate(NULL), m_action(NULL), m_internalObject(NULL)
{
#if CC_ENABLE_SCRIPT_BINDING
    m_handler = 0;
#endif
}

YHAnimationKeyEvents::~YHAnimationKeyEvents()
{
	CC_SAFE_RELEASE_NULL(m_action);
	CC_SAFE_RELEASE_NULL(m_internalObject);
}

bool YHAnimationKeyEvents::init(cocos2d::CCAnimation * animation, float32 offset, bool loop)
{
	assert(animation != NULL);
	
	m_internalObject = new YHAnimationKeyEventsInternalObject();
	m_internalObject->setKeyEvents(this);
	
	float duration = animation->getDelayPerUnit();
    Vector<CCFiniteTimeAction *> actions;
    const Vector<CCAnimationFrame *> & frames = animation->getFrames();
	uint32 index = 0;
	float elapse = offset;
	float lastTime = offset;
    Vector<CCAnimationFrame *>::const_iterator begin = frames.begin();
    Vector<CCAnimationFrame *>::const_iterator end = frames.end();
    for (; begin != end; ++begin)
    {
        CCAnimationFrame * frame = *begin;
        if (!frame->getUserInfo().empty())
		{
			if (index != 0)
			{
				CCDelayTime * delay = CCDelayTime::create(elapse - lastTime);
                actions.pushBack(delay);
				lastTime = elapse;
			}
			
			CCCallFuncO * callFuncO = CCCallFuncO::create(m_internalObject,
                                                          callfuncO_selector(YHAnimationKeyEventsInternalObject::onCallFuncOHandle),
                                                          frame);
            actions.pushBack(callFuncO);
		}
		
		elapse += frame->getDelayUnits() * duration;
		++index;
    }
	
	if (!actions.empty())
	{
		// 补齐动画
        if (elapse > lastTime)
        {
            CCDelayTime * delay = CCDelayTime::create(elapse - lastTime);
            actions.pushBack(delay);
        }
		
		CCSequence * sequence = CCSequence::create(actions);
		if (loop)
			m_action = CCRepeatForever::create(sequence);
		else
		{
			if (animation->getLoops() > 1)
				m_action = CCRepeat::create(sequence, animation->getLoops());
			else
				m_action = sequence;
		}
		CC_SAFE_RETAIN(m_action);
	}
	
	return true;
}

bool YHAnimationKeyEvents::init(cocos2d::CCDictionary * dataDict, float32 offset)
{
    assert(dataDict != NULL);
    
    m_internalObject = new YHAnimationKeyEventsInternalObject();
	m_internalObject->setKeyEvents(this);
    
    float sumTime = dataDict->valueForKey("Sum")->floatValue();
    float elapse = offset;
    CCArray * steps = (CCArray *)dataDict->objectForKey("Steps");
    CCObject * obj = NULL;
    Vector<CCFiniteTimeAction *> actions;
    CCARRAY_FOREACH(steps, obj)
    {
        CCDictionary * dict = (CCDictionary *)obj;
        float delay = dict->valueForKey("Delay")->floatValue() + offset;
        CCDictionary * userInfo = (CCDictionary *)dict->objectForKey("UserInfo");
        
        CCDelayTime * delayTime = CCDelayTime::create(delay);
        CCCallFuncO * callFuncO = CCCallFuncO::create(m_internalObject,
                                                      callfuncO_selector(YHAnimationKeyEventsInternalObject::onCallFuncOHandle),
                                                      userInfo);
        actions.pushBack(delayTime);
        actions.pushBack(callFuncO);
        
        elapse += delay;
    }
    
    if (!actions.empty())
    {
        // 总时间必须大于时间段时间之和
        assert(sumTime >= elapse);
        
        // 判断是否需要补齐动画
        if (sumTime != elapse)
        {
            CCDelayTime * delayTime = CCDelayTime::create(sumTime - elapse);
            actions.pushBack(delayTime);
        }
        
        // 决定循环次数
        unsigned int loops = dataDict->valueForKey("Loops")->uintValue();
        if (loops == 0)
        {
            m_action = CCRepeatForever::create(CCSequence::create(actions));
        }
        else
        {
            if (loops > 1)
            {
                m_action = CCRepeat::create(CCSequence::create(actions), loops);
            }
            else
            {
                m_action = CCSequence::create(actions);
            }
        }
        
        CC_SAFE_RETAIN(m_action);
    }
    
    return true;
}

void YHAnimationKeyEvents::onCallFuncOHandle(cocos2d::CCObject * object)
{
	if (m_delegate != NULL)
	{
        if (dynamic_cast<CCDictionary *>(object) == NULL)
        {
            m_delegate->handleKeyEvent(m_node, (CCAnimationFrame *)object);
        }
        else
        {
            m_delegate->handleKeyEvent(m_node, (CCDictionary *)object);
        }
	}

#if CC_ENABLE_SCRIPT_BINDING
    if (m_handler != 0)
    {
        if(dynamic_cast<CCDictionary *>(object) == nullptr)
        {
            LuaStack * stack = LuaEngine::getInstance()->getLuaStack();
            stack->pushLuaValue(LuaValue::ccobjectValue(m_node, "Node"));
            stack->pushLuaValue(LuaValue::ccobjectValue((CCAnimationFrame *)object, "AnimationFrame"));
            stack->executeFunctionByHandler(m_handler, 2);
            stack->clean();
        }
        else
        {
            LuaStack * stack = LuaEngine::getInstance()->getLuaStack();
            stack->pushLuaValue(LuaValue::ccobjectValue(m_node, "Node"));
            stack->pushLuaValue(LuaValue::ccobjectValue((CCDictionary *)object, "AnimationFrame"));
            stack->executeFunctionByHandler(m_handler, 2);
            stack->clean();
        }
    }
#endif
}













































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


