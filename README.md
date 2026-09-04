# Nature Overhaul Redux

Object Spawner conversion of NatureOverhaul for DayZ 1.29.

Original placement work: Kaffeina / NatureOverhaul

Redux and conversion: McBrutal

Discord: [DayZ Game Over](https://discord.gg/ap6kFWgKjC)

## Installation

1. Copy the `custom` folder into `mpmissions/dayzOffline.chernarusplus/`.
2. Merge the array from `objectSpawnersArr.json` into `WorldsData` in `cfgGameplay.json`.
3. Set `enableCfgGameplayFile = 1` in `serverDZ.cfg`.
4. Keep BuilderItems loaded on the server and all clients. A small number of placements still require it.

Do not also load the original NatureOverhaul script mod. Doing so will spawn a second copy of every placement.

Enable location files gradually while watching the RPT log and server FPS. The complete set contains more than 8,000 objects.

## DayZ 1.29 correction audit

The conversion was checked against all active `SpawnObject` calls in the original mission scripts and every used BuilderItems class in the supplied converted configs. This was a full object audit, not a vegetation-only pass.

- 25 JSON files validated
- 8,297 distinct placements preserved
- 8,310 active original calls accounted for
- 13 exact adjacent duplicates intentionally removed
- 0 distinct original placements missing
- 0 unexpected placements added
- 8,100 placements corrected across 191 class mappings
- 1,416 trees and bushes changed to interactive DayZ classes
- 6,450 grass, ivy, and cut-tree placements changed to supported native P3D paths
- 234 props, structures, wrecks, roadblocks, walls, furniture, garbage, rubble, and lamps changed to exact-model native static classes
- 26 BuilderItems placements retained across 10 classes where no safe behavior-preserving native substitute exists

Positions, rotations, scales, array order, and all non-name fields remain unchanged.

The interactive vegetation reference was the official DayZ 1.29.163709 script definition set. Static classes were checked against a current DayZ configuration dump dated May 26, 2026.

### Why BuilderItems is still required

Most BuilderItems wrappers were replaced, but 26 placements intentionally remain:

| Class | Placements | Reason |
| --- | ---: | --- |
| `bldr_Garbage_Pile8` | 1 | No exact behavior-preserving native standalone class |
| `bldr_HouseB_Tenement_DayZ_airplane` | 1 | No exact behavior-preserving native standalone class |
| `bldr_PortableGasLamp` | 1 | Native `PortableGasLamp` is a pickup item, not static scenery |
| `bldr_Rubble_DirtPile_Small` | 1 | No exact behavior-preserving native standalone class |
| `bldr_Slum_Roof4` | 1 | No exact behavior-preserving native standalone class |
| `bldr_T34` | 10 | No exact behavior-preserving native standalone class |
| `bldr_tent_boxwooden` | 4 | No exact behavior-preserving native standalone class |
| `bldr_tent_chair` | 4 | No exact behavior-preserving native standalone class |
| `bldr_tent_gunrack` | 2 | No exact behavior-preserving native standalone class |
| `bldr_wall_gate_kolchoz` | 1 | No exact behavior-preserving native standalone class |

Approximate visual replacements were not used. In particular, `bldr_PortableGasLamp` was kept so scenery does not become a pickup-capable inventory item.

### Books and other pickup items

No active or commented original `SpawnObject` call uses a book, paper, magazine, or newspaper class. No book was omitted from the JSON conversion, and this correction does not introduce any new inventory classes.

## Scope notes

The inactive WN9, bridgebase, Electro, and commented Nizhnoye sections were not exported. The two BuilderItems models previously reported unsafe after DayZ 1.29, `pond_small_14.p3d` and `wooden_log.p3d`, are not present.

The repository contains 25 location files and 8,297 objects. See [`docs/audit`](docs/audit) for the complete source comparison, every class disposition, every replacement mapping, and all intentionally retained BuilderItems classes.
