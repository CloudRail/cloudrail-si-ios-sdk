//
//  ImageViewController.swift
//  Cloudstorage
//
//  Created by Mujtaba Alam on 08.06.17.
//  Copyright © 2017 CloudRail. All rights reserved.
//

import UIKit
import CloudrailSI

class ImageViewController: UIViewController {

    @IBOutlet weak var mainImgView: UIImageView!
    
    var cloudStorage: CloudStorageProtocol?
    var cloudMetaData: CRCloudMetaData?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.navigationItem.backBarButtonItem = UIBarButtonItem(title:"", style:.plain, target:nil, action:nil)
        
        let backgroundQueue = DispatchQueue(label: "com.app.queue",
                                            qos: .background,
                                            target: nil)
        backgroundQueue.async {
            self.startActivityIndicator()
            
            let fileURL = Helpers.getDocumentsDirectory()?.appendingPathComponent((self.cloudMetaData?.name)!)
            if !FileManager.default.fileExists(atPath: (fileURL?.path)!) {
                self.downloadImage(path: (self.cloudMetaData?.path)!, name: (self.cloudMetaData?.name)!)
            } else {
                self.loadImage(fileURL: fileURL!)
            }
            
            self.stopActivityIndicator()
        }
    }
    
    func loadImage(fileURL: URL) {
        let image = UIImage(contentsOfFile: fileURL.path)
        self.mainImgView.image = image
    }
    
    // MARK: - Download Image - using downloadFileWithPath and Retrive Data as InputStream
    
    func downloadImage(path: String, name: String) {
        
        if let result = CloudStorageLogic.downloadFileWithPath(cloudStorage:self.cloudStorage!, path: path) {
            let dataOfTheImage = NSMutableData()
            var buffer = [UInt8](repeating: 0, count:1024)
            result.open()
            
            //MARK: Loop through thumbnail stream
            while (result.hasBytesAvailable) {
                //MARK: Read from the stream and append bytes to NSMutableData variable
                let len  = result.read(&buffer, maxLength: buffer.count)
                dataOfTheImage.append(buffer, length: len)
            }
            
            //MARK: Check if there are no bytes left and show the image
            if result.hasBytesAvailable == false {
                result.close()
                // var pictureData = NSData(bytes: buffer, length: len)
                let progressData = (dataOfTheImage as Data)
                let progressImage = UIImage(data: progressData)!
                DispatchQueue.main.async(execute: {() -> Void in
                    let filename = Helpers.getDocumentsDirectory()?.appendingPathComponent(name)
                    try? progressData.write(to: filename!)
                    self.mainImgView.image = progressImage
                })
            }
        }
    }
}
