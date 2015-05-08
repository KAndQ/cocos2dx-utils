
#ifndef __YHFiniteEffect_H__
#define __YHFiniteEffect_H__

#include "YHIFiniteEffect.h"

using namespace cocos2d;

class YHDefaultFiniteEffect;

/**
 * 特效动画的委托
 * @author Zhenyu Yao
 */
class YHFiniteEffectDelegate
{
public:
	
	/**
	 * 特效动画播放结束
	 * @param effect 播放结束的特效
	 */
	virtual void effectFinish(YHDefaultFiniteEffect * effect) = 0;
};

/**
 * 默认限定特效播放的实现
 * @author Zhenyu Yao
 */
class YHDefaultFiniteEffect : public Sprite, public YHIFiniteEffect
{
public: /** Create Functions **/
	YHDefaultFiniteEffect() : m_active(false), m_delegate(NULL) {}
	~YHDefaultFiniteEffect() { this->cleanup(); }
	
	CCSPRITE_CREATE_FUNCTIONS(YHDefaultFiniteEffect);
	
	/// 委托
	CC_SYNTHESIZE(YHFiniteEffectDelegate *, m_delegate, Delegate);
    
#if CC_ENABLE_SCRIPT_BINDING
    void setHandler(int handler) { m_handler = handler; }
#endif
	
public: /* Override Functions */
	
	virtual void		setParent(CCNode* parent);
	virtual void 		setColor(const ccColor3B& color3);
	
public: /** YHIFiniteEffect **/
	virtual bool		isActive() { return m_active; }
	virtual void		resetBasicParams();
	virtual void		reset(cocos2d::CCFiniteTimeAction * finiteAction);
	virtual void		reset(cocos2d::CCArray * actions, float duration);
	virtual void		reset(float duration);
	virtual void		reset();
	virtual void		autoRemoveFromParent();
	
protected:
	
	/// 动画播放结束回调函数
	virtual void		onFinishHandler();
	
private:
	bool				m_active;
    int                 m_handler = 0;
};

#endif // __YHFiniteEffect_H__


