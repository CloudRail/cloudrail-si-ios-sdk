
#import <Foundation/Foundation.h>

#import "PaymentProtocol.h"




@interface PayPal : NSObject <PaymentProtocol>


-(instancetype)initWithUseSandbox:(BOOL)useSandbox clientId: (NSString *)clientId clientSecret: (NSString *)clientSecret;
@end
