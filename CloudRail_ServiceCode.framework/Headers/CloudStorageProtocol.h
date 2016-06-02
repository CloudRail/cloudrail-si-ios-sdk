//
//  CloudStorage.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 11/05/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CloudMetaData.h"
#import "AuthenticatingProtocol.h"
#import "PersistableProtocol.h"

@protocol CloudStorageProtocol <AuthenticatingProtocol,PersistableProtocol>



/**
 * Downloads a file from a cloud storage
 * @param filePath The path to the file from the root folder and including the name, e.g /myFolder/myFile.jpg
 * @return A stream from which the file can be read
 */
-(NSInputStream *) downloadWithFilePath:(NSString*) filePath;

/**
 * Uploads a file to a cloud storage
 * @param filePath The path where to store the file from the root folder and including the name, e.g /myFolder/myFile.jpg
 * @param stream A stream from which the file can bwe read
 * @param size The size in bytes of the data that can be read from the stream
 */
-(void) uploadWithFilePath: (NSString *) filePath
                    stream: (NSInputStream *) stream
                      size: (long) size
                 overwrite: (BOOL) overwrite;
/**
 * Moves a file in the cloud storage
 * @param sourcePath The path to the file which should be moved from the root folder and including the name
 * @param destinationPath The path to move the file to from the root folder and including the name
 */
-(void) moveWithSourcePath:(NSString *) sourcePath destinationPath:(NSString*) destinationPath;


/**
 * Deletes a file from the cloud storage
 * @param filePath The path to the file to be deleted from the root folder and including the name
 */
-(void) deleteWithPath:(NSString*) filePath;

/**
 * Copies a file from one path in the cloud storage to another
 * @param sourcePath The path of the origin file from the root folder and including the name
 * @param destinationPath The path of the destination file from the root folder and including the name
 */
-(void) copyWithSourcePath:(NSString *) sourcePath destinationPath:(NSString*) destinationPath;

/**
 * Creates a folder at the given path
 * @param folderPath The path to the folder from the root folder and including the name, e.g. /myNewFolder
 */

-(void) createFolderWithPath:(NSString*) folderPath;

/**
 * Gets metadata about the file/folder
 * @param filePath The path to the file from the root folder and including the name
 * @return A container for metadata
 */
-(CloudMetaData*) metadataWithPath:(NSString*) filePath;

/**
 * Gets the metadata of this folder's children
 * @param folderPath The path to the file from the root folder and including the name
 * @return A container for metadata
 */
-(NSMutableArray<CloudMetaData*> *) childrenWithPath:(NSString *) filePath;

@end
