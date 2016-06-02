
#import <Foundation/Foundation.h>

#import "CloudStorageProtocol.h"




@interface GoogleDrive : NSObject <CloudStorageProtocol>

-(void) initializeServiceCode;
-(instancetype)initWithClientId:(NSString *) clientId clientSecret:(NSString *) clientSecret;



@end
