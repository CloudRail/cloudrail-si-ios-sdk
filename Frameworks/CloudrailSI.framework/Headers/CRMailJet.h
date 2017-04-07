
#import <Foundation/Foundation.h>
#import "CREmailProtocol.h"
#import "CRAdvancedRequestSupporterProtocol.h"

@interface CRMailJet : NSObject <CREmailProtocol, CRAdvancedRequestSupporterProtocol>
@property (weak, nonatomic) id target;


-(instancetype)initWithClientId:(NSString *)clientId clientSecret:(NSString *)clientSecret;


-(void)useAdvancedAuthentication;
-(NSString *) saveAsString;
-(void) loadAsString:(NSString*) savedState;

@end
