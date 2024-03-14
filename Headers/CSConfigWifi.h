//
//  CSConfigWifi.h
//  ComaiotUIDemo
//
//  Created by 郑丰 on 2019/2/26.
//  Copyright © 2019年 zfeng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CocoaAsyncSocket/GCDAsyncSocket.h>

@interface CSConfigWifi : NSObject
//自动获取当前wifi路由地址 给设备发送code
+ (CSConfigWifi *)sendConfigCode:(NSString*)code timeout:(NSTimeInterval)timeout complete:(void (^)(BOOL finish))complete;
//使用wifi  给设备发送code
+ (CSConfigWifi *)sendConfigCode:(NSString*)code wifi:(NSString *)wifiIP timeout:(NSTimeInterval)timeout complete:(void (^)(BOOL finish))complete;
//使用路由地址  给设备发送code
+ (CSConfigWifi *)sendConfigCode:(NSString*)code router:(NSString *)routerIP timeout:(NSTimeInterval)timeout complete:(void (^)(BOOL finish))complete;



@end

