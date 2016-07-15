//
//  CloudStorageViewController.m
//  CloudRail-SI-iOS
//
//  Created by Felipe Cesar on 15/06/16.
//  Copyright © 2016 Felipe Cesar. All rights reserved.
//

#import "CloudStorageViewController.h"
#import <MobileCoreServices/MobileCoreServices.h>
@interface CloudStorageViewController () <UIImagePickerControllerDelegate, UINavigationControllerDelegate,UIPopoverControllerDelegate>

@end

@implementation CloudStorageViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
  
  NSDictionary * authDic = @{
                   
                   @"dropboxKey" : @"38nu3lwdvyaqs78",
                   @"dropboxSecret" : @"c95g0wfkdv6ua2d",
                   
                   @"googledriveKey" : @"871545970580-rsfohjd4g7ge0j3bmue6vc3t1t4if22c.apps.googleusercontent.com",
                   @"googledriveSecret" : @"MpVwm1MK2lgKQCP2T6BjVn8c",
                   
                   @"boxKey" : @"qnskodzvd2naq16xowc40t43fug2848n",
                   @"boxSecret" : @"cQE7Sf9DzZqChjvCTxIMTp3ye6hynhTd",
                   
                   @"onedriveKey" : @"000000004018F12F",
                   @"onedriveSecret" : @"lGQPubehDO6eklir1GQmIuCPFfzwihMo",
                   
                   
                   @"facebookKey" : @"636472443170383",
                   @"facebookSecret" : @"572d1e670d481820e6de7525cfec757f",
                   
                   };
  
  NSString * key = [[self.serviceName lowercaseString] stringByAppendingString:@"Key"];
  NSString * secret = [[self.serviceName lowercaseString] stringByAppendingString:@"Secret"];
  
  self.serviceName = [@"CR" stringByAppendingString:self.serviceName];
  Class cl = NSClassFromString(self.serviceName);
  self.service = [(id<CRCloudStorageProtocol>)[cl alloc] initWithClientId:authDic[key] clientSecret:authDic[secret] redirectUri:@"https://www.cloudrailauth.com/auth" state:@"CR123"];
  
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}



- (IBAction)uploadDefault:(id)sender {
  UIImage * image = [UIImage imageNamed:@"futurama.jpg"];
  
  NSData * imageData = UIImageJPEGRepresentation(image, 1);
  NSInputStream * inputStream = [NSInputStream inputStreamWithData:imageData];
  [self.service uploadFileToPath:@"/futurama.jpg" withStream:inputStream size:imageData.length overwrite:YES];
}

-(void)imagePickerController:(UIImagePickerController *)picker
didFinishPickingMediaWithInfo:(NSDictionary *)info
{
  [picker dismissViewControllerAnimated:YES completion:^{
    
    dispatch_async(dispatch_get_global_queue( DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^(void){
      
      //Background Thread to not block the app while authenticating
      UIImage * image = info[UIImagePickerControllerEditedImage];
      
      NSData * imageData = UIImageJPEGRepresentation(image, 1);
      NSInputStream * inputStream = [NSInputStream inputStreamWithData:imageData];
      [self.service uploadFileToPath:@"/futurama.jpg" withStream:inputStream size:imageData.length overwrite:YES];

    });
    
  }];
  
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (IBAction)uploadFromCamera:(id)sender {
  
  if ([UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera])
  {
    
    UIImagePickerController *picker = [[UIImagePickerController alloc] init];
    picker.delegate = self;
    picker.allowsEditing = YES;
    picker.sourceType = UIImagePickerControllerSourceTypeCamera;
    
    [self presentViewController:picker animated:YES completion:NULL];
  }
  else
  {
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error to access Camera (Simulators Cant use this button!!)"
                                                    message:@""
                                                   delegate:nil
                                          cancelButtonTitle:@"OK"
                                          otherButtonTitles:nil];
    [alert show];
    
  }
}
- (IBAction)uploadFromCameraRoll:(id)sender {

  
  
  UIImagePickerController *picker = [[UIImagePickerController alloc] init];
  picker.delegate = self;
  picker.allowsEditing = YES;
  picker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
  
  [self presentViewController:picker animated:YES completion:NULL];
}


@end
