# Change Log

## [5.9.3](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.9.3) (2017-10-17)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/5.9.2...5.9.3)

* Added New Messaging Interfaces (Facebook / Viber)
* Fixed Amazon S3 pagination issue
* Fixed for CloudStorage (OneDrive, Google Drive, Box and Dropbox)
* Fixed OneDrive Business

## [5.9.2](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.9.2) (2017-10-09)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/5.9.1...5.9.2)

* Updated Messaging Interface
* Fixed timestamp issue
* Fixed missing constructor for OneDrive / Gmail

## [5.9.1](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.9.1) (2017-10-02)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/5.9.0...5.9.1)

* Hotfix fixed major bug causing the interface to crash

## [5.9.0](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.9.0) (2017-09-29)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/5.8.4...5.9.0)

* Added Messaging Interface

## [5.8.4](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.8.4) (2017-09-12)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/5.8.3...5.8.4)

* Hotfix Added missing OneDrive Construtor

## [5.8.3](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.8.3) (2017-09-08)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/5.8.2...5.8.3)

* Fix Vimeo fixed the offset / limit logic
* Fix Gmail attachment crash fixed

## [5.8.2](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.8.2) (2017-09-04)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/5.8.0...5.8.2)

* Hotfix Added missing constuctor for Twitch and Vimeo
* Hotfix Search and List Videos by channel for Twitch and Vimeo

## [5.8.1](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.8.1) (2017-09-01)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/5.8.0...5.8.1)

* Hotfix: Added missing Gmail interface

## [5.8.0](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.8.1) (2017-08-31)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/5.7.0...5.8.0)

* Added new Video Interface (CRVideoProtocol) **Youtube** , **Twitch** and **Vimeo**


## [5.5.1](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.5.1) (2017-05-28)
+[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/5.5.0...5.5.1)
+
+* Fix for swift 3.1 modules.

## [5.5.0](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.5.0) (2016-11-25)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/5.4.4...5.5.0)

* Fix getChildrenPage method in all services of the CloudStorage interface
* Repair OneDrive after a sudden change in the OneDrive API that happened without any prior notice
* Hotfix for GoogleDrive download method
* Enable downloading Google Documents as PDFs through the download method of Google Drive
* Fix an issue with Facebook: Logout method now correctly performs the logout
* Enable developers to specify the scopes they want to acquire for the different services using OAuth
* Advanced request functionality for all of the services
* Hotfix: Using the advanced authentication on multiple services caused an issue

## [5.4.2](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.4.2) (2016-11-25)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/5.4.1...5.4.2)

* Introduce the external authentication which uses the standard web browser instead of a WebView. This is optional for the most services except from GoogleDrive and GooglePlus as of now. Developers using those services need to upgrade until 20. April 2017

## [5.4.1](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.4.1) (2016-11-25)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/5.4.0...5.4.1)

* Bugfix in Mailjet which caused the SDK to crash

## [5.4.0](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.4.0) (2016-11-25)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/5.3.0...5.4.0)

* Advanced Request now available for the services implementing the Profile interface

## [5.3.0](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.3.0) (2016-11-25)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/5.2.1...5.3.0)

* Added a new function to make supported raw HTTP requests to the services implementing Cloud Storage (advanced request)
* Added functions to post pictures and videos to a user's wall to the Social interface, Facebook and Twitter have been extended accordingly
* Added FacebookPage as a new service to the Social interface. It allows posting updates/pictures/videos to a Facebook page
* Google Cloud Platform added as a new integration in the Business Cloud Storage interface

## [5.2.1](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.2.1) (2016-11-25)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/5.2.0...5.2.1)

* Fix for modified date returned by Box
* Fix for shared links in Dropbox
* Fix for special characters within the path

## [5.2.0](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.2.0) (2016-11-25)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/5.1.4...5.2.0)

* Added OneDrive for Business as a new service to the Cloud Storage interface
* Fixed an issue where Box and GoogleDrive would return maximally 100 children of a folder
* Added a function to retrieve children in chunks to all Cloud Storage services
* Updated Google Drive from API version 2 to 3
* Heroku has been added as a new service implementing Profile. It supports the retrieval of a unique ID, the full name and the email address. It is still in Beta and not officially listed or documented

## [5.1.4](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.1.4) (2016-11-11)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/5.1.3...5.1.4)

* Fix for Google services authentication

## [5.1.3](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.1.3) (2016-11-11)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/5.1.2...5.1.3)

* Fixed Bug of AmazonS3 instability when performing multiple operations
* Updated documentation for BusinessCloudStorage (BCS)
* Fixed method names (BCS) to conform with Apple style guide

## [5.1.2](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.1.2) (2016-11-9)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/5.0.2...5.1.2)
* Added new interface - CRBusinessCloudStorage

## [5.1.2](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.1.2) (2016-11-9)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/5.0.2...5.1.2)
* Added new interface - CRBusinessCloudStorage

## [5.0.2](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.0.2) (2016-11-2)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/5.0.1...5.0.2)
* Using Swift 3.0.1

## [5.0.1](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.0.1) (2016-10-31)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/5.0.0...5.0.1)
* Fixed bug where couldnt download files with special characters in Dropbox interface.

## [5.0.0](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/5.0.0) (2016-10-17)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/4.2.0...5.0.0)
* Changed to swift 3

## [4.2.0](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/4.2.0) (2016-10-12)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/4.1.0...4.2.0)
* New CloudStorage interface added, **Egnyte**
* Method `thumbnail:` on CloudStorage interface renamed to thumbnailOfFileWithPath:
* Disabled CodeSigning
* Update CRCLoudMetadata code documentaton
* Bug fixes on GoogleDrive and OneDrive
* Internal bug fixes and improvements

## [4.1.0](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/4.0.0) (2016-09-30)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/4.0.0...4.1.0)
* The services in the CloudStorage interface now have an additional method to get thumbnails
* The CloudMetaData objects now have additional dimension information for images

## [4.0.0](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/4.0.0) (2016-09-14)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/3.3.1...4.0.0)
* BREAKING: License key is now mandatory
* Fixed Bug when authenticating through OAuth2
* Fixed Issue of bundle getting rejected on AppStore

## [3.3.1](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/3.3.1) (2016-09-12)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/3.3.0...3.3.1)
* Fixed code signing issue

## [3.3.0](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/3.3.0) (2016-09-07)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/3.2.5...3.3.0)
* Fixed bug that app locks during authentication popup.
* Implemented feature that enable user to specify the viewController that authentication will be presented. (target property)

## [3.2.5](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/3.2.5) (2016-09-07)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/3.2.4...3.2.5)
* Minor bug fixes
* Added CHANGELOG file.

## [3.2.4](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/3.2.4) (2016-08-22)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/3.2.3...3.2.4)
* Improved Swift compatibility
* Added full bitcode to the final binary (necessary for archiving or Appstore).

## [3.2.3](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/3.2.3) (2016-08-10)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/3.2.2...3.2.3)
 - Fixed bug of Missing Arch when compiling with CloudrailSI
## [3.2.2](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/3.2.2) (2016-08-02)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/3.1.2...3.2.2)
- Added Swift interface
## [3.1.2](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/3.1.2) (2016-07-15)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/3.1.1...3.1.2)
- Critical bug fix on CloudStorage 

## [3.1.1](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/3.1.1) (2016-07-11)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/3.1.0...3.1.1)
 - Critical Bug fix on CRLocation class
 - Code documentation improvement
 - Added constructor for CRCloudStorage
 - Fixed property name from `id` to `identifier`
## [3.1.0](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/3.1.0) (2016-07-06)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/3.0.0...3.1.0)
 - Removed unused files and references
 - Fixed CRCloudMetadata Object properties
 - Added method to CRCloudStorageProtocol `shareLinkForFileWithPath:`
 - Added CRSpaceAllocation class
## [3.0.0](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/3.0.0) (2016-07-01)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/2.4.0...3.0.0)
 - Changed all classes names to have the prefix "CR" (short for CloudRail). Conforming to Apple conventions regarding Objective-C
 - Changed framework name and import to `CloudrailSI`
 
## [2.4.0](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/2.4.0) (2016-06-24)
[Full Changelog](https://github.com/CloudRail/cloudrail-si-ios-sdk/compare/1.0.0...2.4.0)
- General Bug fixes
- Bitcode added to final binary
- Added Payment Interface

## [1.0.0](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/1.0.0) (2016-06-02)
- Initial release
