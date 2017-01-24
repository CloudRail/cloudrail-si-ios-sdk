
#import <Foundation/Foundation.h>
#import "CRBusinessCloudStorageProtocol.h"

@interface CRRackspace : NSObject <CRBusinessCloudStorageProtocol>
@property (weak, nonatomic) id target;

-(instancetype)initWithUsername:(NSString *)username apiKey:(NSString *)apiKey region:(NSString *)region;



-(void)useAdvancedAuthentication;

@end
