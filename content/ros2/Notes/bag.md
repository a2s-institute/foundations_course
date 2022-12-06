<!-- bag files -->
## Bag files

<!-- make directory for bag files -->
### Make directory for bag files

```
mkdir bag_files
cd bag_files
```

<!-- record bag file -->
### Record bag file

`ros2 bag record /turtle1/cmd_vel`

<!-- record bag file with multiple topics -->
### Record bag file with multiple topics
`ros2 bag record -o subset /turtle1/cmd_vel /turtle1/pose`

<!-- record all topics -->
### Record all topics
`-a`

<!-- check bag info -->
### Check bag info
`ros2 bag info subset`

<!-- play bag file -->
### Play bag file
`ros2 bag play subset`