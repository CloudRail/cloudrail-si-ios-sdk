
#import <Foundation/Foundation.h>
#import "CRBusinessCloudStorageProtocol.h"

@interface CRMicrosoftAzure : NSObject <CRBusinessCloudStorageProtocol>
@property (weak, nonatomic) id target;

- (instancetype)initWithAccountName:(NSString *)accountName accessKey:(NSString *)accessKey;



@end
