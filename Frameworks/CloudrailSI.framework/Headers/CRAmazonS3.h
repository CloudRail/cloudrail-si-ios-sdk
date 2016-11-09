
#import <Foundation/Foundation.h>
#import "CRBusinessCloudStorageProtocol.h"

@interface CRAmazonS3 : NSObject <CRBusinessCloudStorageProtocol>
@property (weak, nonatomic) id target;

-(instancetype)initWithAccessKeyId:(NSString *)accessKeyId secretAccessKey:(NSString *)secretAccessKey region:(NSString *)region;



@end
