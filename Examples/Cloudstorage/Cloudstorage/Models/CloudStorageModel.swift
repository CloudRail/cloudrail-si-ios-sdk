//
//  CloudStorageModel.swift
//  Cloudstorage
//
//  Created by Mujtaba Alam on 08.06.17.
//  Copyright © 2017 CloudRail. All rights reserved.
//

import Foundation
import UIKit

class CloudStorageModel {
    
    var cloudStorageTitle: String?
    var image: UIImage?
    var storyboardID: String?
    var cloudStorageType: String?
    
    
    init(_ cloudStorageTitle: String, _ image: UIImage, _ storyboardID: String, _ cloudStorageType: String) {
        self.cloudStorageTitle = cloudStorageTitle
        self.image = image
        self.storyboardID = storyboardID
        self.cloudStorageType = cloudStorageType
    }
    
    class func fetchData() -> [CloudStorageModel] {
        
        var modelArray = [CloudStorageModel]()
        modelArray.append(CloudStorageModel("Home", UIImage(named: "home")!, "HomeID", ""))
        modelArray.append(CloudStorageModel("Dropbox", UIImage(named: "dropbox")!, "FolderID", "dropbox"))
        modelArray.append(CloudStorageModel("Box", UIImage(named: "box")!, "FolderID", "box"))
        modelArray.append(CloudStorageModel("Google Drive", UIImage(named: "gdrive")!, "FolderID", "googleDrive"))
        modelArray.append(CloudStorageModel("One Drive", UIImage(named: "onedrive")!, "FolderID", "oneDrive"))
//        modelArray.append(CloudStorageModel("Egnyte", UIImage(named: "egnyte")!, "FolderID", "egnyte"))
        
        return modelArray
    }
    
}
