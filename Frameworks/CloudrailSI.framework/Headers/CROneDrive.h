
#import <Foundation/Foundation.h>
#import "CRCloudStorageProtocol.h"

@interface CROneDrive : NSObject <CRCloudStorageProtocol>

-(instancetype)initWithClientId:(NSString *)clientID clientSecret:(NSString *)clientSecret redirectUri:(NSString *)redirectUri state:(NSString *)state;

//Specific for CloudStorage Interface
-(instancetype)initWithClientId:(NSString *)clientId clientSecret: (NSString *)clientSecret;

@end
