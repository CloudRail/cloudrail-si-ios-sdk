//
//  SearchTableViewController.swift
//  Cloudstorage
//
//  Created by Mujtaba Alam on 08.06.17.
//  Copyright © 2017 CloudRail. All rights reserved.
//

import UIKit
import CloudrailSI

class SearchTableViewController: UITableViewController, UISearchBarDelegate {

    @IBOutlet weak var searchStorage: UISearchBar!
    
    var cloudStorage: CloudStorageProtocol?
    
    private var data = [CRCloudMetaData]()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.navigationItem.backBarButtonItem = UIBarButtonItem(title:"", style:.plain, target:nil, action:nil)
        self.tableView.tableFooterView = UIView(frame: CGRect.zero)
        searchStorage.becomeFirstResponder()
    }
    
    // MARK: - Search Delegate
    
    func searchBar(_ searchBar: UISearchBar, textDidChange searchText: String) {
        if searchText.isEmpty {
            self.data = []
            self.tableView.reloadData()
        }
    }
    
    func searchBarSearchButtonClicked(_ searchBar: UISearchBar) {
        searchStorage.resignFirstResponder()
        
        if let text = searchBar.text {
            
            let backgroundQueue = DispatchQueue(label: "com.searchapp.queue",
                                                qos: .background,
                                                target: nil)
            backgroundQueue.async {
                self.startActivityIndicator()
                self.data = CloudStorageLogic.searchWithQuery(cloudStorage: self.cloudStorage!, query: text) as! [CRCloudMetaData]
                self.tableView.reloadData()
                self.stopActivityIndicator()
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
        let cell = tableView.dequeueReusableCell(withIdentifier: "Cell", for: indexPath) as! SearchCell
        
        let cloudMetaData = self.data[indexPath.row]
        cell.searchLbl.text = cloudMetaData.name
        cell.searchImgView.image = Helpers.imageType(cloudMetaData)
        
        return cell
    }
}
