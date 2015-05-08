local animutils = {}

local debug = false
local function dprint(...)
    if debug then
        print(...)
    end
end

-- 得到 AnimatorModuleData 对象
-- @param plistfile 文件名
-- @param dataManager YHDataManager 对象
-- @return nil
-- @author Zhenyu Yao
function animutils.getModule(plistfile, dataManager)
    if not plistfile then
        return nil
    end

    local cache = AnimatorModuleDataCache:sharedCache()
    local mod = cache:getData(plistfile)
    if not mod then
        dprint("-----------------> module file not find in cached. ", plistfile)
        local dict = nil
        if not dataManager then
            dprint("-----------------> no use dataManager getModule ", plistfile)
            dict = cc.__Dictionary:createWithContentsOfFile(cc.FileUtils:getInstance():fullPathForFilename(plistfile))
        else
            dict = dataManager:dictionaryForFile(plistfile)
            if not dict then
                dprint("-----------------> use dataManager getModule, but not found file ", plistfile)
                dict = cc.__Dictionary:createWithContentsOfFile(cc.FileUtils:getInstance():fullPathForFilename(plistfile))
            end
            assert(dict, string.format("-----------------> no file: %s", plistfile))
        end
        mod = AnimatorModuleData:data(dict)
        cache:addData(mod, plistfile)
    end

    return mod
end

-- 得到 AnimatorData 对象
-- @param plistfile 文件名
-- @param dataManager YHDataManager 对象
-- @return nil
-- @author Zhenyu Yao
function animutils.getAnim(plistfile, dataManager)
    if not plistfile then
        return nil
    end

    if not dataManager then
        local animData = AnimatorDataCache:sharedCache():getData(plistfile)
        if animData == nil then
            dprint("-----------------> anim file not find in cached. ", plistfile)
            dprint("----------------> no use dataManager getAnim ", plistfile)
            local dict = cc.__Dictionary:createWithContentsOfFile(cc.FileUtils:getInstance():fullPathForFilename(plistfile))
            animData = AnimatorData:data(dict)
            AnimatorDataCache:sharedCache():addData(animData, plistfile)
        end
        return animData
    else
        local animData = AnimatorDataCache:sharedCache():getData(plistfile)
        if animData == nil then
            dprint("-----------------> anim file not find in cached. ", plistfile)
            local dict = dataManager:dictionaryForFile(plistfile)
            if not dict then
                dprint("-----------------> use dataManager getAnim, but not found file ", plistfile)
                dict = cc.__Dictionary:createWithContentsOfFile(cc.FileUtils:getInstance():fullPathForFilename(plistfile))
            end
            assert(dict, string.format("-----------------> no file: %s", plistfile))
            animData = AnimatorData:data(dict)
            AnimatorDataCache:sharedCache():addData(animData, plistfile)
        end
        return animData
    end
end

-- 创建 AvatarComponent 对象
-- @param animationName 在动画文件中的文件名
-- @param plistfile 动作脚本文件名
-- @param animationCache 动画缓存
-- @param dataManager 数据缓存管理器
-- @param tab 预留
-- @return AvatarComponent 对象
-- @author Zhenyu Yao
function animutils.createComponent(animationName, plistfile, animationCache, dataManager, tab)
    local animation = nil
    
    -- 如果给的是图片名, 那么加载图片
    if string.find(animationName, ".png") ~= nil then
        local sf = cc.SpriteFrameCache:getInstance():getSpriteFrame(animationName)
        if not sf then
            local tex = cc.Director:getInstance():getTextureCache():addImage(animationName)
            assert(tex, string.format("animutils.createComponent 找不到资源 %s", animationName))
            sf = cc.SpriteFrame:createWithTexture(tex, cc.rect(0, 0, tex:getContentSize().width, tex:getContentSize().height))
        end

        animation = cc.Animation:create()
        animation:addSpriteFrame(sf)
    else
        if animationName or animationCache then
            animation = animationCache:animationForKeyFromCache_Ver2(animationName)
        end
    end
    assert(animation, "Error: 没有加载对应的动画资源 ", animationName)
    
    local animData = animutils.getAnim(plistfile, dataManager)
    if tab and tab.posScale then
        animData:setPosScale(tab.posScale)
    end
    return AvatarComponent:create(animation, nil, animData)
end

-- 给 node 赋予 plistfile 对应的动作
-- @param node 被赋予动作的 node
-- @param plistfile 动作文件
-- @param dataManager 数据缓存管理器
-- @param tab 预留
-- @return nil
-- @author Zhenyu Yao
function animutils.danceNode(node, plistfile, dataManager, tab)
    local animData = animutils.getAnim(plistfile, dataManager)
    if tab and tab.posScale then
        animData:setPosScale(tab.posScale)
    end

    animData:getInitData():initializeNode(node)
    animData:getAnimData():runActions(node)

    return animData
end

return animutils