# Cub3D

A 3D rendering project using raycasting, inspired by the classic game Wolfenstein 3D.

## Project Structure

```
.
├── sources/
│   ├── get_next_line/                   # Line reading utility
│   ├── libft/                           # Custom C library
│   ├── utils/                           # Utility functions
│   ├── wall_casting.c                   # Raycasting implementation
│   ├── safe_exit.c                      # Cleanup memory leaks
│   ├── handle_key_inputs.c              # Keyboard input handling
│   ├── x11_connect.c
│   └── bonus/                           # Bonus features
│       ├── raycasting/                  # Bonus raycasting features
│       │   └── ceilling_floor_casting/
│       ├── bonus_load_textures.c        # Bonus texture loading
│       └── bonus_safe_exit.c
├── includes/
├── maps/                                # Map files (*.cub)
└── textures/
```

## Requirements

- GCC compiler
- X11 libraries
- Make

## Building

```bash
# Regular version
make minilibx && make && make clean

# Bonus version
make minilibx && make bonus && make clean
```

## Running

```bash
# Regular version
./cub3D maps/map1.cub

# Bonus version
./bonus_cub3D maps/map1.cub
```

## Controls

- WASD: Move player
- Arrow keys: Rotate view
- ESC: Exit game

## Map Format

Maps are defined in `.cub` files with the following structure:

```
NO textures/north.xpm    # North wall texture
SO textures/south.xpm    # South wall texture
WE textures/west.xpm     # West wall texture
EA textures/east.xpm     # East wall texture

F 220,100,0              # Floor color (RGB)
C 225,30,0               # Ceiling color (RGB)

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

- 1: Wall
- 0: Empty space
- N/S/E/W: Player starting position and direction
- Space: Optional space (ignored)

## Features

### Regular Version
- 3D rendering using raycasting
- Wall textures
- Floor and ceiling colors
- Player movement and rotation
- Collision detection
- Window resizing
- Error handling

### Bonus Features
- Ceiling and floor textures
- Enhanced texture loading
- Improved cleanup and error handling

## Error Handling

The program handles various error cases:
- Invalid map format
- Missing textures
- Invalid texture paths
- Memory leaks (in bonus version)
