
#import <Foundation/Foundation.h>
#import "CRCloudStorageProtocol.h"

@interface CREgnyte : NSObject <CRCloudStorageProtocol>
@property (weak, nonatomic) id target;

-(instancetype)initWithDomain:(NSString *)domain clientId:(NSString *)clientId clientSecret:(NSString *)clientSecret redirectUri:(NSString *)redirectUri state:(NSString *)state;

//Specific for CloudStorage Interface
-(instancetype)initWithClientId:(NSString *)clientId clientSecret: (NSString *)clientSecret;

@end
