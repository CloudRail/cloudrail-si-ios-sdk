
#import <Foundation/Foundation.h>
#import "CRPaymentProtocol.h"

@interface CRPayPal : NSObject <CRPaymentProtocol>
@property (weak, nonatomic) id target;

-(instancetype)initWithUseSandbox:(BOOL)useSandbox clientId:(NSString *)clientId clientSecret:(NSString *)clientSecret;



-(void)useAdvancedAuthentication;

@end
