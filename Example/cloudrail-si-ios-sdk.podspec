
Pod::Spec.new do |s|
  s.name             = 'cloudrail-si-ios-sdk'
  s.version          = '5.5.2'
  s.summary          = 'CloudRail is a free software library which abstracts multiple APIs from different providers into a single and universal interface.'



  s.description      = <<-DESC
Full documentation can be found at https://docs.cloudrail.com/

With CloudRail, you can easily integrate external APIs into your application. CloudRail is an abstracted interface that takes several services and then gives a developer-friendly API that uses common functions between all providers. This means that, for example, upload() works in exactly the same way for Dropbox as it does for Google Drive, OneDrive, and other Cloud Storage Services.

                       DESC


  s.homepage         = 'http://www.cloudrail.com'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'Copyright', :file => 'LICENSE' }
  s.author           = { 'Felipe Cesar' => 'felipe.cesar@cloudrail.com' }
  s.source           = { :git => 'https://github.com/CloudRail/cloudrail-si-ios-sdk.git', :tag => s.version.to_s }
  s.social_media_url = 'https://twitter.com/CloudRail'

  s.ios.deployment_target = '8.0'
  
  s.frameworks = 'UIKit', 'MapKit', 'CloudrailSI'
end
