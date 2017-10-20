//
//  CloudStorageLogic.swift
//  Cloudstorage
//
//  Created by Mujtaba Alam on 09.06.17.
//  Updated on 10.20.17.
//  Copyright © 2017 CloudRail. All rights reserved.
//

import Foundation
import CloudrailSI

class CloudStorageLogic {
    
    /**
     * Persistent data.
     * URL: http://cocoadocs.org/docsets/cloudrail-si-ios-sdk/1.0.0/Protocols/PersistableProtocol.html
     */
    
    static func saveAsString(cloudStorage: CloudStorageProtocol) -> String {
        do {
            return try cloudStorage.saveAsString()
        } catch {
            return error.localizedDescription
        }
    }
    
    static func loadAsString(cloudStorage: CloudStorageProtocol, savedState: String) {
        do {
            try cloudStorage.loadAsString(savedState)
        } catch {
            print(error.localizedDescription)
        }
    }
    
    /**
     * Authentication Method
     * If Login / Logout shows an Exception it is not working fine
     * URL: http://cocoadocs.org/docsets/cloudrail-si-ios-sdk/1.0.0/Protocols/AuthenticatingProtocol.html
     */
    
    static func login(cloudStorage: CloudStorageProtocol) ->Bool! {
        do {
            try cloudStorage.login()
            return true
        } catch {
            print(error.localizedDescription)
            return false
        }
    }
    
    static func logout(cloudStorage: CloudStorageProtocol) ->Bool! {
        do {
            try cloudStorage.logout()
            return true
        } catch {
            print(error.localizedDescription)
            return false
        }
    }
    
    // MARK: - CloudRail Cloudstorage Methods
    
    /**
     * CloudStorage.
     * URL: https://cloudrail.com/integrations/interfaces/CloudStorage;serviceIds=Box%2CDropbox%2CEgnyte%2CGoogleDrive%2COneDrive;platformId=Swift
     */
    
    // MARK: userLogin - Login User
    
    static func userLogin(cloudStorage: CloudStorageProtocol) -> String? {
        do {
            let result = try cloudStorage.userLogin()
            return result
        } catch {
            print(error.localizedDescription)
            return ""
        }
    }
    
    // MARK: userName - User Name
    
    static func userName(cloudStorage: CloudStorageProtocol) -> String? {
        do {
            let result = try cloudStorage.userName()
            return result
        } catch {
            print(error.localizedDescription)
            return ""
        }
    }
    
    // MARK: childrenOfFolderWithPath - Retrive Files / Folders at Path (as an Array)
    
    static func childrenOfFolderWithPath(cloudStorage: CloudStorageProtocol, path: String) -> Array<Any> {
        do {
            let result = try cloudStorage.childrenOfFolderWithPath(path)
            return result as! Array<Any>
        } catch {
            print(error.localizedDescription)
            return []
        }
    }
    
    // MARK: shareLinkForFileWithPath - Share Http(s) link as String
    
    static func shareLinkForFileWithPath(cloudStorage: CloudStorageProtocol, path: String) -> String? {
        do {
            let resultString = try cloudStorage.shareLinkForFileWithPath(path)
            return resultString
        } catch {
            print(error.localizedDescription)
            return""
        }
    }
    
    // MARK: deleteFileWithPath - Delete File or Folder with Path
    
    static func deleteFileWithPath(cloudStorage: CloudStorageProtocol, path: String) -> Bool{
        do {
            try cloudStorage.deleteFileWithPath(path)
            return true
        } catch {
            print(error.localizedDescription)
            return false
        }
    }
    
    // MARK: uploadFileToPath - Upload File to Path
    
    static func uploadFileToPath(cloudStorage: CloudStorageProtocol,
                          path: String,
                          inputStream: InputStream,
                          size: Int) -> Bool {
        do {
            try cloudStorage.uploadFileToPath(path, stream: inputStream, size: size, overwrite: true)
            return true
        } catch {
            print(error.localizedDescription)
            return false
        }
    }
    
    // MARK: downloadFileWithPath - Download File with Path
    static func downloadFileWithPath(cloudStorage: CloudStorageProtocol, path: String) -> InputStream? {
        do {
            let result = try cloudStorage.downloadFileWithPath(path)
            return result
        } catch {
            print(error.localizedDescription)
            return nil
        }
    }
    
    // MARK: spaceAllocation - Get the total and used space in bytes
    static func spaceAllocation(cloudstorage: CloudStorageProtocol) -> CRSpaceAllocation? {
        do {
            let result = try cloudstorage.spaceAllocation()
            return result
        } catch {
            print(error.localizedDescription)
            return nil
        }
    }
    
    // MARK: fileExistsAtPath - Check if file exist at path
    static func fileExistsAtPath(cloudstorage: CloudStorageProtocol, path: String) -> Bool {
        do {
            let result = try cloudstorage.fileExistsAtPath(path)
            return result
        } catch {
            print(error.localizedDescription)
            return false
        }
    }
    
    
    // MARK: thumbnailOfFileWithPath - Get thumbnail of a image
    static func thumbnailOfFileWithPath(cloudstorage: CloudStorageProtocol, path: String) -> InputStream? {
        do {
            let result = try cloudstorage.thumbnailOfFileWithPath(path)
            return result
        } catch {
            print(error.localizedDescription)
            return nil
        }
    }
    
    // MARK: createFolderWithPath - Create Folder with Path
    
    static func createFolderWithPath(cloudstorage: CloudStorageProtocol, path: String) {
        do {
            try cloudstorage.createFolderWithPath(path)
        } catch {
            print(error.localizedDescription)
        }
    }
    
    // MARK: copyFileFromPath - Copy File or Folder with Path to Destination
    
    static func copyFileFromPath(cloudstorage: CloudStorageProtocol, path: String, destination: String) {
        do {
            try cloudstorage.copyFileFromPath(path,destinationPath: destination)
        } catch {
            print(error.localizedDescription)
        }
    }
    
    // MARK: moveFileFromPath - Move File or Folder with Path to Destination
    
    static func moveFileFromPath(cloudstorage: CloudStorageProtocol, path: String, destination: String) {
        do {
            try cloudstorage.moveFileFromPath(path,destinationPath: destination)
        } catch {
            print(error.localizedDescription)
        }
    }
    
    
    // MARK: metadataOfFileWithPath - Get Meta Data of file with path
    static func metadataOfFileWithPath(cloudstorage: CloudStorageProtocol, path: String) -> CRCloudMetaData? {
        do {
            let result = try cloudstorage.metadataOfFileWithPath(path)
            return result
        } catch {
            print(error.localizedDescription)
            return nil
        }
    }
    
    // MARK: searchFileWithQuery - Search Files or Folders with Query
    static func searchWithQuery(cloudStorage: CloudStorageProtocol, query: String) -> Array<Any> {
        do {
            let result = try cloudStorage.searchWithQuery(query)
            return result as! Array<Any>
        } catch {
            print(error.localizedDescription)
            return []
        }
    }
}
