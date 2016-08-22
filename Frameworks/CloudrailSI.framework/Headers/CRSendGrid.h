
#import <Foundation/Foundation.h>
#import "CREmailProtocol.h"

@interface CRSendGrid : NSObject <CREmailProtocol>

-(instancetype)initWithApiKey:(NSString *)apiKey;



@end
