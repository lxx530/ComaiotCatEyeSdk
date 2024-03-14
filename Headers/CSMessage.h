//
//  CSMessage.h
//  ComaiotSDK
//
//  Created by 郑丰 on 2019/1/6.
//  Copyright © 2019年 zfeng. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CSMessage : NSObject
//发送方命令；
@property (nonatomic, strong) NSString* cmd;
//时间戳
@property (nonatomic) NSTimeInterval timestamp;
//类似http body
@property (nonatomic, strong) NSMutableDictionary* content;
@end

@interface CSMessage (Command)

+ (CSMessage*)messageWithCMD:(NSString*)cmd;

//查询在线状态
+(CSMessage *)queryStatus;
//查询设备设置
+(CSMessage *)queryConfig;
//修改设备设置
+(CSMessage *)setConfig;
//重启设备
+(CSMessage *)reset;
//操作设备  //控制类型  control_type   0/1/2/3        拍照/录像/关闭紧急通话/上传日志
+(CSMessage *)controlDev;
//获取视频通道
+(CSMessage *)getVideo;
//修改设备分享
+(CSMessage *)removeShare;

//事件和报警是否抓拍
+(CSMessage *)enableAlerm:(BOOL)al event:(BOOL)ev;

//查询升级信息
+(CSMessage *)queryUpgradeInfo;
//升级设备
+(CSMessage *)upgrade;

//设置设备工作模式 0:省电模式；1:标准模式；2：智能模式
+(CSMessage *)workMode:(int)mode;

@end

