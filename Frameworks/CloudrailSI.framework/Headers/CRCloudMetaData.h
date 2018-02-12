//
//  CloudMetaData.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 02/05/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "CRSandboxObject.h"
#import "CRImageMetaData.h"

@interface CRCloudMetaData : CRSandboxObject

/**
 *  The path of the file in the cloud storage service starting from the Root.
 */
@property (nonatomic) NSString * path;

/**
 *  The name of the file, usually the last path component including the file extension.
 */
@property (nonatomic) NSString * name;

/**
 *  The size of the file (in bytes), derived from long type.
 */
@property (nonatomic) NSNumber * size;

/**
 *  A number describing if the file is a folder or not. Zero value representss false (NO) and positive 1 represents True (YES)
 */
@property (nonatomic) NSNumber * folder;
 
/**
 *  Timestamp that describest the last time the file was modified, derived from long type.
 */
@property (nonatomic) NSNumber * modifiedAt;

/**
 *  ImageMetadata object with aditional metadata of
 */
@property (nonatomic) CRImageMetaData * imageMetaData;

/**
 * Timestamp that describes the last time the contents of a file were modified, derived from long type.
 */
@property (nonatomic) NSNumber *contentModifiedAt;

@end
