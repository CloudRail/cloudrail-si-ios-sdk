//
//  CloudStorage.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 11/05/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CRCloudMetaData.h"
#import "CRAuthenticatingProtocol.h"
#import "CRPersistableProtocol.h"
#import "CRSpaceAllocation.h"
#import "CRAdvancedRequestSupporterProtocol.h"

/**
 * A common interface for cloud storage services, abstracts to the level of paths consistently for all services.
 */
@protocol CRCloudStorageProtocol <CRAuthenticatingProtocol,CRPersistableProtocol,CRAdvancedRequestSupporterProtocol>

/**
 *  Downloads a file from a cloud storage
 * @param filePath The path to the file from the root folder and including the name, e.g /myFolder/myFile.jpg
 * @return A stream from which the file can be read
 */
- (nonnull NSInputStream *)downloadFileWithPath:(nonnull NSString *) filePath;

/**
 *  Uploads a file to a cloud storage
 * @param filePath The path where to store the file from the root folder and including the name, e.g /myFolder/myFile.jpg
 * @param stream A stream from which the file can bwe read
 * @param size The size in bytes of the data that can be read from the stream
 */
- (void)uploadFileToPath:(nonnull NSString *) filePath
              withStream:(nonnull NSInputStream *) stream
                    size:(long) size
               overwrite:(BOOL) overwrite;
/**
 *  Moves a file in the cloud storage
 * @param sourcePath The path to the file which should be moved from the root folder and including the name
 * @param destinationPath The path to move the file to from the root folder and including the name
 */
- (void)moveFileFromPath:(nonnull NSString *) sourcePath
      toDestinationPath:(nonnull NSString *) destinationPath;

/**
 *  Deletes a file from the cloud storage
 * @param filePath The path to the file to be deleted from the root folder and including the name
 */
- (void)deleteFileWithPath:(nonnull NSString *) filePath;

/**
 *  Copies a file from one path in the cloud storage to another
 * @param sourcePath The path of the origin file from the root folder and including the name
 * @param destinationPath The path of the destination file from the root folder and including the name
 */
- (void)copyFileFromPath:(nonnull NSString *) sourcePath
       toDestinationPath:(nonnull NSString *) destinationPath;

/**
 *  Creates a folder at the given path
 * @param folderPath The path to the folder from the root folder and including the name, e.g. /myNewFolder
 */
- (void)createFolderWithPath:(nonnull NSString*) folderPath;

/**
 *  Gets metadata about the file/folder
 * @param filePath The path to the file from the root folder and including the name
 * @return A container for metadata
 */
- (nonnull CRCloudMetaData *)metadataOfFileWithPath:(nonnull NSString *) filePath;

/**
 *  Checks the existance of a File or Folder
 *
 *  @param path Path to the file on cloud.
 *
 *  @return BOOL YES if the file exist at a given path
 */
- (BOOL) fileExistsAtPath:(nonnull NSString *) path;

/**
 *  Gets the metadata of this folder's children
 * @param folderPath The path to the file from the root folder and including the name
 * @return A container for metadata
 */
- (nonnull NSMutableArray<CRCloudMetaData *> *)childrenOfFolderWithPath:(nonnull NSString *) folderPath;

/**
 * Retrives metadata of files within the specified folder. Unlike {@link CloudStorage#getChildren(String)} the
 * result of this function only returns a subset of the folders content.
 *
 * @param path The path to the file from the root folder and including the name.
 * @param offset The first child to return metadata for.
 * @param limit The maximum amount of children that should be returned.
 * @return List of metadata entries for the children of the specified folder.
 */
- (nonnull NSMutableArray<CRCloudMetaData *> *)childrenOfFolderWithPath:(nonnull NSString *) folderPath
                                                                 offset:(long) offset
                                                                  limit:(long) limit;

/**
 * Creates a share link and the permission is only to 'view' and download the file/folder
 *
 * @param path the path to the file/folder which the link to will be created
 * @return The url as a String
 */
- (nonnull NSString *) shareLinkForFileWithPath:(nonnull NSString *) path;

/**
 *
 * @return The total space in bytes and the used space
 */
- (nonnull CRSpaceAllocation *) spaceAllocation;

/**
 *  Method to retrieve a user's login (name/email address/...)
 *
 *  @return NSString the user login.
 */
- (nullable NSString *) userLogin;

/**
 *  Method to retrieve a user's name
 *
 *  @return NSString the user name.
 */
- (nullable NSString *) userName;

/**
 *  Gets a thumbnail of the image at the path. The path must resolve into an image.
 *
 *  @param path path to the image
 *
 *  @return NSIntputStream Stream that points to the image thumbnail
 */
- (nullable  NSInputStream *) thumbnailOfFileWithPath: (nonnull NSString *) path;

@optional
/**
 *  Basic contructor method for any CRCloudStorageProtocol conforming class
 *
 *  @param clientId     The client identifier (or key) of the corresponding service.
 *  @param clientSecret The client secret (or secret) of the corresponding service.
 *  @param redirectUri  The redirect url used to capture the response from the service.
 *  @param state        Value used to identify diferent states on the server side. Unused in iOS version of CloudRail SDK
 *
 *  @return instancetype  id<CRCloudStorageProtocol> Initialized instance of a CRCloudStorage service using the values from the parameters.
 */
- (nonnull instancetype)initWithClientId:(nonnull NSString *) clientId
                           clientSecret:(nonnull NSString *) clientSecret
                            redirectUri:(nonnull NSString *) redirectUri
                                  state:(nonnull NSString *) state __attribute__((deprecated));


/**
 *  Use the given query to search for matching files.
 *
 *  @param query     A query string to be used in the search for the file in the service.
 *  @return NSMutableArray<CRCloudMetaData *> An array containing the metadata of the files matching the query.
 */
-(nonnull NSMutableArray<CRCloudMetaData *> *)searchWithQuery:(nonnull NSString *) query;

/**
 *  Uploads a file to a cloud storage with content modified date
 * @param filePath The path where to store the file from the root folder and including the name, e.g /myFolder/myFile.jpg
 * @param stream A stream from which the file can bwe read
 * @param size The size in bytes of the data that can be read from the stream
 * @param contentModifiedDate The timeInterval (in ms) when the contents of a file were last modified
 */
-(void) uploadFileWithContentModifiedDateToPath: (nonnull NSString *) filePath
                                     withStream: (nonnull NSInputStream *) stream
                                           size: (long) size
                                      overwrite: (BOOL) overwrite
                            contentModifiedDate: (long) contentModifiedDate;
@end
