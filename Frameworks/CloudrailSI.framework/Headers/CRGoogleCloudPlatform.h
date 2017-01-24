
#import <Foundation/Foundation.h>
#import "CRBusinessCloudStorageProtocol.h"

@interface CRGoogleCloudPlatform : NSObject <CRBusinessCloudStorageProtocol>
@property (weak, nonatomic) id target;

-(instancetype)initWithClientEmail:(NSString *)clientEmail privateKey:(NSString *)privateKey projectId:(NSString *)projectId;



-(void)useAdvancedAuthentication;

@end
