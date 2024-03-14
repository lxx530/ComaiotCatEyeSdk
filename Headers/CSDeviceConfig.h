//
//  CSDeviceConfig.h
//  ComaiotSDK
//
//  Created by 郑丰 on 2019/2/16.
//  Copyright © 2019年 zfeng. All rights reserved.
//

#import <Foundation/Foundation.h>


@class CSDevicePerson,CSDeviceInfo;
@interface CSDeviceConfig : NSObject
@property (nonatomic, strong) NSString *deviceId;
//铃声 0/1/2/3 四种铃声模式（传统，鸟叫，音乐，人声）
@property (nonatomic, strong) NSString *ring;
//音量  0/1/2      低/中/高
@property (nonatomic, strong) NSString *sound;
//拆机报警开关 0/1        关/开
@property (nonatomic, strong) NSString *alarm;
//语言  0/1        英文/中文
@property (nonatomic, strong) NSString *language;
//wifi名称
@property (nonatomic, strong) NSString *wifi;
//wifi 信号量 0~-99
@property (nonatomic, strong) NSString *wifi_rssi;
//电量模式  0/1/2        省电模式/普通模式/智能模式
@property (nonatomic, strong) NSString *batteryMode;
//电量  0~100
@property (nonatomic, strong) NSString *battery;

//红外夜视模式  0/1/2  自动/常开/常闭
@property (nonatomic, strong) NSString *infraredMode;

/*人形侦测*/
@property (nonatomic, strong) CSDevicePerson *person;
/*设备信息*/
@property (nonatomic, strong) CSDeviceInfo *deviceInfo;

+ (instancetype)modelWithObjDic:(NSDictionary *)dic;
- (void)updateWithDic:(NSDictionary*)dic;
- (NSDictionary *)getInfo;
@end

@interface CSDeviceInfo : NSObject
//软件版本信息
@property (nonatomic, strong) NSString *version_info;
//固件信息
@property (nonatomic, strong) NSString *firm_version;
//硬件版本号
@property (nonatomic, strong) NSString *version;
//设备总容量
@property (nonatomic, strong) NSString *total_stroage;
//已用容量
@property (nonatomic, strong) NSString *use_stroage;
//新固件版本，没有则为空
@property (nonatomic, strong) NSString *update_firm_version;
//最新固件下载地址，没有则为空
@property (nonatomic, strong) NSString *update_firm_download;

//型号
@property (nonatomic, strong) NSString *model;
//蓝牙地址
@property (nonatomic, strong) NSString *ble_mac;
//mac地址
@property (nonatomic, strong) NSString *macAddress;

+ (instancetype)modelWithObjDic:(NSDictionary *)dic;
- (void)updateWithDic:(NSDictionary*)dic;
- (NSDictionary *)getInfo;
@end

@interface CSDevicePerson : NSObject

//门铃灯 0/1        关/开
@property (nonatomic, strong) NSString *ring_light;
//人体检测开关   0/1        关/开
@property (nonatomic, strong) NSString *status;
//自动抓拍时间
@property (nonatomic, strong) NSString *auto_pic;
//灵敏度         0/1/2        低/高
@property (nonatomic, strong) NSString *sensitive;
//报警模式       0/1          拍照/录像
@property (nonatomic, strong) NSString *alarm_mode;
//连拍张数 3/5/7       3张/5张/7张
@property (nonatomic, strong) NSString *tack_pic_num;
//门外声音报警 0/1          关/开
@property (nonatomic, strong) NSString *out_door_alarm;
//报警音量 0/1/2        高/中/低
@property (nonatomic, strong) NSString *out_door_sound;
//门外铃声  0/1/2/3    四种铃声模式（人声，狗叫，雷达，自定义）
@property (nonatomic, strong) NSString *out_door_ring;
//报警通知间隔(计量单位为秒)
@property (nonatomic, strong) NSString *notification_duration;
+(instancetype)modelWithObjDic:(NSDictionary*)dic;

- (void)updateWithDic:(NSDictionary*)dic;
- (NSDictionary *)getInfo;
@end


