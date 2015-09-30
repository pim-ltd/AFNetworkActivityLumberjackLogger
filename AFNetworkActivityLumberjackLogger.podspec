Pod::Spec.new do |s|
  s.name     = 'AFNetworkActivityLumberjackLogger@pim-ltd'
  s.version  = '2.0.4'
  s.license  = 'MIT'
  s.summary  = 'AFNetworking 2.0 Extension for Network Request Logging with Support of CocoaLumberjack forked from AFNetworkActivityLogger by Matt Thompson'
  s.homepage = 'https://github.com/pim-ltd/AFNetworkActivityLogger'
  s.authors  = { 'Sohayb Hassoun' => 'sohayb.hassoun@gmail.com' }
  s.source   = { :git => 'https://github.com/pim-ltd/AFNetworkActivityLogger.git', :tag => '2.0.4' }
  s.source_files = 'AFNetworkActivityLogger'
  s.requires_arc = true
  s.ios.deployment_target = '6.0'
  s.osx.deployment_target = '10.8'

  s.dependency 'AFNetworking/NSURLSession', '~> 2.0'
  s.dependency 'AFNetworking/NSURLConnection', '~> 2.0'
  s.dependency 'CocoaLumberjack', '~> 2.0'
end
