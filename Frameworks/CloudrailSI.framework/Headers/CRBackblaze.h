
#import <Foundation/Foundation.h>
#import "CRBusinessCloudStorageProtocol.h"

@interface CRBackblaze : NSObject <CRBusinessCloudStorageProtocol>
@property (weak, nonatomic) id target;

-(instancetype)initWithAccountID:(NSString *)accountID appKey:(NSString *)appKey;



@end
