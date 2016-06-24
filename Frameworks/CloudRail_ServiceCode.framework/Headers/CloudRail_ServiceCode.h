//
//  CloudRail_ServiceCode.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 20/04/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for CloudRail_ServiceCode.
FOUNDATION_EXPORT double CloudRail_ServiceCodeVersionNumber;

//! Project version string for CloudRail_ServiceCode.
FOUNDATION_EXPORT const unsigned char CloudRail_ServiceCodeVersionString[];

// To use the framework just do #import <CloudRail_ServiceCode/CloudRail_ServiceCode.h>

#pragma mark - CloudStorage
#import <CloudRail_ServiceCode/Dropbox.h>
#import <CloudRail_ServiceCode/Box.h>
#import <CloudRail_ServiceCode/GoogleDrive.h>
#import <CloudRail_ServiceCode/OneDrive.h>


#pragma mark - ProfileInterface
#import <CloudRail_ServiceCode/Facebook.h>
#import <CloudRail_ServiceCode/GitHub.h>
#import <CloudRail_ServiceCode/GooglePlus.h>
#import <CloudRail_ServiceCode/LinkedIn.h>
#import <CloudRail_ServiceCode/MicrosoftLive.h>
#import <CloudRail_ServiceCode/Slack.h>
#import <CloudRail_ServiceCode/Twitter.h>
#import <CloudRail_ServiceCode/Yahoo.h>
#import <CloudRail_ServiceCode/Instagram.h>


#pragma mark - PointsOfInterestInterface

#import <CloudRail_ServiceCode/Foursquare.h>
#import <CloudRail_ServiceCode/GooglePlaces.h>
#import <CloudRail_ServiceCode/Yelp.h>


#pragma mark - PaymentInterface

#import <CloudRail_ServiceCode/PayPal.h>
#import <CloudRail_ServiceCode/Stripe.h>

#pragma mark - SMSInterface

#import <CloudRail_ServiceCode/Nexmo.h>
#import <CloudRail_ServiceCode/Twilio.h>


#pragma mark - Email
#import <CloudRail_ServiceCode/SendGrid.h>
#import <CloudRail_ServiceCode/MailJet.h>





#pragma mark - Protocols
#import <CloudRail_ServiceCode/CloudMetaData.h>
#import <CloudRail_ServiceCode/CloudStorageProtocol.h>
#import <CloudRail_ServiceCode/ProfileProtocol.h>
#import <CloudRail_ServiceCode/AuthenticatingProtocol.h>
#import <CloudRail_ServiceCode/PersistableProtocol.h>
#import <CloudRail_ServiceCode/PointsOfInterestProtocol.h>
#import <CloudRail_ServiceCode/SMSProtocol.h>
#import <CloudRail_ServiceCode/EmailProtocol.h>
#import <CloudRail_ServiceCode/PaymentProtocol.h>


#pragma mark - ClourRail types

#import <CloudRail_ServiceCode/Address.h>
#import <CloudRail_ServiceCode/CloudMetaData.h>
#import <CloudRail_ServiceCode/Date.h>
#import <CloudRail_ServiceCode/DateOfBirth.h>

#import <CloudRail_ServiceCode/Error.h>
#import <CloudRail_ServiceCode/Location.h>
#import <CloudRail_ServiceCode/Pressure.h>
#import <CloudRail_ServiceCode/SandboxObject.h>
#import <CloudRail_ServiceCode/Temperature.h>
#import <CloudRail_ServiceCode/UserInfo.h>
#import <CloudRail_ServiceCode/Velocity.h>
#import <CloudRail_ServiceCode/WeatherInfo.h>

#import <CloudRail_ServiceCode/Charge.h>
#import <CloudRail_ServiceCode/CreditCard.h>
#import <CloudRail_ServiceCode/Subscription.h>
#import <CloudRail_ServiceCode/SubscriptionPlan.h>
#import <CloudRail_ServiceCode/Refund.h>

