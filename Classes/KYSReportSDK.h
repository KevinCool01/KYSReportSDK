//
//  KYSReportSDK.h
//  PB
//
//  Created by gukai on 2019/10/28.
//  Copyright © 2019 gukai. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KYSModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface KYSReportSDK : NSObject
#pragma mark -- SDK的基本配置

/// 初始化SDK,，注册AppKey。
/// @note appKey 为必须参数，（必须配置）
/// @param appKey 数据统计平台配置的给应用的appKey
+ (void)registWithAppKey:(NSString *)appKey;

/// 设置 SDK 的运行环境
/// @note 必须设置运行环境， KYSEnvironmentNone 不能运行，需要选择开发环境或者生产环境
/// @param environment 默认为 KYSEnvironmentNone

+ (void)runEnvironment:(KYSEnvironment)environment;

/// 设置心跳周期
/// @note 心跳必须设置
/// @param time 多少时间进行心跳上报 ( 传入 0，则为默认的30s )
/// @param callBack   单次心跳将要上报的回调，返回当前心跳的pageId；返回值传入心跳的扩展数据
/// @param complete  单次心跳上报完成的回调
+ (void)setHeartTime:(NSTimeInterval)time
     heartWillReport:(nullable HeartWillReportCallBack)callBack
      reportComplete:(nullable ReportComplete)complete;

/// 设置单次曝光时长的阈值，单次曝光时长大于等于此单位，才进行曝光上报。( 默认 2s )
/// @param duration 曝光时长阈值
+ (void)setExposureThresholdDuration:(NSTimeInterval)duration;

/// 设置曝光数据上报的回调（非必须配置设置，如果需要查看上报结果，可以设置）
/// @param complete 回调
+ (void)setExposureReportComplete:(ReportComplete)complete;

/// 设置上报请求的超时时间，默认30s
/// @param timeout 超时时间
+ (void)setReportHttpTimeout:(NSTimeInterval)timeout;

/// 启动SDK，保持SDK的活跃 (SDK配置完成之后，调用此方法，以启动 SDK)
+ (void)alive;

#pragma mark -- 设置公共参数
/// 读取公共参数
+ (KYSCommon *)commonParamter;
/// 设置用户的基本信息
/// @param userInfo 用户信息
+ (void)setUserInfoWith:(KYSUserInfo *)userInfo;
+ (void)setUserId:(nullable NSString *)userId;
+ (void)setUserType:(nullable NSString *)userType;
+ (void)setUserLabels:(nullable NSArray *)labels;
+ (void)addUserLabel:(nullable NSString *)userLabel;
+ (void)removeUserLabel:(nullable NSString *)userLabel;
+ (void)setUserRegisterTime:(nullable NSString *)userRegisterTime;
+ (void)setUserRegisterVersion:(nullable NSString *)userRegisterVersion;
+ (void)setCountry:(nullable NSString *)country;
+ (void)setProvince:(nullable NSString *)province;
+ (void)setCity:(nullable NSString *)city;
+ (void)setArea:(nullable NSString *)area;
+ (void)setStreet:(nullable NSString *)street;
+ (void)setAdderss:(nullable NSString *)adderss;
+ (void)setLongitude:(nullable NSString *)longitude;
+ (void)setLatitude:(nullable NSString *)latitude;
+ (void)setBaseMap:(nullable NSDictionary *)baseMap;

/// 清除用户信息, 当用户退出登录的时候，可能要清除用户的信息
/// @note 会清除用户的userId, userType, userLabel, userRegisterTime, userRegisterVersion
+ (void)clearUser;

/// 清除设置的地址信息
/// @note 会清除公共参数的 国家 country，省份 province，城市 city ， 地区area， 具体街道street，详细地址 adderss，
+ (void)clearAddressInfo;

/// 清除用户的定位相关的经纬度信息
/// @note 会清除 longitude，latitude
+ (void)clearLocation;

/// 清除自定义设置的扩展 map 信息
/// @note 会清除 baseMap
+ (void)clearBaseMap;

#pragma mark -- 大数据上报事件
/// 页面访问
+ (void)pageEnter:(KYSPage *)page;
/// 页面退出 (页面退出上报的同时，会进行曝光数据的上报)
+ (void)pageExit:(KYSPage *)page reportWithComplete:(nullable ReportComplete)complete;
/// 点击事件
+ (void)click:(KYSClick *)click reportWithComplete:(nullable ReportComplete)complete;
/// 页面某个item滑入屏幕，开始曝光
+ (void)beginExposure:(KYSExposure *)exposure;
/// 页面某个item滑出屏幕，结束曝光
+ (void)endExposure:(KYSExposure *)exposure;
/// 曝光数据的上报，手动上报曝光数据，SDK在页面结束访问的时候会进行曝光上报，也可以在某个时刻自己调用一次曝光上报
+ (void)exposureReportWithComplete:(nullable ReportComplete)complete;
/// 页面请求错误，上报一个错误
+ (void)error:(KYSError *)error reportWithComplete:(nullable ReportComplete)complete;
/// 自定义上报。上报一个自定义消息
+ (void)customer:(KYSCustomer *)customer reportWithComplete:(nullable ReportComplete)complete;

#pragma mark -- 初始化 model

/// 用户的基本信息
/// @param userId 用户ID
/// @param userType 用户类型（webchat，qq，phone）
/// @param userLabels 用户标签，数组形式上报   exp: ['少儿'，'游戏','动漫']
/// @param userRegisterTime 用户注册时间
/// @param userRegisterVersion 用户注册版本号
/// @param country 国家
/// @param province 省份
/// @param city 城市
/// @param area 地区
/// @param adderss 详细街道地址
/// @param extMap 扩展数据
+ (KYSUserInfo *)modelWithUserId:(NSString *)userId
                        userType:(NSString *)userType
                      userLabels:(nullable NSArray *)userLabels
                userRegisterTime:(NSString *)userRegisterTime
             userRegisterVersion:(nullable NSString *)userRegisterVersion
                         country:(nullable NSString *)country
                        province:(nullable NSString *)province
                            city:(nullable NSString *)city
                            area:(nullable NSString *)area
                         adderss:(nullable NSString *)adderss
                          extMap:(nullable NSDictionary *)extMap;

/// 页面访问数据
/// @param pageId 页面ID，每个页面唯一标识
/// @param pageName 页面名称，英文字母格式，不能有中文或特殊字符
/// @param pageType 页面类型
/// @param netWorkTime 请求出网络数据的时间
/// @param extMap 扩展数据
+ (KYSPage *)modelWithPage:(NSString *)pageId
                  pageName:(nullable NSString *)pageName
                  pageType:(nullable NSString *)pageType
               netWorkTime:(NSTimeInterval)netWorkTime
                    extMap:(nullable NSDictionary *)extMap;

/// 点击事件
/// @param pageId 页面ID，每个页面唯一标识
/// @param eventId 点击内容Id/展示位id
/// @param eventType 点击事件类型 exp:collect/download/share/search/login
/// @param targetId 对应内容id（专题id/影片id/频道id/广告id）
/// @param targetName 对应内容名称（专题名称/影片名称/频道名称/广告名称）
/// @param targetType 对应内容类型（专题topic/影片video/频道channel/广告ad
/// @param extMap 扩展数据
+ (KYSClick *)modelWithClick:(NSString *)pageId
                     eventId:(nullable NSString *)eventId
                   eventType:(NSString *)eventType
                    targetId:(nullable NSString *)targetId
                  targetName:(nullable NSString *)targetName
                  targetType:(nullable NSString *)targetType
                      extMap:(nullable NSDictionary *)extMap;

/// 曝光的数据的item
/// @param pageId 页面ID，每个页面唯一标识
/// @param eventId 曝光位置Id/展示位id
/// @param targetId 对应内容id（专题id/影片id/频道id/广告id）
/// @param targetName 对应内容名称（专题名称/影片名称/频道名称/广告名称）
/// @param targetType  对应内容类型（专题topic/影片video/频道channel/广告ad
/// @param extMap 扩展数据map
+ (KYSExposure *)modelWithExposure:(NSString *)pageId
                           eventId:(nullable NSString *)eventId
                          targetId:(nullable NSString *)targetId
                        targetName:(nullable NSString *)targetName
                        targetType:(nullable NSString *)targetType
                            extMap:(nullable NSDictionary *)extMap;

/// 错误数据
/// @param errorType 错误类型
/// @param errorCode 错误码
/// @param errorDesc  错误描述
/// @param extMap 扩展数据map
+ (KYSError *)modelWithError:(NSString *)errorType
                   errorCode:(NSString *)errorCode
                   errorDesc:(NSString *)errorDesc
                      extMap:(nullable NSDictionary *)extMap;


/// 自定义上报
/// @param eventType  自定义事件类型
/// @param extMap 扩展数据map {goodsId:123,goodsName:oppo手机,goodsPrice:2300}
+ (KYSCustomer *)modelWithCutomer:(NSString *)eventType
                           extMap:(nullable NSDictionary *)extMap;
@end

NS_ASSUME_NONNULL_END