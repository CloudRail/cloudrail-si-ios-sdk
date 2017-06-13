//
//  CustomStream.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 20/05/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CRUploadProgressDelegate.h"

@interface CustomStream : NSInputStream



@property (nonatomic) NSInputStream * source;
@property (nonatomic) long  available;
@property (nonatomic, weak) id<CRUploadProgressDelegate> uploadProgressDelegate;

- (instancetype)initWithStream:(NSInputStream*) inputStream;
- (void) resetStream;
@end
