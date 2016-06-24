
#import <Foundation/Foundation.h>

#import "PaymentProtocol.h"




@interface Stripe : NSObject <PaymentProtocol>


-(instancetype)initWithSecretKey:(NSString *)secretKey;
@end
