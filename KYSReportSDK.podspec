#
#  Be sure to run `pod spec lint KYSReportSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  s.name         = "KYSReportSDK"
  s.version      = "3.1.0"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
  s.summary      = "Xingjiang CBC scientific research big data iOS SDK"
  s.homepage     = "https://github.com/KevinCool01/KYSReportSDK"
  s.license      = "MIT"

  s.author       = { "Kevin Gu" => "gukai@cncoral.com" }
  s.platform     = :ios, "9.0"
  s.social_media_url   = "https://www.jianshu.com/u/2340260ae5ed"

  s.source       = { :git => "https://github.com/KevinCool01/KYSReportSDK.git", :tag => "#{s.version}" }
  s.source_files = "Classes/*.{h,m}"
  s.public_header_files = "Classes/*.h"
  s.frameworks = "Foundation", "UIKit", "CoreTelephony", "Security", "SystemConfiguration"
  s.libraries = "sqlite3"
  s.vendored_libraries = "Libraries/libKYSReportSDK.a"
  s.dependency "Protobuf"
  # xcode 12 的环境下需要加上如下配置，xcode 则不需要。因为xcode12 环境下的模拟器也包含此架构
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

end
