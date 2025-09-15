Geo Integration

- Capture GPS coordinates on scan/write:

final pos = await Geolocator.getCurrentPosition();

- Save {tagUid, lat, lon} in app DB (not on tag).

- Later: display on a map or detect misplaced tags.