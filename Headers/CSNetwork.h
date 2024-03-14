//
//  CSNetwork.h
//  ComaiotSDK
//
//  Created by 郑丰 on 2019/1/5.
//  Copyright © 2019年 zfeng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AFNetworking/AFNetworking.h>
@interface CSNetwork : NSObject

+(CSNetwork*)shareInstance;

- (void)networkWithAPI:(NSString *)api parameters:(NSDictionary *)parameters response:(void (^)(id data, NSError*error))response;

- (void)CSNetworkWithAPI:(NSString *)api parameters:(NSDictionary *)parameters response:(void (^)(id data, NSError*error))response;
@end

