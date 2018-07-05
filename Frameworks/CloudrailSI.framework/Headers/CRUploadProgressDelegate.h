//
//  CRUploadProgressDelegate.h
//  CloudrailSI
//
//  Created by Patrick Stoklasa on 20.02.17.
//  Copyright © 2017 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CRUploadProgressDelegate <NSObject>

-(void) didUploadBytes:(long) bytes;
@optional
-(BOOL) didCancelUpload;
@end
