//
//  Helpers.swift
//  Cloudstorage
//
//  Created by Mujtaba Alam on 07.06.17.
//  Copyright © 2017 CloudRail. All rights reserved.
//

import Foundation
import CloudrailSI

class Helpers {
    
    // MARK: Show Side Menu
    static func showSideMenu(_ menuBarButton: UIBarButtonItem, _ controller: UIViewController) {
        
        if controller.revealViewController() != nil {
            menuBarButton.target = controller.revealViewController()
            menuBarButton.action = #selector(SWRevealViewController.revealToggle(_:))
            controller.view.addGestureRecognizer(controller.revealViewController().panGestureRecognizer())
        }
    }
    
    
    // MARK: - Custom Methods related to CloudMetaData (type of File, is Image or is Folder)
    
    static func imageType(_ cloudMetaData: CRCloudMetaData) -> UIImage {
        
        if isFolder(cloudMetaData) {
            return UIImage(named: "folder")!
        } else {
            
            if isImage(cloudMetaData) {
                return UIImage(named: "picture")!
            } else {
                return UIImage(named: "document")!
            }
        }
    }
    
    
    static func isImage(_ cloudMetaData: CRCloudMetaData) -> Bool {
        let imageExtension = URL(string : cloudMetaData.name.lowercased())?.pathExtension
        if imageExtension == "jpg" || imageExtension == "jpeg" || imageExtension == "png"  {
            return true
        }
        
        return false
    }
    
    static func isFolder(_ cloudMetaData: CRCloudMetaData) -> Bool {
        if cloudMetaData.folder! == 1 {
            return true
        }
        return false
    }
    
    // MARK: - Random generated Image Name
    
    static func randomImageName() -> String {
        let min: UInt32 = 100_000
        let max: UInt32 = 999_999
        let i = min + arc4random_uniform(max - min + 1)
        return "DSCR\(String(i)).jpg";
    }
    
    // MARK: - Get Document Directory Path
    
    static func getDocumentsDirectory() -> URL? {
        let paths = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask)
        let documentsDirectory = paths[0]
        return documentsDirectory
    }
    
    // MARK: - Download File pass InputStream, Path and Name
    
    static func downloadFileToDoc(inputStream: InputStream, name: String) {
        
        let data = NSMutableData()
        var buffer = [UInt8](repeating: 0, count:256)
        inputStream.open()
        
        //MARK: Loop through thumbnail stream
        while (inputStream.hasBytesAvailable) {
            //MARK: Read from the stream and append bytes to NSMutableData variable
            let len  = inputStream.read(&buffer, maxLength: buffer.count)
            data.append(buffer, length: len)
        }
        
        //MARK: Check if there are no bytes left and show the image
        if inputStream.hasBytesAvailable == false {
            inputStream.close()
            
            let progressData = (data as Data)
            DispatchQueue.main.async {
                let filename = getDocumentsDirectory()?.appendingPathComponent(name)
                try? progressData.write(to: filename!)
            }
        }
    }
}
