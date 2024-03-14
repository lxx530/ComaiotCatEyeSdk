//
//  CSLockDevice.h
//  ComaiotSDK
//
//  Created by 郑丰 on 2020/3/26.
//  Copyright © 2020 zfeng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSMessage.h"

//开锁状态
extern  NSString * const CSMessageOpenLockStatusNotice;

//开锁
extern  NSString * const CSMessageOpenLockCMD;
//门锁电量
extern  NSString * const CSMessageLockBATCMD;

@interface CSMessage (TYLock)

//开锁
+(CSMessage *)openLock;
//门锁电量
+(CSMessage *)lockBAT;


@end




