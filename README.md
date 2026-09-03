NatureOverhaul Object Spawner Conversion for DayZ 1.29

Discord: DAyz Game Over: https://discord.gg/ap6kFWgKjC

Original placement work: Kaffeina / NatureOverhaul.
Resurrected by McBrutal.

(I am looking for volunteers to correct edits to these files and also to help finish Chernarus)

Copy the custom folder into mpmissions/dayzOffline.chernarusplus/.
Merge the array from objectSpawnersArr.json into WorldsData in cfgGameplay.json.
Ensure enableCfgGameplayFile = 1 in serverDZ.cfg.

These placements use original NatureOverhaul coordinates and current Object Spawner fields: name, pos, ypr, scale.

Keep BuilderItems loaded on both server and clients because the placement set uses bldr_ classnames.

Do not also load the original NatureOverhaul script mod or every object will be duplicated.

The inactive WN9, bridgebase, Electro and commented Nizhnoye sections were not exported.

The two BuilderItems models reported unsafe after DayZ 1.29 (pond_small_14.p3d and wooden_log.p3d) are not present.

Enable location files gradually and watch the RPT and server FPS; 8,000+ static objects can be expensive.

Files: 25
Objects: 8297
Exact duplicates removed: 13

Tulga.json: 97

Msta.json: 124

Balota_circel.json: 367

Balota_city.json: 154

Komarovo.json: 229

SmallCityNorthToBalota.json: 206

Novy_Sober.json: 475

Polana.json: 365

Gorka.json: 428

Vavilovo.json: 451

Khelm.json: 371

Dolina.json: 452

DolinaSmallStreet.json: 784

Mogilevka.json: 432

PustaandCircelChernos2.json: 512

NadezhdinoandSmallCityRoad.json: 380

Pulkovo.json: 338

Pogorevka.json: 300

Rogovo.json: 280

Pavlovo.json: 504

Bor.json: 298

TrainStationChernogorsk.json: 102

WindPowers.json: 31

Solnichniy.json: 310

Kamyshovo.json: 307
