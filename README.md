# CPP Custom sized numeric values

**IMPORTANT:** This project is a work in progress and should not be intergrated nor tested until further notice


**README.md is imcomplete**

## Storage

These classes use dynamic memory and the memory must be freed with ```delete```. Numbers are stored as bitmaps.

## uDecimal

Represents an unsigned decimal. Synax:


```
uDecimal(
    int sz,
    int dp
);
```
**sz**: size of decimal in bits
**dp**: offset of decimal point in bits
