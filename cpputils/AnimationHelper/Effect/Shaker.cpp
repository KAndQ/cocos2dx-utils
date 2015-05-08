#include "Shaker.h"

USING_NS_CC;

Shaker::~Shaker()
{
    Director::getInstance()->getScheduler()->unscheduleAllForTarget(this);
}

bool Shaker::init()
{
    return true;
}

void Shaker::start(const cocos2d::Vec2 & amp, float32 period, float32 duration, float32 loss)
{
    if (m_shaking && (m_ampMax.x != 0 || m_ampMax.y != 0))
    {
        if (m_amp.x < 0)
        {
            m_amp.x -= fabsf(amp.x);
        }
        else
        {
            m_amp.x += fabsf(amp.x);
        }
        
        if (m_amp.y < 0)
        {
            m_amp.y -= fabsf(amp.y);
        }
        else
        {
            m_amp.y += fabsf(amp.y);
        }
        
        if (m_ampMax.x != 0)
        {
            if (m_amp.x > m_ampMax.x)
            {
                m_amp.x = m_ampMax.x;
            }
        }
        
        if (m_ampMax.y != 0)
        {
            if (m_amp.y > m_ampMax.y)
            {
                m_amp.y = m_ampMax.y;
            }
        }
    }
    else
    {
        m_amp = amp;
    }
    
    m_shaking = true;

    m_period = period;
    
    if (m_loss < 0.0f)
        m_loss = 0.0f;
    else if (m_loss > 1.0f)
        m_loss = 1.0f;
    else
        m_loss = loss;
    
    if (m_node)
    {
        if (m_shaking)
            m_node->setPosition(m_origin);
        else
            m_origin = m_node->getPosition();
    }

    m_position = Vec2::ZERO;
    
    m_elapse = 0.0f;
    m_count = 0;
    
    Director::getInstance()->getScheduler()->unscheduleAllForTarget(this);
    Director::getInstance()->getScheduler()->scheduleUpdate(this, 0, false);
    Director::getInstance()->getScheduler()->schedule(schedule_selector(Shaker::callback), this, duration, false);
}

void Shaker::stop()
{
    m_shaking = false;
    if (m_node != nullptr)
        m_node->setPosition(m_origin);
    Director::getInstance()->getScheduler()->unscheduleAllForTarget(this);
}

void Shaker::update(float dt)
{
    if (!m_shaking)
        return;
    
    m_elapse += dt;
    if (m_elapse >= m_period)
    {
        m_elapse -= m_period;
        
        if (++m_count > 3)
            m_count = 0;
        
        if (m_count == 2 || m_count == 0)
        {
            m_amp *= 1.0f - m_loss;
            if (m_random)
            {
                Vec2 tmp = m_amp;
                float radian = CCRANDOM_MINUS1_1() * M_PI;
                tmp.x = cosf(radian) * m_amp.x - sinf(radian) * m_amp.y;
                tmp.y = cosf(radian) * m_amp.y + sinf(radian) * m_amp.x;
                m_amp = tmp;
            }
        }
    }
    
    float32 percent = m_elapse / m_period;
    switch (m_count)
    {
        case 0:
            m_position = m_amp * percent;
            break;
        case 1:
            m_position = m_amp * (1.0f - percent);
            break;
        case 2:
            m_position = m_amp * -percent;
            break;
        case 3:
            m_position = m_amp * -(1.0f - percent);
            break;
    }
    
    m_node->setPosition(m_origin + m_position);
}
                                                                        
void Shaker::callback(float32 dt)
{
    stop();
}
