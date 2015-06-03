//
//  XORUtils.h
//  clean
//
//  Created by Zhenyu Yao on 15/5/14.
//
//

#ifndef __clean__XORUtils__
#define __clean__XORUtils__

#include <stdio.h>



/**
 * 将 source 的数据根据 key 做异或处理
 * @param source 源数据
 * @param dst 源数据异或到的目标数据
 * @param slen 源数据长度, dst 也至少有 slen 的内存空间
 * @param key 加密密钥
 * @param klen 密钥长度
 * @return 成功返回 1, 失败返回 0
 * @author Zhenyu Yao
 */
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
extern int xorutils_transfer(char * source, char * dst, unsigned int slen, char * key, unsigned int klen);
    
#ifdef __cplusplus
}
#endif // __cplusplus

#endif /* defined(__clean__XORUtils__) */
