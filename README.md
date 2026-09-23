# Lab 2 Physics Interaction

Lab 2 Physics Interaction (The assignment says Lab one but I assuming this is an error.)

Control is E to add impulse it is called interact

ImpulseDemoComponent is the component name

Interaction Distance and Impulse Strength are the two editor configurable variables

Lab 3 - Projectile System
C++ Projectile Class

Created a reusable C++ AProjectile Actor. The projectile contains a physics-enabled Static Mesh component, configurable launch strength, and automatic lifetime cleanup.

Blueprint Child

Created BP_Projectile as a Blueprint child of the C++ projectile class. The Blueprint is responsible for assigning the projectile mesh, material, and designer-facing configuration values.

Launch Control

The player uses the Fire input to spawn a projectile. C++ obtains the player's current camera location and rotation, calculates a forward direction, and spawns the projectile slightly in front of the camera.

Configurable Values

The projectile's launch strength and lifetime can be changed through the Blueprint/Editor without modifying the C++ launch logic.

Physics and Collision

The projectile uses a physics-enabled Static Mesh and applies an impulse in the camera's forward direction. It can collide with and physically affect physics-enabled objects in the test environment.

Independent Extension

Added a launch cooldown that limits how frequently the player can spawn projectiles. This prevents unlimited rapid-fire spawning and provides a simple gameplay control.
