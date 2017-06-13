//
//  CloudStorageTableViewController.swift
//  Cloudstorage
//
//  Created by Mujtaba Alam on 06.06.17.
//  Copyright © 2017 CloudRail. All rights reserved.
//

import UIKit

class CloudStorageTableViewController: UITableViewController {

    var modelsArray: [CloudStorageModel]?
    
    // MARK: - Life Cycle
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.revealViewController().rearViewRevealWidth = self.view.frame.width - 64
        modelsArray = CloudStorageModel.fetchData()
        self.tableView.reloadData()
        self.tableView.tableFooterView = UIView(frame: CGRect.zero)
    }
    
    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return (modelsArray?.count)!
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "Cell", for: indexPath) as! CloudStorageCell

        cell.model = self.modelsArray?[indexPath.row]
        
        return cell
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        let model = self.modelsArray?[indexPath.row]
        
        if model?.storyboardID == "HomeID" {
            if let homeVC = self.storyboard?.instantiateViewController(withIdentifier: "HomeID") as? HomeViewController {
                let nav = UINavigationController(rootViewController: homeVC)
                nav.setViewControllers([homeVC], animated:true)
                self.revealViewController().setFront(nav, animated: true)
                self.revealViewController().pushFrontViewController(nav, animated: true)
            }
        } else {
            if let folderVC = self.storyboard?.instantiateViewController(withIdentifier: "FolderID") as? FoldersTableViewController {
                
                folderVC.cloudStorageTitle = model?.cloudStorageTitle
                folderVC.cloudStorageType = model?.cloudStorageType
                
                let nav = UINavigationController(rootViewController: folderVC)
                nav.setViewControllers([folderVC], animated:true)
                self.revealViewController().setFront(nav, animated: true)
                self.revealViewController().pushFrontViewController(nav, animated: true)
            }
        }
    }
    
}
