//
//  CRStorageMetadata.h
//  CloudrailSI
//
//  Created by Felipe Cesar on 14/09/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "CRSandboxObject.h"

@interface CRBusinessFileMetaData : CRSandboxObject

@property (nonatomic) NSString * fileID;
@property (nonatomic) NSString * fileName;

@property (nonatomic) long fileSize;
@property (nonatomic) long lastModifiedTimestamp;

@property (nonatomic) NSNumber * size;
@property (nonatomic) NSNumber * lastModified;

@end
