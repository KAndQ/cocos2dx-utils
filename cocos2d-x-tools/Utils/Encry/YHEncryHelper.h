//
//  YHEncryHelper.h
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-1-8.
//
//

#ifndef __MonsterHunter__YHEncryHelper__
#define __MonsterHunter__YHEncryHelper__

#include "YHTypes.h"
#include "Utils/Buffer/YHByteArray.h"

/**
 * 文件加密/界面的助手
 * @author Zhenyu Yao
 */
class YHEncryHelper : public YHObject
{
public:
	
	/// 单例模式得到 YHEncryHelper 对象
	static YHEncryHelper * sharedInstance();
	
	/**
	 * 对传入的二进制数据进行加密, 需要手动 release 返回的 YHByteArray 对象
	 * @param data 待加密的数据
	 * @param secret 加密需要的密码
	 * @return 加密后的数据, 需要手动 release 返回的 YHByteArray 对象
	 */
	virtual YHByteArray * encode(YHByteArray * data, YHByteArray * secret) = 0;
	
	/**
	 * 将传入的数据进行加密后, 将数据写入到指定的文件中
	 * @param file 存储路径
	 * @param data 待加密的数据
	 * @param secret 加密需要的密码
	 */
	virtual void encodeToFile(const std::string & file, YHByteArray * data, YHByteArray * secret);
	
	/**
	 * 对传入的二进制数据解密, 需要手动 release 返回的 YHByteArray 对象
	 * @param data 带解密的数据
	 * @param secret 解密需要的密码
	 * @return 解密后的数据, 需要手动 release 返回的 YHByteArray 对象
	 */
	virtual YHByteArray * decode(YHByteArray * data, YHByteArray * secret) = 0;
	
	/**
	 * 传入需要解密的文件, 需要手动 release 返回的 YHByteArray 对象
	 * @param file 文件名
	 * @param secret 解密需要的密码
	 * @return 解密后的数据, 需要手动 release 返回的 YHByteArray 对象
	 */
	virtual YHByteArray * decodeWithFile(const std::string & file, YHByteArray * secret);
	
protected:
	
	YHEncryHelper() {}
	virtual ~YHEncryHelper() {}
};

#endif /* defined(__MonsterHunter__YHEncryHelper__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


