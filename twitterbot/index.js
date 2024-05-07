require("dotenv").config({ path: __dirname + "/.env" });
const { twitterClient } = require("./twitterClient.js");
const CronJob = require("cron").CronJob;

let dayCounter = 1;

const tweet = async () => {
  try {
    await twitterClient.v2.tweet(`Day ${dayCounter} asking for @elonmusk to gift me a new Tesla!`);
    dayCounter++;
  } catch (e) {
    console.log(e);
  }
};

const cronTweet = new CronJob("0 0 9 * * *", async () => {
  tweet();
});

cronTweet.start();
