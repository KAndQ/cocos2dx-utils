//
//  AnimationTypes.cpp
//  cocos2d-x-Utils
//
//  Created by mac on 13-7-15.
//
//

#include "AnimationTypes.h"
#include "ActionContext.h"
#include "ActionParseBase.h"
#include "cocos2d-extension/CCSpecialSprite.h"
#include "cocos2d-extension/CCActionExtension.h"

std::string convertKeyFromFile(const std::string& file)
{
	size_t pos =  file.rfind('/');
	std::string lastPath = file.substr(pos+1, file.length());
	size_t pos1 = lastPath.rfind('.');
	std::string key = lastPath.substr(0, pos1);
	return key;
}

////////AnimatorInitData///////////
void AnimatorInitData::init(cocos2d::CCDictionary *dataDict)
{
	assert(dataDict);
	
	m_anchorPoint = PointFromString(dataDict->valueForKey("AnchorPoint")->getCString());
	m_position = PointFromString(dataDict->valueForKey("Position")->getCString());
    m_position = ActionParseBase::pointWithContentScale(m_position);
	m_scale = PointFromString(dataDict->valueForKey("Scale")->getCString());
	m_rotation = dataDict->valueForKey("Rotation")->floatValue();
	m_opacity = dataDict->valueForKey("Opacity")->uintValue();
    m_zOrder = dataDict->valueForKey("ZOrder")->intValue();
}

AnimatorInitData* AnimatorInitData::data(cocos2d::CCDictionary *dataDict)
{
	AnimatorInitData* data = new AnimatorInitData();
	data->init(dataDict);
	data->autorelease();
	return data;
}

void AnimatorInitData::initializeNode(cocos2d::CCNodeRGBA *node)
{
	node->setAnchorPoint(m_anchorPoint);
    CCPoint position = ActionParseBase::pointWithContentScale(m_position, m_posScale);
	node->setPosition(position);
	node->setScaleX(m_scale.x);
	node->setScaleY(m_scale.y);
	node->setRotation(m_rotation);
	node->setOpacity(m_opacity);
    node->setZOrder(m_zOrder);
}

void AnimatorInitData::setPosScale(float posScale)
{
    m_posScale = posScale;
}

void AnimatorInitData::tweenToNow(CCNodeRGBA * node, float32 duration)
{
    CCAnchorPointTo * at = CCAnchorPointTo::create(duration, m_anchorPoint);
    CCPoint position = ActionParseBase::pointWithContentScale(m_position, m_posScale);
    MoveTo * mt = MoveTo::create(duration, position);
    ScaleTo * st = ScaleTo::create(duration, m_scale.x, m_scale.y);
    RotateTo * rt = RotateTo::create(duration, m_rotation);
    FadeTo * ft = FadeTo::create(duration, m_opacity);
    node->runAction(at);
    node->runAction(mt);
    node->runAction(st);
    node->runAction(rt);
    node->runAction(ft);
}

///////////////AnimatorAnimData////////////////////
void AnimatorAnimData::init(cocos2d::CCDictionary *dataDict)
{
	assert(dataDict);
	
	m_dataDict = dataDict;
	m_dataDict->retain();
}

AnimatorAnimData::~AnimatorAnimData()
{
	CC_SAFE_RELEASE_NULL(m_dataDict);
}

AnimatorAnimData* AnimatorAnimData::data(cocos2d::CCDictionary *dataDict)
{
	AnimatorAnimData* data = new AnimatorAnimData();
	data->init(dataDict);
	data->autorelease();
	return data;
}

CCAction* AnimatorAnimData::action(const std::string &type)
{
	CCDictionary* actionDict = (CCDictionary*)m_dataDict->objectForKey(type.c_str());
    if (actionDict != NULL)
    {
        actionDict->setObject(CCString::create(float32ToString(m_posScale)), "PosScale");
        CCAction* action = ActionContext::getContext()->getAction(actionDict);
        return action;
    }
    
    return NULL;
}

void AnimatorAnimData::runActions(cocos2d::CCNodeRGBA *node, const std::vector<int32> & tags)
{
	runAction(node, ANIMATION_TYPE_ANCHORPOINT, tags[0]);
	runAction(node, ANIMATION_TYPE_POSITION, tags[1]);
	runAction(node, ANIMATION_TYPE_SCALE, tags[2]);
	runAction(node, ANIMATION_TYPE_ROTATION, tags[3]);
	runAction(node, ANIMATION_TYPE_OPACITY, tags[4]);
}

void AnimatorAnimData::runAction(cocos2d::CCNodeRGBA *node, const std::string &type, int32 tag)
{
	CCAction* action = this->action(type);
	if (action)
	{
        action->setTag(tag);
		node->runAction(action);
	}
}

CCDelayTime * AnimatorAnimData::getDelayTimeAction()
{
    CCDictionary * delayDict = (CCDictionary *)m_dataDict->objectForKey("Delay");
    if (delayDict != nullptr)
    {
        CCDelayTime * action = (CCDelayTime *)ActionContext::getContext()->getAction(delayDict);
        return action;
    }
    return nullptr;
}

float32 AnimatorAnimData::getOffsetTime() const
{
    CCDictionary * delayDict = (CCDictionary *)m_dataDict->objectForKey("Delay");
    if (delayDict != nullptr)
    {
        float32 offset = delayDict->valueForKey("Duration")->floatValue();
        return offset;
    }
    
    return 0.0f;
}

/////////////////AnimatorData/////////////////////////
void AnimatorData::init(cocos2d::CCDictionary *dataDict)
{
	CCDictionary* initDict = (CCDictionary*)dataDict->objectForKey("InitData");
	CCDictionary* animDict = (CCDictionary*)dataDict->objectForKey("AnimData");
	m_initData = AnimatorInitData::data(initDict);
	m_initData->retain();
	m_animData = AnimatorAnimData::data(animDict);
	m_animData->retain();
}

void AnimatorData::init(AnimatorInitData *initData, AnimatorAnimData *animData)
{
	m_initData  = initData;
	m_initData->retain();
	m_animData = animData;
	m_animData->retain();
}

AnimatorData* AnimatorData::data(AnimatorInitData *initData, AnimatorAnimData *animData)
{
	AnimatorData* data = new AnimatorData();
	data->init(initData, animData);
	data->autorelease();
	return data;
}

AnimatorData* AnimatorData::data(cocos2d::CCDictionary *dataDict)
{
	AnimatorData* data = new AnimatorData();
	data->init(dataDict);
	data->autorelease();
	return data;
}

AnimatorData::~AnimatorData()
{
	CC_SAFE_RELEASE_NULL(m_initData);
	CC_SAFE_RELEASE_NULL(m_animData);
}

/////////////////AnimatorModuleData//////////////////////////////
void AnimatorModuleData::init(cocos2d::CCDictionary *moduleDict)
{
	m_anchorPoint = PointFromString(moduleDict->valueForKey("AnchorPoint")->getCString());
	m_contentSize = SizeFromString(moduleDict->valueForKey("Size")->getCString());
    m_contentSize.width = ActionParseBase::floatWithContentScale(m_contentSize.width);
    m_contentSize.height = ActionParseBase::floatWithContentScale(m_contentSize.height);
}

AnimatorModuleData* AnimatorModuleData::data(cocos2d::CCDictionary *moduleDict)
{
	AnimatorModuleData* data = new AnimatorModuleData();
	data->init(moduleDict);
	data->autorelease();
	return data;
}

CCSpecialSprite* AnimatorModuleData::createSpecialSprite()
{
	return CCSpecialSprite::create(this);
}

void AnimatorModuleData::assignToNode(CCNode * node)
{
    node->setAnchorPoint(m_anchorPoint);
    node->setContentSize(m_contentSize);
}

///////////////////AnimatorSettignData///////////////////
void AnimatorSettingData::init(cocos2d::CCDictionary *settingDict)
{
	m_animatorFile = settingDict->valueForKey("AnimatorFile")->getCString();
	m_animatorDataFile = settingDict->valueForKey("AnimatorDataFile")->getCString();
}

AnimatorSettingData* AnimatorSettingData::data(cocos2d::CCDictionary *settingDict)
{
	AnimatorSettingData* data = new AnimatorSettingData();
	data->init(settingDict);
	data->autorelease();
	return data;
}


//////////////////AnimatorDataCache///////////////////////
CCObject* AnimatorDataCache::autorelease()
{
	return this;
}

void AnimatorDataCache::retain()
{
}

void AnimatorDataCache::release()
{
}

AnimatorDataCache* AnimatorDataCache::sharedCache()
{
	static AnimatorDataCache cache;
	return &cache;
}

AnimatorDataCache::AnimatorDataCache()
{
	m_dict = CCDictionary::create();
	m_dict->retain();
}

void AnimatorDataCache::addData(AnimatorData *data, const std::string& key)
{
	assert(data);
	assert(key != "");
	
	m_dict->setObject(data, convertKeyFromFile(key));
}

AnimatorData* AnimatorDataCache::getData(const std::string &key)
{
	assert(key != "");
	
	return (AnimatorData*)m_dict->objectForKey(convertKeyFromFile(key));
}

void AnimatorDataCache::clean()
{
	m_dict->removeAllObjects();
}


/////////////////AnimatorModuleDataCache//////////////////
CCObject* AnimatorModuleDataCache::autorelease()
{
	return this;
}

void AnimatorModuleDataCache::retain()
{
}

void AnimatorModuleDataCache::release()
{
}

AnimatorModuleDataCache* AnimatorModuleDataCache::sharedCache()
{
	static AnimatorModuleDataCache cache;
	return &cache;
}

AnimatorModuleDataCache::AnimatorModuleDataCache()
{
	m_dict = CCDictionary::create();
	m_dict->retain();
}

void AnimatorModuleDataCache::addData(AnimatorModuleData *data, const std::string& key)
{
	assert(data);
	assert(key != "");
	
	m_dict->setObject(data, convertKeyFromFile(key));
}

AnimatorModuleData* AnimatorModuleDataCache::getData(const std::string &key)
{
	assert(key != "");
	
	return (AnimatorModuleData*)m_dict->objectForKey(convertKeyFromFile(key));
}

void AnimatorModuleDataCache::clean()
{
	m_dict->removeAllObjects();
}

///////////////////AnimatorSettingDataCache///////////////////

CCObject* AnimatorSettingDataCache::autorelease()
{
	return this;
}

void AnimatorSettingDataCache::retain()
{
}

void AnimatorSettingDataCache::release()
{
}

AnimatorSettingDataCache* AnimatorSettingDataCache::sharedCache()
{
	static AnimatorSettingDataCache cache;
	return &cache;
}

AnimatorSettingDataCache::AnimatorSettingDataCache()
{
	m_dict = CCDictionary::create();
	m_dict->retain();
}

void AnimatorSettingDataCache::addData(AnimatorSettingData *data, const std::string& key)
{
	assert(data);
	assert(key != "");
	
	m_dict->setObject(data, convertKeyFromFile(key));
}

AnimatorSettingData* AnimatorSettingDataCache::getData(const std::string &key)
{
	assert(key != "");
	
	return (AnimatorSettingData*)m_dict->objectForKey(convertKeyFromFile(key));
}

void AnimatorSettingDataCache::clean()
{
	m_dict->removeAllObjects();
}


























