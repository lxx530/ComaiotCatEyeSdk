//
//  CSMessageCenter.h
//  ComaiotSDK
//
//  Created by 郑丰 on 2019/1/5.
//  Copyright © 2019年 zfeng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIApplication.h>
#import "CSMessage.h"
#import "CSDevice.h"
#import "CSMessageConfig.h"

#import <CocoaMQTT/CocoaMQTT-Swift.h>
@class CSMessageCenter;
typedef NS_ENUM(NSInteger, CSMessageCenterState){
    CSMessageCenterStateNone,
    CSMessageCenterStateConnecting,
    CSMessageCenterStateConnected,
    CSMessageCenterStateDisconnected,
};


//连接消息服务完成
extern  NSString * const CSMsgCenterDidConnectSeverNotification;
//添加设备完成
extern  NSString * const CSMsgCenterDidAddDeviceNotification;
//接受到消息
extern  NSString * const CSMsgCenterDidReceiveMsgNotification;
//消息发送完成
extern  NSString * const CSMsgCenterDidPushMsgNotification;

//通知 userinfo 设备信息key
extern  NSString * const CSMsgCenterNotificationDeviceKey;
//通知 userinfo Message信息key
extern  NSString * const CSMsgCenterNotificationMessageKey;

@protocol CSMessageCenterDelegate <NSObject>
@optional
//连接消息服务完成
- (void)didConnectSever:(CSMessageCenter*)center;
//添加设备完成
- (void)msgCenter:(CSMessageCenter*)center didAddDevice:(CSDevice *)dev;
//接受到消息
- (void)msgCenter:(CSMessageCenter*)center didReceiveMsg:(CSMessage *)msg withDevice:(CSDevice *)device;
//消息发送完成
- (void)msgCenter:(CSMessageCenter*)center didPushMsg:(CSMessage *)msg toDevice:(CSDevice *)device;
@end

@interface CSMessageCenter : NSObject
+ (CSMessageCenter*)defaultCenter;

@property (weak, nonatomic) id<CSMessageCenterDelegate> delegate;

- (void)configMssageCenter:(CSMessageConfig*)config;
- (void)bindCustomMqttToMssageCenter:(CocoaMQTT*)mqtt;

- (void)connectMessageSever;
- (void)disconnectMessageSever;

- (CSMessageCenterState)currentState;

- (void)addDevice:(CSDevice*)dev;
- (void)removeDevice:(CSDevice*)dev;

- (BOOL)sendMsg:(CSMessage*)msg toDevice:(CSDevice*)dev;
@end
