//
//  CSShareUser.h
//  ComaiotSDK
//
//  Created by 郑丰 on 2019/2/25.
//  Copyright © 2019年 zfeng. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CSUserPlatform;

@interface CSShareUser : NSObject

@property (nonatomic, strong) NSString *appAid;
@property (nonatomic, strong) NSString *appUid;

@property (nonatomic, strong) NSString *devUid;

@property (nonatomic, strong) NSString *avatar;
@property (nonatomic, strong) NSString *nickname;
@property (nonatomic, strong) NSString *phoneNum;

@property (nonatomic, strong) CSUserPlatform *wechart;

+ (id)shareUserWithInfo:(NSDictionary*)userInfo;
@end

@interface CSUserPlatform : NSObject

@property (nonatomic, strong) NSString *avatar;
@property (nonatomic, strong) NSString *nickname;

@end

