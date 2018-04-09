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
 * This is a common interface for Bucket based Cloud Storage Services. Instead of organizing files in nested folders, 
 * they reside in a bucket.
 */
@protocol CRBusinessCloudStorageProtocol

#pragma mark - Bucket Operations

/**
* Creates a new empty bucket.
*
* @param bucketName The name of the new bucket.
* @return The newly created bucket.
*/
- (CRBucket *)createBucketWithName:(NSString *) bucketName;

/**
 * Get a list of all buckets within your account.
 *
 * @return List of buckets. This might be an empty list if there are no buckets.
 */
- (NSMutableArray<CRBucket *> *) listBuckets;

/**
 * Deletes the specified bucket, the bucket must be empty.
 *
 * @param bucket The bucket which will be deleted.
 */
- (void)deleteBucket:(CRBucket *) bucket;

/**
 * Get a list of files contained in the specified bucket.
 *
 * @param bucket The bucket containing the files.
 */
- (NSMutableArray<CRBusinessFileMetaData *> *)listFilesInBucket:(CRBucket *) bucket;

/**
 * Get a list of files contained in the specified bucket.
 *
 * @param bucket The bucket containing the files.
 * @param prefix The name prefix of the files to be listed
 */
-(NSMutableArray<CRBusinessFileMetaData *> *) listFilesInBucket: (CRBucket *) bucket
                                                     withPrefix: (NSString *) prefix;
#pragma mark - File Operations

/**
 * Get metadata of a file containing the name, the size and the last
 * modified date.
 *
 * @param bucket   The bucket where the file is located.
 * @param fileName The name of the file.
 */
- (CRBusinessFileMetaData *)metadataOfFileInBucket:(CRBucket *) bucket
                                          fileName:(NSString *) fileName;

/**
 * Uploads a new file into a bucket or replaces the file if it is already present.
 *
 * @param bucket  The bucket into which the file shall be put.
 * @param name    The name of the file.
 * @param stream The file content as a readable stream.
 * @param size    The amount of bytes that the file contains.
 */
- (void)uploadFileToBucket:(CRBucket *) bucket
                      name:(NSString *) name
                withStream:(NSInputStream *) stream
                      size:(long) size;

/**
 * Downloads a file from a bucket.
 *
 * @param bucket   The bucket which contains the file.
 * @param fileName The name of the file.
 * @return The content of the file as a readable stream.
 */
- (NSInputStream *)downloadFileWithName:(NSString *) fileName
                                 bucket:(CRBucket *) bucket;

/**
 * Deletes a file within a bucket.
 *
 * @param fileName The name of the file.
 * @param bucket   The bucket that contains the file.
 */
- (void)deleteFileWithName:(NSString *) fileName
                    bucket:(CRBucket *) bucket;

@end
