export function organizeGifts(gifts: string): string {
  // Helper function to group gifts into packs of the given size
  const packGifts = ({
    count,
    size,
  }: {
    count: number;
    size: number;
  }): [number, number] => {
    // Return the number of packs and the remaining gifts
    return [Math.floor(count / size), count % size];
  };

  // Count the initial gifts
  const giftsRegex = new RegExp(/\d+[a-z]/, "g");

  const giftsCount = gifts.match(giftsRegex)?.reduce((acc, curr) => {
    const giftType = curr.at(-1)!;
    acc[giftType] = Number(curr.replace(giftType, ""));
    return acc;
  }, {} as Record<string, number>);

  // Group into boxes and pallets
  const giftsGroups: {
    [key: string]: {
      boxes: number;
      pallets: number;
      gifts: number;
    };
  } = {};

  const GIFTS_IN_BOXES = 10;
  const BOXES_IN_PALLETS = 5;

  for (const giftType in giftsCount) {
    const [initialBoxes, individualGifts] = packGifts({
      count: giftsCount[giftType],
      size: GIFTS_IN_BOXES,
    });

    const [pallets, boxes] = packGifts({
      count: initialBoxes,
      size: BOXES_IN_PALLETS,
    });

    giftsGroups[giftType] = {
      gifts: individualGifts,
      boxes,
      pallets,
    };
  }

  // Form the final result
  const giftsPackaging = Object.keys(giftsGroups).map((giftType) => {
    const {
      pallets: palletsCount,
      boxes: boxesCount,
      gifts: additionalGiftsCount,
    } = giftsGroups[giftType];

    const pallets = palletsCount ? `[${giftType}]`.repeat(palletsCount) : "";
    const boxes = boxesCount ? `{${giftType}}`.repeat(boxesCount) : "";
    const additionalGifts = additionalGiftsCount
      ? `(${giftType.repeat(additionalGiftsCount)})`
      : "";

    return `${pallets}${boxes}${additionalGifts}`;
  });

  return giftsPackaging.join("");
}

organizeGifts("76a11b");
