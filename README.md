<p align="center">
  <img width="200px" src="http://cloudrail.github.io/img/cloudrail_logo_github.png"/>
  
</p>
[![Version](https://img.shields.io/cocoapods/v/cloudrail-si-ios-sdk.svg?style=flat)](http://cocoapods.org/pods/cloudrail-si-ios-sdk)
[![Platform](https://img.shields.io/cocoapods/p/cloudrail-si-ios-sdk.svg?style=flat)](http://cocoapods.org/pods/cloudrail-si-ios-sdk)
## Integrate With Cocoapods (Swift & Objective-C)

CloudRail-SI-iOS is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile (remember to put the `use_frameworks!` flag on top of the `Podfile`):
````ruby
pod "cloudrail-si-ios-sdk"
````
Run `Pod install` again.

## Integrate Into Projects Without Cocoapods
### Swift

1. add a new __Objective-C__ File (any file will do) to your project and Xcode will prompt if you want to configure your project with a bridging header (`PROJECTNAME-Bridging-Header.h`), press __YES__ on the prompt.
2. Drag an drop the Framework file to the __"Embedded Binaries"__ of the iOS project, check __"copy files"__ if needed.
3. Xcode will generate and configure the file for you, on the file you have to import ( in a Objective-C way the framework) with `#import <CloudRail_ServiceCode/CloudRail_ServiceCode.h>`.
3. Make an AWESOME APP!!!

### Objective-C

Simply drag an drop the Framework file to the __"Embedded Binaries"__ of the iOS project, check __"copy files"__ if needed. Import the framework on the desired class with `#import <CloudRail_ServiceCode/CloudRail_ServiceCode.h>`, and have fun!

# CloudRail SI for iOS
Integrate Mulitple Services With Just One API

<p align="center">
<img width="300px" src="http://cloudrail.github.io/img/cloudrail_si_github.png"/>
</p>

CloudRail is a free software library which abstracts multiple APIs from different providers into a single and universal interface.

**Current Interfaces:**
<p align="center">
  <img width="255px" src="http://cloudrail.github.io/img/available_interfaces_ios.png"/>
</p>

Full documentation can be found at https://docs.cloudrail.com/

With CloudRail, you can easily integrate external APIs into your application. CloudRail is an abstracted interface that takes several services and then gives a developer-friendly API that uses common functions between all providers. This means that, for example, upload() works in exactly the same way for Dropbox as it does for Google Drive, OneDrive, and other Cloud Storage Services, and getEmail() works similarly the same way across all social networks.

## Code Sample
### Swift

```` swift
override func viewDidAppear(animated: Bool) {
    let dropbox: Dropbox = Dropbox.init(clientId: "DROPBOX_ID", clientSecret: "DROPBOX_SECRET")
    let inputstream =  dropbox.downloadWithFilePath("/futurama.jpg")
    //READ FROM THE INPUT STREAM 
  }
````

### Objective C
```` objective-c
#import <CloudRail_ServiceCode/CloudRail_ServiceCode.h>

@interface CRViewController ()
@property (nonatomic) Dropbox * dropbox;
@property (nonatomic) GoogleDrive * googleDrive;
//@property (nonatomic) OneDrive * oneDrive;
//@property (nonatomic) Box * box;
@end

@implementation CRViewController

- (void)viewDidLoad
{
[super viewDidLoad];
self.dropbox = [[Dropbox alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret"];

self.dropbox = [[GoogleDrive alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret"];


}

-(void)downloadAndUpload{

//Download File from Dropbox
NSInputStream * streamToDownloadedFile = [self.dropbox downloadWithPath:@"/mudkip.jpg"];

//Upload the downloaded file to Googledrive
[self.googleDrive uploadWithPath:@"/mudkip.jpg" inputStream:streamToDownloadedFile size:size];

}

@end
````

## Current Interfaces:

### Social Media Profiles Interface:

* Facebook
* Github
* Google Plus
* LinkedIn
* Slack
* Twitter
* Windows Live
* Yahoo

#### Features

* Get profile information, including full names, emails, genders, date of birth, and locales.
* Retrieve profile pictures.
* Login using the Social Network.

[Full Documentation](https://docs.cloudrail.com/docs/profile)

---

### Cloud Storage Interface:

* Dropbox
* Box
* Google Drive
* Microsoft OneDrive

#### Features:

* Download files from Cloud Storage.
* Upload files to Cloud Storage.
* Get Meta Data of files, folders and perform all standard operations (copy, move, etc) with them.
* Retrieve user information.

[Full Documentation](https://docs.cloudrail.com/docs/cloud-storage)

More interfaces like payment and messaging are coming soon.

## Advantages of Using CloudRail

* Consistent Interfaces: As functions work the same across all services, you can perform tasks between services simply.

* Easy Authentication: CloudRail includes easy ways to authenticate, to remove one of the biggest hassles of coding for external APIs.

* Switch services instantly: One line of code is needed to set up the service you are using. Changing which service is as simple as changing the name to the one you wish to use.

* Simple Documentation: There is no searching around Stack Overflow for the answer. The CloudRail documentation at https://docs.cloudrail.com/ is regularly updated, clean, and simple to use.

* No Maintenance Times: The CloudRail Libraries are updated when a provider changes their API.

## Get Updates

To keep updated with CloudRail, including any new providers that are added, just add your email address to https://cloudrail.com/updates/.

## Pricing

CloudRail is free to use. For all projects; commercial and non-commercial. We want APIs to be accessible to all developers. We want APIs to be easier to manage. This is only possible if there are free, powerful tools out there to do this. The only favor we are asking for, is to spread the word about this library. Thank you!

## Other Platforms

CloudRail is also available for other platforms like Android and Java. You can find all libraries on https://cloudrail.github.io

## Questions?

Get in touch at any time by emailing us: support@cloudrail.com
