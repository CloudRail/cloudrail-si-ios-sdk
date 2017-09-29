//
//  CRMessage.h
//  CloudrailSI
//
//  Created by Felipe César Silveira de Assis on 28/09/17.
//  Copyright © 2017 CloudRail. All rights reserved.
//

#import "CRSandboxObject.h"
#import "CRLocation.h"
#import "CRMessagingAttachment.h"

@interface CRMessage : CRSandboxObject

/// Unique ID of the message
@property (nonatomic) NSString * messageId;

/// User ID of the sender
@property (nonatomic) NSString * senderId;

/// ID of the chat (may be different from sender ID, e.g. in group chats)
@property (nonatomic) NSString * chatId;

/// Stores a message ID if message is a reply to an already existing message
@property (nonatomic) NSString * replyTo;

/// Stores a message ID if message is an edit of an already existing message
@property (nonatomic) NSString * editOf;

/// Saves the time when the message was sent as Unix timestamp
@property (nonatomic)  long * sendAt;

/// The text content of the message
@property (nonatomic) NSString * messageText;

/// Contains location that was sent with the message
@property (nonatomic)  CRLocation * location;

/*
 * Contains attachments that were sent with the message
 * Typically, when receiving a message, only parts of the MessagingAttachment object(s) will be filled.
 * Receiving more information (including the stream) can be done by calling Messaging::downloadContent(MessagingAttachment att).
 */
@property (nonatomic) NSMutableArray<CRMessagingAttachment *> * attachments;


@end
