
#import <Foundation/Foundation.h>

#import "CRPaymentProtocol.h"




@interface CRPayPal : NSObject <CRPaymentProtocol>

-(instancetype)initWithUseSandbox:(BOOL)useSandbox clientId:(NSString *)clientId clientSecret:(NSString *)clientSecret;
@end
