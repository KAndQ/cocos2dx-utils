//
//  XORUtils.c
//  clean
//
//  Created by Zhenyu Yao on 15/5/14.
//
//

#include "XORUtils.h"

int xorutils_transfer(char * source, char * dst, unsigned int slen, char * key, unsigned int klen)
{
    
    for (unsigned int i = 0; i < slen;)
    {
        for (unsigned int j = 0; j < klen && i < slen; ++j, ++i)
        {
            dst[i] = source[i] ^ key[j];
        }
    }
    
    return 1;
}
