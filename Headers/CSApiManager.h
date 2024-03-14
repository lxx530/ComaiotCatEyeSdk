//
//  CSApiManager.h
//  CSDemo
//
//  Created by 郑丰 on 2019/2/16.
//  Copyright © 2019年 zfeng. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CSMessageConfig.h"
#import "CSMessageCenter.h"
#import "CSMessage.h"
#import "CSDevice.h"
#import "CSDeviceConfig.h"
#import "CSShareUser.h"
#import "CSNetwork.h"
#import "CSLoginUser.h"

typedef void (^CSLoginBlock)(NSInteger errCode) ;

//视频key
extern NSString * CSAgoraRtcAppid;

//设备列表更新
extern NSString * CSDeviceUpdateNotifacation;
//收到设备发送的Notice消息
extern NSString * CSDeviceNoticeNotifacation;



@interface CSApiManager : NSObject

+(CSApiManager*)shareInstance;
//Jwt登录
- (void)launchApiWithPublicToken:(NSString *)pToken resp:(CSLoginBlock)resp;
//退出登录
- (void)exitlogin:(void (^)(BOOL complete))complete;
//Jwt登录成功后使用
- (NSString*)jwtUid;

//登录成功后使用

- (NSString*)appClentId;

//用户系统登录成功后使用
- (CSLoginUser*)loginUser;

//当前设备列表
-(NSArray *)devices;

- (CSDevice*)deviveWithUID:(NSString*)uid;
-(void)addDevice:(CSDevice*)device;
-(void)addDeviceWithArray:(NSArray<CSDevice*>*)devices;

-(void)removeDevice:(CSDevice*)device;
-(void)removeDeviceWithArray:(NSArray<CSDevice*>*)devices;

- (BOOL)sendMsg:(CSMessage*)msg toDevice:(CSDevice*)dev;

//发起远程视频查看
- (void)useConnetRomoteVideo:(CSDevice*)device;
@end

@interface CSNetwork (APIPublic)/*请在登录后使用以下api*/

- (void)interfaceNetworkWithAPI:(NSString *)api parameters:(NSDictionary *)parameters response:(void (^)(id data, NSError*error))response;

#pragma mark - 设备信息相关
//查询登录用户设备列表
- (void)networkDeviceList:(NSDictionary *)parameters response:(void (^)(id data, NSError*error))response;

//获取设备配置信息
- (void)networkGetDevConfig:(NSDictionary *)parameters response:(void (^)(id data, NSError*error))response;

//获取设备报警信息
- (void)networkGetDevAlarmList:(NSDictionary *)parameters response:(void (^)(id data, NSError*error))response;

#pragma mark - 设备绑定相关
//获取AID
- (void)networkGetAID:(NSDictionary *)parameters response:(void (^)(id data, NSError*error))response;
//获取绑定二维码字段
- (void)networkBindQRCode:(NSDictionary *)parameters response:(void (^)(id data, NSError*error))response;
//通过分享绑定设备// 错误码：1301<分享code或num错误>,1303<分享code或numq过期>,1501<已经绑定>
- (void)networkShareBind:(NSDictionary *)parameters response:(void (^)(id data, NSError*error))response;

//查询设备是否绑定成功(注意调用频次，建议间隔3s查询一次)
- (void)networkDeviceBind:(NSDictionary *)parameters response:(void (^)(id data, NSError*error))response;
//删除绑定设备
- (void)networkRemoveBind:(NSDictionary *)parameters response:(void (^)(id data, NSError*error))response;
#pragma mark - 设备分享相关
//生成分享二维码和分享码<有效时间10分钟>
- (void)networkShareCode:(NSDictionary *)parameters response:(void (^)(id data, NSError*error))response;
//添加分享设备
- (void)networkShareAddWithPhone:(NSDictionary *)parameters response:(void (^)(id data, NSError*error))response;
//获取设备分享用户
- (void)networkGetShareUser:(NSDictionary *)parameters response:(void (^)(id data, NSError*error))response;
//删除分享用户
- (void)networkRemoveShareUser:(NSDictionary *)parameters response:(void (^)(id data, NSError*error))response;
@end

@interface CSApiManager (APIHandle)/*请在登录后使用以下api*/

//获取设备列表
- (void)getDeviceList:(void (^)(NSArray<CSDevice*>*devices, NSError*error))response;

//获取设备配置信息
- (void)getDevConfig:(CSDevice *)device response:(void (^)(CSDeviceConfig* config, NSError*error))response;

//移除设备
- (void)removeDevice:(CSDevice*)device response:(void (^)(NSError*error))response;
//获取配网Code
- (void)deviceNetCodeWithSSID:(NSString*)ssid password:(NSString *)pw response:(void (^)(NSString*aid,NSString*code, NSError*error))response;

//设备添加分享code和分享码 <code和num 二选一> // 错误码：1301<分享code或num错误>,1303<分享code或numq过期>,1501<已经绑定>
- (void)shareAddWithCode:(NSString *)code number:(NSString *)num
                 response:(void (^)(id data, NSError*error))response;
@end

@interface CSDevice (Public)

/**
 查询设备在线状态
 */
- (void)updateStatusFromDev;

/**
 查询设备配置信息
 */
- (void)updateConfigFromDev;

/**
 设备上传日志
 */
- (void)sendUplodLog;

/**
 设置设备人形侦测
 */
- (void)sendSetPerson:(CSDevicePerson*)person;

/**
 设置设备昵称
 */
- (void)sendSetNickname:(NSString*)name;
/**
 设置门铃类型和门铃音量
 
 @param r 门铃类型
 @param s 音量
 @param infrared 红外夜视模式
 */
- (void)sendSetRing:(int)r sound:(int)s infrared:(int)i;

//查询设备是否休眠
- (void)getDevSleep:(void (^)(BOOL sleep, NSError*error))response;

//生成添加分享code和分享码<有效时间10分钟>
- (void)genDevShareCode:(void (^)(NSString*code, NSString*number, NSError*error))response;

//设备添加分享用户
- (void)shareAddWithPhone:(NSString *)phone
                 response:(void (^)(id data, NSError*error))response;
//获取设备分享用户
- (void)getShareUserList:(void (^)(NSArray<CSShareUser*>* users, NSError*error))response;
@end

@interface CSShareUser (Public)

//删除分享用户
- (void)removeShareUser:(void (^)(id data, NSError*error))response;
@end

#pragma mark - 用户系统

@interface CSApiManager (UserSystem)

/* 用户系统 非jwt登录使用 */

//手机号发送验证码
- (void)sendSmsCodeAuth:(NSString*)phone sign:(NSString*)sign resp:(void (^)(NSError *error))resp;

//手机号密码登录
- (void)loginPhone:(NSString*)phone password:(NSString *)pw resp:(void (^)(NSError *error, CSLoginUser *user))resp;
//手机号验证码登录
- (void)loginPhone:(NSString*)phone smsCode:(NSString *)smsCode resp:(void (^)(NSError *error, CSLoginUser *user))resp;

/**
 微信登录
 @param code 微信授权code
 */
- (void)loginWXCode:(NSString*)code resp:(void (^)(NSError *error, CSLoginUser *user))resp;

/**
 注册
 
 @param phone 手机号
 @param pw 密码
 @param smsCode 短信验证码
 
 */
- (void)registerUser:(NSString*)phone password:(NSString*)pw smsCode:(NSString*)smsCode resp:(void (^)(NSError *error))resp;

/**
 绑定微信
 
 @param phone 手机号
 @param smsCode 短信验证码
 @param wxcode 微信Code
 */
- (void)bindWXWithPhone:(NSString*)phone smsCode:(NSString *)smsCode wxcode:(NSString *)wxcode resp:(void (^)(NSError *error))resp;

/**
 忘记密码
 
 @param phone 手机号
 @param smsCode 短信验证码
 @param pw 新密码
 */
- (void)forgetPassword:(NSString*)phone smsCode:(NSString *)smsCode newPassword:(NSString *)pw resp:(void (^)(NSError *error))resp;

//修改密码
- (void)resetPasswordWithOld:(NSString*)opw newPassword:(NSString *)npw withUser:(CSLoginUser*)user resp:(void (^)(NSError *error))resp;
//设置头像
- (void)updateUserAvatar:(NSString*)url withUser:(CSLoginUser*)user resp:(void (^)(NSError *error))resp;

@end
