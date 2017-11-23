//
//  CRMessagingAttachment.h
//  CloudrailSI
//
//  Created by Felipe César Silveira de Assis on 28/09/17.
//  Copyright © 2017 CloudRail. All rights reserved.
//

#import "CRSandboxObject.h"

@interface CRMessagingAttachment : CRSandboxObject

/// Attachment ID
@property (nonatomic) NSString * identifier;

/// Attachment Content Type
@property (nonatomic) NSString * contentType;

/// Attachment Mime Type
@property (nonatomic) NSString * mimeType;

/// Attachment Caption
@property (nonatomic) NSString * caption;

/// Converted to Stream
@property (nonatomic) NSInputStream * stream;

@end
