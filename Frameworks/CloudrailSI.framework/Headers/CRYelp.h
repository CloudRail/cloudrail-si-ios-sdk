
#import <Foundation/Foundation.h>
#import "CRPointsOfInterestProtocol.h"

@interface CRYelp : NSObject <CRPointsOfInterestProtocol>
@property (weak, nonatomic) id target;


-(instancetype)initWithApiKey:(NSString *)apiKey;


-(void)useAdvancedAuthentication;
-(NSString *) saveAsString;
-(void) loadAsString:(NSString*) savedState;

@end
