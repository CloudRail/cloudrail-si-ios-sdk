//
//  CRMessagingProtocol.h
//  CloudrailSI
//
//  Created by Felipe César Silveira de Assis on 28/09/17.
//  Copyright © 2017 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CRMessage.h"
#import "CRMessagingAttachment.h"
#import "CRMessageItem.h"
#import "CRAdvancedRequestSupporterProtocol.h"

/**
 * Messaging interface including required types. Services that
 * should be part of this interface: Facebook Messenger, Line, Telegram.
 */
@protocol CRMessagingProtocol <CRAdvancedRequestSupporterProtocol>


#pragma mark - Implementation of Protocols

-(CRMessage *) sendMessageWithReceiverId: (NSString *) receiverId
                                 message: (NSString *) message;

-(CRMessage *) sendImageWithReceiverId: (NSString *) receiverId
                               message: (NSString *) message
                               imageId: (NSString *) imageId
                           imageStream: (NSInputStream *) imageStream
                            previewUrl: (NSString *) previewUrl
                              mimeType: (NSString *) mimeType;

-(CRMessage *) sendVideoWithReceiverId: (NSString *) receiverId
                               message: (NSString *) message
                               videoId: (NSString *) videoId
                           videoStream: (NSInputStream *) videoStream
                            previewUrl: (NSString *) previewUrl
                                  size: (long) size;

-(CRMessage *) sendAudioWithReceiverId: (NSString *) receiverId
                               message: (NSString *) message
                               audioId: (NSString *) audioId
                           audioStream: (NSInputStream *) audioStream
                            previewUrl: (NSString *) previewUrl
                             audioName: (NSString *) audioName
                                  size: (long) size;

-(CRMessage *) sendFileWithReceiverId: (NSString *) receiverId
                              message: (NSString *) message
                               fileId: (NSString *) fileId
                           fileStream: (NSInputStream *) fileStream
                           previewUrl: (NSString *) previewUrl
                             fileName: (NSString *) fileName
                                 size: (long) size;

-(CRMessage *) sendCarouselWithReceiverId: (NSString *) receiverId
                              messageItem: (NSMutableArray<CRMessageItem *> *) messageItem;


-(NSMutableArray<CRMessage *> *) parseReceivedMessages: (NSInputStream *) httpRequestStream;

-(CRMessagingAttachment *) downloadContent: (CRMessagingAttachment *) attachment;

@end
