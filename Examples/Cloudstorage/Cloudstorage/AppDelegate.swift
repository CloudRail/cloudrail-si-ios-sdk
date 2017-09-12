//
//  AppDelegate.swift
//  Cloudstorage
//
//  Created by Mujtaba Alam on 06.06.17.
//  Copyright © 2017 CloudRail. All rights reserved.
//

import UIKit
import CloudrailSI

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?
    //Get your free key: https://cloudrail.com/signup
    
    static let kCloudRailAPIKey = "59ad578aded6ef25c77d17cc"
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        
        CRCloudRail.setAppKey(AppDelegate.kCloudRailAPIKey)
        
        UINavigationBar.appearance().barTintColor = UIColor(red: 226.0/255.0, green: 122.0/255.0, blue: 63.0/255.0, alpha: 1.0)
        UINavigationBar.appearance().isTranslucent = false
        UINavigationBar.appearance().tintColor = UIColor.white
        UINavigationBar.appearance().titleTextAttributes = [NSForegroundColorAttributeName : UIColor.white]
        
        return true
    }
    
    func applicationWillResignActive(_ application: UIApplication) {
        // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
        // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
    }

    func applicationDidEnterBackground(_ application: UIApplication) {
        // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
        // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    }

    func applicationWillEnterForeground(_ application: UIApplication) {
        // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
    }

    func applicationDidBecomeActive(_ application: UIApplication) {
        // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    }

    func applicationWillTerminate(_ application: UIApplication) {
        // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    }

    func application(_ application: UIApplication, open url: URL, sourceApplication: String?, annotation: Any) -> Bool {
        
        if (sourceApplication == "com.apple.SafariViewService") {
            // Here we pass the response to the SDK which will automatically
            // complete the authentication process.
            NotificationCenter.default.post(name: NSNotification.Name(rawValue: "kCloseSafariViewControllerNotification"), object: url)
            return true
        }
        return true
    }

}

