//
//  CSDevice.h
//  ComaiotSDK
//
//  Created by 郑丰 on 2019/1/5.
//  Copyright © 2019年 zfeng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSDeviceConfig.h"
@class CSMessage;

@interface CSDevice : NSObject

@property (nonatomic, strong) NSString *appEnvid;
@property (nonatomic, strong) NSString *appUid;
//猫眼sn
@property (nonatomic, copy) NSString *comaiotSN;
//绑定时间
@property (nonatomic, strong) NSDate *bindDate;
@property (nonatomic, strong) NSString *devUid;
@property (nonatomic, strong) NSString *appAid;
//昵称
@property (nonatomic, strong) NSString *nickName;

@property (nonatomic, strong) NSString *clientId;

@property (nonatomic, getter=isOnline) BOOL online;
@property (nonatomic, getter=isShare) BOOL share;

@property (nonatomic, getter=isSleeping) BOOL sleep;

@property (nonatomic, strong) CSDeviceConfig *config;

+(instancetype)moddelWithDic:(NSDictionary*)dic;
- (void)updateWithDic:(NSDictionary*)dic;
@end

@interface CSDevice (CSMessage)

- (NSString*)sendTopic;
- (NSString*)noticeTopic;

- (NSString*)appNoticeTopic;

- (void)handleMessage:(CSMessage*)msg;
@end
/*
 device notice app
 */
//设备设置更新
extern  NSString * const CSMessageSetChangeNotice;
//设备远程视频
extern  NSString * const CSMessageRemoteVideoNotice;
//设备离线通知
extern  NSString * const CSMessageOfflineNotice;
//设备紧急电话呼叫
extern  NSString * const CSMessageCallAlertNotice;
//设备开启省电模式
extern  NSString * const CSMessageSavingModeNotice;
//设备进入声网
extern  NSString * const CSMessageJoinAgoraNotice;
//设备挂断
extern  NSString * const CSMessageCloseRemoteNotice;
//分享设备被取消
extern  NSString * const CSMessageShareRemoveNotice;
//设备升级过程状态上报
extern  NSString * const CSMessageUpgradingDeviceNotice;
/*
 CSMessageUpgradingDeviceNotice 上报数据格式
 {
 "downloadSize": 6467584,    //已下载byte
 "totalSize": 6467584,    //总共 byte
 "updateState": 2,       //1-开始下载 2-正在下载 3-下载失败 4-下载成功
 "clientId": "54cac70cd99a1ade1195bcf673f69afb-2c1717054275",
 "createTime": 1558526183574,
 "devUid": "9f66041c43de-9d757069"
 }
 */

/*
 app send device
 */
//查询在线状态
extern  NSString * const CSMessageStatusCMD;
//查询设备设置
extern  NSString * const CSMessageConfigGetCMD;
//修改设备设置
extern  NSString * const CSMessageConfigSetCMD;
//重启设备
extern  NSString * const CSMessageResetCMD;
//操作设备  //控制类型  0/1/2/3/4/5        拍照/录像/关闭紧急通话/上传日志/主动呼叫屋内通话
extern  NSString * const CSMessageControlCMD;
//远程视频
extern  NSString * const CSMessageGetVideoCMD;
//取消设备分享
extern  NSString * const CSMessageRemoveShareCMD;
//事件和报警是否抓拍
extern  NSString * const CSMessageEnableAlermCMD;
//升级信息
extern  NSString * const CSMessageUpgradeInfoCMD;
//升级设备
extern  NSString * const CSMessageUpgradeDeviceCMD;
/*
 CSMessageUpgradeInfoCMD 数据格式
 {
 "updateStatus":1                             1/0    //有新版本/无新版本
 "newFirmVersionName":"Ver_1.1.0"                    //版本名称
 "newFirmVersionDate":"2019-04-23"                   //版本发布时间
 "newFirmVersionContent":"1.修复系统 2.解决部分bug"  //版本更新内容
 }
 */

//切换设备工作模式workMode 0:省电模式；1:标准模式；2：智能模式
extern  NSString * const CSMessageSetWorkModeCMD;
