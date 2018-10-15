# box2d manual

## Chapter 1 Introduction

## Chapter 2 Hello Box2D

## Chapter 3 Common

## Chapter 4 Collision Module

## Chapter 5 Dynamics Module

## Chapter 6 Bodies  
+   夹具  
+	刚体  
+	接触  
+	关节  
+	世界  
+	监听者  

你可以将力(forces)、扭矩(torques)、冲量(impulses)应用到物体上。  
有三种物体类型: static、kinematic和dynamic。

**注意**  
不要在原点创建物体后再移动它。如果你在原点上同时创建了几个物体，性能会很差。


+ 休眠参数  
    ```
    bodyDef.allowSleep = true;
    bodyDef.awake = true;
    ```
+ 固定旋转  
    ```
    bodyDef.fixedRotation = true;
    ```
+ 子弹  
    ```
    bodyDef.bullet = true;
    ```
+ 活动状态 
    ```
    以创建一个非活动的物体，之后再激活它。
    bodyDef.active = true;
    ```
+ 用户数据  
 你应该保持一致性，所有物体的用户数据都指向相同的对象类型。
    ```
    b2BodyDef bodyDef;
    bodyDef.userData = &myActor;
    ```

+ 位置和速度  
你可以访问一个物体的位置和旋转角，这在你渲染相关游戏角色时很常用。
点可能在正方形的一个角点，而质心却位于正方形的中心点。
    ```
    const b2Vec2& GetWorldCenter() const;
    const b2Vec2& GetLocalCenter() const;
    ```

## Chapter 7 
 fixture具有下列属性：
+	关联的形状
+	broad-phase代理
+	密度(density)、摩擦(friction)和恢复(restitution)
+	碰撞筛选标记(collision filtering flags)
+	指向父物体的指针
+	用户数据
+	传感器标记(sensor flag)

### 7.2 创建夹具
要创建fixture，先要创始化一个fixture定义，并将定义传到父物体中。
```
b2FixtureDef fixtureDef;
fixtureDef.shape = &myShape;
fixtureDef.density = 1.0f;
b2Fixture* myFixture = myBody->CreateFixture(&fixtureDef);
```
+ 密度
    ```
    fixture->SetDensity(5.0f);
    body->ResetMassData();
    ```
+ 摩擦  
    Box2D支持静摩擦和动摩擦，两者都使用相同的参数。摩擦在Box2D中会被精确地模拟，摩擦力的强度与正交力 (称之为库仑摩擦)成正比。
+ 恢复  
    恢复可以使对象弹起。
    ```
    float32 restitution;
    restitution = b2Max(fixtureA->restitution, fixtureB->restitution);
    ```
+ 筛选  
   Box2D通过种群和分组来支持这样的碰撞筛选。  
   ```
    fixture1Def.filter.groupIndex = 2;
    fixture2Def.filter.groupIndex = 2;
    fixture3Def.filter.groupIndex = -8;
    fixture4Def.filter.groupIndex = -8;
   ```
   你可以使用b2Fixture::GetFilterData 和b2Fixture::SetFilterData来访问和设置已存在的fixture的b2FilterData结构。注意就算修改了筛选数据，到下一个时间步 为止，现在的接触并不会被增加或删除（参见world类）。

### 7.3 传感器  
有时候游戏逻辑需要判断两个fixture是否相交，而不想有碰撞反应。这可以通过传感器(sensor)来完成。

只有至少一个物体是dynamic的，传感器才会产生接触事件，而kinematic 与kinematic 、kinematic 与static ，或者static 与static 之间都不会产生接触事件。  
传感器不会生成接触点。这里有两种方法得到传感器的状态：
1.	b2Contact::IsTouching
2.	b2ContactListener::BeginContact 和 EndContact

## Chapter 8 Joints

### 8.3 关节工厂
```csharp
b2RevoluteJointDef jointDef;
jointDef.bodyA = myBodyA;
jointDef.bodyB = myBodyB;
jointDef.anchorPoint = myBodyA->GetCenterPosition();
b2RevoluteJoint* joint = (b2RevoluteJoint*)myWorld->CreateJoint(&jointDef);
... do stuff ...
myWorld->DestroyJoint(joint);
joint = NULL;
```
要使关节弹性，可以调节一下定义中的两个常数：频率(frequency)和阻尼率(damping ratio)。将频率想象成谐振子(harmonic oscillator，比如吉他弦)振动的快慢。频率使用单位赫兹(Hertz)来指定。典型情况下，关节频率要小于时间步(time step)频率的一半。比如每秒执行60次时间步， 距离关节的频率就要小于30赫兹。这样做的理由可以参考Nyquist频率理论。
阻尼率无单位，典型是在0到1之间，也可以更大。1是阻尼率的临界值，当阻尼率为1时，没有振动。


### 8.8 滑轮关节
length1 + length2 == constant

length1 + ratio * length2 == constant

## Chapter 9 接触


## Chapter 10 世界类

