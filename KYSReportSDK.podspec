#
#  Be sure to run `pod spec lint KYSReportSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  s.name         = "KYSReportSDK"
  s.version      = "2.1.1"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
  s.summary      = "Xingjiang CBC scientific research big data iOS SDK"
  s.homepage     = "https://github.com/KevinCool01/KYSReportSDK"
  s.license      = "MIT"

  s.author       = { "Kevin Gu" => "gukai@cncoral.com" }
  s.platform     = :ios, "8.0"
  s.social_media_url   = "https://www.jianshu.com/u/2340260ae5ed"

  s.source       = { :git => "https://github.com/KevinCool01/KYSReportSDK.git", :tag => "#{s.version}" }
  s.source_files = "Classes/*.{h,m}"
  s.public_header_files = "Classes/*.h"
  s.frameworks = "Foundation", "UIKit", "CoreTelephony", "Security", "SystemConfiguration"
  s.libraries = "sqlite3"
  s.vendored_libraries = "Libraries/libKYSReportSDK.a"
  s.dependency "Protobuf"

end
