# Change Log

## [4.1.0](https://github.com/CloudRail/cloudrail-si-ios-sdk/tree/4.0.0) (2016-09-302)
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
