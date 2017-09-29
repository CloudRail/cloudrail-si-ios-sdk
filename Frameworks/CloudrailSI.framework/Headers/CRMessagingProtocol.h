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
#import "CRAdvancedRequestSupporterProtocol.h"

/**
 * Messaging interface including required types. Services that
 * should be part of this interface: Facebook Messenger, Line, Telegram.
 */
@protocol CRMessagingProtocol <CRAdvancedRequestSupporterProtocol>


#pragma mark - Implementation of Protocols

-(CRMessage *) sendMessageTo: (NSString *) receiverId
                 withContent: (NSString *) message;

-(CRMessage *) sendImageTo: (NSString *) receiverId
               withMessage: (NSString *) message
                   imageId: (NSString *) imageId
               imageStream: (NSInputStream *) imageStream
                previewUrl: (NSString *) previewUrl;

-(CRMessage *) sendVideoTo: (NSString *) receiverId
               withMessage: (NSString *) message
                   videoId: (NSString *) videoId
               videoStream: (NSInputStream *) videoStream
                previewUrl: (NSString *) previewUrl
                      size: (long) size;

-(CRMessage *) sendAudioTo: (NSString *) receiverId
               withMessage: (NSString *) message
                   audioId: (NSString *) audioId
               audioStream: (NSInputStream *) audioStream
                previewUrl: (NSString *) previewUrl
                 audioName: (NSString *) audioName
                      size: (long) size;

-(CRMessage *) sendFileTo: (NSString *) receiverId
              withMessage: (NSString *) message
                   fileId: (NSString *) fileId
               fileStream: (NSInputStream *) fileStream
               previewUrl: (NSString *) previewUrl
                 fileName: (NSString *) fileName
                     size: (long) size;

-(NSMutableArray<CRMessage *> *) processWebhookRequest: (NSInputStream *) httpRequestStream;

-(CRMessagingAttachment *) downloadContent: (CRMessagingAttachment *) attachment;

@end
