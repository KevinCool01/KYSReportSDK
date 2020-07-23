//
//  KYSModel.h
//  KYS
//
//  Created by gukai on 2019/10/28.
//  Copyright © 2019 gukai. All rights reserved.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, KYSEnvironment) {
    KYSEnvironmentNone,         // 未配置环境上报地址
    KYSEnvironmentDevelopment,  // 开发测试地址
    KYSEnvironmentProduction    // 生产正式地址
};
/// 大数据上报的回调
typedef void(^ReportComplete)(BOOL isSuccess,  id _Nullable object, NSString * message);
/// 心跳将要上报的回调
typedef NSDictionary * _Nullable(^HeartWillReportCallBack)(NSString * pageId);

@interface KYSModel : NSObject
@end

@interface KYSCommon : KYSModel
@property(nonatomic, copy) NSString * appKey;/**< 数据统计平台配置*/
@property(nonatomic, copy) NSString * randomId;/**< 客户端一次开启到关闭完整流程标识，web一次访问流程标识*/
@property(nonatomic, copy) NSString * device;/**< exp: iphone6s*/
@property(nonatomic, copy) NSString * deviceId;/**< 设备唯一标示符，必填项 */
@property(nonatomic, copy) NSString * deviceType;/**< 设备类型（Phone/Pad/PC）*/
@property(nonatomic, copy) NSString * system;/**< exp: ios or android or h5 or pc*/
@property(nonatomic, copy) NSString * systemVersion;/**< exp: 10.1.0*/
@property(nonatomic, copy) NSString * network;/**< exp: 3g or 4g or wifi*/
@property(nonatomic, copy) NSString * userId;/**< 已登录用户必填*/
@property(nonatomic, copy) NSString * userType;/**< 用户类型（webchat，qq，phone），已登录用户必填 */
@property(nonatomic, copy) NSString * userLabels;/**< 用户标签，数组形式上报   exp: ['少儿'，'游戏','动漫'] */
@property(nonatomic, copy) NSString * userRegisterTime;/**< 用户注册时间*/
@property(nonatomic, copy) NSString * userRegisterVersion;/**< 用户注册版本号 */
@property(nonatomic, copy) NSString * appVersion;/**< exp: 5.1.0 */
@property(nonatomic, copy) NSString * appChannel;/**< exp: appstore */
@property(nonatomic, copy) NSString * cityAddr;/**< 城市位置信息，省市县之间用逗号隔开（中国，新疆，喀什地区，喀什市，浩罕乡）*/
@property(nonatomic, copy) NSString * longitude; /**< 经度*/
@property(nonatomic, copy) NSString * latitude;  /**< 纬度*/
@property(nonatomic, copy) NSString * ip; /**< exp: 127.0.0.1*/
@property(nonatomic, copy) NSString * operators;/**< 运营商 exp: 中国移动 */
@property(nonatomic, copy) NSString * sdkVersion;/**<  sdk 的版本*/
@property(nonatomic, copy) NSDictionary * extMap;/**< 扩展数据map*/
@end

@interface KYSUserInfo : KYSModel
@property (nonatomic, copy, nullable) NSString * userId;/**< 用户ID*/
@property (nonatomic, copy, nullable) NSString * userType;/**< 用户类型（webchat，qq，phone），已登录用户必填*/
@property (nonatomic, copy, nullable) NSMutableArray * userLabels;/**< 用户标签，数组形式上报   exp: ['少儿'，'游戏','动漫'] */
@property (nonatomic, copy, nullable) NSString * userRegisterTime;/**< 用户注册时间 */
@property (nonatomic, copy, nullable) NSString * userRegisterVersion;/**<  用户注册版本号*/
@property (nonatomic, copy, nullable) NSString * country;/**< 国家*/
@property (nonatomic, copy, nullable) NSString * province;/**< 省份*/
@property (nonatomic, copy, nullable) NSString * city;/**< 城市*/
@property (nonatomic, copy, nullable) NSString * area;/**< 地区*/
@property (nonatomic, copy, nullable) NSString * street;/**< 街道地址*/
@property (nonatomic, copy, nullable) NSString * adderss;/**< 详细地址*/
@property (nonatomic, copy, nullable) NSString * longitude;/**< 经度*/
@property (nonatomic, copy, nullable) NSString * latitude;/**< 纬度*/
@property (nonatomic, copy, nullable) NSString * lang; /**< 语言*/
@property (nonatomic, copy, nullable) NSDictionary * extMap;/**< 扩展数据*/
@end

@interface KYSPage : KYSModel
@property (nonatomic, copy) NSString * pageId;/**<页面的唯一标识符*/
@property (nonatomic, copy) NSString * pageName; /**< 页面名称，英文字母格式，不能有中文或特殊字符*/
@property (nonatomic, copy) NSString * pageType;/**< 页面类型 */
@property (nonatomic, assign) NSTimeInterval netWorkTime ;/**< 请求出网络数据的时间戳，毫秒*/
@property (nonatomic, copy, nullable) NSDictionary * extMap;/**< 扩展数据*/
@end

@interface KYSClick : KYSModel
@property (nonatomic, copy) NSString * pageId;/**< 页面ID，每个页面唯一标识*/
@property (nonatomic, copy) NSString * eventId;/**< 点击内容Id/展示位id **/
@property (nonatomic, copy) NSString * eventType;/**< 点击事件类型 exp:collect/download/share/search/login **/
@property (nonatomic, copy) NSString * targetId;/**< 对应内容id*/
@property (nonatomic, copy) NSString * targetName;/**< 对应内容名称*/
@property (nonatomic, copy) NSString * targetType;/**< 对应内容类型*/
@property (nonatomic, copy, nullable) NSDictionary * extMap;/**< 扩展数据map*/
@end

@interface KYSExposure : KYSModel
@property (nonatomic, copy) NSString * pageId;/**< 页面ID，每个页面唯一标识*/
@property (nonatomic, copy) NSString * eventId;/**< 曝光位置Id/展示位id */
@property (nonatomic, copy) NSString * targetId;/**< 对应内容id（专题id/影片id/频道id/广告id*/
@property (nonatomic, copy) NSString * targetName;/**< 对应内容名称（专题名称/影片名称/频道名称/广告名称）*/
@property (nonatomic, copy) NSString * targetType;/**< 对应内容类型（专题topic/影片video/频道channel/广告ad*/
@property (nonatomic, copy, nullable) NSDictionary * extMap;/**< 扩展数据map*/
@end

@interface KYSError : KYSModel
@property (nonatomic, copy) NSString * errorType;/**< 错误类型*/
@property (nonatomic, copy) NSString * errorCode;/**< 错误码*/
@property (nonatomic, copy) NSString * errorDesc;/**< 错误描述*/
@property (nonatomic, copy, nullable) NSDictionary * extMap;/**< 扩展数据map */
@end

@interface KYSCustomer : KYSModel
@property (nonatomic, copy) NSString * eventType;/**< 自定义事件类型*/
@property (nonatomic, copy, nullable) NSDictionary * extMap;/**< 扩展数据map {goodsId:123,goodsName:oppo手机,goodsPrice:2300} */
@end

NS_ASSUME_NONNULL_END
