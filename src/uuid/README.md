# UUID

## Summary

Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla sit amet placerat ex, sollicitudin convallis urna. Sed pulvinar pellentesque sapien ut iaculis. Nunc commodo massa id diam suscipit sodales. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. In id mauris ligula. Nunc pellentesque leo tortor, non dignissim turpis placerat non. Suspendisse potenti. Nunc accumsan molestie enim non eleifend. Curabitur semper nisl quis ex lobortis, sed interdum tellus sagittis.

Cras viverra, nibh sit amet efficitur vulputate, lacus ante aliquam lectus, eget gravida sem sapien eu nibh. Integer rutrum, risus quis elementum varius, felis nunc pretium metus, fermentum tristique dolor est sit amet mauris. In consectetur leo at congue sagittis. Sed ut ante efficitur, maximus ligula eu, venenatis eros. Ut tempus elit turpis, finibus dignissim orci porttitor non. Mauris rhoncus neque eget nisi commodo, sit amet porttitor justo mattis. Etiam commodo eros sapien, a dapibus sapien malesuada sit amet. Curabitur malesuada erat magna, non varius erat fringilla et.

[UUID](https://en.wikipedia.org/wiki/Universally_unique_identifier)

| Name                               | Bytes | Contents                                                                                       |
| ---------------------------------- | ----- | ---------------------------------------------------------------------------------------------- |
| time_low                           | 4     | integer giving the low 32 bits of the time                                                     |
| time_mid                           | 2     | integer giving the middle 16 bits of the time                                                  |
| time_hi_and_version                | 2     | 4-bit "version" in the most significant bits, followed by the high 12 bits of the time         |
| clock_seq_hi_and_res clock_seq_low | 2     | 1 to 3-bit "variant" in the most significant bits, followed by the 13 to 15-bit clock sequence |
| node                               | 6     | the 48-bit node id                                                                             |
