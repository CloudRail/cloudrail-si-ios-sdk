
#import <Foundation/Foundation.h>
#import "CREmailProtocol.h"

@interface CRSendGrid : NSObject <CREmailProtocol>
@property (weak, nonatomic) id target;

- (instancetype)initWithApiKey:(NSString *)apiKey;



@end
