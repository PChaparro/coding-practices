/**
 * Regular expression and general idea to solve the problem taken from:
 * https://github.com/jamerrq/advent-js-2023/blob/master/src/challenges/04.ts
 */
export function decode(message: string): string {
  const encodedMsgRegex = new RegExp(/\(([\w\s]+)\)/g);

  while (encodedMsgRegex.test(message)) {
    message = message.replaceAll(encodedMsgRegex, (_, encodedMsg) =>
      [...encodedMsg].reverse().join("")
    );
  }

  return message;
}

/**
 * This is an un-optimal and harder to read solution.
 */
/* export function decode(message: string): string {
  const ENCODED_MESSAGE_DELIMITERS = {
    OPENING: "(",
    CLOSING: ")",
  };

  // Save the index of the parenthesis to close
  const pendingToDecode: number[] = [];

  for (let i = 0; i < message.length; i++) {
    if (message[i] === ENCODED_MESSAGE_DELIMITERS["OPENING"]) {
      pendingToDecode.push(i);
    }
  }

  // Decode the message
  let decodedMsg = message;

  while (pendingToDecode.length) {
    const encodedSegmentStart = pendingToDecode.pop()!;
    const slicedArrayOffset = encodedSegmentStart + 1;
    const encodedSegmentEnd =
      decodedMsg
        .slice(encodedSegmentStart + 1)
        .indexOf(ENCODED_MESSAGE_DELIMITERS["CLOSING"]) + slicedArrayOffset;

    const encodedSegment = decodedMsg.slice(
      encodedSegmentStart + 1,
      encodedSegmentEnd
    );
    const decodedSegment = [...encodedSegment].reverse().join("");

    decodedMsg =
      decodedMsg.slice(0, encodedSegmentStart) +
      decodedSegment +
      decodedMsg.slice(encodedSegmentEnd + 1);
  }

  return decodedMsg;
} */
