//
//  EmailProtocol.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 20/06/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CRAttachment.h"

/**
 * An interface whose implementations allow sending emails
 */
@protocol CREmailProtocol <NSObject>

/**
 * Sends an email. Used like sendEmail("info@cloudrail.com", "CloudRail", Arrays.asList("foo@bar.com", "bar@foo.com"), "Welcome", "Hello from CloudRail", null, null, null).
 * Throws if an error occurs.
 *
 * @param fromAddress Mandatory. The sender email address. Must normally be registered with the corresponding service.
 * @param fromName Mandatory. The from name to be displayed to the recipient(s).
 * @param toAddresses Mandatory. A list of recipient email addresses.
 * @param subject Mandatory. The email's subject line.
 * @param textBody The email's body plain text part. Either this and/or the htmlBody must be specified.
 * @param htmlBody The email's body HTML part. Either this and/or the textBody must be specified.
 * @param ccAddresses Optional. A list of CC recipient email addresses.
 * @param bccAddresses Optional. A list of BCC recipient email addresses.
 * @param attachments Optional. A list of attachments.
 */
- (void)sendEmailFromAddress:(NSString *)fromAddress
                   fromName:(NSString *)fromName
                toAddresses:(NSMutableArray<NSString *> *)toAddresses
                    subject:(NSString *)subject
                   textBody:(NSString *)textBody
                   htmlBody:(NSString *)htmlBody
                ccAddresses:(NSMutableArray<NSString *> *)ccAddresses
               bccAddresses:(NSMutableArray<NSString *> *)bccAddresses
                attachments:(NSMutableArray<CRAttachment *> *) attachments;


@end
