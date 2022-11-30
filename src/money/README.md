# Money

## Summary

Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla sit amet placerat ex, sollicitudin convallis urna. Sed pulvinar pellentesque sapien ut iaculis. Nunc commodo massa id diam suscipit sodales. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. In id mauris ligula. Nunc pellentesque leo tortor, non dignissim turpis placerat non. Suspendisse potenti. Nunc accumsan molestie enim non eleifend. Curabitur semper nisl quis ex lobortis, sed interdum tellus sagittis.

Cras viverra, nibh sit amet efficitur vulputate, lacus ante aliquam lectus, eget gravida sem sapien eu nibh. Integer rutrum, risus quis elementum varius, felis nunc pretium metus, fermentum tristique dolor est sit amet mauris. In consectetur leo at congue sagittis. Sed ut ante efficitur, maximus ligula eu, venenatis eros. Ut tempus elit turpis, finibus dignissim orci porttitor non. Mauris rhoncus neque eget nisi commodo, sit amet porttitor justo mattis. Etiam commodo eros sapien, a dapibus sapien malesuada sit amet. Curabitur malesuada erat magna, non varius erat fringilla et.

<br/>

Suppose we have a report like this:

| Asset      | Quantity | Price | Total   |
|------------|---------:|------:|--------:|
| MSFT       | 1000     | 95    | 95000   |
| XYZ        | 200      | 100   | 200000  |
|            |          | Total | 295000  |

<br/>

To make a multi-currency report, we need to add currencies:

| Asset      | Quantity | Price   | Total      |
|------------|---------:|--------:|-----------:|
| MSFT       | 1000     | 95 USD  | 95000 USD  |
| ABC        | 200      | 100 EUR | 200000 EUR |
|            |          | Total   | ??????     |

<br/>
We also need to specify exchange rates:

| From  | To    | Rate  | 
|-------|-------|------:|
| USD   | EUR   | 1.10  | 
| EUR   | USD   | 0.87  | 

