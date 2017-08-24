//
//  CRAttachment.h
//  CloudRail_ServiceCode
//
//  Created by Fabian Stolz on 15/08/17.
//  Copyright © 2017 CloudRail. All rights reserved.
//

#import "CRSandboxObject.h"

@interface CRAttachment : CRSandboxObject

/*
 * The InputStream of the file contents
 */
@property (nonatomic) NSInputStream * content;

/*
 * The MIME type of the file
 */
@property (nonatomic) NSString * mimeType;

/*
 * The file's filename
 */
@property (nonatomic) NSString * filename;


- (void)initWithContent:(NSInputStream *) stream
                   type:(NSString *) mimeType
               filename:(NSString *) name;

@end
