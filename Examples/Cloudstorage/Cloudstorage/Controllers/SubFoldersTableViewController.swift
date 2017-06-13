//
//  SubFoldersTableViewController.swift
//  Cloudstorage
//
//  Created by Mujtaba Alam on 08.06.17.
//  Copyright © 2017 CloudRail. All rights reserved.
//

import UIKit
import CloudrailSI

class SubFoldersTableViewController: UITableViewController {

    var cloudStorage: CloudStorageProtocol?
    var path: String?
    
    //CloudMetaData is retrived
    private var data = [CRCloudMetaData]()
    
    // MARK: - Life Cycle
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.tableView.tableFooterView = UIView(frame: CGRect.zero)
        self.navigationItem.title = path?.replacingOccurrences(of: "/", with: "")
        
        self.startActivityIndicator()
        
        let backgroundQueue = DispatchQueue(label: "com.cloudrailapp.queue",
                                            qos: .background,
                                            target: nil)
        
        backgroundQueue.async {
            
            self.data = CloudStorageLogic.childrenOfFolderWithPath(cloudStorage: self.cloudStorage!,
                                                                   path: self.path!) as! [CRCloudMetaData]
            self.stopActivityIndicator()
            DispatchQueue.main.async {
                self.tableView.reloadData()
            }
        }
    }
    
    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.data.count
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "Cell", for: indexPath) as! FoldersCell
        
        let cloudMetaData = self.data[indexPath.row]
        cell.folderLbl.text = cloudMetaData.name
        cell.folderImgView.image = Helpers.imageType(cloudMetaData)
        
        return cell
    }
    
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
