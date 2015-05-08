#ifndef __cocos2d_x_tools__Shaker__
#define __cocos2d_x_tools__Shaker__

#include "YHTypes.h"

/**
 * 震动器
 * @author Zhenyu Yao
 */
class Shaker : public YHObject
{
public:
    
    virtual ~Shaker();

	/// 创建 Shaker 对象
	static Shaker * create()
    {
        Shaker * instance = new Shaker();
        instance->init();
        instance->autorelease();
        return instance;
    }
    
    /**
     * 开始震动
     * @param amp 振幅
     * @param period 1/4周期
     * @param loss 每次回到震中损失的能量
     */
    void start(const cocos2d::Vec2 & amp, float32 period, float32 duration, float32 loss = 0.0f);
    
    /// 停止震动
    void stop();
    
    /// 设置震中
    void setOrigin(const cocos2d::Vec2 & origin)
    {
        m_origin = origin;
    }
    
    /// 设置关联的 node
    void setNode(cocos2d::Node * node)
    {
        m_node = node;
        if (m_node != nullptr)
            m_origin = m_node->getPosition();
    }
    
    /// 随机振动
    void setRandom(bool r)
	{
		m_random = r;
	}
    
    /// 获得震动偏移量
    cocos2d::Vec2 getPosition() const
    {
        return m_position;
    }
    
    /// 振幅最大值, 为 0 表示没有设置
    CC_SYNTHESIZE(cocos2d::Vec2, m_ampMax, AmpMax);
    
    /// 逻辑更新
    void update(float dt);
    
protected:
    
    virtual bool init();
    
    virtual void callback(float32 dt);
    
    bool m_shaking = false;
    bool m_random = true;
    float32 m_elapse = 0.0f;
    float32 m_period = 0.0f;
    uint32 m_count = 0;
    cocos2d::Vec2 m_amp;        // 振幅
    cocos2d::Vec2 m_origin;     // 震中
    cocos2d::Vec2 m_position;   // 距离震中的偏移量
    float32 m_loss = 0.0f;      // 每次经过震中衰减速度的百分比
    cocos2d::Node * m_node = nullptr;
};

#endif /* defined(__cocos2d_x_tools__Shaker__) */
