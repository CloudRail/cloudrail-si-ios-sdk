//
//  PaymentProtocol.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 20/06/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Charge.h"
#import "Refund.h"
#import "Subscription.h"
#import "SubscriptionPlan.h"

/**
 * A simple interface for managing payment tasks.
 */
@protocol PaymentProtocol <NSObject>


/**
 * Charges a credit card and returns a charge resource.
 *
 * @param amount A positive integer in the smallest currency unit (e.g. cents)
 *      representing how much to charge the credit card.
 * @param currency A three-letter ISO code for currency.
 * @param source The credit card to be charged.
 * @return A charge resource representing the newly created payment.
 * @throws IllegalArgumentException Is thrown if any of the parameters is null, amount is
 *      less than 0 or currency is not a valid three-letter currency code.
 * @throws AuthenticationException Is thrown if the provided credentials are invalid.
 * @throws HttpException Is thrown if the communication with a services fails.
 *      More detail is provided in the error message.
 */
-(Charge *) createChargeWithAmount: (NSNumber *) amount
                currency: (NSString *) currency
                  source: (CreditCard *) source ;
/**
 * Returns information about an existing charge. Mostly used to get an update
 * on the status of the charge.
 *
 * @param id The ID of the charge.
 * @return A charge resource for the provided ID.
 * @throws IllegalArgumentException Is thrown if id is null.
 * @throws NotFoundException Is thrown if there is now charge with that ID.
 * @throws AuthenticationException Is thrown if the provided credentials are invalid.
 * @throws HttpException Is thrown if the communication with a services fails.
 *      More detail is provided in the error message.
 */
-(Charge *) chargeWithIdentifier: (NSString *) id ;

/**
 * Receive a list of charges within a specified timeframe.
 *
 * @param from Timestamp representing the start date for the list.
 * @param to Timestamp representing the end date for the list.
 * @param creditCard Optionally the credit card information so it can be listed all the charges of this specific credit card.
 * @return List of charge resources.
 * @throws IllegalArgumentException Is thrown if from or to is null, from or to is less than 0, from
 *      is greater than to or to is greater than the current date.
 * @throws AuthenticationException Is thrown if the provided credentials are invalid.
 * @throws HttpException Is thrown if the communication with a services fails.
 *      More detail is provided in the error message.
 */
-(NSMutableArray<Charge *> *) listChargesFrom: (NSNumber *) from
                                       to: (NSNumber *) to
                               creditCard: (CreditCard *) creditCard ;
/**
 * Refund a previously made charge.
 *
 * @param id The ID of the charge to be refunded.
 * @return A refund resource.
 * @throws IllegalArgumentException Is thrown if id is null.
 * @throws NotFoundException Is thrown if there is now charge with that ID.
 * @throws AuthenticationException Is thrown if the provided credentials are invalid.
 * @throws HttpException Is thrown if the communication with a services fails.
 *      More detail is provided in the error message.
 */
-(Refund *) refundChargeWithIdentifier: (NSString *) id ;

/**
 * Refund a specified amount from a previously made charge.
 *
 * @param id The ID of the charge to be refunded.
 * @param amount The amount that shall be refunded.
 * @return A refund resource.
 * @throws IllegalArgumentException Is thrown if any of the parameters is null or lower/equals than 0.
 * @throws NotFoundException Is thrown if there is now charge with that ID.
 * @throws AuthenticationException Is thrown if the provided credentials are invalid.
 * @throws HttpException Is thrown if the communication with a services fails.
 *      More detail is provided in the error message.
 */
-(Refund *) partiallyRefundChargeWithIdentifier: (NSString *) id
amount: (NSNumber *) amount ;
/**
 * Returns information about an existing refund. Mostly used to get an update
 * on the status of the refund.
 *
 * @param id The ID of the refund.
 * @return A refund resource for the provided ID.
 * @throws IllegalArgumentException Is thrown if id is null.
 * @throws NotFoundException Is thrown if there is now refund with that ID.
 *      More detail is provided in the error message.
 */
-(NSMutableArray<Refund *> *) refundsForChargeWithIdentifier: (NSString *) id ;

/**
 * Returns information about the refunds for a specific charge.
 *
 * @param id The ID of the charge.
 * @return A refund resource for the provided charge.
 * @throws IllegalArgumentException Is thrown if id is null.
 * @throws NotFoundException Is thrown if there is now charge with that ID or the charge has not
 *      been refunded.
 * @throws AuthenticationException Is thrown if the provided credentials are invalid.
 * @throws HttpException Is thrown if the communication with a services fails.
 *      More detail is provided in the error message.
 */
-(Refund *) refundWithIdentifier: (NSString *) id ;

/**
 * Creates a subscription plan which is required to use subscription based payments.
 * The result of this method can be used together with 'createSubscription' in
 * order to subscribe someone to your subscription plan.
 *
 * @param name The name for the subscription plan.
 * @param amount The amount that is charged on a regular basis. A positive integer
 *      in the smallest currency unit (e.g. cents).
 * @param currency A three-letter ISO code for currency.
 * @param description A description for this subscription plan.
 * @param interval Specifies the billing frequency together with interval_count.
 *      Allowed values are: day, week, month or year.
 * @param interval_count Specifies the billing frequency together with interval.
 *      For example: interval_count = 2 and interval = "week" -> Billed every
 *      two weeks.
 * @return Returns the newly created subscription plan resource.
 * @throws IllegalArgumentException Is thrown if any of the parameters is null
 *      or lower/equal than 0, currency is not a three-letter
 *      currency code, interval is not one of the allowed values or amount is
 *      less/equal than 0.
 * @throws AuthenticationException Is thrown if the provided credentials are invalid.
 * @throws HttpException Is thrown if the communication with a services fails.
 *      More detail is provided in the error message.
 */
-(SubscriptionPlan *) createSubscriptionPlanWithName: (NSString *) name
                                              amount: (NSNumber *) amount
                                            currency: (NSString *) currency
                                         description: (NSString *) description
                                           Longerval: (NSString *) Longerval
                                     Longerval_count: (NSNumber *) Longerval_count ;


/**
 * Returns a list of all existing subscription plans.
 *
 * @return List of subscription plans.
 * @throws AuthenticationException Is thrown if the provided credentials are invalid.
 * @throws HttpException Is thrown if the communication with a services fails.
 *      More detail is provided in the error message.
 */
-(NSMutableArray<SubscriptionPlan *> *) listSubscriptionPlans;

/**
 * Subscribes a new customer to an existing subscription plan.
 *
 * @param planID The ID of the subscription plan.
 * @param name A name for the subscription.
 * @param description A description for the subscription.
 * @param creditCard The customer that shall be subscribed.
 * @return The newly created subscription resource.
 * @throws IllegalArgumentException Is thrown if planID, name, description or
 *      payer is null.
 * @throws NotFoundException Is thrown if there is no subscription plan with
 *      the passed ID.
 * @throws AuthenticationException Is thrown if the provided credentials are invalid.
 * @throws HttpException Is thrown if the communication with a services fails.
 *      More detail is provided in the error message.
 */
-(Subscription *) createSubscriptionWithPlanID: (NSString *) planID
                                          name: (NSString *) name
                                   description: (NSString *) description
                                        source: (CreditCard *) source ;

/**
 * Cancel an active subscription.
 *
 * @param id ID of the subscription that should be canceled.
 * @throws IllegalArgumentException Is thrown if id is null.
 * @throws NotFoundException Is thrown if there is no subscription with the
 *      provided ID.
 * @throws AuthenticationException Is thrown if the provided credentials are invalid.
 * @throws HttpException Is thrown if the communication with a services fails.
 *      More detail is provided in the error message.
 */
-(void) cancelSubscriptionWithIdentifier: (NSString *) id ;


@end
