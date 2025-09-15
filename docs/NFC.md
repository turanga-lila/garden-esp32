# NFC Integration (NTAG215 + Flutter)

## NFC Basics
- **Passive tags** (no battery) powered by the phone’s NFC field.
- Operates at **13.56 MHz** (ISO 14443-A for NTAG21x).
- **NDEF (NFC Data Exchange Format)** is the standard for storing data (URL, text, MIME).

## Tag Choice
- **NTAG215** (Type 2 NFC Forum tag):
  - ~504 bytes usable.
  - Great for short URLs + text.
  - Supported on Android + iOS.
- Avoid MIFARE Classic (iOS doesn’t support it).

## Best Practices
- Store **small payloads** (e.g., URL with UUID).
- Don’t rewrite tags frequently (limited write cycles).
- Keep sensitive data in app/cloud; tag holds only ID/URL.
- Delay permanent **write-locking** until you’re sure.

## Content Strategy
- **URL record**: `https://garden.app/plant/84e9...`
- **Optional text record**: `"Cherry tree in yard"`
- Associate NFC **tag UID** with app DB entry (plant, tree, or location).

## Flutter Libraries
- [`nfc_manager`](https://pub.dev/packages/nfc_manager) → cross-platform, recommended.
- [`ndef`](https://pub.dev/packages/ndef`) → encode/decode NDEF records.
- [`flutter_nfc_kit`](https://pub.dev/packages/flutter_nfc_kit) → low-level access, needed if password protection.

## Code Sketch
```dart
import 'package:nfc_manager/nfc_manager.dart';
import 'package:ndef/ndef.dart' as ndef;

Future<void> readTag() async {
  await NfcManager.instance.startSession(onDiscovered: (tag) async {
    final ndefTag = Ndef.from(tag);
    if (ndefTag != null) {
      final message = await ndefTag.read();
      for (final record in message.records) {
        final rec = ndef.NDEFRecord.fromNdefRecord(record);
        if (rec is ndef.UriRecord) print("URI: ${rec.uri}");
      }
    }
    await NfcManager.instance.stopSession();
  });
}
