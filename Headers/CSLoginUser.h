//
//  CSLoginUser.h
//  ComaiotSDK
//
//  Created by 郑丰 on 2019/3/15.
//  Copyright © 2019年 zfeng. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface CSLoginUser : NSObject

@property (nonatomic, strong) NSString *token;

@property (strong, nonatomic) NSString *phone;
@property (strong, nonatomic) NSString *email;

@property (strong, nonatomic) NSString *nickname;
@property (strong, nonatomic) NSString *avatar;

@property (strong, nonatomic) NSString *wxNickname;
@property (strong, nonatomic) NSString *wxAvatar;

- (instancetype)initWithLoginInfo:(NSDictionary*)info;
@end

