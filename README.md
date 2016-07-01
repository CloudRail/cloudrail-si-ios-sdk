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
//   self.service = [[CROneDrive alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret" redirectUri:@"REDIRURL" state:@"CRSTATE"];
//   self.service = [[CRGoogleDrive alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret" redirectUri:@"REDIRURL" state:@"CRSTATE"];
//   self.service = [[CRBox alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret" redirectUri:@"REDIRURL" state:@"CRSTATE"];

self.service = [[CRDropbox alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret" redirectUri:@"REDIRURL" state:@"CRSTATE"];
NSInputStream * object = [self.dropbox downloadFileWithPath:@"/mudkip.jpg"];

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
//  self.service = [[CRGitHub alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret" redirectUri:@"REDIRURL" state:@"CRSTATE"];
//  self.service = [[CRInstagram alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret" redirectUri:@"REDIRURL" state:@"CRSTATE"];
//  self.service = [[CRSlack alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret" redirectUri:@"REDIRURL" state:@"CRSTATE"];
//  self.service = [[CRGooglePlus alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret" redirectUri:@"REDIRURL" state:@"CRSTATE"];

self.service = [[CRFacebook alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret" redirectUri:@"REDIRURL" state:@"CRSTATE"];

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
//  self.service = [[CRPayPal alloc] initWithUseSandbox:YES clientId:key clientSecret:secret];
self.service = [[CRStripe alloc] initWithSecretKey:key];

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
//  self.service = [[CRMailJet alloc] initWithClientId:key clientSecret:secret];
self.service = [[CRSendGrid alloc]initWithUsername:key password:secret];

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
self.service = [[CRNexmo alloc] initWithClientId:key clientSecret:secret];
self.service = [[CRTwilio alloc] initWithAccountSid:key authToken:secret];

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
//  self.service = [[CRYelp alloc] initWithConsumerKey:@"key" consumerSecret:@"secret" token:@"token"  tokenSecret:@"tokensecret"];
//  self.service = [[CRGooglePlaces alloc] initWithApiKey:@"apiKey"];
self.service = [[CRFoursquare alloc] initWithClientId:key clientSecret:secret];
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
3. Xcode will generate and configure the file for you, on the file you have to import ( in a Objective-C way) with `#import <CloudRailSI/CloudRailSI.h>`.
3. Make an AWESOME APP!!!

### Objective-C

Simply drag an drop the Framework file to the __"Embedded Binaries"__ of the iOS project, check __"copy files"__ if needed. Import the framework on the desired class with `#import <CloudRailSI/CloudRailSI.h>`, and have fun!

## Other Code Samples
### Swift

```` swift
override func viewDidAppear(animated: Bool) {
let dropbox: CRDropbox = CRDropbox.init(clientId: "DROPBOX_ID", clientSecret: "DROPBOX_SECRET", redirectUri:"https://www.cloudrailauth.com/auth", state:"CRSTATE")
let inputstream =  dropbox.downloadFileWithPath("/futurama.jpg")
//READ FROM THE INPUT STREAM 
}
````

### Objective C
```` objective-c
#import <CloudRailSI/CloudRailSI.h>

@interface CRViewController ()
@property (nonatomic) CRDropbox * dropbox;
@property (nonatomic) CRGoogleDrive * googleDrive;
//@property (nonatomic) CROneDrive * oneDrive;
//@property (nonatomic) CRBox * box;
@end

@implementation CRViewController

- (void)viewDidLoad
{
[super viewDidLoad];
self.dropbox = [[CRDropbox alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret" redirectUri:@"https://www.cloudrailauth.com/auth" //example state:@"CRSTATE"];

self.googleDrive = [[CRGoogleDrive alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret" redirectUri:@"https://www.cloudrailauth.com/auth" //example state:@"CRSTATE"];


}

-(void)downloadAndUpload{

//Download File from Dropbox
NSInputStream * streamToDownloadedFile = [self.dropbox downloadFileWithPath:@"/mudkip.jpg"];

//Upload the downloaded file to Googledrive
[self.googleDrive uploadFileToPath:@"/mudkip.jpg" withStream:streamToDownloadedFile size:size overwrite:YES];
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