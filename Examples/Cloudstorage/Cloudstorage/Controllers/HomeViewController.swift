//
//  HomeViewController.swift
//  Cloudstorage
//
//  Created by Mujtaba Alam on 06.06.17.
//  Copyright © 2017 CloudRail. All rights reserved.
//

import UIKit

class HomeViewController: UIViewController {

    @IBOutlet weak var menuBarButton: UIBarButtonItem!
    
    var someID:String?
    
    // MARK: - Life Cycle
    
    override func viewDidLoad() {
        super.viewDidLoad()
        Helpers.showSideMenu(menuBarButton, self)
    }
    
    // MARK: - Aciton Methos
    
    @IBAction func linkAction(_ sender: Any) {
        if let url = URL(string: "https://cloudrail.com") {
            UIApplication.shared.openURL(url)
        }
    }
    
}
