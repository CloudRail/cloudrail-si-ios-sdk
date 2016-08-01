
#import <Foundation/Foundation.h>
#import "CRPaymentProtocol.h"

@interface CRStripe : NSObject <CRPaymentProtocol>

-(instancetype)initWithSecretKey:(NSString *)secretKey;



@end
