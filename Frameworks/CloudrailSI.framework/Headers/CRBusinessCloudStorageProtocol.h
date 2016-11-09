//
//  CloudStorage.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 11/05/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CRBusinessFileMetaData.h"
#import "CRBucket.h"

/**
 * A common interface for cloud storage services, abstracts to the level of paths consistently for all services.
 */
@protocol CRBusinessCloudStorageProtocol
#pragma mark - Implementation of Protocols

-(CRBucket *) createBucket: (NSString *) bucketName;

-(NSMutableArray<CRBucket *> *) listBuckets;

-(void) deleteBucketWithID: (CRBucket *) bucket;

-(CRBusinessFileMetaData *) metadataOfFileWithPath: (CRBucket *) bucket
                                     fileName: (NSString *) fileName;

-(NSMutableArray<CRBusinessFileMetaData *> *) listFilesInBucket: (CRBucket *) bucket;

-(void) uploadFileToBucket: (CRBucket *) bucket
                      name: (NSString *) name
                withStream: (NSInputStream *) stream
                      size: (long) size;

-(NSInputStream *) downloadFileWithName: (NSString *) fileName
                                 bucket: (CRBucket *) bucket;
#pragma mark - AuthenticatingProtocol
-(NSString *) saveAsString;
-(void) loadAsString:(NSString*) savedState;
-(void) deleteFileWithName: (NSString *) fileName
                    bucket: (CRBucket *) bucket;
@end
