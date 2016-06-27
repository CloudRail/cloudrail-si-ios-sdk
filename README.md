<p align="center">
  <img width="200px" src="http://cloudrail.github.io/img/cloudrail_logo_github.png"/>
</p>
# CloudRail SI for iOS
Integrate Multiple Services With Just One API

<p align="center">
  <img width="300px" src="http://cloudrail.github.io/img/cloudrail_si_github.png"/>
</p>

CloudRail is a free software library which abstracts multiple APIs from different providers into a single and universal interface.

**Current Interfaces:**
<p align="center">
  <img width="800px" src="http://cloudrail.github.io/img/available_interfaces_v2.png"/>
</p>

Full documentation can be found at https://docs.cloudrail.com/

With CloudRail, you can easily integrate external APIs into your application. CloudRail is an abstracted interface that takes several services and then gives a developer-friendly API that uses common functions between all providers. This means that, for example, upload() works in exactly the same way for Dropbox as it does for Google Drive, OneDrive, and other Cloud Storage Services, and getEmail() works similarly the same way across all social networks.

## Current Interfaces:
Interface | Included Services 
--- | --- 
Cloud Storage | Dropbox, Google Drive, OneDrive, Box
Social Profiles | Facebook, GitHub, Google+, LinkedIn, Slack, Twitter, Windows Live, Yahoo, Instagram
Payment | PayPal, Stripe
Email | Maljet, Sendgrid
SMS | Twilio, Nexmo
Point of Interest | Google Places, Foursquare, Yelp
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
#### Code Sample
```` objective-c
//   self.service = [[OneDrive alloc] initWithClientId:self.authDic[@"key"] clientSecret:self.authDic[@"secret"]];
//   self.service = [[GoogleDrive alloc] initWithClientId:self.authDic[@"key"] clientSecret:self.authDic[@"secret"]];
//   self.service = [[Box alloc] initWithClientId:self.authDic[@"key"] clientSecret:self.authDic[@"secret"]];
  
  self.service = [[Dropbox alloc] initWithClientId:self.authDic[@"dropboxKey"] clientSecret:self.authDic[@"dropboxSecret"]];
  NSInputStream * object = [self.dropbox downloadWithFilePath:@"/mudkip.jpg"];
  
    //READ FROM STREAM
````

---

### Social Media Profiles Interface:

* Facebook
* Github
* Google Plus
* LinkedIn
* Slack
* Twitter
* Windows Live
* Yahoo
* Instagram

#### Features

* Get profile information, including full names, emails, genders, date of birth, and locales.
* Retrieve profile pictures.
* Login using the Social Network.

[Full Documentation](https://docs.cloudrail.com/docs/profile)
#### Code Sample

```` objective-c
//  self.service = [[GitHub alloc] initWithClientId:@"key" clientSecret:@"secret"];
//  self.service = [[Instagram alloc] initWithClientId:@"key" clientSecret:@"secret"];
//  self.service = [[Slack alloc] initWithClientId:@"key" clientSecret:@"secret"];
//  self.service = [[GooglePlus alloc] initWithClientId:@"key" clientSecret:@"secret"];
 
  self.service = [[Facebook alloc] initWithClientId:@"key" clientSecret:@"secret"];

  NSString * fullName = [self.service fullName];
````

---

### Payment Interface:

* PayPal
* Stripe

#### Features Interface

* Perform charges
* Refund previously made charges
* Manage subscriptions

[Full Documentation](https://docs.cloudrail.com/docs/payment)
#### Code Sample

```` objective-c
//  self.service = [[PayPal alloc] initWithUseSandbox:YES clientId:key clientSecret:secret];
  self.service = [[Stripe alloc]initWithSecretKey:key];
  
  SubscriptionPlan * subPlan = [self.service createSubscriptionPlanWithName:@"Plan name" amount:@2000 currency:@"USD" description:@"description" Longerval:@"day" Longerval_count:@7];
  
  NSLog(@"Sub plan %@", subPlan);
````
---

### Email Interface:

* Mailjet
* Sendgrid

#### Features

* Send Email

[Full Documentation](https://docs.cloudrail.com/docs/email)
#### Code Sample

````objective-c
//  self.service = [[MailJet alloc] initWithClientId:key clientSecret:secret];
  self.service = [[SendGrid alloc]initWithUsername:key password:secret];

  [self.service sendEmailFromAddress:@"cloudrail@cloudrail.com"
                            fromName:@"Bob"
                         toAddresses:[@[@"foo@gmail.com",@"bar@gmail.com"] mutableCopy]
                             subject:@"Mailjet and SendGrid"
                            textBody:@"The Mailjet and Sendgrid is on cloudrail now!!!"
                            htmlBody:@""
                         ccAddresses:[@[]mutableCopy] bccAddresses:[@[] mutableCopy]];
````

---

### SMS Interface:

* Twilio
* Nexmo

#### Features

* Send SMS

[Full Documentation](https://docs.cloudrail.com/docs/sms)
#### Code Sample

````objective-c
  self.service = [[Nexmo alloc] initWithClientId:key clientSecret:secret];
  self.service = [[Twilio alloc] initWithAccountSid:key authToken:secret];

  [self.service sendSmsFromName:@"from Code" toNumber:@"+12323423423" content:@"Testing message"];
````

---

### Points of Interest Interface:

* Google Places
* Foursquare
* Yelp

#### Features

* Get a list of POIs nearby
* Filter by categories or search term

[Full Documentation](https://docs.cloudrail.com/docs/points-of-interest)
#### Code Example

```` objective-c
//  self.service = [[Yelp alloc] initWithConsumerKey:@"key" consumerSecret:@"secret" token:@"token"  tokenSecret:@"tokensecret"];
//  self.service = [[GooglePlaces alloc] initWithApiKey:@"apiKey"];
  self.service = [[Foursquare alloc] initWithClientId:key clientSecret:secret];
  NSMutableArray<POI*>* pois =  [self.service nearbyPoisWithLatitude:@49.483927 longitude:@8.473272 radius:@300 searchTerm:[NSNull null] categories:[NSNull null]];
  
  NSLog(@"%@", pois);
````

---


More interfaces are coming soon.

## Advantages of Using CloudRail

* Consistent Interfaces: As functions work the same across all services, you can perform tasks between services simply.

* Easy Authentication: CloudRail includes easy ways to authenticate, to remove one of the biggest hassles of coding for external APIs.

* Switch services instantly: One line of code is needed to set up the service you are using. Changing which service is as simple as changing the name to the one you wish to use.

* Simple Documentation: There is no searching around Stack Overflow for the answer. The CloudRail documentation at https://docs.cloudrail.com/ is regularly updated, clean, and simple to use.

* No Maintenance Times: The CloudRail Libraries are updated when a provider changes their API.

* Direct Data: Everything happens directly in the Library. No data ever passes a CloudRail server.

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
3. Xcode will generate and configure the file for you, on the file you have to import ( in a Objective-C way) with `#import <CloudRail_ServiceCode/CloudRail_ServiceCode.h>`.
3. Make an AWESOME APP!!!

### Objective-C

Simply drag an drop the Framework file to the __"Embedded Binaries"__ of the iOS project, check __"copy files"__ if needed. Import the framework on the desired class with `#import <CloudRail_ServiceCode/CloudRail_ServiceCode.h>`, and have fun!

## Other Code Samples
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

self.googleDrive = [[GoogleDrive alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret"];


}

-(void)downloadAndUpload{

//Download File from Dropbox
NSInputStream * streamToDownloadedFile = [self.dropbox downloadWithPath:@"/mudkip.jpg"];

//Upload the downloaded file to Googledrive
[self.googleDrive uploadWithPath:@"/mudkip.jpg" inputStream:streamToDownloadedFile size:size];

}

@end
````

## Get Updates

To keep updated with CloudRail, including any new providers that are added, just add your email address to https://cloudrail.com/updates/.

## Pricing

CloudRail is **free to use**. For all projects; **commercial and non-commercial**. We want APIs to be accessible to all developers. We want APIs to be easier to manage. This is only possible if there are free, powerful tools out there to do this. The only favor we are asking for, is to spread the word about this library. Thank you!

CloudRail also has enterprise licensing options. Please contact us for more information: support@cloudrail.com

## Other Platforms

CloudRail is also available for other platforms like Java and Android. You can find all libraries on https://cloudrail.github.io

## Questions?

Get in touch at any time by emailing us: support@cloudrail.com

or

Tag a question with cloudrail on [StackOverflow](http://stackoverflow.com/questions/tagged/cloudrail)
