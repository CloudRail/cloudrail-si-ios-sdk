//
//  CloudRailSI.h
//  CloudRailSI
//
//  Created by Felipe Cesar on 20/04/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for CloudRailSI.
FOUNDATION_EXPORT double CloudRailSIVersionNumber;

//! Project version string for CloudRailSI.
FOUNDATION_EXPORT const unsigned char CloudRailSIString[];

// To use the framework just do #import <CloudRailSI/CloudRailSI.h>
#import <CloudRailSI/CRCloudRail.h>

#pragma mark - CloudStorage
#import <CloudRailSI/CRDropbox.h>
#import <CloudRailSI/CRBox.h>
#import <CloudRailSI/CRGoogleDrive.h>
#import <CloudRailSI/CROneDrive.h>
#import <CloudRailSI/CREgnyte.h>
#import <CloudRailSI/CROneDriveBusiness.h>
#import <CloudRailSI/CRMicrosoft.h>
#import <CloudRailSI/CRPCloud.h>

#pragma mark - BusinessCloudStorage
#import <CloudRailSI/CRAmazonS3.h>
#import <CloudRailSI/CRBackblaze.h>
#import <CloudRailSI/CRRackspace.h>
#import <CloudRailSI/CRMicrosoftAzure.h>
#import <CloudRailSI/CRGoogleCloudPlatform.h>

#pragma mark - ProfileInterface
#import <CloudRailSI/CRFacebook.h>
#import <CloudRailSI/CRGitHub.h>
#import <CloudRailSI/CRGooglePlus.h>
#import <CloudRailSI/CRLinkedIn.h>
#import <CloudRailSI/CRMicrosoftLive.h>
#import <CloudRailSI/CRSlack.h>
#import <CloudRailSI/CRTwitter.h>
#import <CloudRailSI/CRYahoo.h>
#import <CloudRailSI/CRInstagram.h>
#import <CloudRailSI/CRHeroku.h>
#import <CloudRailSI/CRFacebookPage.h>
#import <CloudRailSI/CRProductHunt.h>


#pragma mark - PointsOfInterestInterface
#import <CloudRailSI/CRFoursquare.h>
#import <CloudRailSI/CRGooglePlaces.h>
#import <CloudRailSI/CRYelp.h>


#pragma mark - PaymentInterface
#import <CloudRailSI/CRPayPal.h>
#import <CloudRailSI/CRStripe.h>

#pragma mark - SMSInterface
#import <CloudRailSI/CRNexmo.h>
#import <CloudRailSI/CRTwilio.h>
#import <CloudRailSI/CRTwizo.h>

#pragma mark - Email
#import <CloudRailSI/CRSendGrid.h>
#import <CloudRailSI/CRMailJet.h>
#import <CloudRailSI/CRGMail.h>

#pragma mark - Video
#import <CloudRailSI/CRYouTube.h>
#import <CloudRailSI/CRTwitch.h>
#import <CloudRailSI/CRVimeo.h>

#pragma mark - Messaging
#import <CloudRailSI/CRFacebookMessenger.h>
#import <CloudRailSI/CRLine.h>
#import <CloudRailSI/CRTelegram.h>
#import <CloudRailSI/CRViber.h>
#import <CloudRailSI/CRSlackBot.h>

#pragma mark - Protocols
#import <CloudRailSI/CRCloudStorageProtocol.h>
#import <CloudRailSI/CRProfileProtocol.h>
#import <CloudRailSI/CRAuthenticatingProtocol.h>
#import <CloudRailSI/CRPersistableProtocol.h>
#import <CloudRailSI/CRPointsOfInterestProtocol.h>
#import <CloudRailSI/CRSMSProtocol.h>
#import <CloudRailSI/CREmailProtocol.h>
#import <CloudRailSI/CRPaymentProtocol.h>
#import <CloudRailSI/CRSocialProtocol.h>
#import <CloudRailSI/CRBusinessCloudStorageProtocol.h>
#import <CloudRailSI/CRAdvancedRequestSupporterProtocol.h>
#import <CloudRailSI/CRVideoProtocol.h>
#import <CloudRailSI/CRMessagingProtocol.h>

#pragma mark - ClourRail types
#import <CloudRailSI/CRAddress.h>
#import <CloudRailSI/CRCloudMetaData.h>
#import <CloudRailSI/CRDateOfBirth.h>
#import <CloudRailSI/CRLocation.h>
#import <CloudRailSI/CRSandboxObject.h>
#import <CloudRailSI/CRCharge.h>
#import <CloudRailSI/CRCreditCard.h>
#import <CloudRailSI/CRSubscription.h>
#import <CloudRailSI/CRSubscriptionPlan.h>
#import <CloudRailSI/CRRefund.h>
#import <CloudRailSI/CRSpaceAllocation.h>
#import <CloudRailSI/CRImageMetaData.h>
#import <CloudRailSI/CRBucket.h>
#import <CloudRailSI/CRBusinessFileMetaData.h>
#import <CloudRailSI/CRAdvancedRequestResponse.h>
#import <CloudRailSI/CRAdvancedRequestSpecification.h>
#import <CloudRailSI/CustomStream.h>
#import <CloudRailSI/CRVideoMetaData.h>
#import <CloudRailSI/CRChannelMetaData.h>
#import <CloudRailSI/CRMessage.h>
#import <CloudRailSI/CRMessagingAttachment.h>
#import <CloudRailSI/CRMessageItem.h>
#import <CloudRailSI/CRMessageButton.h>

#pragma mark - Helper Protocols
#import <CloudRailSI/CRAuthenticationDelegate.h>
#import <CloudRailSI/CRUploadProgressDelegate.h>

#pragma mark - Swift Helpers
#import <CloudRailSI/CRError.h>
#import <CloudRailSI/CRExceptionHandler.h>
