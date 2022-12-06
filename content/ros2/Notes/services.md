<!-- services -->
## Services

<!-- list the services -->
### List the services
`ros2 service list`

<!-- get the service type -->
### Get the service type
`ros2 service type /clear`

<!-- list services with type -->
### List services with type
`ros2 service list -t`

<!-- find service based on type -->
### Find service based on type
`ros2 service find std_srvs/srv/Empty`

<!-- get the structure of the service -->
### Get the structure of the service
`ros2 interface show std_srvs/srv/Empty`

`ros2 interface show turtlesim/srv/Spawn`

<!-- call the service -->
### Call the service
`ros2 service call /clear std_srvs/srv/Empty`

`ros2 service call /spawn turtlesim/srv/Spawn "{x: 2, y: 2, theta: 0.2, name: ''}"`

