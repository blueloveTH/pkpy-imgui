from linalg import vec2, vec3, vec2i, vec3i, mat3x3
from typing import overload
intptr = int

class b2Version:
    major: int #  (int)
    minor: int #  (int)
    revision: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, major: int, minor: int, revision: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2Version': ...
    
class b2Vec2:
    x: float #  (float)
    y: float #  (float)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, x: float, y: float): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2Vec2': ...
    
class b2Rot:
    c: float #  (float)
    s: float #  (float)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, c: float, s: float): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2Rot': ...
    
class b2Transform:
    p: vec2 #  (b2Vec2)
    q: b2Rot #  (b2Rot)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, p: vec2, q: b2Rot): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2Transform': ...
    
class b2Mat22:
    cx: vec2 #  (b2Vec2)
    cy: vec2 #  (b2Vec2)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, cx: vec2, cy: vec2): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2Mat22': ...
    
class b2AABB:
    lowerBound: vec2 #  (b2Vec2)
    upperBound: vec2 #  (b2Vec2)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, lowerBound: vec2, upperBound: vec2): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2AABB': ...
    
class b2RayCastInput:
    origin: vec2 #  (b2Vec2)
    translation: vec2 #  (b2Vec2)
    maxFraction: float #  (float)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, origin: vec2, translation: vec2, maxFraction: float): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2RayCastInput': ...
    
class b2ShapeCastInput:
    points: intptr #  (const b2Vec2*)
    count: int #  (int)
    radius: float #  (float)
    translation: vec2 #  (b2Vec2)
    maxFraction: float #  (float)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, points: intptr, count: int, radius: float, translation: vec2, maxFraction: float): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2ShapeCastInput': ...
    
class b2CastOutput:
    normal: vec2 #  (b2Vec2)
    point: vec2 #  (b2Vec2)
    fraction: float #  (float)
    iterations: int #  (int)
    hit: bool #  (_Bool)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, normal: vec2, point: vec2, fraction: float, iterations: int, hit: bool): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2CastOutput': ...
    
class b2MassData:
    mass: float #  (float)
    center: vec2 #  (b2Vec2)
    rotationalInertia: float #  (float)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, mass: float, center: vec2, rotationalInertia: float): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2MassData': ...
    
class b2Circle:
    center: vec2 #  (b2Vec2)
    radius: float #  (float)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, center: vec2, radius: float): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2Circle': ...
    
class b2Capsule:
    center1: vec2 #  (b2Vec2)
    center2: vec2 #  (b2Vec2)
    radius: float #  (float)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, center1: vec2, center2: vec2, radius: float): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2Capsule': ...
    
class b2Polygon:
    vertices: intptr #  (const b2Vec2*)
    normals: intptr #  (const b2Vec2*)
    centroid: vec2 #  (b2Vec2)
    radius: float #  (float)
    count: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, vertices: intptr, normals: intptr, centroid: vec2, radius: float, count: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2Polygon': ...
    
class b2Segment:
    point1: vec2 #  (b2Vec2)
    point2: vec2 #  (b2Vec2)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, point1: vec2, point2: vec2): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2Segment': ...
    
class b2SmoothSegment:
    ghost1: vec2 #  (b2Vec2)
    segment: b2Segment #  (b2Segment)
    ghost2: vec2 #  (b2Vec2)
    chainId: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, ghost1: vec2, segment: b2Segment, ghost2: vec2, chainId: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2SmoothSegment': ...
    
class b2Hull:
    points: intptr #  (const b2Vec2*)
    count: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, points: intptr, count: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2Hull': ...
    
class b2SegmentDistanceResult:
    closest1: vec2 #  (b2Vec2)
    closest2: vec2 #  (b2Vec2)
    fraction1: float #  (float)
    fraction2: float #  (float)
    distanceSquared: float #  (float)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, closest1: vec2, closest2: vec2, fraction1: float, fraction2: float, distanceSquared: float): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2SegmentDistanceResult': ...
    
class b2DistanceProxy:
    points: intptr #  (const b2Vec2*)
    count: int #  (int)
    radius: float #  (float)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, points: intptr, count: int, radius: float): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2DistanceProxy': ...
    
class b2DistanceCache:
    count: int #  (unsigned)
    indexA: intptr #  (const unsigned*)
    indexB: intptr #  (const unsigned*)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, count: int, indexA: intptr, indexB: intptr): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2DistanceCache': ...
    
class b2DistanceInput:
    proxyA: b2DistanceProxy #  (b2DistanceProxy)
    proxyB: b2DistanceProxy #  (b2DistanceProxy)
    transformA: b2Transform #  (b2Transform)
    transformB: b2Transform #  (b2Transform)
    useRadii: bool #  (_Bool)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, proxyA: b2DistanceProxy, proxyB: b2DistanceProxy, transformA: b2Transform, transformB: b2Transform, useRadii: bool): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2DistanceInput': ...
    
class b2DistanceOutput:
    pointA: vec2 #  (b2Vec2)
    pointB: vec2 #  (b2Vec2)
    distance: float #  (float)
    iterations: int #  (int)
    simplexCount: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, pointA: vec2, pointB: vec2, distance: float, iterations: int, simplexCount: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2DistanceOutput': ...
    
class b2SimplexVertex:
    wA: vec2 #  (b2Vec2)
    wB: vec2 #  (b2Vec2)
    w: vec2 #  (b2Vec2)
    a: float #  (float)
    indexA: int #  (int)
    indexB: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, wA: vec2, wB: vec2, w: vec2, a: float, indexA: int, indexB: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2SimplexVertex': ...
    
class b2Simplex:
    v1: b2SimplexVertex #  (b2SimplexVertex)
    v2: b2SimplexVertex #  (b2SimplexVertex)
    v3: b2SimplexVertex #  (b2SimplexVertex)
    count: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, v1: b2SimplexVertex, v2: b2SimplexVertex, v3: b2SimplexVertex, count: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2Simplex': ...
    
class b2ShapeCastPairInput:
    proxyA: b2DistanceProxy #  (b2DistanceProxy)
    proxyB: b2DistanceProxy #  (b2DistanceProxy)
    transformA: b2Transform #  (b2Transform)
    transformB: b2Transform #  (b2Transform)
    translationB: vec2 #  (b2Vec2)
    maxFraction: float #  (float)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, proxyA: b2DistanceProxy, proxyB: b2DistanceProxy, transformA: b2Transform, transformB: b2Transform, translationB: vec2, maxFraction: float): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2ShapeCastPairInput': ...
    
class b2Sweep:
    localCenter: vec2 #  (b2Vec2)
    c1: vec2 #  (b2Vec2)
    c2: vec2 #  (b2Vec2)
    q1: b2Rot #  (b2Rot)
    q2: b2Rot #  (b2Rot)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, localCenter: vec2, c1: vec2, c2: vec2, q1: b2Rot, q2: b2Rot): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2Sweep': ...
    
class b2TOIInput:
    proxyA: b2DistanceProxy #  (b2DistanceProxy)
    proxyB: b2DistanceProxy #  (b2DistanceProxy)
    sweepA: b2Sweep #  (b2Sweep)
    sweepB: b2Sweep #  (b2Sweep)
    tMax: float #  (float)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, proxyA: b2DistanceProxy, proxyB: b2DistanceProxy, sweepA: b2Sweep, sweepB: b2Sweep, tMax: float): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2TOIInput': ...
    
class b2TOIOutput:
    state: int #  (b2TOIState)
    t: float #  (float)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, state: int, t: float): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2TOIOutput': ...
    
class b2ManifoldPoint:
    point: vec2 #  (b2Vec2)
    anchorA: vec2 #  (b2Vec2)
    anchorB: vec2 #  (b2Vec2)
    separation: float #  (float)
    normalImpulse: float #  (float)
    tangentImpulse: float #  (float)
    maxNormalImpulse: float #  (float)
    normalVelocity: float #  (float)
    id: int #  (unsigned)
    persisted: bool #  (_Bool)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, point: vec2, anchorA: vec2, anchorB: vec2, separation: float, normalImpulse: float, tangentImpulse: float, maxNormalImpulse: float, normalVelocity: float, id: int, persisted: bool): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2ManifoldPoint': ...
    
class b2Manifold:
    points: intptr #  (const b2ManifoldPoint*)
    normal: vec2 #  (b2Vec2)
    pointCount: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, points: intptr, normal: vec2, pointCount: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2Manifold': ...
    
class b2TreeNode:
    aabb: b2AABB #  (b2AABB)
    categoryBits: int #  (unsigned)
    child1: int #  (int)
    child2: int #  (int)
    userData: int #  (int)
    height: int #  (int)
    enlarged: bool #  (_Bool)
    pad: str #  (const char*)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, aabb: b2AABB, categoryBits: int, child1: int, child2: int, userData: int, height: int, enlarged: bool, pad: str): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2TreeNode': ...
    
class b2DynamicTree:
    nodes: intptr #  (b2TreeNode*)
    root: int #  (int)
    nodeCount: int #  (int)
    nodeCapacity: int #  (int)
    freeList: int #  (int)
    proxyCount: int #  (int)
    leafIndices: intptr #  (int*)
    leafBoxes: intptr #  (b2AABB*)
    leafCenters: intptr #  (b2Vec2*)
    binIndices: intptr #  (int*)
    rebuildCapacity: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, nodes: intptr, root: int, nodeCount: int, nodeCapacity: int, freeList: int, proxyCount: int, leafIndices: intptr, leafBoxes: intptr, leafCenters: intptr, binIndices: intptr, rebuildCapacity: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2DynamicTree': ...
    
class b2WorldId:
    index1: int #  (unsigned)
    revision: int #  (unsigned)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, index1: int, revision: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2WorldId': ...
    
class b2BodyId:
    index1: int #  (int)
    world0: int #  (unsigned)
    revision: int #  (unsigned)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, index1: int, world0: int, revision: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2BodyId': ...
    
class b2ShapeId:
    index1: int #  (int)
    world0: int #  (unsigned)
    revision: int #  (unsigned)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, index1: int, world0: int, revision: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2ShapeId': ...
    
class b2JointId:
    index1: int #  (int)
    world0: int #  (unsigned)
    revision: int #  (unsigned)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, index1: int, world0: int, revision: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2JointId': ...
    
class b2ChainId:
    index1: int #  (int)
    world0: int #  (unsigned)
    revision: int #  (unsigned)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, index1: int, world0: int, revision: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2ChainId': ...
    
class b2RayResult:
    shapeId: b2ShapeId #  (b2ShapeId)
    point: vec2 #  (b2Vec2)
    normal: vec2 #  (b2Vec2)
    fraction: float #  (float)
    hit: bool #  (_Bool)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, shapeId: b2ShapeId, point: vec2, normal: vec2, fraction: float, hit: bool): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2RayResult': ...
    
class b2WorldDef:
    gravity: vec2 #  (b2Vec2)
    restitutionThreshold: float #  (float)
    contactPushoutVelocity: float #  (float)
    hitEventThreshold: float #  (float)
    contactHertz: float #  (float)
    contactDampingRatio: float #  (float)
    jointHertz: float #  (float)
    jointDampingRatio: float #  (float)
    maximumLinearVelocity: float #  (float)
    enableSleep: bool #  (_Bool)
    enableContinuous: bool #  (_Bool)
    workerCount: int #  (int)
    enqueueTask: intptr #  (b2EnqueueTaskCallback*)
    finishTask: intptr #  (b2FinishTaskCallback*)
    userTaskContext: intptr #  (void*)
    internalValue: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, gravity: vec2, restitutionThreshold: float, contactPushoutVelocity: float, hitEventThreshold: float, contactHertz: float, contactDampingRatio: float, jointHertz: float, jointDampingRatio: float, maximumLinearVelocity: float, enableSleep: bool, enableContinuous: bool, workerCount: int, enqueueTask: intptr, finishTask: intptr, userTaskContext: intptr, internalValue: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2WorldDef': ...
    
class b2BodyDef:
    type: int #  (b2BodyType)
    position: vec2 #  (b2Vec2)
    rotation: b2Rot #  (b2Rot)
    linearVelocity: vec2 #  (b2Vec2)
    angularVelocity: float #  (float)
    linearDamping: float #  (float)
    angularDamping: float #  (float)
    gravityScale: float #  (float)
    sleepThreshold: float #  (float)
    userData: intptr #  (void*)
    enableSleep: bool #  (_Bool)
    isAwake: bool #  (_Bool)
    fixedRotation: bool #  (_Bool)
    isBullet: bool #  (_Bool)
    isEnabled: bool #  (_Bool)
    automaticMass: bool #  (_Bool)
    allowFastRotation: bool #  (_Bool)
    internalValue: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, type: int, position: vec2, rotation: b2Rot, linearVelocity: vec2, angularVelocity: float, linearDamping: float, angularDamping: float, gravityScale: float, sleepThreshold: float, userData: intptr, enableSleep: bool, isAwake: bool, fixedRotation: bool, isBullet: bool, isEnabled: bool, automaticMass: bool, allowFastRotation: bool, internalValue: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2BodyDef': ...
    
class b2Filter:
    categoryBits: int #  (unsigned)
    maskBits: int #  (unsigned)
    groupIndex: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, categoryBits: int, maskBits: int, groupIndex: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2Filter': ...
    
class b2QueryFilter:
    categoryBits: int #  (unsigned)
    maskBits: int #  (unsigned)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, categoryBits: int, maskBits: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2QueryFilter': ...
    
class b2ShapeDef:
    userData: intptr #  (void*)
    friction: float #  (float)
    restitution: float #  (float)
    density: float #  (float)
    filter: b2Filter #  (b2Filter)
    customColor: int #  (unsigned)
    isSensor: bool #  (_Bool)
    enableSensorEvents: bool #  (_Bool)
    enableContactEvents: bool #  (_Bool)
    enableHitEvents: bool #  (_Bool)
    enablePreSolveEvents: bool #  (_Bool)
    forceContactCreation: bool #  (_Bool)
    internalValue: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, userData: intptr, friction: float, restitution: float, density: float, filter: b2Filter, customColor: int, isSensor: bool, enableSensorEvents: bool, enableContactEvents: bool, enableHitEvents: bool, enablePreSolveEvents: bool, forceContactCreation: bool, internalValue: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2ShapeDef': ...
    
class b2ChainDef:
    userData: intptr #  (void*)
    points: intptr #  (const b2Vec2*)
    count: int #  (int)
    friction: float #  (float)
    restitution: float #  (float)
    filter: b2Filter #  (b2Filter)
    isLoop: bool #  (_Bool)
    internalValue: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, userData: intptr, points: intptr, count: int, friction: float, restitution: float, filter: b2Filter, isLoop: bool, internalValue: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2ChainDef': ...
    
class b2Profile:
    step: float #  (float)
    pairs: float #  (float)
    collide: float #  (float)
    solve: float #  (float)
    buildIslands: float #  (float)
    solveConstraints: float #  (float)
    prepareTasks: float #  (float)
    solverTasks: float #  (float)
    prepareConstraints: float #  (float)
    integrateVelocities: float #  (float)
    warmStart: float #  (float)
    solveVelocities: float #  (float)
    integratePositions: float #  (float)
    relaxVelocities: float #  (float)
    applyRestitution: float #  (float)
    storeImpulses: float #  (float)
    finalizeBodies: float #  (float)
    splitIslands: float #  (float)
    sleepIslands: float #  (float)
    hitEvents: float #  (float)
    broadphase: float #  (float)
    continuous: float #  (float)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, step: float, pairs: float, collide: float, solve: float, buildIslands: float, solveConstraints: float, prepareTasks: float, solverTasks: float, prepareConstraints: float, integrateVelocities: float, warmStart: float, solveVelocities: float, integratePositions: float, relaxVelocities: float, applyRestitution: float, storeImpulses: float, finalizeBodies: float, splitIslands: float, sleepIslands: float, hitEvents: float, broadphase: float, continuous: float): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2Profile': ...
    
class b2Counters:
    staticBodyCount: int #  (int)
    bodyCount: int #  (int)
    shapeCount: int #  (int)
    contactCount: int #  (int)
    jointCount: int #  (int)
    islandCount: int #  (int)
    stackUsed: int #  (int)
    staticTreeHeight: int #  (int)
    treeHeight: int #  (int)
    byteCount: int #  (int)
    taskCount: int #  (int)
    colorCounts: intptr #  (const int*)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, staticBodyCount: int, bodyCount: int, shapeCount: int, contactCount: int, jointCount: int, islandCount: int, stackUsed: int, staticTreeHeight: int, treeHeight: int, byteCount: int, taskCount: int, colorCounts: intptr): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2Counters': ...
    
class b2DistanceJointDef:
    bodyIdA: b2BodyId #  (b2BodyId)
    bodyIdB: b2BodyId #  (b2BodyId)
    localAnchorA: vec2 #  (b2Vec2)
    localAnchorB: vec2 #  (b2Vec2)
    length: float #  (float)
    enableSpring: bool #  (_Bool)
    hertz: float #  (float)
    dampingRatio: float #  (float)
    enableLimit: bool #  (_Bool)
    minLength: float #  (float)
    maxLength: float #  (float)
    enableMotor: bool #  (_Bool)
    maxMotorForce: float #  (float)
    motorSpeed: float #  (float)
    collideConnected: bool #  (_Bool)
    userData: intptr #  (void*)
    internalValue: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, bodyIdA: b2BodyId, bodyIdB: b2BodyId, localAnchorA: vec2, localAnchorB: vec2, length: float, enableSpring: bool, hertz: float, dampingRatio: float, enableLimit: bool, minLength: float, maxLength: float, enableMotor: bool, maxMotorForce: float, motorSpeed: float, collideConnected: bool, userData: intptr, internalValue: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2DistanceJointDef': ...
    
class b2MotorJointDef:
    bodyIdA: b2BodyId #  (b2BodyId)
    bodyIdB: b2BodyId #  (b2BodyId)
    linearOffset: vec2 #  (b2Vec2)
    angularOffset: float #  (float)
    maxForce: float #  (float)
    maxTorque: float #  (float)
    correctionFactor: float #  (float)
    collideConnected: bool #  (_Bool)
    userData: intptr #  (void*)
    internalValue: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, bodyIdA: b2BodyId, bodyIdB: b2BodyId, linearOffset: vec2, angularOffset: float, maxForce: float, maxTorque: float, correctionFactor: float, collideConnected: bool, userData: intptr, internalValue: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2MotorJointDef': ...
    
class b2MouseJointDef:
    bodyIdA: b2BodyId #  (b2BodyId)
    bodyIdB: b2BodyId #  (b2BodyId)
    target: vec2 #  (b2Vec2)
    hertz: float #  (float)
    dampingRatio: float #  (float)
    maxForce: float #  (float)
    collideConnected: bool #  (_Bool)
    userData: intptr #  (void*)
    internalValue: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, bodyIdA: b2BodyId, bodyIdB: b2BodyId, target: vec2, hertz: float, dampingRatio: float, maxForce: float, collideConnected: bool, userData: intptr, internalValue: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2MouseJointDef': ...
    
class b2PrismaticJointDef:
    bodyIdA: b2BodyId #  (b2BodyId)
    bodyIdB: b2BodyId #  (b2BodyId)
    localAnchorA: vec2 #  (b2Vec2)
    localAnchorB: vec2 #  (b2Vec2)
    localAxisA: vec2 #  (b2Vec2)
    referenceAngle: float #  (float)
    enableSpring: bool #  (_Bool)
    hertz: float #  (float)
    dampingRatio: float #  (float)
    enableLimit: bool #  (_Bool)
    lowerTranslation: float #  (float)
    upperTranslation: float #  (float)
    enableMotor: bool #  (_Bool)
    maxMotorForce: float #  (float)
    motorSpeed: float #  (float)
    collideConnected: bool #  (_Bool)
    userData: intptr #  (void*)
    internalValue: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, bodyIdA: b2BodyId, bodyIdB: b2BodyId, localAnchorA: vec2, localAnchorB: vec2, localAxisA: vec2, referenceAngle: float, enableSpring: bool, hertz: float, dampingRatio: float, enableLimit: bool, lowerTranslation: float, upperTranslation: float, enableMotor: bool, maxMotorForce: float, motorSpeed: float, collideConnected: bool, userData: intptr, internalValue: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2PrismaticJointDef': ...
    
class b2RevoluteJointDef:
    bodyIdA: b2BodyId #  (b2BodyId)
    bodyIdB: b2BodyId #  (b2BodyId)
    localAnchorA: vec2 #  (b2Vec2)
    localAnchorB: vec2 #  (b2Vec2)
    referenceAngle: float #  (float)
    enableSpring: bool #  (_Bool)
    hertz: float #  (float)
    dampingRatio: float #  (float)
    enableLimit: bool #  (_Bool)
    lowerAngle: float #  (float)
    upperAngle: float #  (float)
    enableMotor: bool #  (_Bool)
    maxMotorTorque: float #  (float)
    motorSpeed: float #  (float)
    drawSize: float #  (float)
    collideConnected: bool #  (_Bool)
    userData: intptr #  (void*)
    internalValue: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, bodyIdA: b2BodyId, bodyIdB: b2BodyId, localAnchorA: vec2, localAnchorB: vec2, referenceAngle: float, enableSpring: bool, hertz: float, dampingRatio: float, enableLimit: bool, lowerAngle: float, upperAngle: float, enableMotor: bool, maxMotorTorque: float, motorSpeed: float, drawSize: float, collideConnected: bool, userData: intptr, internalValue: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2RevoluteJointDef': ...
    
class b2WeldJointDef:
    bodyIdA: b2BodyId #  (b2BodyId)
    bodyIdB: b2BodyId #  (b2BodyId)
    localAnchorA: vec2 #  (b2Vec2)
    localAnchorB: vec2 #  (b2Vec2)
    referenceAngle: float #  (float)
    linearHertz: float #  (float)
    angularHertz: float #  (float)
    linearDampingRatio: float #  (float)
    angularDampingRatio: float #  (float)
    collideConnected: bool #  (_Bool)
    userData: intptr #  (void*)
    internalValue: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, bodyIdA: b2BodyId, bodyIdB: b2BodyId, localAnchorA: vec2, localAnchorB: vec2, referenceAngle: float, linearHertz: float, angularHertz: float, linearDampingRatio: float, angularDampingRatio: float, collideConnected: bool, userData: intptr, internalValue: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2WeldJointDef': ...
    
class b2WheelJointDef:
    bodyIdA: b2BodyId #  (b2BodyId)
    bodyIdB: b2BodyId #  (b2BodyId)
    localAnchorA: vec2 #  (b2Vec2)
    localAnchorB: vec2 #  (b2Vec2)
    localAxisA: vec2 #  (b2Vec2)
    enableSpring: bool #  (_Bool)
    hertz: float #  (float)
    dampingRatio: float #  (float)
    enableLimit: bool #  (_Bool)
    lowerTranslation: float #  (float)
    upperTranslation: float #  (float)
    enableMotor: bool #  (_Bool)
    maxMotorTorque: float #  (float)
    motorSpeed: float #  (float)
    collideConnected: bool #  (_Bool)
    userData: intptr #  (void*)
    internalValue: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, bodyIdA: b2BodyId, bodyIdB: b2BodyId, localAnchorA: vec2, localAnchorB: vec2, localAxisA: vec2, enableSpring: bool, hertz: float, dampingRatio: float, enableLimit: bool, lowerTranslation: float, upperTranslation: float, enableMotor: bool, maxMotorTorque: float, motorSpeed: float, collideConnected: bool, userData: intptr, internalValue: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2WheelJointDef': ...
    
class b2SensorBeginTouchEvent:
    sensorShapeId: b2ShapeId #  (b2ShapeId)
    visitorShapeId: b2ShapeId #  (b2ShapeId)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, sensorShapeId: b2ShapeId, visitorShapeId: b2ShapeId): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2SensorBeginTouchEvent': ...
    
class b2SensorEndTouchEvent:
    sensorShapeId: b2ShapeId #  (b2ShapeId)
    visitorShapeId: b2ShapeId #  (b2ShapeId)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, sensorShapeId: b2ShapeId, visitorShapeId: b2ShapeId): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2SensorEndTouchEvent': ...
    
class b2SensorEvents:
    beginEvents: intptr #  (b2SensorBeginTouchEvent*)
    endEvents: intptr #  (b2SensorEndTouchEvent*)
    beginCount: int #  (int)
    endCount: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, beginEvents: intptr, endEvents: intptr, beginCount: int, endCount: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2SensorEvents': ...
    
class b2ContactBeginTouchEvent:
    shapeIdA: b2ShapeId #  (b2ShapeId)
    shapeIdB: b2ShapeId #  (b2ShapeId)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, shapeIdA: b2ShapeId, shapeIdB: b2ShapeId): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2ContactBeginTouchEvent': ...
    
class b2ContactEndTouchEvent:
    shapeIdA: b2ShapeId #  (b2ShapeId)
    shapeIdB: b2ShapeId #  (b2ShapeId)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, shapeIdA: b2ShapeId, shapeIdB: b2ShapeId): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2ContactEndTouchEvent': ...
    
class b2ContactHitEvent:
    shapeIdA: b2ShapeId #  (b2ShapeId)
    shapeIdB: b2ShapeId #  (b2ShapeId)
    point: vec2 #  (b2Vec2)
    normal: vec2 #  (b2Vec2)
    approachSpeed: float #  (float)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, shapeIdA: b2ShapeId, shapeIdB: b2ShapeId, point: vec2, normal: vec2, approachSpeed: float): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2ContactHitEvent': ...
    
class b2ContactEvents:
    beginEvents: intptr #  (b2ContactBeginTouchEvent*)
    endEvents: intptr #  (b2ContactEndTouchEvent*)
    hitEvents: intptr #  (b2ContactHitEvent*)
    beginCount: int #  (int)
    endCount: int #  (int)
    hitCount: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, beginEvents: intptr, endEvents: intptr, hitEvents: intptr, beginCount: int, endCount: int, hitCount: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2ContactEvents': ...
    
class b2BodyMoveEvent:
    transform: b2Transform #  (b2Transform)
    bodyId: b2BodyId #  (b2BodyId)
    userData: intptr #  (void*)
    fellAsleep: bool #  (_Bool)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, transform: b2Transform, bodyId: b2BodyId, userData: intptr, fellAsleep: bool): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2BodyMoveEvent': ...
    
class b2BodyEvents:
    moveEvents: intptr #  (b2BodyMoveEvent*)
    moveCount: int #  (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, moveEvents: intptr, moveCount: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2BodyEvents': ...
    
class b2ContactData:
    shapeIdA: b2ShapeId #  (b2ShapeId)
    shapeIdB: b2ShapeId #  (b2ShapeId)
    manifold: b2Manifold #  (b2Manifold)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, shapeIdA: b2ShapeId, shapeIdB: b2ShapeId, manifold: b2Manifold): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'b2ContactData': ...
    
def b2SetAllocator(_0: intptr, _1: intptr) -> None:
    """Wraps `void b2SetAllocator(b2AllocFcn* _0, b2FreeFcn* _1)`"""

def b2GetByteCount() -> int:
    """Wraps `int b2GetByteCount()`"""

def b2SetAssertFcn(_0: intptr) -> None:
    """Wraps `void b2SetAssertFcn(b2AssertFcn* _0)`"""

def b2GetVersion() -> b2Version:
    """Wraps `b2Version b2GetVersion()`"""

def b2GetTicks(_0: intptr) -> int:
    """Wraps `int b2GetTicks(b2Timer* _0)`"""

def b2GetMilliseconds(_0: intptr) -> float:
    """Wraps `float b2GetMilliseconds(const b2Timer* _0)`"""

def b2GetMillisecondsAndReset(_0: intptr) -> float:
    """Wraps `float b2GetMillisecondsAndReset(b2Timer* _0)`"""

def b2SleepMilliseconds(_0: int) -> None:
    """Wraps `void b2SleepMilliseconds(int _0)`"""

def b2Yield() -> None:
    """Wraps `void b2Yield()`"""

def b2Atan2(_0: float, _1: float) -> float:
    """Wraps `float b2Atan2(float _0, float _1)`"""

def b2MakeRot(_0: float) -> b2Rot:
    """Wraps `b2Rot b2MakeRot(float _0)`"""

def b2IsValid(_0: float) -> bool:
    """Wraps `_Bool b2IsValid(float _0)`"""

def b2Vec2_IsValid(_0: vec2) -> bool:
    """Wraps `_Bool b2Vec2_IsValid(b2Vec2 _0)`"""

def b2Rot_IsValid(_0: b2Rot) -> bool:
    """Wraps `_Bool b2Rot_IsValid(b2Rot _0)`"""

def b2AABB_IsValid(_0: b2AABB) -> bool:
    """Wraps `_Bool b2AABB_IsValid(b2AABB _0)`"""

def b2SetLengthUnitsPerMeter(_0: float) -> None:
    """Wraps `void b2SetLengthUnitsPerMeter(float _0)`"""

def b2GetLengthUnitsPerMeter() -> float:
    """Wraps `float b2GetLengthUnitsPerMeter()`"""

def b2IsValidRay(_0: intptr) -> bool:
    """Wraps `_Bool b2IsValidRay(const b2RayCastInput* _0)`"""

def b2MakePolygon(_0: intptr, _1: float) -> b2Polygon:
    """Wraps `b2Polygon b2MakePolygon(const b2Hull* _0, float _1)`"""

def b2MakeOffsetPolygon(_0: intptr, _1: float, _2: b2Transform) -> b2Polygon:
    """Wraps `b2Polygon b2MakeOffsetPolygon(const b2Hull* _0, float _1, b2Transform _2)`"""

def b2MakeSquare(_0: float) -> b2Polygon:
    """Wraps `b2Polygon b2MakeSquare(float _0)`"""

def b2MakeBox(_0: float, _1: float) -> b2Polygon:
    """Wraps `b2Polygon b2MakeBox(float _0, float _1)`"""

def b2MakeRoundedBox(_0: float, _1: float, _2: float) -> b2Polygon:
    """Wraps `b2Polygon b2MakeRoundedBox(float _0, float _1, float _2)`"""

def b2MakeOffsetBox(_0: float, _1: float, _2: vec2, _3: b2Rot) -> b2Polygon:
    """Wraps `b2Polygon b2MakeOffsetBox(float _0, float _1, b2Vec2 _2, b2Rot _3)`"""

def b2TransformPolygon(_0: b2Transform, _1: intptr) -> b2Polygon:
    """Wraps `b2Polygon b2TransformPolygon(b2Transform _0, const b2Polygon* _1)`"""

def b2ComputeCircleMass(_0: intptr, _1: float) -> b2MassData:
    """Wraps `b2MassData b2ComputeCircleMass(const b2Circle* _0, float _1)`"""

def b2ComputeCapsuleMass(_0: intptr, _1: float) -> b2MassData:
    """Wraps `b2MassData b2ComputeCapsuleMass(const b2Capsule* _0, float _1)`"""

def b2ComputePolygonMass(_0: intptr, _1: float) -> b2MassData:
    """Wraps `b2MassData b2ComputePolygonMass(const b2Polygon* _0, float _1)`"""

def b2ComputeCircleAABB(_0: intptr, _1: b2Transform) -> b2AABB:
    """Wraps `b2AABB b2ComputeCircleAABB(const b2Circle* _0, b2Transform _1)`"""

def b2ComputeCapsuleAABB(_0: intptr, _1: b2Transform) -> b2AABB:
    """Wraps `b2AABB b2ComputeCapsuleAABB(const b2Capsule* _0, b2Transform _1)`"""

def b2ComputePolygonAABB(_0: intptr, _1: b2Transform) -> b2AABB:
    """Wraps `b2AABB b2ComputePolygonAABB(const b2Polygon* _0, b2Transform _1)`"""

def b2ComputeSegmentAABB(_0: intptr, _1: b2Transform) -> b2AABB:
    """Wraps `b2AABB b2ComputeSegmentAABB(const b2Segment* _0, b2Transform _1)`"""

def b2PointInCircle(_0: vec2, _1: intptr) -> bool:
    """Wraps `_Bool b2PointInCircle(b2Vec2 _0, const b2Circle* _1)`"""

def b2PointInCapsule(_0: vec2, _1: intptr) -> bool:
    """Wraps `_Bool b2PointInCapsule(b2Vec2 _0, const b2Capsule* _1)`"""

def b2PointInPolygon(_0: vec2, _1: intptr) -> bool:
    """Wraps `_Bool b2PointInPolygon(b2Vec2 _0, const b2Polygon* _1)`"""

def b2RayCastCircle(_0: intptr, _1: intptr) -> b2CastOutput:
    """Wraps `b2CastOutput b2RayCastCircle(const b2RayCastInput* _0, const b2Circle* _1)`"""

def b2RayCastCapsule(_0: intptr, _1: intptr) -> b2CastOutput:
    """Wraps `b2CastOutput b2RayCastCapsule(const b2RayCastInput* _0, const b2Capsule* _1)`"""

def b2RayCastSegment(_0: intptr, _1: intptr, _2: bool) -> b2CastOutput:
    """Wraps `b2CastOutput b2RayCastSegment(const b2RayCastInput* _0, const b2Segment* _1, _Bool _2)`"""

def b2RayCastPolygon(_0: intptr, _1: intptr) -> b2CastOutput:
    """Wraps `b2CastOutput b2RayCastPolygon(const b2RayCastInput* _0, const b2Polygon* _1)`"""

def b2ShapeCastCircle(_0: intptr, _1: intptr) -> b2CastOutput:
    """Wraps `b2CastOutput b2ShapeCastCircle(const b2ShapeCastInput* _0, const b2Circle* _1)`"""

def b2ShapeCastCapsule(_0: intptr, _1: intptr) -> b2CastOutput:
    """Wraps `b2CastOutput b2ShapeCastCapsule(const b2ShapeCastInput* _0, const b2Capsule* _1)`"""

def b2ShapeCastSegment(_0: intptr, _1: intptr) -> b2CastOutput:
    """Wraps `b2CastOutput b2ShapeCastSegment(const b2ShapeCastInput* _0, const b2Segment* _1)`"""

def b2ShapeCastPolygon(_0: intptr, _1: intptr) -> b2CastOutput:
    """Wraps `b2CastOutput b2ShapeCastPolygon(const b2ShapeCastInput* _0, const b2Polygon* _1)`"""

def b2ComputeHull(_0: intptr, _1: int) -> b2Hull:
    """Wraps `b2Hull b2ComputeHull(const b2Vec2* _0, int _1)`"""

def b2ValidateHull(_0: intptr) -> bool:
    """Wraps `_Bool b2ValidateHull(const b2Hull* _0)`"""

def b2SegmentDistance(_0: vec2, _1: vec2, _2: vec2, _3: vec2) -> b2SegmentDistanceResult:
    """Wraps `b2SegmentDistanceResult b2SegmentDistance(b2Vec2 _0, b2Vec2 _1, b2Vec2 _2, b2Vec2 _3)`"""

def b2ShapeDistance(_0: intptr, _1: intptr, _2: intptr, _3: int) -> b2DistanceOutput:
    """Wraps `b2DistanceOutput b2ShapeDistance(b2DistanceCache* _0, const b2DistanceInput* _1, b2Simplex* _2, int _3)`"""

def b2ShapeCast(_0: intptr) -> b2CastOutput:
    """Wraps `b2CastOutput b2ShapeCast(const b2ShapeCastPairInput* _0)`"""

def b2MakeProxy(_0: intptr, _1: int, _2: float) -> b2DistanceProxy:
    """Wraps `b2DistanceProxy b2MakeProxy(const b2Vec2* _0, int _1, float _2)`"""

def b2GetSweepTransform(_0: intptr, _1: float) -> b2Transform:
    """Wraps `b2Transform b2GetSweepTransform(const b2Sweep* _0, float _1)`"""

def b2TimeOfImpact(_0: intptr) -> b2TOIOutput:
    """Wraps `b2TOIOutput b2TimeOfImpact(const b2TOIInput* _0)`"""

def b2CollideCircles(_0: intptr, _1: b2Transform, _2: intptr, _3: b2Transform) -> b2Manifold:
    """Wraps `b2Manifold b2CollideCircles(const b2Circle* _0, b2Transform _1, const b2Circle* _2, b2Transform _3)`"""

def b2CollideCapsuleAndCircle(_0: intptr, _1: b2Transform, _2: intptr, _3: b2Transform) -> b2Manifold:
    """Wraps `b2Manifold b2CollideCapsuleAndCircle(const b2Capsule* _0, b2Transform _1, const b2Circle* _2, b2Transform _3)`"""

def b2CollideSegmentAndCircle(_0: intptr, _1: b2Transform, _2: intptr, _3: b2Transform) -> b2Manifold:
    """Wraps `b2Manifold b2CollideSegmentAndCircle(const b2Segment* _0, b2Transform _1, const b2Circle* _2, b2Transform _3)`"""

def b2CollidePolygonAndCircle(_0: intptr, _1: b2Transform, _2: intptr, _3: b2Transform) -> b2Manifold:
    """Wraps `b2Manifold b2CollidePolygonAndCircle(const b2Polygon* _0, b2Transform _1, const b2Circle* _2, b2Transform _3)`"""

def b2CollideCapsules(_0: intptr, _1: b2Transform, _2: intptr, _3: b2Transform) -> b2Manifold:
    """Wraps `b2Manifold b2CollideCapsules(const b2Capsule* _0, b2Transform _1, const b2Capsule* _2, b2Transform _3)`"""

def b2CollideSegmentAndCapsule(_0: intptr, _1: b2Transform, _2: intptr, _3: b2Transform) -> b2Manifold:
    """Wraps `b2Manifold b2CollideSegmentAndCapsule(const b2Segment* _0, b2Transform _1, const b2Capsule* _2, b2Transform _3)`"""

def b2CollidePolygonAndCapsule(_0: intptr, _1: b2Transform, _2: intptr, _3: b2Transform) -> b2Manifold:
    """Wraps `b2Manifold b2CollidePolygonAndCapsule(const b2Polygon* _0, b2Transform _1, const b2Capsule* _2, b2Transform _3)`"""

def b2CollidePolygons(_0: intptr, _1: b2Transform, _2: intptr, _3: b2Transform) -> b2Manifold:
    """Wraps `b2Manifold b2CollidePolygons(const b2Polygon* _0, b2Transform _1, const b2Polygon* _2, b2Transform _3)`"""

def b2CollideSegmentAndPolygon(_0: intptr, _1: b2Transform, _2: intptr, _3: b2Transform) -> b2Manifold:
    """Wraps `b2Manifold b2CollideSegmentAndPolygon(const b2Segment* _0, b2Transform _1, const b2Polygon* _2, b2Transform _3)`"""

def b2CollideSmoothSegmentAndCircle(_0: intptr, _1: b2Transform, _2: intptr, _3: b2Transform) -> b2Manifold:
    """Wraps `b2Manifold b2CollideSmoothSegmentAndCircle(const b2SmoothSegment* _0, b2Transform _1, const b2Circle* _2, b2Transform _3)`"""

def b2CollideSmoothSegmentAndCapsule(_0: intptr, _1: b2Transform, _2: intptr, _3: b2Transform, _4: intptr) -> b2Manifold:
    """Wraps `b2Manifold b2CollideSmoothSegmentAndCapsule(const b2SmoothSegment* _0, b2Transform _1, const b2Capsule* _2, b2Transform _3, b2DistanceCache* _4)`"""

def b2CollideSmoothSegmentAndPolygon(_0: intptr, _1: b2Transform, _2: intptr, _3: b2Transform, _4: intptr) -> b2Manifold:
    """Wraps `b2Manifold b2CollideSmoothSegmentAndPolygon(const b2SmoothSegment* _0, b2Transform _1, const b2Polygon* _2, b2Transform _3, b2DistanceCache* _4)`"""

def b2DynamicTree_Create() -> b2DynamicTree:
    """Wraps `b2DynamicTree b2DynamicTree_Create()`"""

def b2DynamicTree_Destroy(_0: intptr) -> None:
    """Wraps `void b2DynamicTree_Destroy(b2DynamicTree* _0)`"""

def b2DynamicTree_CreateProxy(_0: intptr, _1: b2AABB, _2: int, _3: int) -> int:
    """Wraps `int b2DynamicTree_CreateProxy(b2DynamicTree* _0, b2AABB _1, unsigned _2, int _3)`"""

def b2DynamicTree_DestroyProxy(_0: intptr, _1: int) -> None:
    """Wraps `void b2DynamicTree_DestroyProxy(b2DynamicTree* _0, int _1)`"""

def b2DynamicTree_MoveProxy(_0: intptr, _1: int, _2: b2AABB) -> None:
    """Wraps `void b2DynamicTree_MoveProxy(b2DynamicTree* _0, int _1, b2AABB _2)`"""

def b2DynamicTree_EnlargeProxy(_0: intptr, _1: int, _2: b2AABB) -> None:
    """Wraps `void b2DynamicTree_EnlargeProxy(b2DynamicTree* _0, int _1, b2AABB _2)`"""

def b2DynamicTree_Query(_0: intptr, _1: b2AABB, _2: int, _3: intptr, _4: intptr) -> None:
    """Wraps `void b2DynamicTree_Query(const b2DynamicTree* _0, b2AABB _1, unsigned _2, b2TreeQueryCallbackFcn* _3, void* _4)`"""

def b2DynamicTree_RayCast(_0: intptr, _1: intptr, _2: int, _3: intptr, _4: intptr) -> None:
    """Wraps `void b2DynamicTree_RayCast(const b2DynamicTree* _0, const b2RayCastInput* _1, unsigned _2, b2TreeRayCastCallbackFcn* _3, void* _4)`"""

def b2DynamicTree_ShapeCast(_0: intptr, _1: intptr, _2: int, _3: intptr, _4: intptr) -> None:
    """Wraps `void b2DynamicTree_ShapeCast(const b2DynamicTree* _0, const b2ShapeCastInput* _1, unsigned _2, b2TreeShapeCastCallbackFcn* _3, void* _4)`"""

def b2DynamicTree_Validate(_0: intptr) -> None:
    """Wraps `void b2DynamicTree_Validate(const b2DynamicTree* _0)`"""

def b2DynamicTree_GetHeight(_0: intptr) -> int:
    """Wraps `int b2DynamicTree_GetHeight(const b2DynamicTree* _0)`"""

def b2DynamicTree_GetMaxBalance(_0: intptr) -> int:
    """Wraps `int b2DynamicTree_GetMaxBalance(const b2DynamicTree* _0)`"""

def b2DynamicTree_GetAreaRatio(_0: intptr) -> float:
    """Wraps `float b2DynamicTree_GetAreaRatio(const b2DynamicTree* _0)`"""

def b2DynamicTree_RebuildBottomUp(_0: intptr) -> None:
    """Wraps `void b2DynamicTree_RebuildBottomUp(b2DynamicTree* _0)`"""

def b2DynamicTree_GetProxyCount(_0: intptr) -> int:
    """Wraps `int b2DynamicTree_GetProxyCount(const b2DynamicTree* _0)`"""

def b2DynamicTree_Rebuild(_0: intptr, _1: bool) -> int:
    """Wraps `int b2DynamicTree_Rebuild(b2DynamicTree* _0, _Bool _1)`"""

def b2DynamicTree_ShiftOrigin(_0: intptr, _1: vec2) -> None:
    """Wraps `void b2DynamicTree_ShiftOrigin(b2DynamicTree* _0, b2Vec2 _1)`"""

def b2DynamicTree_GetByteCount(_0: intptr) -> int:
    """Wraps `int b2DynamicTree_GetByteCount(const b2DynamicTree* _0)`"""

def b2DefaultWorldDef() -> b2WorldDef:
    """Wraps `b2WorldDef b2DefaultWorldDef()`"""

def b2DefaultBodyDef() -> b2BodyDef:
    """Wraps `b2BodyDef b2DefaultBodyDef()`"""

def b2DefaultFilter() -> b2Filter:
    """Wraps `b2Filter b2DefaultFilter()`"""

def b2DefaultQueryFilter() -> b2QueryFilter:
    """Wraps `b2QueryFilter b2DefaultQueryFilter()`"""

def b2DefaultShapeDef() -> b2ShapeDef:
    """Wraps `b2ShapeDef b2DefaultShapeDef()`"""

def b2DefaultChainDef() -> b2ChainDef:
    """Wraps `b2ChainDef b2DefaultChainDef()`"""

def b2DefaultDistanceJointDef() -> b2DistanceJointDef:
    """Wraps `b2DistanceJointDef b2DefaultDistanceJointDef()`"""

def b2DefaultMotorJointDef() -> b2MotorJointDef:
    """Wraps `b2MotorJointDef b2DefaultMotorJointDef()`"""

def b2DefaultMouseJointDef() -> b2MouseJointDef:
    """Wraps `b2MouseJointDef b2DefaultMouseJointDef()`"""

def b2DefaultPrismaticJointDef() -> b2PrismaticJointDef:
    """Wraps `b2PrismaticJointDef b2DefaultPrismaticJointDef()`"""

def b2DefaultRevoluteJointDef() -> b2RevoluteJointDef:
    """Wraps `b2RevoluteJointDef b2DefaultRevoluteJointDef()`"""

def b2DefaultWeldJointDef() -> b2WeldJointDef:
    """Wraps `b2WeldJointDef b2DefaultWeldJointDef()`"""

def b2DefaultWheelJointDef() -> b2WheelJointDef:
    """Wraps `b2WheelJointDef b2DefaultWheelJointDef()`"""

def b2CreateWorld(_0: intptr) -> b2WorldId:
    """Wraps `b2WorldId b2CreateWorld(const b2WorldDef* _0)`"""

def b2DestroyWorld(_0: b2WorldId) -> None:
    """Wraps `void b2DestroyWorld(b2WorldId _0)`"""

def b2World_IsValid(_0: b2WorldId) -> bool:
    """Wraps `_Bool b2World_IsValid(b2WorldId _0)`"""

def b2World_Step(_0: b2WorldId, _1: float, _2: int) -> None:
    """Wraps `void b2World_Step(b2WorldId _0, float _1, int _2)`"""

def b2World_Draw(_0: b2WorldId, _1: intptr) -> None:
    """Wraps `void b2World_Draw(b2WorldId _0, b2DebugDraw* _1)`"""

def b2World_GetBodyEvents(_0: b2WorldId) -> b2BodyEvents:
    """Wraps `b2BodyEvents b2World_GetBodyEvents(b2WorldId _0)`"""

def b2World_GetSensorEvents(_0: b2WorldId) -> b2SensorEvents:
    """Wraps `b2SensorEvents b2World_GetSensorEvents(b2WorldId _0)`"""

def b2World_GetContactEvents(_0: b2WorldId) -> b2ContactEvents:
    """Wraps `b2ContactEvents b2World_GetContactEvents(b2WorldId _0)`"""

def b2World_OverlapAABB(_0: b2WorldId, _1: b2AABB, _2: b2QueryFilter, _3: intptr, _4: intptr) -> None:
    """Wraps `void b2World_OverlapAABB(b2WorldId _0, b2AABB _1, b2QueryFilter _2, b2OverlapResultFcn* _3, void* _4)`"""

def b2World_OverlapCircle(_0: b2WorldId, _1: intptr, _2: b2Transform, _3: b2QueryFilter, _4: intptr, _5: intptr) -> None:
    """Wraps `void b2World_OverlapCircle(b2WorldId _0, const b2Circle* _1, b2Transform _2, b2QueryFilter _3, b2OverlapResultFcn* _4, void* _5)`"""

def b2World_OverlapCapsule(_0: b2WorldId, _1: intptr, _2: b2Transform, _3: b2QueryFilter, _4: intptr, _5: intptr) -> None:
    """Wraps `void b2World_OverlapCapsule(b2WorldId _0, const b2Capsule* _1, b2Transform _2, b2QueryFilter _3, b2OverlapResultFcn* _4, void* _5)`"""

def b2World_OverlapPolygon(_0: b2WorldId, _1: intptr, _2: b2Transform, _3: b2QueryFilter, _4: intptr, _5: intptr) -> None:
    """Wraps `void b2World_OverlapPolygon(b2WorldId _0, const b2Polygon* _1, b2Transform _2, b2QueryFilter _3, b2OverlapResultFcn* _4, void* _5)`"""

def b2World_CastRay(_0: b2WorldId, _1: vec2, _2: vec2, _3: b2QueryFilter, _4: intptr, _5: intptr) -> None:
    """Wraps `void b2World_CastRay(b2WorldId _0, b2Vec2 _1, b2Vec2 _2, b2QueryFilter _3, b2CastResultFcn* _4, void* _5)`"""

def b2World_CastRayClosest(_0: b2WorldId, _1: vec2, _2: vec2, _3: b2QueryFilter) -> b2RayResult:
    """Wraps `b2RayResult b2World_CastRayClosest(b2WorldId _0, b2Vec2 _1, b2Vec2 _2, b2QueryFilter _3)`"""

def b2World_CastCircle(_0: b2WorldId, _1: intptr, _2: b2Transform, _3: vec2, _4: b2QueryFilter, _5: intptr, _6: intptr) -> None:
    """Wraps `void b2World_CastCircle(b2WorldId _0, const b2Circle* _1, b2Transform _2, b2Vec2 _3, b2QueryFilter _4, b2CastResultFcn* _5, void* _6)`"""

def b2World_CastCapsule(_0: b2WorldId, _1: intptr, _2: b2Transform, _3: vec2, _4: b2QueryFilter, _5: intptr, _6: intptr) -> None:
    """Wraps `void b2World_CastCapsule(b2WorldId _0, const b2Capsule* _1, b2Transform _2, b2Vec2 _3, b2QueryFilter _4, b2CastResultFcn* _5, void* _6)`"""

def b2World_CastPolygon(_0: b2WorldId, _1: intptr, _2: b2Transform, _3: vec2, _4: b2QueryFilter, _5: intptr, _6: intptr) -> None:
    """Wraps `void b2World_CastPolygon(b2WorldId _0, const b2Polygon* _1, b2Transform _2, b2Vec2 _3, b2QueryFilter _4, b2CastResultFcn* _5, void* _6)`"""

def b2World_EnableSleeping(_0: b2WorldId, _1: bool) -> None:
    """Wraps `void b2World_EnableSleeping(b2WorldId _0, _Bool _1)`"""

def b2World_EnableContinuous(_0: b2WorldId, _1: bool) -> None:
    """Wraps `void b2World_EnableContinuous(b2WorldId _0, _Bool _1)`"""

def b2World_SetRestitutionThreshold(_0: b2WorldId, _1: float) -> None:
    """Wraps `void b2World_SetRestitutionThreshold(b2WorldId _0, float _1)`"""

def b2World_SetHitEventThreshold(_0: b2WorldId, _1: float) -> None:
    """Wraps `void b2World_SetHitEventThreshold(b2WorldId _0, float _1)`"""

def b2World_SetCustomFilterCallback(_0: b2WorldId, _1: intptr, _2: intptr) -> None:
    """Wraps `void b2World_SetCustomFilterCallback(b2WorldId _0, b2CustomFilterFcn* _1, void* _2)`"""

def b2World_SetPreSolveCallback(_0: b2WorldId, _1: intptr, _2: intptr) -> None:
    """Wraps `void b2World_SetPreSolveCallback(b2WorldId _0, b2PreSolveFcn* _1, void* _2)`"""

def b2World_SetGravity(_0: b2WorldId, _1: vec2) -> None:
    """Wraps `void b2World_SetGravity(b2WorldId _0, b2Vec2 _1)`"""

def b2World_GetGravity(_0: b2WorldId) -> vec2:
    """Wraps `b2Vec2 b2World_GetGravity(b2WorldId _0)`"""

def b2World_Explode(_0: b2WorldId, _1: vec2, _2: float, _3: float) -> None:
    """Wraps `void b2World_Explode(b2WorldId _0, b2Vec2 _1, float _2, float _3)`"""

def b2World_SetContactTuning(_0: b2WorldId, _1: float, _2: float, _3: float) -> None:
    """Wraps `void b2World_SetContactTuning(b2WorldId _0, float _1, float _2, float _3)`"""

def b2World_EnableWarmStarting(_0: b2WorldId, _1: bool) -> None:
    """Wraps `void b2World_EnableWarmStarting(b2WorldId _0, _Bool _1)`"""

def b2World_GetProfile(_0: b2WorldId) -> b2Profile:
    """Wraps `b2Profile b2World_GetProfile(b2WorldId _0)`"""

def b2World_GetCounters(_0: b2WorldId) -> b2Counters:
    """Wraps `b2Counters b2World_GetCounters(b2WorldId _0)`"""

def b2World_DumpMemoryStats(_0: b2WorldId) -> None:
    """Wraps `void b2World_DumpMemoryStats(b2WorldId _0)`"""

def b2CreateBody(_0: b2WorldId, _1: intptr) -> b2BodyId:
    """Wraps `b2BodyId b2CreateBody(b2WorldId _0, const b2BodyDef* _1)`"""

def b2DestroyBody(_0: b2BodyId) -> None:
    """Wraps `void b2DestroyBody(b2BodyId _0)`"""

def b2Body_IsValid(_0: b2BodyId) -> bool:
    """Wraps `_Bool b2Body_IsValid(b2BodyId _0)`"""

def b2Body_GetType(_0: b2BodyId) -> int:
    """Wraps `b2BodyType b2Body_GetType(b2BodyId _0)`"""

def b2Body_SetType(_0: b2BodyId, _1: int) -> None:
    """Wraps `void b2Body_SetType(b2BodyId _0, b2BodyType _1)`"""

def b2Body_SetUserData(_0: b2BodyId, _1: intptr) -> None:
    """Wraps `void b2Body_SetUserData(b2BodyId _0, void* _1)`"""

def b2Body_GetUserData(_0: b2BodyId) -> intptr:
    """Wraps `void* b2Body_GetUserData(b2BodyId _0)`"""

def b2Body_GetPosition(_0: b2BodyId) -> vec2:
    """Wraps `b2Vec2 b2Body_GetPosition(b2BodyId _0)`"""

def b2Body_GetRotation(_0: b2BodyId) -> b2Rot:
    """Wraps `b2Rot b2Body_GetRotation(b2BodyId _0)`"""

def b2Body_GetTransform(_0: b2BodyId) -> b2Transform:
    """Wraps `b2Transform b2Body_GetTransform(b2BodyId _0)`"""

def b2Body_SetTransform(_0: b2BodyId, _1: vec2, _2: b2Rot) -> None:
    """Wraps `void b2Body_SetTransform(b2BodyId _0, b2Vec2 _1, b2Rot _2)`"""

def b2Body_GetLocalPoint(_0: b2BodyId, _1: vec2) -> vec2:
    """Wraps `b2Vec2 b2Body_GetLocalPoint(b2BodyId _0, b2Vec2 _1)`"""

def b2Body_GetWorldPoint(_0: b2BodyId, _1: vec2) -> vec2:
    """Wraps `b2Vec2 b2Body_GetWorldPoint(b2BodyId _0, b2Vec2 _1)`"""

def b2Body_GetLocalVector(_0: b2BodyId, _1: vec2) -> vec2:
    """Wraps `b2Vec2 b2Body_GetLocalVector(b2BodyId _0, b2Vec2 _1)`"""

def b2Body_GetWorldVector(_0: b2BodyId, _1: vec2) -> vec2:
    """Wraps `b2Vec2 b2Body_GetWorldVector(b2BodyId _0, b2Vec2 _1)`"""

def b2Body_GetLinearVelocity(_0: b2BodyId) -> vec2:
    """Wraps `b2Vec2 b2Body_GetLinearVelocity(b2BodyId _0)`"""

def b2Body_GetAngularVelocity(_0: b2BodyId) -> float:
    """Wraps `float b2Body_GetAngularVelocity(b2BodyId _0)`"""

def b2Body_SetLinearVelocity(_0: b2BodyId, _1: vec2) -> None:
    """Wraps `void b2Body_SetLinearVelocity(b2BodyId _0, b2Vec2 _1)`"""

def b2Body_SetAngularVelocity(_0: b2BodyId, _1: float) -> None:
    """Wraps `void b2Body_SetAngularVelocity(b2BodyId _0, float _1)`"""

def b2Body_ApplyForce(_0: b2BodyId, _1: vec2, _2: vec2, _3: bool) -> None:
    """Wraps `void b2Body_ApplyForce(b2BodyId _0, b2Vec2 _1, b2Vec2 _2, _Bool _3)`"""

def b2Body_ApplyForceToCenter(_0: b2BodyId, _1: vec2, _2: bool) -> None:
    """Wraps `void b2Body_ApplyForceToCenter(b2BodyId _0, b2Vec2 _1, _Bool _2)`"""

def b2Body_ApplyTorque(_0: b2BodyId, _1: float, _2: bool) -> None:
    """Wraps `void b2Body_ApplyTorque(b2BodyId _0, float _1, _Bool _2)`"""

def b2Body_ApplyLinearImpulse(_0: b2BodyId, _1: vec2, _2: vec2, _3: bool) -> None:
    """Wraps `void b2Body_ApplyLinearImpulse(b2BodyId _0, b2Vec2 _1, b2Vec2 _2, _Bool _3)`"""

def b2Body_ApplyLinearImpulseToCenter(_0: b2BodyId, _1: vec2, _2: bool) -> None:
    """Wraps `void b2Body_ApplyLinearImpulseToCenter(b2BodyId _0, b2Vec2 _1, _Bool _2)`"""

def b2Body_ApplyAngularImpulse(_0: b2BodyId, _1: float, _2: bool) -> None:
    """Wraps `void b2Body_ApplyAngularImpulse(b2BodyId _0, float _1, _Bool _2)`"""

def b2Body_GetMass(_0: b2BodyId) -> float:
    """Wraps `float b2Body_GetMass(b2BodyId _0)`"""

def b2Body_GetRotationalInertia(_0: b2BodyId) -> float:
    """Wraps `float b2Body_GetRotationalInertia(b2BodyId _0)`"""

def b2Body_GetLocalCenterOfMass(_0: b2BodyId) -> vec2:
    """Wraps `b2Vec2 b2Body_GetLocalCenterOfMass(b2BodyId _0)`"""

def b2Body_GetWorldCenterOfMass(_0: b2BodyId) -> vec2:
    """Wraps `b2Vec2 b2Body_GetWorldCenterOfMass(b2BodyId _0)`"""

def b2Body_SetMassData(_0: b2BodyId, _1: b2MassData) -> None:
    """Wraps `void b2Body_SetMassData(b2BodyId _0, b2MassData _1)`"""

def b2Body_GetMassData(_0: b2BodyId) -> b2MassData:
    """Wraps `b2MassData b2Body_GetMassData(b2BodyId _0)`"""

def b2Body_ApplyMassFromShapes(_0: b2BodyId) -> None:
    """Wraps `void b2Body_ApplyMassFromShapes(b2BodyId _0)`"""

def b2Body_SetAutomaticMass(_0: b2BodyId, _1: bool) -> None:
    """Wraps `void b2Body_SetAutomaticMass(b2BodyId _0, _Bool _1)`"""

def b2Body_GetAutomaticMass(_0: b2BodyId) -> bool:
    """Wraps `_Bool b2Body_GetAutomaticMass(b2BodyId _0)`"""

def b2Body_SetLinearDamping(_0: b2BodyId, _1: float) -> None:
    """Wraps `void b2Body_SetLinearDamping(b2BodyId _0, float _1)`"""

def b2Body_GetLinearDamping(_0: b2BodyId) -> float:
    """Wraps `float b2Body_GetLinearDamping(b2BodyId _0)`"""

def b2Body_SetAngularDamping(_0: b2BodyId, _1: float) -> None:
    """Wraps `void b2Body_SetAngularDamping(b2BodyId _0, float _1)`"""

def b2Body_GetAngularDamping(_0: b2BodyId) -> float:
    """Wraps `float b2Body_GetAngularDamping(b2BodyId _0)`"""

def b2Body_SetGravityScale(_0: b2BodyId, _1: float) -> None:
    """Wraps `void b2Body_SetGravityScale(b2BodyId _0, float _1)`"""

def b2Body_GetGravityScale(_0: b2BodyId) -> float:
    """Wraps `float b2Body_GetGravityScale(b2BodyId _0)`"""

def b2Body_IsAwake(_0: b2BodyId) -> bool:
    """Wraps `_Bool b2Body_IsAwake(b2BodyId _0)`"""

def b2Body_SetAwake(_0: b2BodyId, _1: bool) -> None:
    """Wraps `void b2Body_SetAwake(b2BodyId _0, _Bool _1)`"""

def b2Body_EnableSleep(_0: b2BodyId, _1: bool) -> None:
    """Wraps `void b2Body_EnableSleep(b2BodyId _0, _Bool _1)`"""

def b2Body_IsSleepEnabled(_0: b2BodyId) -> bool:
    """Wraps `_Bool b2Body_IsSleepEnabled(b2BodyId _0)`"""

def b2Body_SetSleepThreshold(_0: b2BodyId, _1: float) -> None:
    """Wraps `void b2Body_SetSleepThreshold(b2BodyId _0, float _1)`"""

def b2Body_GetSleepThreshold(_0: b2BodyId) -> float:
    """Wraps `float b2Body_GetSleepThreshold(b2BodyId _0)`"""

def b2Body_IsEnabled(_0: b2BodyId) -> bool:
    """Wraps `_Bool b2Body_IsEnabled(b2BodyId _0)`"""

def b2Body_Disable(_0: b2BodyId) -> None:
    """Wraps `void b2Body_Disable(b2BodyId _0)`"""

def b2Body_Enable(_0: b2BodyId) -> None:
    """Wraps `void b2Body_Enable(b2BodyId _0)`"""

def b2Body_SetFixedRotation(_0: b2BodyId, _1: bool) -> None:
    """Wraps `void b2Body_SetFixedRotation(b2BodyId _0, _Bool _1)`"""

def b2Body_IsFixedRotation(_0: b2BodyId) -> bool:
    """Wraps `_Bool b2Body_IsFixedRotation(b2BodyId _0)`"""

def b2Body_SetBullet(_0: b2BodyId, _1: bool) -> None:
    """Wraps `void b2Body_SetBullet(b2BodyId _0, _Bool _1)`"""

def b2Body_IsBullet(_0: b2BodyId) -> bool:
    """Wraps `_Bool b2Body_IsBullet(b2BodyId _0)`"""

def b2Body_EnableHitEvents(_0: b2BodyId, _1: bool) -> None:
    """Wraps `void b2Body_EnableHitEvents(b2BodyId _0, _Bool _1)`"""

def b2Body_GetShapeCount(_0: b2BodyId) -> int:
    """Wraps `int b2Body_GetShapeCount(b2BodyId _0)`"""

def b2Body_GetShapes(_0: b2BodyId, _1: intptr, _2: int) -> int:
    """Wraps `int b2Body_GetShapes(b2BodyId _0, b2ShapeId* _1, int _2)`"""

def b2Body_GetJointCount(_0: b2BodyId) -> int:
    """Wraps `int b2Body_GetJointCount(b2BodyId _0)`"""

def b2Body_GetJoints(_0: b2BodyId, _1: intptr, _2: int) -> int:
    """Wraps `int b2Body_GetJoints(b2BodyId _0, b2JointId* _1, int _2)`"""

def b2Body_GetContactCapacity(_0: b2BodyId) -> int:
    """Wraps `int b2Body_GetContactCapacity(b2BodyId _0)`"""

def b2Body_GetContactData(_0: b2BodyId, _1: intptr, _2: int) -> int:
    """Wraps `int b2Body_GetContactData(b2BodyId _0, b2ContactData* _1, int _2)`"""

def b2Body_ComputeAABB(_0: b2BodyId) -> b2AABB:
    """Wraps `b2AABB b2Body_ComputeAABB(b2BodyId _0)`"""

def b2CreateCircleShape(_0: b2BodyId, _1: intptr, _2: intptr) -> b2ShapeId:
    """Wraps `b2ShapeId b2CreateCircleShape(b2BodyId _0, const b2ShapeDef* _1, const b2Circle* _2)`"""

def b2CreateSegmentShape(_0: b2BodyId, _1: intptr, _2: intptr) -> b2ShapeId:
    """Wraps `b2ShapeId b2CreateSegmentShape(b2BodyId _0, const b2ShapeDef* _1, const b2Segment* _2)`"""

def b2CreateCapsuleShape(_0: b2BodyId, _1: intptr, _2: intptr) -> b2ShapeId:
    """Wraps `b2ShapeId b2CreateCapsuleShape(b2BodyId _0, const b2ShapeDef* _1, const b2Capsule* _2)`"""

def b2CreatePolygonShape(_0: b2BodyId, _1: intptr, _2: intptr) -> b2ShapeId:
    """Wraps `b2ShapeId b2CreatePolygonShape(b2BodyId _0, const b2ShapeDef* _1, const b2Polygon* _2)`"""

def b2DestroyShape(_0: b2ShapeId) -> None:
    """Wraps `void b2DestroyShape(b2ShapeId _0)`"""

def b2Shape_IsValid(_0: b2ShapeId) -> bool:
    """Wraps `_Bool b2Shape_IsValid(b2ShapeId _0)`"""

def b2Shape_GetType(_0: b2ShapeId) -> int:
    """Wraps `b2ShapeType b2Shape_GetType(b2ShapeId _0)`"""

def b2Shape_GetBody(_0: b2ShapeId) -> b2BodyId:
    """Wraps `b2BodyId b2Shape_GetBody(b2ShapeId _0)`"""

def b2Shape_IsSensor(_0: b2ShapeId) -> bool:
    """Wraps `_Bool b2Shape_IsSensor(b2ShapeId _0)`"""

def b2Shape_SetUserData(_0: b2ShapeId, _1: intptr) -> None:
    """Wraps `void b2Shape_SetUserData(b2ShapeId _0, void* _1)`"""

def b2Shape_GetUserData(_0: b2ShapeId) -> intptr:
    """Wraps `void* b2Shape_GetUserData(b2ShapeId _0)`"""

def b2Shape_SetDensity(_0: b2ShapeId, _1: float) -> None:
    """Wraps `void b2Shape_SetDensity(b2ShapeId _0, float _1)`"""

def b2Shape_GetDensity(_0: b2ShapeId) -> float:
    """Wraps `float b2Shape_GetDensity(b2ShapeId _0)`"""

def b2Shape_SetFriction(_0: b2ShapeId, _1: float) -> None:
    """Wraps `void b2Shape_SetFriction(b2ShapeId _0, float _1)`"""

def b2Shape_GetFriction(_0: b2ShapeId) -> float:
    """Wraps `float b2Shape_GetFriction(b2ShapeId _0)`"""

def b2Shape_SetRestitution(_0: b2ShapeId, _1: float) -> None:
    """Wraps `void b2Shape_SetRestitution(b2ShapeId _0, float _1)`"""

def b2Shape_GetRestitution(_0: b2ShapeId) -> float:
    """Wraps `float b2Shape_GetRestitution(b2ShapeId _0)`"""

def b2Shape_GetFilter(_0: b2ShapeId) -> b2Filter:
    """Wraps `b2Filter b2Shape_GetFilter(b2ShapeId _0)`"""

def b2Shape_SetFilter(_0: b2ShapeId, _1: b2Filter) -> None:
    """Wraps `void b2Shape_SetFilter(b2ShapeId _0, b2Filter _1)`"""

def b2Shape_EnableSensorEvents(_0: b2ShapeId, _1: bool) -> None:
    """Wraps `void b2Shape_EnableSensorEvents(b2ShapeId _0, _Bool _1)`"""

def b2Shape_AreSensorEventsEnabled(_0: b2ShapeId) -> bool:
    """Wraps `_Bool b2Shape_AreSensorEventsEnabled(b2ShapeId _0)`"""

def b2Shape_EnableContactEvents(_0: b2ShapeId, _1: bool) -> None:
    """Wraps `void b2Shape_EnableContactEvents(b2ShapeId _0, _Bool _1)`"""

def b2Shape_AreContactEventsEnabled(_0: b2ShapeId) -> bool:
    """Wraps `_Bool b2Shape_AreContactEventsEnabled(b2ShapeId _0)`"""

def b2Shape_EnablePreSolveEvents(_0: b2ShapeId, _1: bool) -> None:
    """Wraps `void b2Shape_EnablePreSolveEvents(b2ShapeId _0, _Bool _1)`"""

def b2Shape_ArePreSolveEventsEnabled(_0: b2ShapeId) -> bool:
    """Wraps `_Bool b2Shape_ArePreSolveEventsEnabled(b2ShapeId _0)`"""

def b2Shape_EnableHitEvents(_0: b2ShapeId, _1: bool) -> None:
    """Wraps `void b2Shape_EnableHitEvents(b2ShapeId _0, _Bool _1)`"""

def b2Shape_AreHitEventsEnabled(_0: b2ShapeId) -> bool:
    """Wraps `_Bool b2Shape_AreHitEventsEnabled(b2ShapeId _0)`"""

def b2Shape_TestPoint(_0: b2ShapeId, _1: vec2) -> bool:
    """Wraps `_Bool b2Shape_TestPoint(b2ShapeId _0, b2Vec2 _1)`"""

def b2Shape_RayCast(_0: b2ShapeId, _1: vec2, _2: vec2) -> b2CastOutput:
    """Wraps `b2CastOutput b2Shape_RayCast(b2ShapeId _0, b2Vec2 _1, b2Vec2 _2)`"""

def b2Shape_GetCircle(_0: b2ShapeId) -> b2Circle:
    """Wraps `b2Circle b2Shape_GetCircle(b2ShapeId _0)`"""

def b2Shape_GetSegment(_0: b2ShapeId) -> b2Segment:
    """Wraps `b2Segment b2Shape_GetSegment(b2ShapeId _0)`"""

def b2Shape_GetSmoothSegment(_0: b2ShapeId) -> b2SmoothSegment:
    """Wraps `b2SmoothSegment b2Shape_GetSmoothSegment(b2ShapeId _0)`"""

def b2Shape_GetCapsule(_0: b2ShapeId) -> b2Capsule:
    """Wraps `b2Capsule b2Shape_GetCapsule(b2ShapeId _0)`"""

def b2Shape_GetPolygon(_0: b2ShapeId) -> b2Polygon:
    """Wraps `b2Polygon b2Shape_GetPolygon(b2ShapeId _0)`"""

def b2Shape_SetCircle(_0: b2ShapeId, _1: intptr) -> None:
    """Wraps `void b2Shape_SetCircle(b2ShapeId _0, const b2Circle* _1)`"""

def b2Shape_SetCapsule(_0: b2ShapeId, _1: intptr) -> None:
    """Wraps `void b2Shape_SetCapsule(b2ShapeId _0, const b2Capsule* _1)`"""

def b2Shape_SetSegment(_0: b2ShapeId, _1: intptr) -> None:
    """Wraps `void b2Shape_SetSegment(b2ShapeId _0, const b2Segment* _1)`"""

def b2Shape_SetPolygon(_0: b2ShapeId, _1: intptr) -> None:
    """Wraps `void b2Shape_SetPolygon(b2ShapeId _0, const b2Polygon* _1)`"""

def b2Shape_GetParentChain(_0: b2ShapeId) -> b2ChainId:
    """Wraps `b2ChainId b2Shape_GetParentChain(b2ShapeId _0)`"""

def b2Shape_GetContactCapacity(_0: b2ShapeId) -> int:
    """Wraps `int b2Shape_GetContactCapacity(b2ShapeId _0)`"""

def b2Shape_GetContactData(_0: b2ShapeId, _1: intptr, _2: int) -> int:
    """Wraps `int b2Shape_GetContactData(b2ShapeId _0, b2ContactData* _1, int _2)`"""

def b2Shape_GetAABB(_0: b2ShapeId) -> b2AABB:
    """Wraps `b2AABB b2Shape_GetAABB(b2ShapeId _0)`"""

def b2Shape_GetClosestPoint(_0: b2ShapeId, _1: vec2) -> vec2:
    """Wraps `b2Vec2 b2Shape_GetClosestPoint(b2ShapeId _0, b2Vec2 _1)`"""

def b2CreateChain(_0: b2BodyId, _1: intptr) -> b2ChainId:
    """Wraps `b2ChainId b2CreateChain(b2BodyId _0, const b2ChainDef* _1)`"""

def b2DestroyChain(_0: b2ChainId) -> None:
    """Wraps `void b2DestroyChain(b2ChainId _0)`"""

def b2Chain_SetFriction(_0: b2ChainId, _1: float) -> None:
    """Wraps `void b2Chain_SetFriction(b2ChainId _0, float _1)`"""

def b2Chain_SetRestitution(_0: b2ChainId, _1: float) -> None:
    """Wraps `void b2Chain_SetRestitution(b2ChainId _0, float _1)`"""

def b2Chain_IsValid(_0: b2ChainId) -> bool:
    """Wraps `_Bool b2Chain_IsValid(b2ChainId _0)`"""

def b2DestroyJoint(_0: b2JointId) -> None:
    """Wraps `void b2DestroyJoint(b2JointId _0)`"""

def b2Joint_IsValid(_0: b2JointId) -> bool:
    """Wraps `_Bool b2Joint_IsValid(b2JointId _0)`"""

def b2Joint_GetType(_0: b2JointId) -> int:
    """Wraps `b2JointType b2Joint_GetType(b2JointId _0)`"""

def b2Joint_GetBodyA(_0: b2JointId) -> b2BodyId:
    """Wraps `b2BodyId b2Joint_GetBodyA(b2JointId _0)`"""

def b2Joint_GetBodyB(_0: b2JointId) -> b2BodyId:
    """Wraps `b2BodyId b2Joint_GetBodyB(b2JointId _0)`"""

def b2Joint_GetLocalAnchorA(_0: b2JointId) -> vec2:
    """Wraps `b2Vec2 b2Joint_GetLocalAnchorA(b2JointId _0)`"""

def b2Joint_GetLocalAnchorB(_0: b2JointId) -> vec2:
    """Wraps `b2Vec2 b2Joint_GetLocalAnchorB(b2JointId _0)`"""

def b2Joint_SetCollideConnected(_0: b2JointId, _1: bool) -> None:
    """Wraps `void b2Joint_SetCollideConnected(b2JointId _0, _Bool _1)`"""

def b2Joint_GetCollideConnected(_0: b2JointId) -> bool:
    """Wraps `_Bool b2Joint_GetCollideConnected(b2JointId _0)`"""

def b2Joint_SetUserData(_0: b2JointId, _1: intptr) -> None:
    """Wraps `void b2Joint_SetUserData(b2JointId _0, void* _1)`"""

def b2Joint_GetUserData(_0: b2JointId) -> intptr:
    """Wraps `void* b2Joint_GetUserData(b2JointId _0)`"""

def b2Joint_WakeBodies(_0: b2JointId) -> None:
    """Wraps `void b2Joint_WakeBodies(b2JointId _0)`"""

def b2Joint_GetConstraintForce(_0: b2JointId) -> vec2:
    """Wraps `b2Vec2 b2Joint_GetConstraintForce(b2JointId _0)`"""

def b2Joint_GetConstraintTorque(_0: b2JointId) -> float:
    """Wraps `float b2Joint_GetConstraintTorque(b2JointId _0)`"""

def b2CreateDistanceJoint(_0: b2WorldId, _1: intptr) -> b2JointId:
    """Wraps `b2JointId b2CreateDistanceJoint(b2WorldId _0, const b2DistanceJointDef* _1)`"""

def b2DistanceJoint_SetLength(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2DistanceJoint_SetLength(b2JointId _0, float _1)`"""

def b2DistanceJoint_GetLength(_0: b2JointId) -> float:
    """Wraps `float b2DistanceJoint_GetLength(b2JointId _0)`"""

def b2DistanceJoint_EnableSpring(_0: b2JointId, _1: bool) -> None:
    """Wraps `void b2DistanceJoint_EnableSpring(b2JointId _0, _Bool _1)`"""

def b2DistanceJoint_IsSpringEnabled(_0: b2JointId) -> bool:
    """Wraps `_Bool b2DistanceJoint_IsSpringEnabled(b2JointId _0)`"""

def b2DistanceJoint_SetSpringHertz(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2DistanceJoint_SetSpringHertz(b2JointId _0, float _1)`"""

def b2DistanceJoint_SetSpringDampingRatio(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2DistanceJoint_SetSpringDampingRatio(b2JointId _0, float _1)`"""

def b2DistanceJoint_GetSpringHertz(_0: b2JointId) -> float:
    """Wraps `float b2DistanceJoint_GetSpringHertz(b2JointId _0)`"""

def b2DistanceJoint_GetSpringDampingRatio(_0: b2JointId) -> float:
    """Wraps `float b2DistanceJoint_GetSpringDampingRatio(b2JointId _0)`"""

def b2DistanceJoint_EnableLimit(_0: b2JointId, _1: bool) -> None:
    """Wraps `void b2DistanceJoint_EnableLimit(b2JointId _0, _Bool _1)`"""

def b2DistanceJoint_IsLimitEnabled(_0: b2JointId) -> bool:
    """Wraps `_Bool b2DistanceJoint_IsLimitEnabled(b2JointId _0)`"""

def b2DistanceJoint_SetLengthRange(_0: b2JointId, _1: float, _2: float) -> None:
    """Wraps `void b2DistanceJoint_SetLengthRange(b2JointId _0, float _1, float _2)`"""

def b2DistanceJoint_GetMinLength(_0: b2JointId) -> float:
    """Wraps `float b2DistanceJoint_GetMinLength(b2JointId _0)`"""

def b2DistanceJoint_GetMaxLength(_0: b2JointId) -> float:
    """Wraps `float b2DistanceJoint_GetMaxLength(b2JointId _0)`"""

def b2DistanceJoint_GetCurrentLength(_0: b2JointId) -> float:
    """Wraps `float b2DistanceJoint_GetCurrentLength(b2JointId _0)`"""

def b2DistanceJoint_EnableMotor(_0: b2JointId, _1: bool) -> None:
    """Wraps `void b2DistanceJoint_EnableMotor(b2JointId _0, _Bool _1)`"""

def b2DistanceJoint_IsMotorEnabled(_0: b2JointId) -> bool:
    """Wraps `_Bool b2DistanceJoint_IsMotorEnabled(b2JointId _0)`"""

def b2DistanceJoint_SetMotorSpeed(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2DistanceJoint_SetMotorSpeed(b2JointId _0, float _1)`"""

def b2DistanceJoint_GetMotorSpeed(_0: b2JointId) -> float:
    """Wraps `float b2DistanceJoint_GetMotorSpeed(b2JointId _0)`"""

def b2DistanceJoint_SetMaxMotorForce(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2DistanceJoint_SetMaxMotorForce(b2JointId _0, float _1)`"""

def b2DistanceJoint_GetMaxMotorForce(_0: b2JointId) -> float:
    """Wraps `float b2DistanceJoint_GetMaxMotorForce(b2JointId _0)`"""

def b2DistanceJoint_GetMotorForce(_0: b2JointId) -> float:
    """Wraps `float b2DistanceJoint_GetMotorForce(b2JointId _0)`"""

def b2CreateMotorJoint(_0: b2WorldId, _1: intptr) -> b2JointId:
    """Wraps `b2JointId b2CreateMotorJoint(b2WorldId _0, const b2MotorJointDef* _1)`"""

def b2MotorJoint_SetLinearOffset(_0: b2JointId, _1: vec2) -> None:
    """Wraps `void b2MotorJoint_SetLinearOffset(b2JointId _0, b2Vec2 _1)`"""

def b2MotorJoint_GetLinearOffset(_0: b2JointId) -> vec2:
    """Wraps `b2Vec2 b2MotorJoint_GetLinearOffset(b2JointId _0)`"""

def b2MotorJoint_SetAngularOffset(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2MotorJoint_SetAngularOffset(b2JointId _0, float _1)`"""

def b2MotorJoint_GetAngularOffset(_0: b2JointId) -> float:
    """Wraps `float b2MotorJoint_GetAngularOffset(b2JointId _0)`"""

def b2MotorJoint_SetMaxForce(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2MotorJoint_SetMaxForce(b2JointId _0, float _1)`"""

def b2MotorJoint_GetMaxForce(_0: b2JointId) -> float:
    """Wraps `float b2MotorJoint_GetMaxForce(b2JointId _0)`"""

def b2MotorJoint_SetMaxTorque(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2MotorJoint_SetMaxTorque(b2JointId _0, float _1)`"""

def b2MotorJoint_GetMaxTorque(_0: b2JointId) -> float:
    """Wraps `float b2MotorJoint_GetMaxTorque(b2JointId _0)`"""

def b2MotorJoint_SetCorrectionFactor(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2MotorJoint_SetCorrectionFactor(b2JointId _0, float _1)`"""

def b2MotorJoint_GetCorrectionFactor(_0: b2JointId) -> float:
    """Wraps `float b2MotorJoint_GetCorrectionFactor(b2JointId _0)`"""

def b2CreateMouseJoint(_0: b2WorldId, _1: intptr) -> b2JointId:
    """Wraps `b2JointId b2CreateMouseJoint(b2WorldId _0, const b2MouseJointDef* _1)`"""

def b2MouseJoint_SetTarget(_0: b2JointId, _1: vec2) -> None:
    """Wraps `void b2MouseJoint_SetTarget(b2JointId _0, b2Vec2 _1)`"""

def b2MouseJoint_GetTarget(_0: b2JointId) -> vec2:
    """Wraps `b2Vec2 b2MouseJoint_GetTarget(b2JointId _0)`"""

def b2MouseJoint_SetSpringHertz(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2MouseJoint_SetSpringHertz(b2JointId _0, float _1)`"""

def b2MouseJoint_GetSpringHertz(_0: b2JointId) -> float:
    """Wraps `float b2MouseJoint_GetSpringHertz(b2JointId _0)`"""

def b2MouseJoint_SetSpringDampingRatio(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2MouseJoint_SetSpringDampingRatio(b2JointId _0, float _1)`"""

def b2MouseJoint_GetSpringDampingRatio(_0: b2JointId) -> float:
    """Wraps `float b2MouseJoint_GetSpringDampingRatio(b2JointId _0)`"""

def b2MouseJoint_SetMaxForce(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2MouseJoint_SetMaxForce(b2JointId _0, float _1)`"""

def b2MouseJoint_GetMaxForce(_0: b2JointId) -> float:
    """Wraps `float b2MouseJoint_GetMaxForce(b2JointId _0)`"""

def b2CreatePrismaticJoint(_0: b2WorldId, _1: intptr) -> b2JointId:
    """Wraps `b2JointId b2CreatePrismaticJoint(b2WorldId _0, const b2PrismaticJointDef* _1)`"""

def b2PrismaticJoint_EnableSpring(_0: b2JointId, _1: bool) -> None:
    """Wraps `void b2PrismaticJoint_EnableSpring(b2JointId _0, _Bool _1)`"""

def b2PrismaticJoint_IsSpringEnabled(_0: b2JointId) -> bool:
    """Wraps `_Bool b2PrismaticJoint_IsSpringEnabled(b2JointId _0)`"""

def b2PrismaticJoint_SetSpringHertz(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2PrismaticJoint_SetSpringHertz(b2JointId _0, float _1)`"""

def b2PrismaticJoint_GetSpringHertz(_0: b2JointId) -> float:
    """Wraps `float b2PrismaticJoint_GetSpringHertz(b2JointId _0)`"""

def b2PrismaticJoint_SetSpringDampingRatio(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2PrismaticJoint_SetSpringDampingRatio(b2JointId _0, float _1)`"""

def b2PrismaticJoint_GetSpringDampingRatio(_0: b2JointId) -> float:
    """Wraps `float b2PrismaticJoint_GetSpringDampingRatio(b2JointId _0)`"""

def b2PrismaticJoint_EnableLimit(_0: b2JointId, _1: bool) -> None:
    """Wraps `void b2PrismaticJoint_EnableLimit(b2JointId _0, _Bool _1)`"""

def b2PrismaticJoint_IsLimitEnabled(_0: b2JointId) -> bool:
    """Wraps `_Bool b2PrismaticJoint_IsLimitEnabled(b2JointId _0)`"""

def b2PrismaticJoint_GetLowerLimit(_0: b2JointId) -> float:
    """Wraps `float b2PrismaticJoint_GetLowerLimit(b2JointId _0)`"""

def b2PrismaticJoint_GetUpperLimit(_0: b2JointId) -> float:
    """Wraps `float b2PrismaticJoint_GetUpperLimit(b2JointId _0)`"""

def b2PrismaticJoint_SetLimits(_0: b2JointId, _1: float, _2: float) -> None:
    """Wraps `void b2PrismaticJoint_SetLimits(b2JointId _0, float _1, float _2)`"""

def b2PrismaticJoint_EnableMotor(_0: b2JointId, _1: bool) -> None:
    """Wraps `void b2PrismaticJoint_EnableMotor(b2JointId _0, _Bool _1)`"""

def b2PrismaticJoint_IsMotorEnabled(_0: b2JointId) -> bool:
    """Wraps `_Bool b2PrismaticJoint_IsMotorEnabled(b2JointId _0)`"""

def b2PrismaticJoint_SetMotorSpeed(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2PrismaticJoint_SetMotorSpeed(b2JointId _0, float _1)`"""

def b2PrismaticJoint_GetMotorSpeed(_0: b2JointId) -> float:
    """Wraps `float b2PrismaticJoint_GetMotorSpeed(b2JointId _0)`"""

def b2PrismaticJoint_SetMaxMotorForce(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2PrismaticJoint_SetMaxMotorForce(b2JointId _0, float _1)`"""

def b2PrismaticJoint_GetMaxMotorForce(_0: b2JointId) -> float:
    """Wraps `float b2PrismaticJoint_GetMaxMotorForce(b2JointId _0)`"""

def b2PrismaticJoint_GetMotorForce(_0: b2JointId) -> float:
    """Wraps `float b2PrismaticJoint_GetMotorForce(b2JointId _0)`"""

def b2CreateRevoluteJoint(_0: b2WorldId, _1: intptr) -> b2JointId:
    """Wraps `b2JointId b2CreateRevoluteJoint(b2WorldId _0, const b2RevoluteJointDef* _1)`"""

def b2RevoluteJoint_EnableSpring(_0: b2JointId, _1: bool) -> None:
    """Wraps `void b2RevoluteJoint_EnableSpring(b2JointId _0, _Bool _1)`"""

def b2RevoluteJoint_IsSpringEnabled(_0: b2JointId) -> bool:
    """Wraps `_Bool b2RevoluteJoint_IsSpringEnabled(b2JointId _0)`"""

def b2RevoluteJoint_SetSpringHertz(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2RevoluteJoint_SetSpringHertz(b2JointId _0, float _1)`"""

def b2RevoluteJoint_GetSpringHertz(_0: b2JointId) -> float:
    """Wraps `float b2RevoluteJoint_GetSpringHertz(b2JointId _0)`"""

def b2RevoluteJoint_SetSpringDampingRatio(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2RevoluteJoint_SetSpringDampingRatio(b2JointId _0, float _1)`"""

def b2RevoluteJoint_GetSpringDampingRatio(_0: b2JointId) -> float:
    """Wraps `float b2RevoluteJoint_GetSpringDampingRatio(b2JointId _0)`"""

def b2RevoluteJoint_GetAngle(_0: b2JointId) -> float:
    """Wraps `float b2RevoluteJoint_GetAngle(b2JointId _0)`"""

def b2RevoluteJoint_EnableLimit(_0: b2JointId, _1: bool) -> None:
    """Wraps `void b2RevoluteJoint_EnableLimit(b2JointId _0, _Bool _1)`"""

def b2RevoluteJoint_IsLimitEnabled(_0: b2JointId) -> bool:
    """Wraps `_Bool b2RevoluteJoint_IsLimitEnabled(b2JointId _0)`"""

def b2RevoluteJoint_GetLowerLimit(_0: b2JointId) -> float:
    """Wraps `float b2RevoluteJoint_GetLowerLimit(b2JointId _0)`"""

def b2RevoluteJoint_GetUpperLimit(_0: b2JointId) -> float:
    """Wraps `float b2RevoluteJoint_GetUpperLimit(b2JointId _0)`"""

def b2RevoluteJoint_SetLimits(_0: b2JointId, _1: float, _2: float) -> None:
    """Wraps `void b2RevoluteJoint_SetLimits(b2JointId _0, float _1, float _2)`"""

def b2RevoluteJoint_EnableMotor(_0: b2JointId, _1: bool) -> None:
    """Wraps `void b2RevoluteJoint_EnableMotor(b2JointId _0, _Bool _1)`"""

def b2RevoluteJoint_IsMotorEnabled(_0: b2JointId) -> bool:
    """Wraps `_Bool b2RevoluteJoint_IsMotorEnabled(b2JointId _0)`"""

def b2RevoluteJoint_SetMotorSpeed(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2RevoluteJoint_SetMotorSpeed(b2JointId _0, float _1)`"""

def b2RevoluteJoint_GetMotorSpeed(_0: b2JointId) -> float:
    """Wraps `float b2RevoluteJoint_GetMotorSpeed(b2JointId _0)`"""

def b2RevoluteJoint_GetMotorTorque(_0: b2JointId) -> float:
    """Wraps `float b2RevoluteJoint_GetMotorTorque(b2JointId _0)`"""

def b2RevoluteJoint_SetMaxMotorTorque(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2RevoluteJoint_SetMaxMotorTorque(b2JointId _0, float _1)`"""

def b2RevoluteJoint_GetMaxMotorTorque(_0: b2JointId) -> float:
    """Wraps `float b2RevoluteJoint_GetMaxMotorTorque(b2JointId _0)`"""

def b2CreateWeldJoint(_0: b2WorldId, _1: intptr) -> b2JointId:
    """Wraps `b2JointId b2CreateWeldJoint(b2WorldId _0, const b2WeldJointDef* _1)`"""

def b2WeldJoint_SetLinearHertz(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2WeldJoint_SetLinearHertz(b2JointId _0, float _1)`"""

def b2WeldJoint_GetLinearHertz(_0: b2JointId) -> float:
    """Wraps `float b2WeldJoint_GetLinearHertz(b2JointId _0)`"""

def b2WeldJoint_SetLinearDampingRatio(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2WeldJoint_SetLinearDampingRatio(b2JointId _0, float _1)`"""

def b2WeldJoint_GetLinearDampingRatio(_0: b2JointId) -> float:
    """Wraps `float b2WeldJoint_GetLinearDampingRatio(b2JointId _0)`"""

def b2WeldJoint_SetAngularHertz(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2WeldJoint_SetAngularHertz(b2JointId _0, float _1)`"""

def b2WeldJoint_GetAngularHertz(_0: b2JointId) -> float:
    """Wraps `float b2WeldJoint_GetAngularHertz(b2JointId _0)`"""

def b2WeldJoint_SetAngularDampingRatio(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2WeldJoint_SetAngularDampingRatio(b2JointId _0, float _1)`"""

def b2WeldJoint_GetAngularDampingRatio(_0: b2JointId) -> float:
    """Wraps `float b2WeldJoint_GetAngularDampingRatio(b2JointId _0)`"""

def b2CreateWheelJoint(_0: b2WorldId, _1: intptr) -> b2JointId:
    """Wraps `b2JointId b2CreateWheelJoint(b2WorldId _0, const b2WheelJointDef* _1)`"""

def b2WheelJoint_EnableSpring(_0: b2JointId, _1: bool) -> None:
    """Wraps `void b2WheelJoint_EnableSpring(b2JointId _0, _Bool _1)`"""

def b2WheelJoint_IsSpringEnabled(_0: b2JointId) -> bool:
    """Wraps `_Bool b2WheelJoint_IsSpringEnabled(b2JointId _0)`"""

def b2WheelJoint_SetSpringHertz(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2WheelJoint_SetSpringHertz(b2JointId _0, float _1)`"""

def b2WheelJoint_GetSpringHertz(_0: b2JointId) -> float:
    """Wraps `float b2WheelJoint_GetSpringHertz(b2JointId _0)`"""

def b2WheelJoint_SetSpringDampingRatio(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2WheelJoint_SetSpringDampingRatio(b2JointId _0, float _1)`"""

def b2WheelJoint_GetSpringDampingRatio(_0: b2JointId) -> float:
    """Wraps `float b2WheelJoint_GetSpringDampingRatio(b2JointId _0)`"""

def b2WheelJoint_EnableLimit(_0: b2JointId, _1: bool) -> None:
    """Wraps `void b2WheelJoint_EnableLimit(b2JointId _0, _Bool _1)`"""

def b2WheelJoint_IsLimitEnabled(_0: b2JointId) -> bool:
    """Wraps `_Bool b2WheelJoint_IsLimitEnabled(b2JointId _0)`"""

def b2WheelJoint_GetLowerLimit(_0: b2JointId) -> float:
    """Wraps `float b2WheelJoint_GetLowerLimit(b2JointId _0)`"""

def b2WheelJoint_GetUpperLimit(_0: b2JointId) -> float:
    """Wraps `float b2WheelJoint_GetUpperLimit(b2JointId _0)`"""

def b2WheelJoint_SetLimits(_0: b2JointId, _1: float, _2: float) -> None:
    """Wraps `void b2WheelJoint_SetLimits(b2JointId _0, float _1, float _2)`"""

def b2WheelJoint_EnableMotor(_0: b2JointId, _1: bool) -> None:
    """Wraps `void b2WheelJoint_EnableMotor(b2JointId _0, _Bool _1)`"""

def b2WheelJoint_IsMotorEnabled(_0: b2JointId) -> bool:
    """Wraps `_Bool b2WheelJoint_IsMotorEnabled(b2JointId _0)`"""

def b2WheelJoint_SetMotorSpeed(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2WheelJoint_SetMotorSpeed(b2JointId _0, float _1)`"""

def b2WheelJoint_GetMotorSpeed(_0: b2JointId) -> float:
    """Wraps `float b2WheelJoint_GetMotorSpeed(b2JointId _0)`"""

def b2WheelJoint_SetMaxMotorTorque(_0: b2JointId, _1: float) -> None:
    """Wraps `void b2WheelJoint_SetMaxMotorTorque(b2JointId _0, float _1)`"""

def b2WheelJoint_GetMaxMotorTorque(_0: b2JointId) -> float:
    """Wraps `float b2WheelJoint_GetMaxMotorTorque(b2JointId _0)`"""

def b2WheelJoint_GetMotorTorque(_0: b2JointId) -> float:
    """Wraps `float b2WheelJoint_GetMotorTorque(b2JointId _0)`"""

# aliases
# enums
b2_toiStateUnknown: int
b2_toiStateFailed: int
b2_toiStateOverlapped: int
b2_toiStateHit: int
b2_toiStateSeparated: int
b2_staticBody: int
b2_kinematicBody: int
b2_dynamicBody: int
b2_bodyTypeCount: int
b2_circleShape: int
b2_capsuleShape: int
b2_segmentShape: int
b2_polygonShape: int
b2_smoothSegmentShape: int
b2_shapeTypeCount: int
b2_distanceJoint: int
b2_motorJoint: int
b2_mouseJoint: int
b2_prismaticJoint: int
b2_revoluteJoint: int
b2_weldJoint: int
b2_wheelJoint: int
b2_colorAliceBlue: int
b2_colorAntiqueWhite: int
b2_colorAquamarine: int
b2_colorAzure: int
b2_colorBeige: int
b2_colorBisque: int
b2_colorBlack: int
b2_colorBlanchedAlmond: int
b2_colorBlue: int
b2_colorBlueViolet: int
b2_colorBrown: int
b2_colorBurlywood: int
b2_colorCadetBlue: int
b2_colorChartreuse: int
b2_colorChocolate: int
b2_colorCoral: int
b2_colorCornflowerBlue: int
b2_colorCornsilk: int
b2_colorCrimson: int
b2_colorCyan: int
b2_colorDarkBlue: int
b2_colorDarkCyan: int
b2_colorDarkGoldenrod: int
b2_colorDarkGray: int
b2_colorDarkGreen: int
b2_colorDarkKhaki: int
b2_colorDarkMagenta: int
b2_colorDarkOliveGreen: int
b2_colorDarkOrange: int
b2_colorDarkOrchid: int
b2_colorDarkRed: int
b2_colorDarkSalmon: int
b2_colorDarkSeaGreen: int
b2_colorDarkSlateBlue: int
b2_colorDarkSlateGray: int
b2_colorDarkTurquoise: int
b2_colorDarkViolet: int
b2_colorDeepPink: int
b2_colorDeepSkyBlue: int
b2_colorDimGray: int
b2_colorDodgerBlue: int
b2_colorFirebrick: int
b2_colorFloralWhite: int
b2_colorForestGreen: int
b2_colorGainsboro: int
b2_colorGhostWhite: int
b2_colorGold: int
b2_colorGoldenrod: int
b2_colorGray: int
b2_colorGray1: int
b2_colorGray2: int
b2_colorGray3: int
b2_colorGray4: int
b2_colorGray5: int
b2_colorGray6: int
b2_colorGray7: int
b2_colorGray8: int
b2_colorGray9: int
b2_colorGreen: int
b2_colorGreenYellow: int
b2_colorHoneydew: int
b2_colorHotPink: int
b2_colorIndianRed: int
b2_colorIndigo: int
b2_colorIvory: int
b2_colorKhaki: int
b2_colorLavender: int
b2_colorLavenderBlush: int
b2_colorLawnGreen: int
b2_colorLemonChiffon: int
b2_colorLightBlue: int
b2_colorLightCoral: int
b2_colorLightCyan: int
b2_colorLightGoldenrod: int
b2_colorLightGoldenrodYellow: int
b2_colorLightGray: int
b2_colorLightGreen: int
b2_colorLightPink: int
b2_colorLightSalmon: int
b2_colorLightSeaGreen: int
b2_colorLightSkyBlue: int
b2_colorLightSlateBlue: int
b2_colorLightSlateGray: int
b2_colorLightSteelBlue: int
b2_colorLightYellow: int
b2_colorLimeGreen: int
b2_colorLinen: int
b2_colorMagenta: int
b2_colorMaroon: int
b2_colorMediumAquamarine: int
b2_colorMediumBlue: int
b2_colorMediumOrchid: int
b2_colorMediumPurple: int
b2_colorMediumSeaGreen: int
b2_colorMediumSlateBlue: int
b2_colorMediumSpringGreen: int
b2_colorMediumTurquoise: int
b2_colorMediumVioletRed: int
b2_colorMidnightBlue: int
b2_colorMintCream: int
b2_colorMistyRose: int
b2_colorMoccasin: int
b2_colorNavajoWhite: int
b2_colorNavyBlue: int
b2_colorOldLace: int
b2_colorOlive: int
b2_colorOliveDrab: int
b2_colorOrange: int
b2_colorOrangeRed: int
b2_colorOrchid: int
b2_colorPaleGoldenrod: int
b2_colorPaleGreen: int
b2_colorPaleTurquoise: int
b2_colorPaleVioletRed: int
b2_colorPapayaWhip: int
b2_colorPeachPuff: int
b2_colorPeru: int
b2_colorPink: int
b2_colorPlum: int
b2_colorPowderBlue: int
b2_colorPurple: int
b2_colorRebeccaPurple: int
b2_colorRed: int
b2_colorRosyBrown: int
b2_colorRoyalBlue: int
b2_colorSaddleBrown: int
b2_colorSalmon: int
b2_colorSandyBrown: int
b2_colorSeaGreen: int
b2_colorSeashell: int
b2_colorSienna: int
b2_colorSilver: int
b2_colorSkyBlue: int
b2_colorSlateBlue: int
b2_colorSlateGray: int
b2_colorSnow: int
b2_colorSpringGreen: int
b2_colorSteelBlue: int
b2_colorTan: int
b2_colorTeal: int
b2_colorThistle: int
b2_colorTomato: int
b2_colorTurquoise: int
b2_colorViolet: int
b2_colorVioletRed: int
b2_colorWheat: int
b2_colorWhite: int
b2_colorWhiteSmoke: int
b2_colorYellow: int
b2_colorYellowGreen: int
b2_colorBox2DRed: int
b2_colorBox2DBlue: int
b2_colorBox2DGreen: int
b2_colorBox2DYellow: int