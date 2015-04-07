//
//  AMWaveTransition.h
//  AMWaveTransition
//
//  Created by Andrea on 11/04/14.
//  Copyright (c) 2014 Fancy Pixel. All rights reserved.
//

@import UIKit;

@protocol AMWaveTransitioning <NSObject>

- (NSArray*)visibleCells;

@end

typedef NS_ENUM(NSInteger, AMWaveTransitionType) {
    AMWaveTransitionTypeSubtle,   //敏感的
    AMWaveTransitionTypeNervous,  //紧张的
    AMWaveTransitionTypeBounce    //弹跳
};

typedef NS_ENUM(NSInteger, AMWaveInteractiveTransitionType) {
    AMWaveTransitionEdgePan,
    AMWaveTransitionFullScreenPan,
};

@interface AMWaveTransition : NSObject <UIViewControllerAnimatedTransitioning>

/**-----------------------------------------------------------------------------
 * @name AMWaveTransition
 *
 * <UIViewControllerAnimatedTransitioning>
 * Adopt the UIViewControllerAnimatedTransitioning protocol in objects that implement the animations for a custom view controller transition. The methods in this protocol let you define an animator object, which creates the animations for transitioning a view controller on or off screen in a fixed amount of time. The animations you create using this protocol must not be interactive. To create interactive transitions, you must combine your animator object with another object that controls the timing of your animations.
 * -----------------------------------------------------------------------------
 */

/** New transition 新建一个形变对象 ,此对象作用是 处理导航控制器的形变操作.
 * 
 * Returns a AMWaveTransition instance.
 *
 * @param operation The UINavigationControllerOperation that determines the transition type (push or pop)
 * operation 当导航控制器push或者pop的时候 创建形变对象
 */
+ (instancetype)transitionWithOperation:(UINavigationControllerOperation)operation;

/** New transition
 *
 * Returns a AMWaveTransition instance.
 *
 * @param operation The UINavigationControllerOperation that determines the transition type (push or pop)
 * @param type The transition type  transition: 转场
 */
+ (instancetype)transitionWithOperation:(UINavigationControllerOperation)operation andTransitionType:(AMWaveTransitionType)type;

/** New transition
 *
 * Returns a AMWaveTransition instance.
 *
 * @param operation The UINavigationControllerOperation that determines the transition type (push or pop)
 */
- (instancetype)initWithOperation:(UINavigationControllerOperation)operation;

/** New transition
 *
 * Returns a AMWaveTransition instance.
 *
 * @param operation The UINavigationControllerOperation that determines the transition type (push or pop)
 * @param type The transition type
 */
- (instancetype)initWithOperation:(UINavigationControllerOperation)operation andTransitionType:(AMWaveTransitionType)type;

/** Attach the interactive gesture  附加交互手势
 *
 * Attach the interactive gesture to the navigation controller. This will pop the current view controller when the user swipes from the left edge.
 * Make sure to detach the gesture when done.
 *
 * @param navigationController The UINavigationController that holds the current view controller
 */
- (void)attachInteractiveGestureToNavigationController:(UINavigationController *)navigationController;

/** Detach the interactive gesture  分离交互手势
 *
 * Detaches the interactive gesture.
 */
- (void)detachInteractiveGesture;

/**-----------------------------------------------------------------------------
 * @name AMWaveTransition Properties
 * -----------------------------------------------------------------------------
 */

/** Operation type
 *
 * Sets the operation type (push or pop)
 */
@property (assign, nonatomic) UINavigationControllerOperation operation;

/** Transition type
 *
 * Sets the transition style
 */
@property (assign, nonatomic) AMWaveTransitionType transitionType;

/** Animation duration
 *
 * Sets the duration of the animation. The whole duration accounts for the maxDelay property.
 */
@property (assign, nonatomic) CGFloat duration;

/** Maximum animation delay
 *
 * Sets the max delay that a cell will wait beofre animating.
 */
@property (assign, nonatomic) CGFloat maxDelay;

/** Inset between view controllers
 *
 * Sets the inset between view controllers. Defaults to 20 points.
 */
@property (assign, nonatomic) CGFloat viewControllersInset;

/** Alpha animation with interactive transition
 *
 * Turn on/off alpha animation with interactive transition. Defaults to NO.
 */
@property (assign, nonatomic) BOOL animateAlphaWithInteractiveTransition;

/** Interactive transition type
 *
 * Sets interactive transition type (edge or fullscreen). Defaults to edge. 
 */
@property (assign, nonatomic) AMWaveInteractiveTransitionType interactiveTransitionType;

@end
