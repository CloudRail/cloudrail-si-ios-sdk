<p align="center">
<img width="200px" src="http://cloudrail.github.io/img/cloudrail_logo_github.png"/>
</p>

# CloudRail SI for iOS

Integrate Multiple Services With Just One API

<p align="center">
<img width="300px" src="http://cloudrail.github.io/img/cloudrail_si_github.png"/>
</p>

CloudRail is an API integration solution which abstracts multiple APIs from different providers into a single and universal interface.

**Current Interfaces:**
<p align="center">
<img width="800px" src="http://cloudrail.github.io/img/available_interfaces_v3.png"/>
</p>
---
---

[![CocoaPods](https://img.shields.io/cocoapods/v/cloudrail-si-ios-sdk.svg)]()
[![CocoaPods](https://img.shields.io/cocoapods/p/cloudrail-si-ios-sdk.svg)]()
<!--[![CocoaPods](https://img.shields.io/cocoapods/l/cloudrail-si-ios-sdk.svg?maxAge=2592000)]()-->
<!--[![CocoaPods](https://img.shields.io/cocoapods/metrics/doc-percent/cloudrail-si-ios-sdk.svg?maxAge=2592000)]()-->
<!--[![CocoaPods](https://img.shields.io/cocoapods/aw/cloudrail-si-ios-sdk.svg?maxAge=2592000)]()-->
<!--[![CocoaPods](https://img.shields.io/cocoapods/at/cloudrail-si-ios-sdk.svg?maxAge=2592000)]()-->
<!--asdas-->
<!--[![CocoaPods](https://img.shields.io/cocoapods/dw/cloudrail-si-ios-sdk.svg?maxAge=2592000)]()-->
<!--[![CocoaPods](https://img.shields.io/cocoapods/dm/cloudrail-si-ios-sdk.svg?maxAge=2592000)]()-->
<!--[![CocoaPods](https://img.shields.io/cocoapods/dt/cloudrail-si-ios-sdk.svg?maxAge=2592000)]()-->

Full documentation can be found at our [website](https://cloudrail.com/integrations).

Learn more about CloudRail on https://cloudrail.com

---
---

With CloudRail, you can easily integrate external APIs into your application. 
CloudRail provides abstracted interfaces that take several services and then exposes a developer-friendly API that uses common functions between all providers. 
This means that, for example, upload() works in exactly the same way for Dropbox as it does for Google Drive, OneDrive, and other Cloud Storage Services, and getEmail() works similarly the same way across all social networks.

## CocoaPods
Add the pod to your podfile
```
pod 'cloudrail-si-ios-sdk'
```
run
```
pod install
```

## Basic setup
In the Project Navigator, open the source file of your application delegate. Add the import statement at the top of the file, then add the following call to CloudRail in the didFinishLaunching or didFinishLaunchingWithOptions method of your app delegate:
#### Objective-C
```objective-c
#import <CloudRailSI/CloudRailSI.h>

[CRCloudRail setAppKey:@"{Your_License_Key}"];

```

#### Swift
```swift
import CloudrailSI

CRCloudRail.setAppKey("{Your_License_Key}")

```
---


## Current Interfaces:
Interface | Included Services
--- | ---
Cloud Storage | Dropbox, Google Drive, OneDrive, Box, PCloud, Egnyte, OneDrive Business
Business Cloud Storage | Amazon S3, Microsoft Azure, Rackspace, Backblaze
Social Profiles | Facebook, GitHub, Google+, LinkedIn, Slack, Twitter, Windows Live, Yahoo, Instagram, Heroku
Social Interaction | Facebook, Twitter
Payment | PayPal, Stripe
Email | Maljet, Sendgrid, Gmail
SMS | Twilio, Nexmo
Point of Interest | Google Places, Foursquare, Yelp
Video | Youtube, Twitch, Vimeo
Messaging | Facebook Messenger, Telegram, Line, Viber

---
### Cloud Storage Interface:

* Dropbox
* Box
* Google Drive
* Microsoft OneDrive
* PCloud
* Egnyte
* OneDrive Business

#### Features:

* Download files from Cloud Storage.
* Upload files to Cloud Storage.
* Get Meta Data of files, folders and perform all standard operations (copy, move, etc) with them.
* Retrieve user and quota information.
* Generate share links for files and folders.

#### Code Sample - Objective-C
[Full Documentation](https://cloudrail.com/integrations/interfaces/CloudStorage;platformId=ObjectiveC)
```objective-c
id<CRCloudStorageProtocol> service;

//   service = [[CROneDrive alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret" redirectUri:@"REDIRURL" state:@"CRSTATE"];
//   service = [[CRGoogleDrive alloc] initWithClientId:@"clientIdentifier" clientSecret:@"" redirectUri:@"REDIRURL" state:@"CRSTATE"];
//   service = [[CRBox alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret" redirectUri:@"REDIRURL" state:@"CRSTATE"];
//   service = [[CRPCloud alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret" redirectUri:@"REDIRURL" state:@"CRSTATE"];

service = [[CRDropbox alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret" redirectUri:@"REDIRURL" state:@"CRSTATE"];
NSInputStream * object = [service downloadFileWithPath:@"/mudkip.jpg"];
//READ FROM STREAM
```
#### Code Sample - Swift
[Full Documentation](https://cloudrail.com/integrations/interfaces/CloudStorage;platformId=Swift)
```swift
//let cloudStorage : CloudStorageProtocol = Box.init(clientId: "ClientID", clientSecret: "ClientSecret")
//let cloudStorage : CloudStorageProtocol = GoogleDrive.init(clientId: "ClientID", clientSecret: "", redirectUri: "[redirectUri]", state: "[state]")
//let cloudStorage : CloudStorageProtocol = OneDrive.init(clientId: "ClientID", clientSecret: "ClientSecret")
//let cloudStorage : CloudStorageProtocol = PCloud.init(clientId: "ClientID", clientSecret: "ClientSecret")

let cloudStorage : CloudStorageProtocol = Dropbox.init(clientId: "ClientID", clientSecret: "ClientSecret")
do {
  let inputStream = try cloudStorage.downloadFileWithPath("/TestFolder/Data.csv")
} catch let error{
  print("An error: \(error)")
}
//READ FROM STREAM
```
---
### Business/Bucket Cloud Storage Interface:

* Amazon Web Services S3
* Microsoft Azure
* Rackspace
* Backblaze

#### Features

* Create, delete and list buckets
* Upload files
* Download files
* List files in a bucket and delete files
* Get file metadata (last modified, size, etc.)


#### Code Sample - Objective-C
[Full Documentation](https://cloudrail.com/integrations/interfaces/BusinessCloudStorage;platformId=ObjectiveC)

```objective-c
id<CRBusinessCloudStorageProtocol> service;

// service = [[CRMicrosoftAzure alloc] initWithAccountName:@"[account_name]" accessKey:@"[access_key]"];
// service = [[CRAmazonS3 alloc] initWithAccessKeyId:@"[clientID]" secretAccessKey:@"[client_Secret]" region:@"[region]"];
// service = [[CRRackspace alloc] initWithUsername:@"[username]" apiKey:@"[api_key]" region:@"[region]"];

service = [[CRBackblaze alloc] initWithAccountID:@"[account_init]" appKey:@"[app_key]"];

CRBucket * bucket = [[CRBucket alloc] init];
bucket.name = @"[bucket_name]";
bucket.identifier = @"[bucket_id]";

NSData * data = //data source;
NSInputStream * inputStream = [NSInputStream inputStreamWithData:data];
@try {
  [service uploadFileToBucket:bucket name:@"[file_name]" withStream:inputStream size:data.length];
} @catch (NSException *exception) {
  //handle exception
}
```
#### Code Sample - Swift
[Full Documentation](https://cloudrail.com/integrations/interfaces/BusinessCloudStorage;platformId=Swift)
```swift
//let cloudStorage : BusinessCloudStorageProtocol = Backblaze.init(accountID: "[account_id]", appKey: "[app_key]")
//let cloudStorage : BusinessCloudStorageProtocol = Rackspace.init(username: "[username]", apiKey: "[api_key]", region: "[region]")
//let cloudStorage : BusinessCloudStorageProtocol = MicrosoftAzure.init(accountName: "[account_name]", accessKey: "access_key")
let cloudStorage : BusinessCloudStorageProtocol = AmazonS3.init(accessKeyId: "[access_key]", secretAccessKey: "[secret_key]", region: "[region]")

let bucket : CRBucket = CRBucket.init()
bucket.name = "[bucketName]";
bucket.identifier = "[identifier]"

let path = Bundle.main.path(forResource: "UserData", ofType: "csv")!
let fileAttributes = try! FileManager.default.attributesOfItem(atPath: path)
let fileSize: UInt64 = fileAttributes[FileAttributeKey.size] as! UInt64
let stream = InputStream.init(fileAtPath: path)!

do {
  try cloudStorage.uploadFileToBucket(bucket, name: "[fileName]", stream: stream, size:fileSize)
} catch let error{
  print("An error: \(error)")
}
```
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
* Heroku

#### Features

* Get profile information, including full names, emails, genders, date of birth, and locales.
* Retrieve profile pictures.
* Login using the Social Network.

#### Code Sample - Objective-C
[Full Documentation](https://cloudrail.com/integrations/interfaces/Profile;platformId=ObjectiveC)

```objective-c
id<CRProfileProtocol> service;

//  service = [[CRGitHub alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret" redirectUri:@"REDIRURL" state:@"CRSTATE"];
//  service = [[CRInstagram alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret" redirectUri:@"REDIRURL" state:@"CRSTATE"];
//  service = [[CRSlack alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret" redirectUri:@"REDIRURL" state:@"CRSTATE"];
//  service = [[CRGooglePlus alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret" redirectUri:@"REDIRURL" state:@"CRSTATE"];

service = [[CRFacebook alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret" redirectUri:@"REDIRURL" state:@"CRSTATE"];

NSString * fullName = [service fullName];
```

#### Code Sample - Swift
[Full Documentation](https://cloudrail.com/integrations/interfaces/Profile;platformId=Swift)
```swift
// let profile = GitHub(clientID: "[clientID]", clientSecret: "[clientSecret]")
// let profile = GooglePlus(clientID: "[clientID]", clientSecret: "[clientSecret]")
// let profile = Instagram(clientID: "[clientID]", clientSecret: "[clientSecret]")
// let profile = Slack(clientID: "[clientID]", clientSecret: "[clientSecret]")

let profile = Facebook(clientID: "[clientID]", clientSecret: "[clientSecret]")
do {
  let fullName = try profile.fullName()
} catch let error{
  print("An error: \(error)")
}
```

---

### Social Media Interaction Interface:

* Facebook
* Twitter

#### Features

* Get a list of connections.
* Make a post for the user.


#### Code Sample - Objective-C
[Full Documentation](https://cloudrail.com/integrations/interfaces/Social;platformId=ObjectiveC)

```objective-c
id<CRSocialProtocol> service;

// service = [[CRTwitter alloc] initWithClientIdentifier:@"clientIdentifier" clientSecret:@"clientSecret" redirectUri:@"REDIRURL"];

service = [[CRFacebook alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret" redirectUri:@"REDIRURL" state:@"CRSTATE"];
[service postUpdateWithContent:@"Using Cloudrail sdk!"];
```
#### Code Sample - Swift
[Full Documentation](https://cloudrail.com/integrations/interfaces/Social;platformId=Swift)

```swift
// let social = Twitter(clientID: "[clientID]", clientSecret: "[clientSecret]")

let social = Facebook(clientID: "[clientID]", clientSecret: "[clientSecret]")
do {
  try social.postUpdateWithContent("CloudRail is awesome!!!")
} catch let error{
  print("An error: \(error)")
}
```
---

### Payment Interface:

* PayPal
* Stripe

#### Features Interface

* Perform charges
* Refund previously made charges
* Manage subscriptions

#### Code Sample - Objective-C
[Full Documentation](https://cloudrail.com/integrations/interfaces/Payment;platformId=ObjectiveC)

```objective-c
id<CRPaymentProtocol> service;

//  service = [[CRPayPal alloc] initWithUseSandbox:YES clientId:@"key" clientSecret:@"secret"];

service = [[CRStripe alloc] initWithSecretKey:@"key"];

SubscriptionPlan * subPlan = [service createSubscriptionPlanWithName:@"Plan name" amount:@2000 currency:@"USD" description:@"description" Longerval:@"day" Longerval_count:@7];

NSLog(@"Sub plan %@", subPlan);
```

#### Code Sample - Swift
[Full Documentation](https://cloudrail.com/integrations/interfaces/Payment;platformId=Swift)

```swift

let payment = PayPal(useSandbox: [true/false], clientId: "[clientID]")
do {
  let subscriptionPlan : CRSubscriptionPlan = try payment.createSubscriptionPlanWithName("My subscription", amount: 500, currency: "USD", description: "myDescription", interval: "week", intervalCount: 2)
} catch let error{
  print("An error: \(error)")
}

```
---

### Email Interface:

* Mailjet
* Sendgrid
* Gmail

#### Features

* Send Email

#### Code Sample - Objective-C
[Full Documentation](https://cloudrail.com/integrations/interfaces/Email;platformId=ObjectiveC)

```objective-c
id<CREmailProtocol> service;

//  service = [[CRMailJet alloc] initWithClientId:@"key" clientSecret:@"secret"];
// service = [[CRGMail alloc] initWithClientID:@"[GMail Client Identifier]" clientSecret:@"" redirectUri:@"com.cloudrail.example:/auth" state:@"someState"];
//[service useAdvancedAuthentication]; //required for Gmail

service = [[CRSendGrid alloc]initWithUsername:@"key" password:@"secret"];

CRAttachment *attachImage = [[CRAttachment alloc] initWithContent:NSInputStream type:"image/jpg" name:"fileName"];
NSMutableArray *attachments = [[NSMutableArray alloc] init];
[attachments addObject:attachImage];

[service sendEmailFromAddress:@"cloudrail@cloudrail.com" fromName:@"Bob" toAddresses:[@[@"foo@gmail.com",@"bar@gmail.com"] mutableCopy] subject:@"Mailjet and SendGrid" textBody:@"The Mailjet and Sendgrid is on cloudrail now!!!" htmlBody:@"" ccAddresses:[@[]mutableCopy] bccAddresses:[@[] mutableCopy], attachments:attachments];
```
#### Code Sample - Swift
[Full Documentation](https://cloudrail.com/integrations/interfaces/Email;platformId=Swift)

```swift

var service: EmailProtocol;

// service = SendGrid(apiKey: "[SendGrid API Key]")
// service = GMail(clientID: "[GMail Client Identifier]",clientSecret: "",redirectUri: "com.cloudrail.example:/auth",state: "someState")
// service.useAdvancedAuthentication() //required for Gmail

service = MailJet(clientID: "[clientID]", clientSecret:"[accountSid]")

let attachImage = CRAttachment()
attachImage.content = InputStream
attachImage.mimeType = "image/jpg"
attachImage.filename = "File.jpg"

var attachments = [CRAttachment]()
attachments.append(attachImage)


do {
  try service.sendEmailFromAddress("info@cloudrail.com", fromName: "CloudRail", toAddresses:NSMutableArray(array:  ["foo@bar.com","bar@foo.com"]), subject: "my subject", textBody: "text body", htmlBody: "Html body", ccAddresses: NSMutableArray(array:  ["foo@bar.com","bar@foo.com"]), bccAddresses: NSMutableArray(array:  ["foo@bar.com","bar@foo.com"])  attachments: attachments)
} catch let error{
  print("An error: \(error)")
}
```
---

### SMS Interface:

* Twilio
* Nexmo
* Twizo

#### Features

* Send SMS

#### Code Sample - Objective-C
[Full Documentation](https://cloudrail.com/integrations/interfaces/SMS;platformId=ObjectiveC)

```objective-c
id<CRSMSProtocol> service;

//service = [[CRNexmo alloc] initWithClientId:@"key" clientSecret:@"secret"];
service = [[CRTwilio alloc] initWithAccountSid:@"key" authToken:@"secret"];

[service sendSmsFromName:@"from Code" toNumber:@"+12323423423" content:@"Testing message"];
```
#### Code Sample - Swift
[Full Documentation](https://cloudrail.com/integrations/interfaces/SMS;platformId=Swift)

```swift
// let sms = Nexmo(accountSid: "[clientID]", authToken: "[authToken]")

let sms = Twilio(accountSid: "[clientID]", authToken: "[authToken]")
do {
  try sms.sendSmsFromName("CloudRail", toNumber: "+491234567890", content: "Hello from CloudRail")
} catch let error{
  print("An error: \(error)")
}
```

---

### Points of Interest Interface:

* Google Places
* Foursquare
* Yelp

#### Features

* Get a list of POIs nearby
* Filter by categories or search term

#### Code Example - Objective-C
[Full Documentation](https://cloudrail.com/integrations/interfaces/PointsOfInterest;platformId=ObjectiveC)

```objective-c
id<CRPointsOfInterestProtocol> service;

//  service = [[CRYelp alloc] initWithConsumerKey:@"key" consumerSecret:@"secret" token:@"token"  tokenSecret:@"tokensecret"];
//  service = [[CRGooglePlaces alloc] initWithApiKey:@"apiKey"];

service = [[CRFoursquare alloc] initWithClientId:key clientSecret:secret];
NSMutableArray<POI*>* pois =  [service nearbyPoisWithLatitude:@49.483927 longitude:@8.473272 radius:@300 searchTerm:[NSNull null] categories:[NSNull null]];

NSLog(@"%@", pois);
```
#### Code Example - Swift
[Full Documentation](https://cloudrail.com/integrations/interfaces/PointsOfInterest;platformId=Swift)

```swift
// let points = GooglePlaces(apiKey: "[secretKey]")

let points = Foursquare(clientID: "[cientID]", clientSecret: "[clientSecret]")
do {
  //Mannheim : 49.483927, 8.473272
  var points = try places.nearbyPoisWithLatitude(49.483927, longitude: 8.473272, radius: 3000, searchTerm: "Restaurant", categories: [])
} catch let error{
  print("An error: \(error)")
}
```
---

### Video Interface:

* Youtube
* Twitch
* Vimeo

#### Features

* Search for videos
* Upload videos
* Get a list of videos for a channel
* Get channel details
* Get your own channel details
* Get video details 

#### Code Example - Objective-C
[Full Documentation](https://cloudrail.com/integrations/interfaces/Video;platformId=ObjectiveC)

```objective-c
id<CRVideoProtocol> service;

//  service = [[CRTwitch alloc] initWithClientId:@"[Twitch Client Identifier]" clientSecret:@"[Twitch Client Secret]"];
//  service = [[CRVimeo alloc] initWithClientId:@"[Vimeo Client Identifier]" clientSecret:@"[Vimeo Client Secret]"];

service = [[CRYouTube alloc] initWithClientId:@"[YouTube Client Identifier]" clientSecret:@"" redirectUri:@"com.cloudrail.example:/auth" state:@"someState"];
[service useAdvancedAuthentication]; //required for Youtube


NSMutableArray<CRVideoMetaData *> * searchResult = [service searchVideosWithQueryQuery:@"CloudRail" offset:[NSNumber numberWithInt: 0] limit:[NSNumber numberWithInt: 12]];

NSLog(@"%@", searchResult);

CRVideoMetaData * uploadResult = [service uploadVideoWithTitleTitle:@"HowTo: Setup CloudRail" 
        description:@"Video about Setting up CloudRail" 
        stream:NSInputStream 
        size:[NSNumber numberWithInt: 1448576] 
        channelId:@"70207321" 
        mimeType:@"video/mp4"
]; //ChannelId optional for youtube

NSLog(@"%@", uploadResult);


```
#### Code Example - Swift
[Full Documentation](https://cloudrail.com/integrations/interfaces/Video;platformId=Swift)

```swift
var service: VideoProtocol

// service = Twitch(clientId: "[Twitch Client Identifier]",clientSecret: "[Twitch Client Secret]")
// service = Vimeo(clientId: "[Vimeo Client Identifier]",clientSecret: "[Vimeo Client Secret]")

service = YouTube(clientId: "[YouTube Client Identifier]",clientSecret: "",redirectUri: "com.cloudrail.example:/auth",state: "someState")
service.useAdvancedAuthentication(); //required for Youtube

do {
   
   let searchResult = service.searchVideos(query: "CloudRail",offset: 0,limit: 12)
   print(searchResult)
   
   let uploadResult = service.uploadVideo(title: "HowTo: Setup CloudRail", description: "Video about Setting up CloudRail", stream: InputStream, size: 1448576, channelId: "70207321", mimeType: "video/mp4") //Channel id optional for youtube
   
   print(uploadResult)
   
} catch let error{
  print("An error: \(error)")
}
```
---
### Messaging Interface:

* FacebookMessenger
* Telegram
* Line
* Viber

#### Features

* Send text messages
* Send files, images, videos and audios
* Parse a message received on your webhook
* Download the content of an attachment sent to your webhook

#### Code Example - Objective-C
[Full Documentation](https://cloudrail.com/integrations/interfaces/Messaging;platformId=ObjectiveC)

```objective-c
id<CRMessagingProtocol> service;

//  service = [[CRViber alloc] initWithBotToken:@"[Bot Token]" webhook:@"[Webhook URL]" botName:@"[Bot Name]"];
//  service = [[CRTelegram alloc] initWithBotToken:@"[Bot Token]" webhook:@"[Webhook URL]"];
//  service = [[CRLine alloc] initWithBotToken:@"[Bot Token]"];

service =  [[CRFacebookMessenger alloc] initWithBotToken:@"[Bot Token]"];

CRMessage * result = [service sendMessageWithReceiverIdReceiverId:@"12123242" 
        message:@"It's so easy to send message via CloudRail"
];

NSLog(@"%@", result);

```
#### Code Example - Swift
[Full Documentation](https://cloudrail.com/integrations/interfaces/Messaging;platformId=Swift)

```swift
var service: MessagingProtocol

// service = Viber(botToken: "[Bot Token]",webhook: "[Webhook URL]",botName: "[Bot Name]")
// service = Telegram(botToken: "[Bot Token]",webhook: "[Webhook URL]")
// service = Line(botToken: "[Bot Token]")

service = FacebookMessenger(botToken: "[Bot Token]")

do {
   
   var result = service.sendMessageWithReceiverId(
    receiverId: "12123242",
    message: "It's so easy to send message via CloudRail")
   
   print(result)
   
} catch let error{
  print("An error: \(error)")
}
```


---

More interfaces are coming soon.

## Advantages of Using CloudRail

* Consistent Interfaces: As functions work the same across all services, you can perform tasks between services simply.

* Easy Authentication: CloudRail includes easy ways to authenticate, to remove one of the biggest hassles of coding for external APIs.

* Switch services instantly: One line of code is needed to set up the service you are using. Changing which service is as simple as changing the name to the one you wish to use.

* Simple Documentation: There is no searching around Stack Overflow for the answer. The CloudRail documentation at https://cloudrail.com/integrations is regularly updated, clean, and simple to use.

* No Maintenance Times: The CloudRail Libraries are updated when a provider changes their API.

* Direct Data: Everything happens directly in the Library. No data ever passes a CloudRail server.

## Integrate With Cocoapods (Swift & Objective-C)

CloudRail-SI-iOS is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile (remember to put the `use_frameworks!` flag on top of the `Podfile`):
```ruby
pod "cloudrail-si-ios-sdk"
```
Run `Pod install` again.
### Swift

* Import the module with `import CloudrailSI` on swift files (Classes, Protocols. etc...).


### Objective-C

* Import the framework on the desired class with `#import <CloudRailSI/CloudRailSI.h>`.

## Integrate Into Projects Without Cocoapods

### Swift (use Swift interface)

1. Drag an drop the Framework file to the __"Embedded Binaries"__ of the iOS project, check __"copy files"__ if needed.
2. You can import the module with `import CloudrailSI` on swift files (Classes, Protocols. etc...).


### Swift (use ObjC interface)

1. add a new __Objective-C__ File (any file will do) to your project and Xcode will prompt if you want to configure your project with a bridging header (`PROJECTNAME-Bridging-Header.h`), press __YES__ on the prompt. (In case you can not add a bridging header use [this](http://www.learnswiftonline.com/getting-started/adding-swift-bridging-header/) guide)
2. Drag an drop the Framework file to the __"Embedded Binaries"__ of the iOS project, check __"copy files"__ if needed.
3. Xcode will generate and configure the file for you, on the file you have to import ( in a Objective-C way) with `#import <CloudRailSI/CloudRailSI.h>`.

### Objective-C

Simply drag an drop the Framework file to the __"Embedded Binaries"__ of the iOS project, check __"copy files"__ if needed. Import the framework on the desired class with `#import <CloudRailSI/CloudRailSI.h>`, and have fun!

# Start implementing

Now that you are all set up, you can learn how to use CloudRail by heading over to [[Usage]] or [[Usage-(Swift)]]
## Other Code Samples
### Swift

```swift
//let cloudStorage : CloudStorageProtocol = Box.init(clientId: "ClientID", clientSecret: "ClientSecret")
//let cloudStorage : CloudStorageProtocol = GoogleDrive.init(clientId: "ClientID", clientSecret: "ClientSecret")
//let cloudStorage : CloudStorageProtocol = OneDrive.init(clientId: "ClientID", clientSecret: "ClientSecret")
let cloudStorage : CloudStorageProtocol = Dropbox.init(clientId: "ClientID", clientSecret: "ClientSecret")
CRCloudRail.setAppKey("CLOUDRAIL_API_KEY")

do {
  let inputStream = try cloudStorage.downloadFileWithPath("/TestFolder/Data.csv")
} catch let error{
  print("An error: \(error)")
}
```

### Objective C
```objective-c
#import <CloudRailSI/CloudRailSI.h>

@interface CRViewController ()
@property (strong, nonatomic) CRDropbox * dropbox;
@property (strong, nonatomic) CRGoogleDrive * googleDrive;
//@property (strong, nonatomic) CROneDrive * oneDrive;
//@property (strong, nonatomic) CRBox * box;
@end

@implementation CRViewController

- (void)viewDidLoad {
[super viewDidLoad];
[CRCloudRail setAppKey:@"CLOUDRAIL_API_KEY"];

self.dropbox = [[CRDropbox alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret"];

self.googleDrive = [[CRGoogleDrive alloc] initWithClientId:@"clientIdentifier" clientSecret:@"clientSecret"  redirectUri:@"https://www.cloudrailauth.com/auth" state:@"CRSTATE"];
[self.googleDrive useAdvancedAuthentication]; //Required for Google Login

}

- (void)downloadAndUpload {

  //Download File from Dropbox
  NSInputStream * streamToDownloadedFile = [self.dropbox downloadFileWithPath:@"/mudkip.jpg"];

  //Upload the downloaded file to Googledrive
  [self.googleDrive uploadFileToPath:@"/mudkip.jpg" withStream:streamToDownloadedFile size:size overwrite:YES];
}

@end
```

## License Key

CloudRail provides a developer portal which offers usage insights for the SDKs and allows you to generate license keys.

It's free to sign up and generate a key.

Head over to https://cloudrail.com/signup

## Pricing

Learn more about our pricing on https://cloudrail.com/pricing 

## Other Platforms

CloudRail is also available for other platforms like Node.js, Java and Android. You can find all libraries on https://cloudrail.com

## Questions?

Get in touch at any time by emailing us: support@cloudrail.com

or

Tag a question with cloudrail on [StackOverflow](http://stackoverflow.com/questions/tagged/cloudrail)
