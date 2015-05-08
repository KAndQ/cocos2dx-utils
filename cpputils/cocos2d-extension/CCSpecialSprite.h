
#ifndef __CCSpecialSprite_H__
#define __CCSpecialSprite_H__

#include "cocos2d.h"
#include "Utils/Common/CommonUtils.h"

using namespace cocos2d;

class AnimatorModuleData;
/**
 * 特殊的 Sprite 类, 为的是解决能在 CCSpriteBatchNode 中使用, 能够设置 contentSize, 但是又不贴图的需求.
 * @author Zhenyu Yao
 */
class CCSpecialSprite : public Sprite
{
public:
	
    virtual bool init() override;
    virtual bool initWithTexture(Texture2D * texture) override;
    virtual bool initWithTexture(Texture2D * texture, const Rect & rect) override;
    virtual bool initWithTexture(Texture2D * texture, const Rect & rect, bool rotated) override;
    virtual bool initWithSpriteFrame(SpriteFrame * pSpriteFrame) override;
    virtual bool initWithSpriteFrameName(const std::string & spriteFrameName) override;
    virtual bool initWithFile(const std::string & filename) override;
    virtual bool initWithFile(const std::string & filename, const Rect & rect) override;
    
	bool init(CCDictionary * moduleDict);
	bool init(AnimatorModuleData * moduleData);
	
    CREATE_FUNC(CCSpecialSprite);
	static CCSpecialSprite * create(CCDictionary * moduleDict);
	static CCSpecialSprite * create(AnimatorModuleData * moduleData);
	
public: // Override Functions
	
	/// 不绘制任何图形, 为的只是当容器能够在 CCSpriteBatchNode 中使用
	virtual void				draw(Renderer *renderer, const kmMat4 &transform, bool transformUpdated);
	
	/// 设置子节点的颜色
	virtual void				setColor(const ccColor3B & color3) override;
	
	/// 设置子节点的透明度
	virtual void				setOpacity(GLubyte opacity) override;
	
	/// 添加进容器的时候负责给子节点着色和设置透明度
    /* override */
    virtual void addChild(cocos2d::Node * child) override;
    virtual void addChild(cocos2d::Node * child, int localZOrder) override;
    virtual void addChild(cocos2d::Node * child, int localZOrder, int tag) override;
    virtual void addChild(cocos2d::Node * child, int localZOrder, const std::string &name) override;
    
private:
    
    /// 为添加的 child 节点做些事情
    void forChildDoSth(cocos2d::Node * node);
	
};

#endif // __CCSpecialSprite_H__


