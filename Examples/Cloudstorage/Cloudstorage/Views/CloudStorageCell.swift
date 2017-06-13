//
//  CloudStorageCell.swift
//  Cloudstorage
//
//  Created by Mujtaba Alam on 06.06.17.
//  Copyright © 2017 CloudRail. All rights reserved.
//

import UIKit

class CloudStorageCell: UITableViewCell {

    @IBOutlet weak var sideImgView: UIImageView!
    @IBOutlet weak var sideLbl: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        sideImgView.setRadius(8)
    }
    
    var model: CloudStorageModel! {
        didSet {
            self.updateUI()
        }
    }
    
    func updateUI() {
        sideImgView.image = model.image
        sideLbl.text = model.cloudStorageTitle
    }
    
}
