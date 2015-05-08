
#ifndef __YHEffectGenerator_H__
#define __YHEffectGenerator_H__

#include "cocos2d.h"
#include "cocos2d-extension/CCSpecialSprite.h"
#include "YHFiniteEffect.h"
#include "AnimationHelper/Animation/YHAnimationHelper.h"
#include "AnimationHelper/Animation/YHAnimationCache.h"

using namespace std;
using namespace cocos2d;

/**
 * 特效动画的定义类型
 * @author Zhenyu Yao
 */
typedef enum _YHEffectDefineType_
{
	kEffectDefineType_Piece1,		// 由 1 个特效组合
	kEffectDefineType_Piece2,		// 由 2 个特效组合, 默认原始图的切片是右边
	kEffectDefineType_Piece4,		// 由 4 个特效组合, 默认原始图的切片是右上角
}YHEffectDefineType;

/**
 * 特效动画的定义器, 从 CCDictionary 解析出的数据放入到 YHEffectDefiner 对象中
 * @author Zhenyu Yao
 */
class YHEffectDefiner : public YHObject
{
public:
    
	YHEffectDefiner(YHEffectDefineType type, const char * name)
        : m_type(type), m_animationName(name), m_spriteDefiner(nullptr)
    {
        setSpriteDefiner(YHSpriteDefiner::create());
    }
    
	YHEffectDefiner(CCDictionary * dict);
    
	~YHEffectDefiner()
    {
        CC_SAFE_RELEASE_NULL(m_spriteDefiner);
    }
	
	/// 获得 特效定义的类型
	YHEffectDefineType		getType() const { return m_type; }
	
	/// getter/setter 动画的名字
	const char *			getAnimationName() const { return m_animationName.c_str(); }
	void					setAnimationName(const char * name) { m_animationName = name; }
    
    /// getter/setter YHSpriteDefiner
    CC_SYNTHESIZE_RETAIN(YHSpriteDefiner *, m_spriteDefiner, SpriteDefiner);
	
private:
	YHEffectDefineType		m_type;
	std::string				m_animationName;
};

/**
 * 特效工厂类, 主要负责生成带有动画效果的 CCSprite 对象
 * @author Zhenyu Yao
 */
class YHEffectFactory : public YHObject
{
public:
	
	YHEffectFactory();
	virtual ~YHEffectFactory();
	
	/// 初始化
	virtual bool init()
	{
		return true;
	}
	
    /// 创建 YHEffectFactory 对象
	CREATE_FUNC(YHEffectFactory);
    
    /// YHAnimationCache 对象
    CC_SYNTHESIZE_RETAIN(YHAnimationCache *, m_animationCache, AnimationCache);
	
	/// 从缓存中获得 YHEffectDefiner 对象
	YHEffectDefiner *			effectDefinerForKey(const string & key);
	
	/// 将 YHEffectDefiner 对象放入到缓存中
	void						addEffectDefiner(const string & key, YHEffectDefiner * definer);
	
	/// 从 CCDictionary 中读出 YHEffectDefiner 放入到缓存中
	void						addEffectDefiner(CCDictionary * dict);
	
	/// 清空缓存中的所有 YHEffectDefiner 对象
	void						cleanAllEffectDefiners();
	
	/// 清空缓存中所有的 CCSprite 对象
	void						cleanAllSprites();
	
	/// cleanAllEffectDefiners + cleanAllSprites
	void						cleanAll();
	
	/// 根据特效的名字得到特效的 CCSprite 对象
	YHDefaultFiniteEffect *     effectSpriteForKey(const string & key);
	
	/// 根据 YHEffectDefiner 得到特效的 CCSprite 对象
	YHDefaultFiniteEffect *		effectSpriteForDefiner(const YHEffectDefiner * definer);
	
private:
	
	/// 从缓存中获得 YHDefaultFiniteEffect 对象
	YHDefaultFiniteEffect *		finiteEffectFromCache();
	
	/// 调整出现的特效
	void						adjustSprite(CCSprite * sp, const YHEffectDefiner * definer);
	
private:
	CCDictionary *				m_definerCache;
	CCSet *						m_effectCache;
};

#endif // __YHEffectGenerator_H__


