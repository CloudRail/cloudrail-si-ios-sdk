//
//  FoldersTableViewController.swift
//  Cloudstorage
//
//  Created by Mujtaba Alam on 06.06.17.
//  Updated on 10.20.17.
//  Copyright © 2017 CloudRail. All rights reserved.
//

import UIKit
import CloudrailSI
//import Toast_Swift
import WebKit

class FoldersTableViewController: UITableViewController, UIImagePickerControllerDelegate, UINavigationControllerDelegate {
    
    @IBOutlet weak var menuBarButton: UIBarButtonItem!
    
    private let activityIndicator = UIActivityIndicatorView()
    
    private let refresh = UIRefreshControl()
    
    private let picker = UIImagePickerController()
    
    var cloudStorageTitle: String?
    var cloudStorageType: String?
    var typeOfService: String?
    
    //CloudStorageProctocol that you want to use e.g Dropxbox, Box, Google Drive, One Drive or Egnyte
    private var cloudStorage: CloudStorageProtocol?
    
    private var storageService: CRPersistableProtocol?
    
    //CloudMetaData is retrived
    private var data = [CRCloudMetaData]()
    
    // MARK: - Life Cycle
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.navigationItem.backBarButtonItem = UIBarButtonItem(title:"", style:.plain, target:nil, action:nil)
        
        Helpers.showSideMenu(menuBarButton, self)
        self.tableView.tableFooterView = UIView(frame: CGRect.zero)
        self.navigationItem.title = cloudStorageTitle
        
        picker.delegate = self
        
        //Refresh Controller
        
        if #available(iOS 10.0, *) {
            self.tableView.refreshControl = refresh
        } else {
            self.tableView.addSubview(refresh)
        }
        
        refresh.addTarget(self, action: #selector(reloadRetivedData), for: .valueChanged)
        
        //Setup service you want to use
        setupService()
    }
    
    // MARK: - Setup Service (Dropbox, Box, GoogleDrive, One Drive or Egnyte)
    //More information: https://cloudrail.com/integrations/interfaces/CloudStorage;platformId=Swift
    
    func setupService() {
        
        //Note: These are sample Keys/Secrets for example purpose, do not use it in live production
        typeOfService = ""
        
        if cloudStorageType == "dropbox" {
            
            //Dropbox needs the following:
            //1. ClientId: App Key
            //2. ClientSecret: App Secret
            //3. Redirect URI: https://auth.cloudrail.com/YourBundleID
            //4. State - Any String e.g. state
            //5. useAdvancedAuthentication() method Must be called!
            //https://blog.cloudrail.com/authenticating-with-dropbox/
            
            typeOfService = "Dropbox"
            let drive = Dropbox(clientId: "[Dropbox App Key]",
                                clientSecret: "[Dropbox App Secret]",
                                redirectUri: "https://auth.cloudrail.com/org.cocoapods.demo.CloudRail-SI-iOS.Cloudstorage",
                                state: "state")
            
            drive.useAdvancedAuthentication()
            cloudStorage = drive
            
        } else if cloudStorageType == "box" {
            //1. ClientId: Client ID
            //2. ClientSecret: Client Secret
            
            typeOfService = "Box"
            cloudStorage = Box(clientId: "[Box Client Id]",
                               clientSecret: "[Box Client Secret]")
            
        } else if cloudStorageType == "googleDrive" {
            
            //Google Drive needs the following:
            //1. ClientId: Client Id
            //2. ClientSecret: Leave Empty
            //3. Redirect URI: YourBundleID:/oauth2redirect
            //4. State - Any String e.g. state
            //5. useAdvancedAuthentication() method Must be called!
            //https://blog.cloudrail.com/authenticating-google-drive/
            
            typeOfService = "GoogleDrive"
            let drive = GoogleDrive(clientId: "[Google Drive Client Identifier]",
                                    clientSecret: "",
                                    redirectUri: "org.cocoapods.demo.CloudRail-SI-iOS.Cloudstorage:/oauth2redirect",
                                    state: "state")
            
            drive.useAdvancedAuthentication()
            cloudStorage = drive
            
        } else if cloudStorageType == "oneDrive" {
            
            //1. ClientId: Application Id
            //2. ClientSecret: Application Secret
            
            typeOfService = "OneDrive"
            cloudStorage = OneDrive(clientId: "[OneDrive Application Id]",
                                    clientSecret: "[OneDrive Application Secret]")
            
        } else if cloudStorageType == "egnyte" {
            
            //Egnyte requires the following:
            //1. Domain
            //2. API Key
            //3. Secret
            //4. Redirect URI and a State (any)
            //5. State - Any String e.g. state
            
            typeOfService = "Egnyte"
            cloudStorage = Egnyte(domain: "[Your Egnyte Domain]",
                             clientId: "[Your Egnyte API Key]",
                             clientSecret: "[Your Egnyte Shared Secret]",
                             redirectUri: "https://www.cloudrailauth.com/auth",
                             state: "state")
        }
        
        //Load Saved Service
        guard let result = UserDefaults.standard.value(forKey: typeOfService!) else {
            retriveFilesFoldersData(true)
            return
        }
        
        if !String(describing: result).isEmpty {
            CloudStorageLogic.loadAsString(cloudStorage: cloudStorage!, savedState: result as! String)
        }
        
        //Retrieve Data
        retriveFilesFoldersData(true)
    }
    
    // MARK: - Retrieve Data
    
    func reloadRetivedData() {
        retriveFilesFoldersData(true)
    }
    
    func retriveFilesFoldersData(_ showIndicator: Bool) {
        
        if refresh.isEnabled {
            self.tableView.isUserInteractionEnabled = false
        }
        
        if showIndicator {
            self.startActivityIndicator()
        }
        
        let backgroundQueue = DispatchQueue(label: "com.cloudrailapp.queue",
                                            qos: .background,
                                            target: nil)
        backgroundQueue.async {
            
            self.data = CloudStorageLogic.childrenOfFolderWithPath(cloudStorage: self.cloudStorage!,
                                                                   path: "/") as! [CRCloudMetaData]
            self.stopActivityIndicator()
            print(self.data)
            
            //Persistent data - Save Service
            let savedString = CloudStorageLogic.saveAsString(cloudStorage: self.cloudStorage!)
            
            if self.typeOfService != "" {
                UserDefaults.standard.set(savedString, forKey: self.typeOfService!)
            }
            
            DispatchQueue.main.async {
                self.tableView.isUserInteractionEnabled = true
                if self.refresh.isEnabled {
                    self.refresh.endRefreshing()
                }
                self.tableView.reloadData()
            }
            
        }
    }
    
    // MARK: - Upload File
    @IBAction func uploadFileAction(_ sender: Any) {
        
        let alertController = UIAlertController(title: "Upload File", message: "Upload Photos, Docs to Cloud Storage", preferredStyle: .actionSheet)
        
        let cameraButton = UIAlertAction(title: "Take a Photo", style: .default, handler: { (action) -> Void in
            self.picker.allowsEditing = false
            self.picker.sourceType = UIImagePickerControllerSourceType.camera
            self.picker.cameraCaptureMode = .photo
            self.picker.modalPresentationStyle = .fullScreen
            self.present(self.picker,animated: true,completion: nil)
        })
        
        let photoButton = UIAlertAction(title: "Choose a Photo", style: .default, handler: { (action) -> Void in
            
            self.picker.allowsEditing = false
            self.picker.sourceType = .photoLibrary
            self.picker.mediaTypes = UIImagePickerController.availableMediaTypes(for: .photoLibrary)!
            self.present(self.picker, animated: true, completion: nil)
            
        })
        
        let cancelButton = UIAlertAction(title: "Cancel", style: .cancel, handler: nil)
        
        alertController.addAction(cameraButton)
        alertController.addAction(photoButton)
        alertController.addAction(cancelButton)
        
        self.navigationController!.present(alertController, animated: true, completion: nil)
    }
    
    
    // MARK: - Search
    
    @IBAction func searchAction(_ sender: Any) {
        self.performSegue(withIdentifier: "SearchSegue", sender: nil)
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
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let cloudMetaData = self.data[indexPath.row]
        
        if Helpers.isImage(cloudMetaData) {
            self.performSegue(withIdentifier: "ImageSegue", sender: indexPath)
        } else {
            
            if Helpers.isFolder(cloudMetaData) {
                self.performSegue(withIdentifier: "SubFolderSegue", sender: indexPath)
            }
        }
    }
    
    override func tableView(_ tableView: UITableView, canEditRowAt indexPath: IndexPath) -> Bool {
        return true
    }
    
    override func tableView(_ tableView: UITableView, editActionsForRowAt indexPath: IndexPath) -> [UITableViewRowAction]? {
        
        let cloudMetaData = self.data[indexPath.row]
        
        let delete = UITableViewRowAction(style: .normal, title: "Delete") { action, index in
            
            let alertController = UIAlertController(title: "Delete", message: "Do you want to delete this file or folder?", preferredStyle: .alert)
            
            let deleteButton = UIAlertAction(title: "Delete", style: .destructive, handler: { (action) -> Void in
                
                if CloudStorageLogic.deleteFileWithPath(cloudStorage: self.cloudStorage!, path: cloudMetaData.path) {
                    self.retriveFilesFoldersData(false)
                }
                self.tableView.reloadData()
                
            })
            
            let cancelButton = UIAlertAction(title: "Cancel", style: .cancel, handler: { (action) -> Void in
                self.tableView.reloadData()
            })
            
            alertController.addAction(deleteButton)
            alertController.addAction(cancelButton)
            self.navigationController!.present(alertController, animated: true, completion: nil)
            
        }
        delete.backgroundColor = UIColor.FlatColor.Red.Valencia
        
        let share = UITableViewRowAction(style: .normal, title: "Share") { action, index in
            
            guard let link = CloudStorageLogic.shareLinkForFileWithPath(cloudStorage: self.cloudStorage!, path: cloudMetaData.path) else {
                return
            }
            
            UIPasteboard.general.string = link
            
            //self.view.makeToast("Link copied to clipboard", duration: 3.0, position: .bottom)
            self.tableView.reloadData()
        }
        share.backgroundColor = UIColor.FlatColor.Blue.Denim
        
        
        let download = UITableViewRowAction(style: .normal, title: "Download") { action, index in
            
            //self.view.makeToast("Downloading file", duration: 3.0, position: .top)
            let backgroundQueue = DispatchQueue(label: "com.cloudrail.queue",
                                                qos: .background,
                                                target: nil)
            backgroundQueue.async {
                self.tableView.reloadData()
                if let result = CloudStorageLogic.downloadFileWithPath(cloudStorage:self.cloudStorage!, path: cloudMetaData.path) {
                    Helpers.downloadFileToDoc(inputStream: result, name: cloudMetaData.name)
                }
            }
            
            //self.view.makeToast("File saved", duration: 2.0, position: .top)
        }
        download.backgroundColor = UIColor.FlatColor.Green.ChateauGreen
        
        if !Helpers.isFolder(cloudMetaData) && !Helpers.isImage(cloudMetaData) {
            return [download, share, delete]
        } else {
            return [share, delete]
        }
        
    }
    
    // MARK: - Image Picker
    
    internal func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [String : Any]) {
        
        self.dismiss(animated: true, completion: nil)
        
        //Always run this on background thread
        //self.view.makeToast("Uploading image", duration: 3.0, position: .top)
        let backgroundQueue = DispatchQueue(label: "com.cloudrailapp.queue",
                                            qos: .background,
                                            target: nil)
        backgroundQueue.async {
            
            let chosenImage = info[UIImagePickerControllerOriginalImage] as! UIImage
            if let data:Data = UIImageJPEGRepresentation(chosenImage,1) {
                let inputStream = InputStream.init(data: data)
                
                //Randome image name
                let path = "/\(Helpers.randomImageName())"
                
                if CloudStorageLogic.uploadFileToPath(cloudStorage: self.cloudStorage!, path: path, inputStream: inputStream, size: data.count) {
                    //self.view.makeToast("Image uploaded", duration: 2.0, position: .top)
                    self.retriveFilesFoldersData(false)
                }
            }
        }
    }
    
    func imagePickerController(picker: UIImagePickerController, didFinishPickingImage image: UIImage!, editingInfo: [NSObject : Any]!) {
        self.dismiss(animated: true, completion: nil)
    }
    
    func imagePickerControllerDidCancel(_ picker: UIImagePickerController) {
        self.dismiss(animated: true, completion: nil)
    }
    
    // MARK: - Navigation
    
    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        
        if segue.identifier == "ImageSegue" {
            
            let indexPath = (sender as! IndexPath)
            let cloudMetaData = self.data[indexPath.row]
            
            let details = (segue.destination as! ImageViewController)
            details.cloudStorage = self.cloudStorage
            details.cloudMetaData = cloudMetaData
        } else if segue.identifier == "SubFolderSegue" {
            
            let indexPath = (sender as! IndexPath)
            let cloudMetaData = self.data[indexPath.row]
            
            let details = (segue.destination as! SubFoldersTableViewController)
            details.cloudStorage = self.cloudStorage
            details.path = cloudMetaData.path
        } else if segue.identifier == "SearchSegue" {
            let details = (segue.destination as! SearchTableViewController)
            details.cloudStorage = self.cloudStorage
        }
    }
    
}
