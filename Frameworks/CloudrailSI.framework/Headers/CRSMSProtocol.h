//
//  SMSProtocol.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 20/06/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * An interface whose implementations allow sending SMS
 */
@protocol CRSMSProtocol <NSObject>

/**
 * Sends an SMS message, used like sendSMS("CloudRail", "+4912345678", "Hello from CloudRail").
 * Throws if an error occurs.
 *
 * @param fromName A alphanumeric sender id to identify/brand the sender. Only works in some countries.
 * @param toNumber The recipients phone number in E.164 format, e.g. +4912345678.
 * @param content The message content. Limited to 1600 characters, messages > 160 characters are sent and charged as multiple messages.
 */
- (void) sendSmsFromName:(nonnull NSString *)fromName
               toNumber:(nonnull NSString *)toNumber
                content:(nonnull NSString *)content;
// Dev hints: Thoroughly verify user input for validity
@end
