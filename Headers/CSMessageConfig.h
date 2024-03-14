//
//  CSMessageConfig.h
//  ComaiotSDK
//
//  Created by 郑丰 on 2019/1/5.
//  Copyright © 2019年 zfeng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CocoaMQTT/CocoaMQTT-Swift.h>
NS_ASSUME_NONNULL_BEGIN

@interface CSMessageConfig : NSObject
@property (strong, nonatomic) NSString* host;
@property ( nonatomic) UInt16 port;
@property (strong, nonatomic) NSString* user;
@property (strong, nonatomic) NSString* password;
@property (strong, nonatomic) NSString* clentId;

//default is 300s Heartbeat interval
@property (nonatomic) NSInteger keepAlive;

- (CocoaMQTT*)generateMQTT;
@end

NS_ASSUME_NONNULL_END
