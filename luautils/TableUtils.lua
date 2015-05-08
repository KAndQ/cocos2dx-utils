-- Table 的一些工具集合
-- @date 2015.04.09
-- @author Zhenyu Yao

local TableUtils = {}

-- 获得 tab 中唯一的键, 键是整型
-- @param tab table 类型
-- @return 唯一可用的键
-- @author Zhenyu Yao
function TableUtils.uniqueKey(tab)
    local max = 0
    for k, v in pairs(tab) do
        if max < k then
            max = k
        end
    end
    return max + 1
end

-- 获得 tab 的长度, 不论是否是数组
-- @param tab table 类型
-- @return 长度
-- @author Zhenyu Yao
function TableUtils.length(tab)
    local len = 0
    for _, _ in pairs(tab) do
        len = len + 1
    end
    return len
end

-- 判断 tab 中是否包含 obj 元素
-- @return true 包含, false 不包含
-- @author Zhenyu Yao
function TableUtils.contains(obj, tab)
    for _, v in pairs(tab) do
        if obj == v then
            return true
        end
    end

    return false
end

-- 实现浅复制
-- @param tab 被复制的表
-- @return tab 的浅复制副本
-- @author Zhenyu Yao
function TableUtils.clone(tab)
    local co = {}
    for k, v in pairs(tab) do
        if type(v) == "table" then
            co[k] = TableUtils.clone(v)
        else
            co[k] = v
        end
    end
    return co
end

-- 合并 tab1 和 tab2 两个表, 全部的元素唯一
-- @param tab1 表1
-- @param tab2 表2
-- @return 合并后的表
-- @author Zhenyu Yao
function TableUtils.merge(tab1, tab2)
    local m = {}
    for i, v in ipairs(tab1) do
        table.insert(m, v)
    end

    for i, v in ipairs(tab2) do
        if not TableUtils.contains(v, m) then
            table.insert(m, v)
        end
    end

    return m
end

-- 合并 tabs 集合里面的数据, 全部的元素唯一
-- @param tabs table 的集合
-- @return 合并后的表
-- @author Zhenyu Yao
function TableUtils.merge2(tabs)
    local m = {}
    for _, tab in pairs(tabs) do
        for _, v in pairs(tab.V) do
            if not TableUtils.contains(v, m) then
                table.insert(m, v)
            end
        end

        for _, v in pairs(tab.H) do
            if not TableUtils.contains(v, m) then
                table.insert(m, v)
            end
        end
    end

    return m
end

return TableUtils